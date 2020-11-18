#include <iostream>
#include "h_file/Lock.h"
#include <array>

int main() {
    wiringPiSetup();
    Lock lock{};
    if(lock.isPasswordCreated()){
        lock.startSecurity();
    }
    return 0;
}
