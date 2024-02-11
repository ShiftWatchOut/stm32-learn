#include "LED.h"

/// @brief A0 处LED 初始化
void LED_A0_Init(void)
{
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_0;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &gpioInit);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}

/// @brief 红外传感器测试
void Toggle_Test(uint8_t val)
{
  if (val)
  {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
  }
  else
  {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
  }
}
