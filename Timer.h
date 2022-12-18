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
        void setTimeout(int function, int delay);
        void setInterval(int function, int interval);
        void stop();

    protected:
        int function;
        int delay;
};
