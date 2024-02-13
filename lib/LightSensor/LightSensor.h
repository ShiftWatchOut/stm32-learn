#if !defined(LIGHTSENSOR_H)
#define LIGHTSENSOR_H

#include "stm32f1xx_hal.h"

void LightSensor_Init(void);
uint8_t LightSensor_Get(void);
void LightSensor_EXTI_Init(void);
uint8_t LightSensor_Count_Get(void);

#endif // LIGHTSENSOR_H
