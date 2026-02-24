#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>

namespace hw
{
    constexpr std::uint32_t PERIPH_BASE     = 0x40000000UL;
    constexpr std::uint32_t AHBPERIPH_BASE  = PERIPH_BASE + 0x20000UL;
    constexpr std::uint32_t RCC_BASE        = AHBPERIPH_BASE + 0x3800UL;
    constexpr std::uint32_t GPIOA_BASE      = AHBPERIPH_BASE + 0x0000UL;

    inline volatile std::uint32_t& RCC_AHBENR =
        *reinterpret_cast<volatile std::uint32_t*>(RCC_BASE + 0x1C);

    inline volatile std::uint32_t& GPIOA_MODER =
        *reinterpret_cast<volatile std::uint32_t*>(GPIOA_BASE + 0x00);

    inline volatile std::uint32_t& GPIOA_ODR =
        *reinterpret_cast<volatile std::uint32_t*>(GPIOA_BASE + 0x14);
}

class GPIOA
{
public:
    static void enableClock()
    {
        hw::RCC_AHBENR |= (1 << 0);
    }

    static void setOutput(std::uint8_t pin)
    {
        hw::GPIOA_MODER &= ~(3U << (pin * 2));
        hw::GPIOA_MODER |=  (1U << (pin * 2));
    }

    static void toggle(std::uint8_t pin)
    {
        hw::GPIOA_ODR ^= (1U << pin);
    }
};

#endif
