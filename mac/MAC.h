//
// Created by Kris Allen on 2023/12/9.
//

#ifndef VIRTUALSWITCH_MAC_H
#define VIRTUALSWITCH_MAC_H


#include <string>
#include <cstring>
#include "../typedef.h"

namespace omg {
    namespace VirtualSwitch {


        /*!
         * 这个类是设计为不可变
         */
        class MAC {
        public:
            /*!
             * 传入一个地址，会拷贝从这个地址往后的 MAC_LENGTH 字节的数据
             * 目前不会判断这个指针是否有效
             * @param mac
             */
            MAC(const Byte* mac);

            /*!
             * 拷贝构造函数
             * @param instance
             */
            MAC(const MAC& instance);

            /*!
             * 返回这个地址的类型
             * @return MAC_TYPE
             */
            MAC_TYPE type() const;

            /*!
             * 比较两个地址是否一致
             * 原理：直接比对数据是否一致
             * @param instance
             * @return
             */
            bool operator==(const MAC& instance) const;

            /*!
             * 返回底层 MAC 的数据指针
             * @return
             */
            const Byte* data() const;

            /*!
             * 格式化，传入一个
             */

            /*!
             *
             * @param separator 分隔符指针（仅限Ascii）
             * @param separatorLength 分隔符长度（多少个ascii字符）
             * @param isCap 转换后是大写还是小写
             * @return 格式化后的字符串
             */
            std::string string(bool isCap = false, const char* separator = "-", int separatorLength = 1) const;
        protected:
        private:
            // 存储 MAC 的底层指针
            Byte _mac[MAC_LENGTH] = { 0 };
        };


    }
} // omg

#endif //VIRTUALSWITCH_MAC_H
