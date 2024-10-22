#include "blink_pattern.hpp"

#include <util/delay.h>

static constexpr double BASE_DELAY_SECONDS = double{500};

namespace AT85::blink
{

static void variable_delay(uint8_t hundred_ms_delays)
{
    for (volatile uint8_t iteration = 0U; iteration < hundred_ms_delays; iteration++)
    {
        _delay_ms(BASE_DELAY_SECONDS);
    }
}

static void SetBlinkPattern(uint8_t hundred_ms_delays_on, uint8_t hundred_ms_delays_off, AT85::GPIO::port_t port)
{
    SetLevel(true, port);
    variable_delay(hundred_ms_delays_on);
    SetLevel(false, port);
    variable_delay(hundred_ms_delays_off);
}

void IterateOverPattern(const duration_t *hundred_ms_delays_array, size_t length, AT85::GPIO::port_t port)
{
    for (size_t iteration = 0U; iteration < length; iteration++)
    {
        SetBlinkPattern(
            hundred_ms_delays_array[iteration].time_on, 
            hundred_ms_delays_array[iteration].time_off, 
            port);
    }
}

}