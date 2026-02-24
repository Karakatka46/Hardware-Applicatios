#include <cstdint>
#include "gpio.hpp"

static void delay()
{
    for (volatile std::uint32_t i = 0; i < 100000; ++i)
    {
        __asm__("nop");
    }
}

int main()
{
    
    GPIOA::enableClock();
    GPIOA::setOutput(5);

    while (true)
    {
        GPIOA::toggle(5);
        delay();
    }
}
