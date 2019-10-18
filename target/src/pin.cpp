// -----------------------------------------------------------------------------
// Pin.cpp
//
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any 
// warranty of the item whatsoever, whether express, implied, or statutory, 
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will 
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including, 
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether 
// or not based upon warranty, contract, tort, or otherwise; whether or not 
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any 
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include "pin.h"
#include "Memory_map.h"

#include <cstdint>

using std::uint32_t;

namespace STM32F407 {

    // ---------------------------------------------------------------
    // Structure overlay for register access.
    // The GPIO ports are at fixed offsets from the start of the AHB1
    // bus.  Each port is at an offset of 0x400 from the previous; and
    // the ports are in port order (Port_A -> Port_I).
    // The AHB1 base address is defined in memory_map.h
    //
    struct Port_registers {
        uint32_t mode;
        uint32_t output_type;
        uint32_t output_speed;
        uint32_t pull_up_down;
        uint32_t input;
        uint32_t output;
        uint32_t bit_set_reset;
        uint32_t lock;
        uint32_t alt_fn_low;
        uint32_t alt_fn_high;
    };


    Pin::Pin(AHB1_device dev, unsigned pin_number, Mode m) :
        port { reinterpret_cast<Port_registers*>(AHB1_base + (0x400 * static_cast<int>(dev))) },
        num  { pin_number }
    {
        // Enable the clock to the GPIO port
        //
        enable(dev);

        // Default configuration.  This is good enough for
        // basic GPIO but will have to be changed for any
        // other functionality
        //
        mode(m);
        output_type(push_pull);
        output_speed(low);
        output_push_pull(none);
    }


    Pin::~Pin()
    {
        // Set the pin to input to avoid
        // generating any spurious outputs
        // outside our control.
        //
        mode(Pin::Mode::input);
    }


    void Pin::set()
    {
        port->output |= (1 << num);
    }


    void Pin::clear()
    {
        port->output &= ~(1 << num);
    }


    bool Pin::is_set() const
    {
        return ((port->input & (1 << num)) != 0);
    }


    void Pin::operator=(int val)
    {
        if (val == 0) clear();
        else          set();
    }


    Pin::operator bool() const
    {
        return is_set();
    }


    void Pin::mode(Mode m)
    {
        port->mode &= ~(0b11 << (num * 2));
        port->mode |= (m << (num * 2));
    }


    void Pin::output_type(Output_type type)
    {
        port->output_type &= ~(0b01 << num);
        port->output_type |=  (type << num);
    }


    void Pin::output_speed(Output_speed speed)
    {
        port->output_speed &= ~(0b11  << (num * 2));
        port->output_speed |=  (speed << (num * 2));
    }


    void Pin::output_push_pull(Push_pull pupd)
    {
        port->pull_up_down &= ~(0b11 << (num * 2));
        port->pull_up_down |=  (pupd << (num * 2));
    }


    void Pin::alternative_function(Alt_function fn)
    {
        if (num < 8) {
            port->alt_fn_low &= ~(0b1111 << (4 * (num % 8)));
            port->alt_fn_low |=  (fn << (4 * (num % 8)));
        }
        else {
            port->alt_fn_high &= ~(0b1111 << (4 * (num % 8)));
            port->alt_fn_high |=  (fn << (4 * (num % 8)));
        }
    }

} // namespace STM32F407