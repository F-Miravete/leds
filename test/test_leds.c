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
 ** @brief Modulo de Testeos (ceedling)
 **/

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

#define LED01 1
#define LED02 2
#define LED03 3
#define LED04 4
#define LED05 5
#define LED06 6
#define LED07 7
#define LED08 8
#define LED09 9
#define LED10 10
#define LED11 11
#define LED12 12
#define LED13 13
#define LED14 14
#define LED15 15
#define LED16 16

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

static uint16_t leds_virtuales;

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/*

TEST (Listado)
1 - 
2 - 
3 - 
4 - Con todos los leds apagados prender un led y verificar que al consultar el estado del mismo me informa que esta prendido
5 - Prender todos los leds que estan apagados
6 - Apagar todos los leds que esten prendidos
7 - Prender leds que ya estaban prendidos de antes
8 - Apagar leds que ya esten apagados
9 - Comprobar valores prohibidos 
10 - Comprobar los valores de limite

*/

void setUp(void)
{
    leds_init(&leds_virtuales);
}

/**
 * @brief Test 1 
 *        Al iniciar el controlador los leds deben quedar apagados sin importar el estado anterior
 *
 * @param  -
 * @return -
 */
void test_todos_los_leds_inician_apagados(void)
{
    leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/**
 * @brief Test 2 
 *        Con todos los leds apagados prender el led 3 y verificar que el bit 2 se pone en 1 y el resto de bits permanece en 0
 *
 * @param  -
 * @return -
 */
void test_prender_un_led(void)
{
    leds_turn_on(LED03);
    // Bit 2 en alto
    TEST_ASSERT_BIT_HIGH((LED03 - 1), leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(1 << (LED03 - 1)), leds_virtuales);
}

/**
 * @brief Test 3
 *        Apagar un led prendido y ver que efectivamente se apaga y que el resto no cambia
 * 
 * @param  -
 * @return -
 */
void test_apagar_un_led(void)
{
    leds_turn_on(LED05);
    leds_turn_off(LED05);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/**
 * @brief Test 4
 *        Prendo 2 leds y apago 1 y verifico que solo quede 1 encendido
 * 
 * @param  -
 * @return -
 */
void test_prender_apagar_leds(void)
{
    leds_turn_on(LED02);
    leds_turn_on(LED05);
    leds_turn_off(LED02);
    TEST_ASSERT_EQUAL_UINT16(0x10, leds_virtuales);
}

/**
 * @brief Test 5
 *        Con todos los leds apagados prender un led y verificar que al consultar el estado del mismo me informa que esta prendido
 * 
 * @param  -
 * @return -
 */
void test_leer_estado_de_leds(void)
{
    leds_turn_on(LED06);
    TEST_ASSERT_TRUE(leds_get_status(LED06));
}



/* === End of documentation ==================================================================== */