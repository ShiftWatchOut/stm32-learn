#include "stm32f1xx_hal.h"
#include "RotaryEncoder.h"

void RotaryEncoder_Init(void)
{

  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef gpioInit;
  // 此处上升下降与延时防抖有关
  gpioInit.Mode = GPIO_MODE_IT_FALLING;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Pin = GPIO_PIN_0;
  gpioInit.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioInit);
  gpioInit.Pin = GPIO_PIN_1;
  HAL_GPIO_Init(GPIOB, &gpioInit);

  HAL_NVIC_SetPriority(EXTI0_IRQn, 3, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
  HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}
uint16_t RE_Count;
uint16_t RotaryEncoder_Get(void)
{
  uint16_t tmp = RE_Count;
  RE_Count = 0;
  return tmp;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_0)
  {
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1) == 0)
    {
      RE_Count--;
    }
  }
  if (GPIO_Pin == GPIO_PIN_1)
  {
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0)
    {
      RE_Count++;
    }
  }
}

void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}
