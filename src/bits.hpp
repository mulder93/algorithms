#pragma once

#include <cstdlib>
#include <stdexcept>

namespace alg::bits
{
    template<typename T>
    bool isBitOne(T number, size_t bitIndex)
    {
        if (bitIndex >= sizeof(T) * 8) throw std::out_of_range("Specified bit is out of range");
        return (number & (1 << bitIndex)) != 0;
    }

    // TODO: template
    // low ordered - high ordered - grouped - format?
    void printBits(int number)
    {

    }
}
