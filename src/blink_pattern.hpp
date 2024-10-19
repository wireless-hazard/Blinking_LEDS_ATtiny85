#pragma once

#include "../ATtiny85_BSP/src/at85_gpio.h"
#include <stdint.h>
#include <stddef.h>

namespace AT85::blink
{

typedef struct
{
    uint8_t time_on;
    uint8_t time_off;
} duration_t;

void IterateOverPattern(const duration_t *seconds, size_t length, AT85::GPIO::port_t port);

}