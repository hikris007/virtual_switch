//
// Created by Kris Allen on 2023/12/9.
//

#ifndef VIRTUALSWITCH_TYPEDEF_H
#define VIRTUALSWITCH_TYPEDEF_H

#include <cstdint>

#define MAC_LENGTH 6

namespace omg {
    namespace VirtualSwitch {


        typedef unsigned char Byte;

        typedef size_t size_t;

        enum class EthernetFrameDataType {
            IPv4 = 0x0800,
            IPv6 = 0x86DD,
            ARP = 0x0806,
            VLAN = 0x8100,
            PPPoE = 0x8864
        };

        enum class MAC_TYPE {
            UNICAST,
            MULTICAST,
            BROADCAST,
            UNKNOWN
        };
    }
}

#endif //VIRTUALSWITCH_TYPEDEF_H
