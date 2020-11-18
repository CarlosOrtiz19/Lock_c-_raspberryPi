//
// Created by carlos on 11/14/20.
//

#include "../h_file/Lock.h"
#include <iostream>
#include<array>

Lock::Lock() {}

void Lock::reset() {
    resetKeys();
    resetSteps();

    outputPin_1.turnOff();
    outputPin_2.turnOff();
    outputPin_3.turnOff();
    std:: cout << "reset"  << std::endl; ;
}

void Lock::resetKeys() {
    keyOneactivated=false;
    keyTwoActivated=false;
    keyThreeActivate=false;
}

void Lock::resetSteps() {
    step_1 = false;
    step_2 = false;
    step_3 = false;
}

void Lock::startSecurity() {
    InputPin pin1= pins.at(0);
    InputPin pin2= pins.at(1);
    InputPin pin3= pins.at(2);

    for (;;) {
        int button_1 = pin1.setInputState();
        int button_2 = pin2.setInputState();
        int button_3 = pin3.setInputState();

        if (!step_1) {
            if (pin1.setInputState() == 1) {
                outputPin_1.turnOn();
                keyOneactivated = true;
                step_1 = true;
            }
        }

        if (step_1 && !step_2) {
            if (pin2.setInputState() == 1) {
                outputPin_2.turnOn();
                keyTwoActivated = true;
                step_2 = true;
            } else if (button_1 || button_3) {
                reset();
            }
        }

        if (step_1 && step_2 && !step_3) {
            if (pin3.setInputState() == 1) {
                outputPin_3.turnOn();
                keyThreeActivate = true;
            } else if (button_1 || button_2) {
                reset();
            }
        }

        if (keyOneactivated && keyTwoActivated && keyThreeActivate) {
            successfullUnlock();

            std::this_thread::sleep_for(std::chrono::seconds(5));
            blinkingOff();
            reset();
            break;
        }
    }
}

void Lock::successfullUnlock() {
    blinkingOn();
}

bool Lock::isPasswordCreated() {
    blinkingOn();

    do {
        if (inputPin_1.setInputState() == 1) {
            pins.push_back(inputPin_1.getPin());
            counter++;
        }

        if (inputPin_2.setInputState() == 1) {
            pins.push_back(inputPin_2.getPin());
            counter++;
        }
        if (inputPin_3.setInputState() == 1) {
            pins.push_back(inputPin_3.getPin());
            counter++;
        }

    } while (counter < 3);

    if(pins.size()==counter){
        blinkingOff();
    }

    return pins.size()==counter;
}

void Lock::blinkingOff() {
    outputPin_3.stopBlinking();
    outputPin_1.stopBlinking();
    outputPin_2.stopBlinking();
}

void Lock::blinkingOn() {
    outputPin_3.startBlinking();
    outputPin_1.startBlinking();
    outputPin_2.startBlinking();
}









