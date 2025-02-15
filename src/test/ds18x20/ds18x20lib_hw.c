#include <avr/interrupt.h>

#define DEBUG
#include "../../main/debug.h"

#include "../../main/ds18x20lib.h"
#include "../mock.h"
#include "Ds18x20libTest.h"

static replay_T* replay;
static uint8_t inited;
static uint16_t bitptr;

void interrupts()
{
//    EVENT(E_INTERRUPTS);
}

void no_interrupts()
{
//    EVENT(E_NO_INTERRUPTS);
}

void delay_hook_us(uint16_t us)
{
    EVENT(E_DELAY_US, us);
}

void delay_hook_ms(uint16_t ms)
{
    EVENT(E_DELAY_MS, ms);
}

void power(uint8_t mode)
{
    EVENT(E_POWER, mode);
}

void direction(uint8_t dir)
{
    EVENT(E_DIRECTION, dir);
}

uint8_t read()
{
    if (!inited) {
        debug("WARNING: not inited");
        return 0;
    }

    uint8_t bit = bitptr % 8;
    uint8_t byte = bitptr / 8;
    char* m = replay->data + byte;
    uint8_t retval = (*m & (1 << bit)) >> bit;
//    debug("read pin: %d (%d,%d,%d) [%d,%d]", retval, byte, bit, bitptr,
//          m[0]);
    bitptr++;
    EVENT(E_READ_PIN, retval);
    return retval;
}

void set_replay_data(replay_T* data)
{
    replay = data;
    inited = 1;
    bitptr = 0;
}

