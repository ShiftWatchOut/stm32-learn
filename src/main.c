#include "main.h"

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);
  SysTick_Init();
  LightSensor_EXTI_Init();
  OLED_Init();

  LED_A0_Init();

  OLED_ShowString(1, 1, "LightCnt: ");
  while (1)
  {
    OLED_ShowNum(1, 11, LightSensor_Count_Get(), 6);
  }
  return 0;
}
