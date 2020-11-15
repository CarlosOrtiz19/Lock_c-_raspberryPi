//
// Created by carlos on 11/14/20.
//

#include "../h_file/OutputPin.h"
#include <wiringPi.h>
#include <iostream>

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

    pinMode(outputPin,OUTPUT);
    turnOff();
}

void OutputPin::turnOff() {
    digitalWrite(outputPin,0);
    state =0;
}

void OutputPin::turnOn() {
    std::cout << "inside"<< std::endl;
    digitalWrite(outputPin,1);
    state = 1;
}
