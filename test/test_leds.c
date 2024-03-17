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

#include "unity.h"
#include "leds.h"

static uint16_t leds_virtuales;
static const int LED = 3;

void setUp(void)
{
    leds_init(&leds_virtuales);
}

/*
Al iniciar el controlador los leds deben quedar apagados sin importar el estado anterior
*/ 

void test_todos_los_leds_inician_apagados(void)
{
    leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/*
Con todos los leds apagados prender el led 3 y verificar que el bit 2 se pone en 1 y el resto de bits permanece en 0
*/
void test_prender_un_led(void)
{
    leds_turn_on(LED);
    // Bit 2 en alto
    TEST_ASSERT_BIT_HIGH((LED - 1), leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

/*
Apagar un led prendido y ver que efectivamente se apaga y que el resto no cambia
*/
void test_apagar_un_led(void)
{
    leds_turn_on(LED);
    leds_turn_off(LED);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

// TEST prendo y apago secuencia de leds
void test_prender_apagar_leds(void)
{
    leds_turn_on(2);
    leds_turn_on(5);
    leds_turn_off(2);
    TEST_ASSERT_EQUAL_UINT16(0x10, leds_virtuales);
}