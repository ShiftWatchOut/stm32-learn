#include "LED.h"

/// @brief 7个 LED 初始化
void LED_A0_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  uint32_t seven_pins = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
  gpioInit.Pin = seven_pins;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &gpioInit);
  HAL_GPIO_WritePin(GPIOA, seven_pins, GPIO_PIN_SET);
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

/// @brief 点亮指定 pin LED
void LED_ON(uint16_t pin)
{
  HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
}

/// @brief 关闭指定 pin LED
void LED_OFF(uint16_t pin)
{
  HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_SET);
}
