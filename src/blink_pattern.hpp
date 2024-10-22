#pragma once

#include "../ATtiny85_BSP/src/at85_gpio.h"
#include <stdint.h>
#include <stddef.h>

namespace AT85::blink
{

typedef struct
{
    uint16_t time_on;
    uint16_t time_off;
} duration_t;

void IterateOverPattern(const duration_t *hundred_ms_delays_array, size_t length, AT85::GPIO::port_t port);

}