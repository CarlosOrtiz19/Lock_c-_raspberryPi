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
    inputCallBack(previousState == actualState);
    previousState = actualState;
    actualState = digitalRead(inputPin);

    return (actualState == LOW) && (previousState == HIGH);
}

int InputPin::getState() {
    digitalRead(inputPin);
}




