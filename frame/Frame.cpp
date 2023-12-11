//
// Created by Kris Allen on 2023/12/11.
//

#include "Frame.h"

namespace omg {
    namespace VirtualSwitch {

        Byte *Frame::raw() {
            return this->_data;
        }

        size_t Frame::capacity() const {
            return this->_capacity;
        }

    }
} // omg