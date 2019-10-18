// -----------------------------------------------------------------------------
// Pin.h
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

#ifndef PIN_H_
#define PIN_H_

#include "Peripherals.h"


namespace STM32F407 {

    class Pin {
    public:
        // Pin configuration
        //
        enum Mode         { input, output, alt_fn, analogue };
        enum Output_type  { push_pull, open_drain };
        enum Output_speed { low, medium, high, very_high };
        enum Push_pull    { none, pull_up, push_down };
        enum Alt_function { alt_fn00, alt_fn01, alt_fn02, alt_fn03,
                            alt_fn04, alt_fn05, alt_fn06, alt_fn07,
                            alt_fn08, alt_fn09, alt_fn10, alt_fn11,
                            alt_fn12, alt_fn13, alt_fn14, alt_fn15 };

        // Basic API
        //
        Pin(AHB1_device dev, unsigned pin_number, Mode m = input);
        ~Pin();

        void set();
        void clear();
        bool is_set() const;

        // Operator overloads
        //
        void operator=(int val);
        operator bool() const;

        // Copy policy
        //
        Pin(const Pin&)            = delete;
        Pin& operator=(const Pin&) = delete;

        // Configuration API - allows Pin function to be changed
        // after construction.
        //
        void mode(Mode m);
        void output_type(Output_type type);
        void output_speed(Output_speed speed);
        void output_push_pull(Push_pull pupd);
        void alternative_function(Alt_function fn);

    private:
        // Using the pImpl idiom
        // for the register overlay
        //
        volatile struct Port_registers* port;
        unsigned int num;
    };

} // namespace STM32F407

#endif // PIN_H_