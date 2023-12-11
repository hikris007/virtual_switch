//
// Created by Kris Allen on 2023/12/9.
//

#include "MAC.h"

namespace omg {
    namespace VirtualSwitch {
        MAC::MAC(const omg::VirtualSwitch::Byte *mac) {
            std::memcpy(this->_mac, mac, MAC_LENGTH);
        }

        MAC::MAC(const omg::VirtualSwitch::MAC &instance) {
            std::memcpy(this->_mac, instance._mac, MAC_LENGTH);
        }

        const Byte *MAC::data() const {
            return this->_mac;
        }

        bool MAC::operator==(const omg::VirtualSwitch::MAC &instance) const {
            return std::memcmp(this->_mac, instance._mac, MAC_LENGTH) == 0;
        }

        MAC_TYPE MAC::type() const {
            const Byte firstByte = this->_mac[0];

            // 单播
            if((firstByte << 7) == 0)
                return MAC_TYPE::UNICAST;

            // 组播
            if((firstByte & 0x1) != 0)
                return MAC_TYPE::MULTICAST;

            // 广播
            bool isBroadcast = true;
            for(int i=0;i<MAC_LENGTH;i++){
                if(this->_mac[i] != 0xff){
                    isBroadcast = false;
                    break;
                }
            }
            if(isBroadcast) return MAC_TYPE::BROADCAST;

            return MAC_TYPE::UNKNOWN;
        }

        std::string MAC::string(bool isCap, const char *separator, int separatorLength) const {
            static const char hexTable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
            static const char capHexTable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

            const char* table = isCap ? capHexTable : hexTable;
            static int  endLength = 1,
                        hexLength = 2;

            int charCount = (hexLength * MAC_LENGTH) + (separatorLength * (MAC_LENGTH - 1)) + endLength;
            char* result = new char[charCount];
            result[charCount - 1] = '\0';

            const Byte* currentByte = reinterpret_cast<const Byte*>(this->_mac);
            char* currentChar = &result[0];

            for(int i=0;i<MAC_LENGTH;i++){
                *currentChar++ = table[(*currentByte) / 16];
                *currentChar++ = table[(*currentByte) % 16];
                currentByte++;

                if(i < (MAC_LENGTH - 1)){
                    std::memcpy(currentChar, separator, separatorLength);
                    currentChar+=separatorLength;
                }
            }

            std::string mac(result);
            delete []result;

            return mac;
        }
    }
} // omg