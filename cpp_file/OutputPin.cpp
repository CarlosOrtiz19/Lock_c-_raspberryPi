//
// Created by carlos on 11/14/20.
//

#include "../h_file/OutputPin.h"
#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

void OutputPin::turnOff() {
    digitalWrite(outputPin, 0);
}

OutputPin::OutputPin(int outputPin) : outputPin(outputPin) {
    pinMode(outputPin, OUTPUT);
    turnOff();
}

void OutputPin::turnOn() {
    digitalWrite(outputPin, 1);
}

void OutputPin::startBlinking() {
    std::lock_guard<std::mutex> lg(mut);
    if (blinking) return;
    blinking = true;
    thr = std::thread{[this]() {
        for (;;) {
            {
                std::lock_guard<std::mutex> lg{mut};
                if (!blinking) break;
            }

            digitalWrite(outputPin, HIGH);
            std::this_thread::sleep_for(std::chrono::milliseconds{100});
            digitalWrite(outputPin, LOW);
            std::this_thread::sleep_for(std::chrono::milliseconds{100});
        }
    }};
}

void OutputPin::stopBlinking() {
    {
        std::lock_guard<std::mutex> lg{mut};
        blinking = false;
    }
    if (thr.joinable())thr.join();


}
