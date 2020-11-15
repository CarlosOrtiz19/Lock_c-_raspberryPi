//
// Created by carlos on 11/14/20.
//

#ifndef TP2_MOCK_LOCK_H
#define TP2_MOCK_LOCK_H


#include "InputPin.h"
#include "OutputPin.h"

class Lock {

public:

    Lock();
    void toggleStatePins(InputPin inputPin, OutputPin outputPin);
    void startSecurity();


private:
    bool keyOneactivated{false};
    bool keyTwoActivated{false};
    bool keyThreeActivate{false};
    bool step_1{};
    bool step_2{};
    bool step_3{};
    void reset();



    InputPin inputPin_1{23};
    InputPin inputPin_2{24};
    InputPin inputPin_3{25};

    OutputPin outputPin_1{0};
    OutputPin outputPin_2{2};
    OutputPin outputPin_3{3};

};


#endif //TP2_MOCK_LOCK_H
