//
// Created by carlos on 11/14/20.
//

#include "../h_file/Lock.h"
#include <iostream>

Lock::Lock() {}
void Lock::reset() {
    keyOneactivated=false;
    keyTwoActivated=false;
    keyThreeActivate=false;
    step_1=false;
    step_2=false;
    step_3= false;
    outputPin_1.turnOff();
    outputPin_2.turnOff();
    outputPin_3.turnOff();
    std:: cout << "reset"  << std::endl; ;

}

void Lock::startSecurity() {

    for (;;) {
        int button_1 = inputPin_1.setInputState();
        int button_2 = inputPin_2.setInputState();
        int button_3 = inputPin_3.setInputState();

        if(!step_1){
            std::cout << "step 1 "  << std::endl;;
            if(inputPin_1.setInputState() == 1){
                //std:: cout << "pulsation step 1 " << inputPin_1.setInputState() << std::endl; ;
                outputPin_1.turnOn();
                keyOneactivated = true;
                step_1= true;
            }
        }



    if(step_1 && !step_2){
        std::cout << "step 2 "  << std::endl;;
            if(inputPin_2.setInputState() == 1 ){
                //std:: cout << "pulsation input2" << inputPin_2.setInputState() << std::endl; ;
                outputPin_2.turnOn();
                keyTwoActivated = true;
                step_2 = true;
            } else if (button_1 || button_3) {
                reset();
            }
        }

        if(step_1 && step_2 && !step_3) {
            std::cout << "step 3"  << std::endl;;
                if (inputPin_3.setInputState() == 1 ){
                    std::cout << "pulsation 3" << inputPin_3.setInputState() << std::endl;;
                    outputPin_3.turnOn();
                    keyThreeActivate = true;
                } else if (button_1 || button_2) {
                    reset();
                }
        }

        if(keyOneactivated && keyTwoActivated && keyThreeActivate){
            successfulUnlock();

            std::this_thread::sleep_for(std::chrono::seconds(5));
            outputPin_1.stopBlinking();
            outputPin_2.stopBlinking();
            outputPin_3.stopBlinking();
            reset();
            break;

        }

       // toggleStatePins(inputPin_1, outputPin_1);
        //delay(10);
        /*if(inputPin_1.setInputState() == 1){
            outputPin_1.turnOn();
        }*/






    }

}

void Lock::successfulUnlock() {
    outputPin_1.startBlinking();
    outputPin_2.startBlinking();
    outputPin_3.startBlinking();
}


void Lock::toggleStatePins(InputPin inputPin, OutputPin outputPin) {
    if(inputPin.setInputState() == 1){
        std:: cout << "pulsation" << inputPin_1.setInputState() << std::endl; ;
        outputPin.controlLed();
    }
}








