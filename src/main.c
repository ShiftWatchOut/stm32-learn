#include "main.h"

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);

  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_All;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &gpioInit);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, GPIO_PIN_SET);
  while (1)
  {
    for (int i = 0; i < 7; i++)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << i, GPIO_PIN_RESET);
      HAL_Delay(300);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << i, GPIO_PIN_SET);
    }
  }
  return 0;
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}
