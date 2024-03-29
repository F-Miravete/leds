/************************************************************************************************
Copyright (c) 2024, Flavio Miravete <flavio.miravete@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file
 ** @brief Capa de abstracción para manejo de leds
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

#define BIT_HIGH     1
#define LED_OFFSET   1

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

static uint16_t * puntero;

/* === Private function implementation ========================================================= */

static uint16_t led_to_mask(int led)
{
    return (BIT_HIGH << (led - LED_OFFSET));
}

/* === Public function implementation ========================================================== */

void leds_init(uint16_t * port)
{
    puntero = port;
    *puntero = ALL_LEDS_OFF;
}

void leds_turn_on(int led)
{
    if((led <= LED16) && (led >= LED01))
        *puntero |= led_to_mask(led);
}

void leds_turn_off(int led)
{
    if((led <= LED16) && (led >= LED01))
        *puntero &= ~led_to_mask(led);
}

bool leds_get_status(int led)
{
    if((led <= LED16) && (led >= LED01))
    {
        if(*puntero & led_to_mask(led))
            return true;
        else return false;
    }
    return false;
}

void leds_turn_on_all()
{
    *puntero = ALL_LEDS_ON;
}

void leds_turn_off_all()
{
    *puntero = ALL_LEDS_OFF;
}

/* === End of documentation ==================================================================== */