#ifndef USART_H
#define USART_H

#include <cstdint>

namespace STM32F407
{

    struct Status
    {
        std::uint32_t :7;
        std::uint32_t TXE :1;
    };

    struct Ctrl_1
    {
        std::uint32_t :10;
        std::uint32_t PCE :1;
        std::uint32_t :1;
        std::uint32_t M :1; 
    };

    class Usart
    {
        public:
        Usart();
        ~Usart();

        private:
        struct Status *status;

    };
}

#endif