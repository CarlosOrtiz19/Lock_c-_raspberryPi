#include <iostream>
#include "h_file/Lock.h"

int main() {
    wiringPiSetup();
    Lock lock{};
    lock.startSecurity();
    return 0;
}
