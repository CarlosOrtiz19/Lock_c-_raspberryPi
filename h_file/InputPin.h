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
    int getInputState();

private:
    InputCallBack inputCallBack {} ;
    int inputPin;
    int state {0};
    int previousState{0};
    int actualState{0};
    bool isButtonPressed();
    bool lastClicked{false};
    bool lastOutState {false};
    int getState();




};


#endif //TP2_MOCK_INPUTPIN_H
