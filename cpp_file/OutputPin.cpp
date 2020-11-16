//
// Created by carlos on 11/14/20.
//

#include "../h_file/OutputPin.h"
#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

void OutputPin::controlLed() {
    switch (state) {
        case 1:
            controlOnState();
            break;
        case 0:
            controlOffState();
            break;
    }
}

void OutputPin::controlOnState() {
    turnOff();
}

void OutputPin::controlOffState() {
    turnOn();
}

OutputPin::OutputPin(int outputPin) : outputPin(outputPin) {
    pinMode(outputPin, OUTPUT);
    turnOff();
}

void OutputPin::turnOff() {
    digitalWrite(outputPin, 0);
    state = 0;
}

void OutputPin::turnOn() {
    std::cout << "inside" << std::endl;
    digitalWrite(outputPin, 1);
    state = 1;
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
