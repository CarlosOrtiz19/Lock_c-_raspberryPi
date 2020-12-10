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

    void turnOff();

    void turnOn();

    void startBlinking();

    void stopBlinking();

private:
    int outputPin;

    void controlOnState();

    void controlOffState();

    bool blinking{};
    std::thread thr{};
    std::mutex mut{};

};


#endif //TP2_MOCK_OUTPUTPIN_H
