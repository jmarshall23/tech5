#include "framework/loadscreen.h"

#include <chrono>
#include <thread>

idLoadScreen loadScreen;

idLoadScreenThread::idLoadScreenThread()
    : initialized(false), stopRunning(false), isRunning(false) {
}

idLoadScreenThread::~idLoadScreenThread() {
    stopRunning = true;
    StopThread(true);
}

int idLoadScreenThread::Run() {
    initialized = true;
    isRunning = true;
    while (!stopRunning && !IsTerminating()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(6));
    }
    isRunning = false;
    stopRunning = false;
    return 0;
}

idLoadScreen::idLoadScreen()
    : thread(nullptr), loadingGui(nullptr), guiModel(nullptr) {
}

idLoadScreen::~idLoadScreen() {
    Shutdown();
}

void idLoadScreen::Init() {
    if (thread != nullptr) return;
    thread = new idLoadScreenThread();
    thread->StartWorkerThread("LoadScreen", CORE_ANY, THREAD_NORMAL);
}

void idLoadScreen::Shutdown() {
    if (thread != nullptr) {
        thread->stopRunning = true;
        thread->SignalWork();
        delete thread;
        thread = nullptr;
    }
    loadingGui = nullptr;
    guiModel = nullptr;
}

void idLoadScreen::LaunchLoadScreen(const char*,
        const idList<idLoadScreenInfo2, 5>&) {
    if (thread == nullptr) Init();
    thread->stopRunning = false;
    thread->SignalWork();
}

void idLoadScreen::LevelLoadCompleted(const gameReturn_t&) {
    if (thread != nullptr) thread->stopRunning = true;
}
