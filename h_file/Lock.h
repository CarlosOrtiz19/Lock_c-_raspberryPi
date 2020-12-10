//
// Created by carlos on 11/14/20.
//

#ifndef TP2_MOCK_LOCK_H
#define TP2_MOCK_LOCK_H


#include "InputPin.h"
#include "OutputPin.h"
#include <vector>

class Lock {

public:
    Lock();

    void startSecurity();

    bool isPasswordCreated();

private:
    std::vector<int> pins;
    bool keyOneactivated{false};
    bool keyTwoActivated{false};
    bool keyThreeActivate{false};
    bool step_1{};
    bool step_2{};
    bool step_3{};
    int counter{0};
    InputPin inputPin_1{23};
    InputPin inputPin_2{24};
    InputPin inputPin_3{25};
    OutputPin outputPin_1{0};
    OutputPin outputPin_2{2};
    OutputPin outputPin_3{3};

    void reset();

    void successfullUnlock();

    void blinkingOn();

    void blinkingOff();

    void resetSteps();

    void resetKeys();

    bool isInvalidKey(int button_1, int button_2, int button_3) const;

    void passwordCreator();
};


#endif //TP2_MOCK_LOCK_H
