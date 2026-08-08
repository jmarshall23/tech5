#include "mqcommon.h"

#ifdef nullptr
#undef nullptr
#endif

idMQClientThread::idMQClientThread()
    : handle(0), signalQuit(false), terminated(true), connection(),
      retryTime(0) {
}

idMQClientThread::~idMQClientThread() { StopThread(true); }

void idMQClientThread::StopThread(const bool waitForStop) {
    signalQuit = true;
    connection.Close();
    if (waitForStop && handle != 0) {
        Sys_WaitForThread(static_cast<uintptr_t>(handle));
        Sys_DestroyThread(static_cast<uintptr_t>(handle));
        handle = 0;
    }
}

void idMQClientThread::Connect(idMQClientThread* thread) {
    if (thread == nullptr) return;
    amqpEndpoint_t endpoint;
    thread->connection.Init(endpoint);
    int delay = 1000;
    for (int attempt = 0; attempt < 4 && !thread->signalQuit; ++attempt) {
        if (thread->connection.Connect()) {
            thread->retryTime = 0;
            return;
        }
        thread->retryTime = static_cast<int>(GetTickCount()) + delay;
        const int end = thread->retryTime;
        while (!thread->signalQuit
                && static_cast<int>(GetTickCount()) < end) Sleep(25);
        delay += 1000;
    }
    thread->signalQuit = true;
}

unsigned int idMQClientThread::Thread(void* value) {
    idMQClientThread* thread = static_cast<idMQClientThread*>(value);
    Connect(thread);
    if (!thread->signalQuit) thread->PreRun();
    while (!thread->signalQuit) {
        thread->ThreadSlice();
        if (thread->connection.connectionTerminated && !thread->signalQuit) {
            Connect(thread);
            if (!thread->signalQuit) thread->PreRun();
        }
    }
    thread->connection.Close();
    thread->OnThreadTerminate();
    thread->terminated = true;
    return 0;
}

void idMQClientThread::StartThread(const char* threadName) {
    if (handle != 0) return;
    signalQuit = false;
    terminated = false;
    handle = static_cast<unsigned int>(Sys_CreateThread(Thread, this,
        THREAD_LOWEST, threadName == nullptr ? "AMQP Client" : threadName,
        CORE_ANY, 0x20000, false));
}
