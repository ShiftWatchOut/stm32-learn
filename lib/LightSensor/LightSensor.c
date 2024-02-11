#include "LightSensor.h"

/// @brief 红外传感器初始化
void LightSensor_Init(void)
{
  __HAL_RCC_GPIOB_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_IT_RISING;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_14;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioInit);
}

/// @brief 红外传感器数据获取
/// @return 引脚 1/0 值
uint8_t LightSensor_Get(void)
{
  return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
}
