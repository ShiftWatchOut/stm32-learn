#include "main.h"

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);

  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_0;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &gpioInit);
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
    HAL_Delay(1000);
  }
  return 0;
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}
