#include "main.h"

void LightSensor_Init(void)
{
  __HAL_RCC_GPIOB_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_INPUT;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_14;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioInit);
}

uint8_t LightSensor_Get(void)
{
  return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
}

int main(void)
{
  HAL_Init();
  stm32_clock_init(RCC_PLL_MUL9);
  LightSensor_Init();

  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_0;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &gpioInit);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
  while (1)
  {
    if (LightSensor_Get())
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    }
    else
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
    }
  }
  return 0;
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}
