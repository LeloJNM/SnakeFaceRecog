#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <cmath>
#include <Mmsystem.h>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include "Pontuacao.h"

using namespace std;

#pragma once

class Timer { 

    bool clear = false;

    public:
        Timer();
        void displayClock();
        void timer(bool *contando);
        int seconds = 59;
        Pontuacao pontuacao;
    };
