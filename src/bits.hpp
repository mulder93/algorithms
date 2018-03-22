#pragma once

#include <cstdlib>
#include <stdexcept>

namespace alg::bits
{
    class BitIndex
    {
    public:
        explicit BitIndex(size_t index) : m_bitIndex(index) { }
        size_t get() { return m_bitIndex; }

    private:
        size_t m_bitIndex;
    };

    class PowerOfTwo
    {
    public:
        explicit PowerOfTwo(size_t power) : m_power(power)
        {
            if (m_power == 0)
                throw std::out_of_range("Cannot take module by zero");
        }

        size_t get() { return m_power; }

    private:
        size_t m_power;
    };

    //TODO: only for integrals (SFINAE)

    template<typename T>
    bool isBitOne(T number, BitIndex bitIndex)
    {
        if (bitIndex.get() >= sizeof(T) * 8)
            throw std::out_of_range("Specified bit is out of range");

        return (number & (T(1) << bitIndex.get())) != 0;
    }

    template<typename T>
    T setBitOne(T number, BitIndex bitIndex)
    {
        if (bitIndex.get() >= sizeof(T) * 8)
            throw std::out_of_range("Specified bit is out of range");

        return number | (T(1) << bitIndex.get());
    }

    template<typename T>
    T setBitZero(T number, BitIndex bitIndex)
    {
        if (bitIndex.get() >= sizeof(T) * 8)
            throw std::out_of_range("Specified bit is out of range");

        return number & (~(T(1) << bitIndex.get()));
    }

    template<typename T>
    T isolateLowestOne(T number)
    {
        return number & (~(number - 1));
    }

    template<typename T>
    T replaceLowestOneByZero(T number)
    {
        return number & (number - 1);
    }

    template<typename T>
    T propagateRightLowestOne(T number)
    {
        return number | (number - 1);
    }

    template<typename T>
    T computeModuloByPowerOfTwo(T number, PowerOfTwo power)
    {
        return number & (T(1) << (power.get() - 1));
    }

    template<typename T>
    bool isPowerOfTwo(T number)
    {
        return (number & (number - 1)) == 0;
    }

    // low ordered - high ordered - grouped - format?
    template<typename T>
    void printBits(T number)
    {

    }
}
