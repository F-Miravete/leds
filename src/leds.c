#include "leds.h"

static uint16_t * puntero;

void leds_init(uint16_t * port)
{
    puntero = port;
    *puntero = 0x00;
}


void leds_turn_on(int led)
{
    *puntero = 4;
}

void leds_turn_off(int led)
{
    *puntero = 0x00;
}