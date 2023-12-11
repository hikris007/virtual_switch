//
// Created by Kris Allen on 2023/12/11.
//

#ifndef VIRTUALSWITCH_NONCOPYABLE_H
#define VIRTUALSWITCH_NONCOPYABLE_H

namespace omg {
    namespace VirtualSwitch {
        class NonCopyable {
        protected:
            // 默认构造函数
            NonCopyable() = default;

            // 默认析构函数
            virtual ~NonCopyable() = default;

            // 禁用拷贝构造函数
            NonCopyable(const NonCopyable&) = delete;

            // 禁用拷贝赋值运算符
            NonCopyable& operator=(const NonCopyable&) = delete;
        };
    }
} // omg

#endif //VIRTUALSWITCH_NONCOPYABLE_H
