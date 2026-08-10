#pragma once

class idAIStateLite {
public:
    idAIStateLite();
    virtual ~idAIStateLite() = default;

protected:
    void* listenerList;
    void* listeningToList;

public:
    int subState;
};
