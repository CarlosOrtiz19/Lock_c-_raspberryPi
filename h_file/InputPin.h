//
// Created by carlos on 11/14/20.
//

#ifndef TP2_MOCK_INPUTPIN_H
#define TP2_MOCK_INPUTPIN_H


#include <wiringPi.h>
#include "InputCallBack.h"

class InputPin {

public:
    InputPin(int inputPin);
    bool setInputState();
    int getPin();
    virtual ~InputPin();

private:
    InputCallBack inputCallBack {} ;
    int inputPin;
    int previousState{0};
    int actualState{0};
};


#endif //TP2_MOCK_INPUTPIN_H
