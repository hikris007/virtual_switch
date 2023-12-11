//
// Created by Kris Allen on 2023/12/11.
//

#ifndef VIRTUALSWITCH_FRAME_H
#define VIRTUALSWITCH_FRAME_H

#include "../typedef.h"
#include "../mac/MAC.h"

namespace omg {
    namespace VirtualSwitch {

        class Frame {
        public:
            /*!
             * 获取原始指针
             * @return 底层容器指针
             */
            Byte* raw();

            /*!
             * 底层数组的容量
             * @return
             */
            size_t capacity() const;

            /*!
             * 获取这个帧的存的数据类型
             * @return
             */
            EthernetFrameDataType type() const;

            /*!
             * 设置这个帧的存的数据类型
             * @return
             */
            void type(EthernetFrameDataType type);

            /*!
             * 获取源地址 MAC
             * 是直接拷贝出去的, 即便 Frame 的数据改变了也不会影响返回后的 MAC
             * @return
             */
            MAC src() const;

            /*!
             * 获取目的地址 MAC
             * 是直接拷贝出去的, 即便 Frame 的数据改变了也不会影响返回后的 MAC
             * @return
             */
            MAC dst() const;

            /*!
             * 设置这个 Frame 的源 MAC
             * 会直接写入底层数据, 之后即便是 MAC 改变也不会影响
             * @param sourceMac
             */
            void src(const MAC& sourceMac);


            /*!
             * 设置这个 Frame 的目的 MAC
             * 会直接写入底层数据, 之后即便是 MAC 改变也不会影响
             * @param sourceMac
             */
            void dst(const MAC& destinationMac);
        protected:
        private:
            Byte* _data = nullptr;
            size_t _capacity = 0;
        };

    }
} // omg

#endif //VIRTUALSWITCH_FRAME_H
