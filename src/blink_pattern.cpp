#include "blink_pattern.hpp"

#include <util/delay.h>

static constexpr double BASE_DELAY = double{1000};

namespace AT85::blink
{

static void variable_delay(uint8_t seconds)
{
    for (volatile uint8_t iteration = 0U; iteration < seconds; iteration++)
    {
        _delay_ms(BASE_DELAY);
    }
}

static void SetBlinkPattern(uint8_t seconds_on, uint8_t seconds_off, AT85::GPIO::port_t port)
{
    SetLevel(true, port);
    variable_delay(seconds_on);
    SetLevel(false, port);
    variable_delay(seconds_off);
}

void IterateOverPattern(const duration_t *seconds, size_t length, AT85::GPIO::port_t port)
{
    for (size_t iteration = 0U; iteration < length; iteration++)
    {
        SetBlinkPattern(seconds[iteration].time_on, seconds[iteration].time_off, port);
    }
}

}