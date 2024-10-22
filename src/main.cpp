#include <util/delay.h>
#include "blink_pattern.hpp"

static const AT85::blink::duration_t array_of_delays[] = {
    {1,1},
    {1,1},
    };

int main(void)
{
    using namespace AT85;

    GPIO::SetDirection(GPIO::OUTPUT, GPIO::PORTB_1);
    
    while(1)
    {  
        blink::IterateOverPattern(
            &array_of_delays[0], 
            sizeof(array_of_delays)/sizeof(blink::duration_t), 
            GPIO::PORTB_1);
    }
}