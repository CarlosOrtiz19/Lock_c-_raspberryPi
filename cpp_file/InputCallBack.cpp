//
// Created by carlos on 11/14/20.
//

#include <wiringPi.h>
#include "../h_file/InputCallBack.h"

bool InputCallBack::operator()(bool signalState) {
    if(signalState){
        delay(10);
    }
    return signalState;
}

InputCallBack::InputCallBack() {}

