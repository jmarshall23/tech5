#pragma once

#include "idlib/networking/amqp/mqmessaging.h"
#include "idlib/networking/protocols/reports.pb.h"

#include <string>
#include <vector>

struct mapLoadEvent_t {
    const char* timestamp;
    idreports::MapReport message;
};

struct viewNoteEvent_t {
    const char* timestamp;
    idreports::ViewNoteReport message;
};

struct assertEvent_t {
    const char* timestmap; // Original spelling retained for recovered ABI users.
    idreports::AssertReport message;
};

struct idUniqueWarning {
    idStr message;
    unsigned int count;
};

struct viewNoteData_t {
    idStr bugTitle;
    idStr taskType;
    idStr reproSteps;
    idStr details;
    idStr severity;
    idStr priority;
    idStr attachmentFilename;
    idStr gameName;
    bool isMultiplayer;
    int buildNumberMajor;
    int buildNumberMinor;
    idStr vt_filePath;
    idStr vt_filePathOverride;
    idStr mapName;
};

class idAnalysisClient : public idMQClientThread {
public:
    idAnalysisClient();
    ~idAnalysisClient() override;

    void StartMessageSystem() override;
    void StopMessageSystem() override;
    void PreRun() override;
    void ThreadSlice() override;
    void OnThreadTerminate() override;

    void SetCurrentMap(const char* mapName);
    void QueueAssert(const idreports::AssertReport& report,
        const char* timestamp = 0);
    void QueueMapLoad(const idreports::MapReport& report,
        const char* timestamp = 0);
    void QueueViewNote(const idreports::ViewNoteReport& report,
        const char* timestamp = 0);

    int NumPendingAsserts();
    int NumPendingMapLoads();
    int NumPendingViewNotes();

    int reportTime;
    idMQChannel* channel;
    idStrStatic<1024> currentMap;
    idSysMutex assertMutex;
    idSysMutex mapLoadMutex;
    idSysMutex viewNoteMutex;

private:
    template<class T>
    struct pendingEvent_t {
        std::string timestamp;
        T message;
    };

    std::vector<pendingEvent_t<idreports::AssertReport> > pendingAsserts;
    std::vector<pendingEvent_t<idreports::MapReport> > pendingMapLoads;
    std::vector<pendingEvent_t<idreports::ViewNoteReport> > pendingViewNotes;
};

extern idCVar mq_enable;
extern idCVar mq_analysisReportRate;
extern idAnalysisClient analysisClient;

void PublishEvent(idreports::LogEvent& logEvent, const char* timestamp,
    idreports::LogEvent_Severity severity, const char* message,
    google::protobuf::MessageLite& outgoing, const char* messageType,
    idMQChannel* channel, const char* routingKey);

