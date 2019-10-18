#include "usart.h"
#include "Peripherals.h"

namespace STM32F407
{
    
    Usart::Usart() :
        status { reinterpret_cast<Status*>(0x40004800 + 0x00) }
    {
        enable(APB1_device::usart_3);
    }
}