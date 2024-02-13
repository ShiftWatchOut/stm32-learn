#include "main.h"

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);
  SysTick_Init();
  LightSensor_Init();
  OLED_Init();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  LED_A0_Init();

  OLED_ShowString(1, 1, "Hello, OLED!");
  while (1)
  {
    Toggle_Test(LightSensor_Get());
  }
  return 0;
}
