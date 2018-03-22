#include "testsBits.hpp"
#include "../src/bits.hpp"
#include <iostream>
#include <numeric>
#include <array>

namespace tests::bits
{
    template<typename T>
    void testIsBitOne(T num)
    {
        std::cout << "Testing 'isBitOne' for number " << num << ":" << std::endl;

        std::array<int, sizeof(num) * 8> bits;
        std::iota(bits.begin(), bits.end(), 0);

        for (const size_t bit : bits) {
            std::cout << "  Bit " << bit << " is " << (alg::bits::isBitOne(num, alg::bits::BitIndex(bit)) ? "1" : "0") << std::endl;
        }
        std::cout << std::endl;
    }

    void testIsBitOne()
    {
        testIsBitOne(4);
        testIsBitOne(7);
        testIsBitOne(32);
    }
}
