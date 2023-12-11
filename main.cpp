#include <iostream>
#include "mac/MAC.h"

int main() {
    omg::VirtualSwitch::Byte mac[6] = { 0xfa, 0x2, 0x3, 0x4, 0x5, 0x6 };
    omg::VirtualSwitch::MAC mac2(mac);
    std::cout << mac2.string(true, "--::xx",6) << std::endl;
    return 0;
}
