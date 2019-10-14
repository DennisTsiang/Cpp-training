// -----------------------------------------------------------------------------
// Bit_ops.h
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

#ifndef BIT_OPS_H_
#define BIT_OPS_H_

#include <cstdint>

namespace Utility {

    // Creates a uint32_t where bit n is set
    //
    inline constexpr
    std::uint32_t bit(std::uint32_t n)
    {
        return (1 << n);
    }

    //
    // Creates a uint32_t where bits start -> end
    // (inclusive) are set
    //
    inline constexpr
    std::uint32_t bit_range(std::uint32_t start, std::uint32_t end)
    {
        std::uint32_t value { 0 };
        for (std::uint32_t i = start; i <= end; ++i) {
            value |= bit(i);
        }
        return value;
    }


    // Returns true if bit b is set in word
    //
    inline constexpr
    bool is_set(std::uint32_t word, std::uint32_t b)
    {
        return ((word & bit(b)) != 0);
    }
}


#endif // BIT_OPS_H_
