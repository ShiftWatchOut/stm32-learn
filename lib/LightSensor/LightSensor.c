#include "LightSensor.h"

#define targetPin GPIO_PIN_13

/// @brief 红外传感器初始化
void LightSensor_Init(void)
{
  __HAL_RCC_GPIOB_CLK_ENABLE();
  GPIO_InitTypeDef gpioInit;
  gpioInit.Mode = GPIO_MODE_IT_RISING;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = targetPin;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioInit);
}

/// @brief 红外传感器数据获取
/// @return 引脚 1/0 值
uint8_t LightSensor_Get(void)
{
  return HAL_GPIO_ReadPin(GPIOB, targetPin);
}

void LightSensor_EXTI_Init(void)
{
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef gpioInit;
  // 此处上升下降与延时防抖有关
  gpioInit.Mode = GPIO_MODE_IT_FALLING;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = targetPin;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioInit);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

uint8_t LightSensor_Count;

/// @brief 红外传感器计数值
/// @return 当前自增后的计数值
uint8_t LightSensor_Count_Get(void)
{
  return LightSensor_Count;
}

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(targetPin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == targetPin)
  {
    HAL_Delay(10);
    if (LightSensor_Get() == GPIO_PIN_RESET)
    {
      LightSensor_Count++;
    }
  }
}
