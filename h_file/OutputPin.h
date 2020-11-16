//
// Created by carlos on 11/14/20.
//

#ifndef TP2_MOCK_OUTPUTPIN_H
#define TP2_MOCK_OUTPUTPIN_H
#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

class OutputPin {

public:
    OutputPin(int outputPin);
    void controlLed();
    void turnOff();
    void turnOn();
    void startBlinking();
    void stopBlinking();
private:
    //states
   int STATE_ON = 1;
    const int STATE_OFF = 2;
    int previousState{LOW};
    int actualState{LOW};
    int state;
    int outputPin;
    void controlOnState();
    void controlOffState();
    bool blinking{};
    std::thread thr{};
std::mutex mut{};



};


#endif //TP2_MOCK_OUTPUTPIN_H
