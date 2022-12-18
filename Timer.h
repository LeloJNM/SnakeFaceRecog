#include <iostream>
#include <string>
#include <windows.h>
#include <thread>

using namespace std;

#pragma once

class Timer { 

    bool clear = false;
    
    public:
        Timer();
        int getTimeout(int func, int del);
        int getInterval(int func, int interv);
        void setTimeout(int func, int del);
        void setInterval(int func, int interv);
        void stop();

    protected:
        int function;
        int delay;
        int interval;
};
