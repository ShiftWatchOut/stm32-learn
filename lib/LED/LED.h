#if !defined(LED_H)
#define LED_H

#include "stm32f1xx_hal.h"

void LED_A0_Init(void);
void Toggle_Test(uint8_t val);
void LED_ON(uint16_t pin);
void LED_OFF(uint16_t pin);

#endif // LED_H
