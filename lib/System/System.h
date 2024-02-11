#if !defined(SYSTEM_H)
#define SYSTEM_H

#include "stm32f1xx_hal.h"
void stm32_clock_init(__UINT32_TYPE__ pll);
void hold(void);

#endif // SYSTEM_H
