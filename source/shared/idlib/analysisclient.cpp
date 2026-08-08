#include "analysisclient.h"

#ifdef nullptr
#undef nullptr
#endif
#ifdef snprintf
#undef snprintf
#endif

#include <algorithm>
#include <cstdio>
#include <ctime>

idCVar mq_analysisReportRate(
    "mq_analysisReportRate", "1", CVAR_INTEGER,
    "Control the rate at which asserts and map stats get reported.");
idCVar mq_enable(
    "mq_enable", "0", CVAR_BOOL,
    "Enables the analysis client");

idAnalysisClient analysisClient;

namespace {

std::string CurrentTimestamp() {
    std::time_t now = std::time(0);
    std::tm utcTime = {};
    gmtime_s(&utcTime, &now);
    char buffer[32] = {};
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", &utcTime);
    return buffer;
}

std::string EventTimestamp(const char* timestamp) {
    return timestamp == 0 || timestamp[0] == 0
        ? CurrentTimestamp() : std::string(timestamp);
}

int NextReportTime() {
    const int seconds = std::max(1, mq_analysisReportRate.GetInteger());
    return Sys_Milliseconds() + seconds * 1000;
}

} // namespace

idAnalysisClient::idAnalysisClient()
    : idMQClientThread(), reportTime(0), channel(nullptr), currentMap(),
      assertMutex(), mapLoadMutex(), viewNoteMutex(), pendingAsserts(),
      pendingMapLoads(), pendingViewNotes() {
}

idAnalysisClient::~idAnalysisClient() {
    StopThread(true);
}

void idAnalysisClient::StartMessageSystem() {
    if (mq_enable.GetBool()) {
        StartThread("AMQP idAnalysisClient >> Server");
    }
}

void idAnalysisClient::StopMessageSystem() {
    StopThread(true);
}

void idAnalysisClient::SetCurrentMap(const char* mapName) {
    currentMap = mapName == nullptr ? "" : mapName;
}

void idAnalysisClient::QueueAssert(const idreports::AssertReport& report,
        const char* timestamp) {
    idScopedCriticalSection lock(assertMutex);
    pendingEvent_t<idreports::AssertReport> event;
    event.timestamp = EventTimestamp(timestamp);
    event.message = report;
    pendingAsserts.push_back(event);
}

void idAnalysisClient::QueueMapLoad(const idreports::MapReport& report,
        const char* timestamp) {
    idScopedCriticalSection lock(mapLoadMutex);
    pendingEvent_t<idreports::MapReport> event;
    event.timestamp = EventTimestamp(timestamp);
    event.message = report;
    pendingMapLoads.push_back(event);
}

void idAnalysisClient::QueueViewNote(const idreports::ViewNoteReport& report,
        const char* timestamp) {
    idScopedCriticalSection lock(viewNoteMutex);
    pendingEvent_t<idreports::ViewNoteReport> event;
    event.timestamp = EventTimestamp(timestamp);
    event.message = report;
    pendingViewNotes.push_back(event);
}

int idAnalysisClient::NumPendingAsserts() {
    idScopedCriticalSection lock(assertMutex);
    return static_cast<int>(pendingAsserts.size());
}

int idAnalysisClient::NumPendingMapLoads() {
    idScopedCriticalSection lock(mapLoadMutex);
    return static_cast<int>(pendingMapLoads.size());
}

int idAnalysisClient::NumPendingViewNotes() {
    idScopedCriticalSection lock(viewNoteMutex);
    return static_cast<int>(pendingViewNotes.size());
}

void idAnalysisClient::PreRun() {
    channel = connection.GetChannel();
    if (channel != nullptr) {
        channel->ExchangeDeclare(idStr("idtech5"), idStr("topic"), true,
            false);
    }
    reportTime = NextReportTime();
}

void PublishEvent(idreports::LogEvent& logEvent, const char* timestamp,
        const idreports::LogEvent_Severity severity, const char* message,
        google::protobuf::MessageLite& outgoing, const char* messageType,
        idMQChannel* channel, const char* routingKey) {
    logEvent.Clear();
    logEvent.set_timestamp(timestamp == nullptr ? "" : timestamp);
    logEvent.set_severity(severity);
    logEvent.set_message(message == nullptr ? "" : message);
    logEvent.set_datatype(messageType == nullptr ? "" : messageType);

    std::string outgoingData;
    outgoing.SerializePartialToString(&outgoingData);
    logEvent.set_data(outgoingData.data(), outgoingData.size());

    std::string envelope;
    logEvent.SerializePartialToString(&envelope);
    if (channel != nullptr) {
        channel->BasicPublish(idStr("idtech5"),
            idStr(routingKey == nullptr ? "" : routingKey), false, false,
            envelope.data(), static_cast<unsigned int>(envelope.size()));
    }
    logEvent.Clear();
}

void idAnalysisClient::ThreadSlice() {
    if (reportTime >= Sys_Milliseconds()) {
        Sleep(25);
        return;
    }

    std::vector<pendingEvent_t<idreports::AssertReport> > asserts;
    std::vector<pendingEvent_t<idreports::MapReport> > mapLoads;
    std::vector<pendingEvent_t<idreports::ViewNoteReport> > viewNotes;
    {
        idScopedCriticalSection lock(assertMutex);
        asserts.swap(pendingAsserts);
    }
    {
        idScopedCriticalSection lock(mapLoadMutex);
        mapLoads.swap(pendingMapLoads);
    }
    {
        idScopedCriticalSection lock(viewNoteMutex);
        viewNotes.swap(pendingViewNotes);
    }

    idreports::LogEvent logEvent;
    for (std::size_t index = 0; index < asserts.size(); ++index) {
        char message[1200];
        std::snprintf(message, sizeof(message), "Hit an assert in %s",
            asserts[index].message.mapname().c_str());
        PublishEvent(logEvent, asserts[index].timestamp.c_str(),
            idreports::LogEvent_Severity_SEV_ERROR, message,
            asserts[index].message, "AssertReport", channel,
            "idtech5.events.assert_report");
    }
    for (std::size_t index = 0; index < mapLoads.size(); ++index) {
        char message[1200];
        std::snprintf(message, sizeof(message), "%s loaded the map %s",
            mapLoads[index].message.username().c_str(),
            mapLoads[index].message.mapname().c_str());
        PublishEvent(logEvent, mapLoads[index].timestamp.c_str(),
            idreports::LogEvent_Severity_SEV_WARNING, message,
            mapLoads[index].message, "MapReport", channel,
            "idtech5.events.map_load");
    }
    for (std::size_t index = 0; index < viewNotes.size(); ++index) {
        char message[1200];
        std::snprintf(message, sizeof(message),
            "%s published a viewnote for %s",
            viewNotes[index].message.username().c_str(),
            viewNotes[index].message.mappath().c_str());
        PublishEvent(logEvent, viewNotes[index].timestamp.c_str(),
            idreports::LogEvent_Severity_SEV_INFO, message,
            viewNotes[index].message, "ViewNoteReport", channel,
            "idtech5.events.viewnote");
    }
    reportTime = NextReportTime();
    Sleep(250);
}

void idAnalysisClient::OnThreadTerminate() {
    channel = nullptr;
    idLib::Printf("idAnalysisClient::OnThreadTerminate \n");
}

