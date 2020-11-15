//
// Created by carlos on 11/14/20.
//

#include "../h_file/InputPin.h"
#include <wiringPi.h>
#include <iostream>



InputPin::InputPin(int inputPin) : inputPin(inputPin) {
    pinMode(inputPin,INPUT);
}

int InputPin::getInputState() {
    return 0;
}

bool InputPin::setInputState() {
    previousState = actualState;
    actualState = digitalRead(inputPin);
    delay(40);
    return (actualState == LOW) && (previousState == HIGH);
}

int InputPin::getState() {
    digitalRead(inputPin);
}




