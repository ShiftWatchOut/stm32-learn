#include "main.h"

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);
  SysTick_Init();
  RotaryEncoder_Init();
  OLED_Init();

  LED_A0_Init();

  OLED_ShowString(1, 1, "LightCnt: ");
  int16_t num = 0;
  while (1)
  {
    num += RotaryEncoder_Get();
    OLED_ShowSignedNum(1, 11, num, 5);
  }
  return 0;
}
