/*

aca copiamos los test escritos al principio de la clase

*/

#include "unity.h"
#include "leds.h"

static const int LED = 3;

// TEST init
void test_todos_los_leds_inician_apagados(void)
{
	//TEST_FAIL_MESSAGE("ARRANCAMOS");
    uint16_t leds_virtuales = 0xFF;
    leds_init(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

// TEST Enciendo 1 led
void test_prender_un_led(void)
{
    uint16_t leds_virtuales;
    leds_init(&leds_virtuales);
    leds_turn_on(LED);
    TEST_ASSERT_BIT_HIGH((LED -1), leds_virtuales);

    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_virtuales);
}

// TEST Apago 1 led
void test_apagar_un_led(void)
{
    uint16_t leds_virtuales;
    leds_init(&leds_virtuales);
    leds_turn_on(LED);
    leds_turn_off(LED);

    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}