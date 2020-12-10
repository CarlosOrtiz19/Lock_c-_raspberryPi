//
// Created by carlos on 11/14/20.
//

#include "../h_file/InputPin.h"
#include <wiringPi.h>
#include <iostream>

InputPin::InputPin(int inputPin) : inputPin(inputPin) {
    pinMode(inputPin, INPUT);
}

bool InputPin::setInputState() {
    previousState = actualState;
    actualState = digitalRead(inputPin);
    inputCallBack(previousState == actualState);
    return (actualState == LOW) && (previousState == HIGH);
}

int InputPin::getPin() {
    return inputPin;
}

InputPin::~InputPin() {

}




