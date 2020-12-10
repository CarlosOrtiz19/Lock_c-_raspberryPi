#include <iostream>
#include "h_file/Lock.h"
#include <array>

int main() {
    wiringPiSetup();
    Lock lock{};
    if(lock.isPasswordCreated()){
        lock.startSecurity();
    }

    for (int i = 0; i < ; ++i) {
        
    }
    return 0;
}
