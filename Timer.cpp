#include "Timer.h"

Timer::Timer() {
}

void Timer::setTimeout(auto function, int delay) {
    this->clear = false;
    std::thread t([=]() {
        if(this->clear) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if(this->clear) return;
        function();
    });
    t.detach();
}

void Timer::setInterval(int function, int interval){

}

void Timer::stop(){

}