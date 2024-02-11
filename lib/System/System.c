#include "System.h"

/// @brief 系统时钟初始化
/// @param pll PLL 倍频系数，取值范围 2~16，中断向量表位置在启动时已经在 SystemInit 中初始化
void stm32_clock_init(__UINT32_TYPE__ pll)
{
  HAL_StatusTypeDef ret = HAL_ERROR;
  RCC_OscInitTypeDef rcc_osc_init;
  RCC_ClkInitTypeDef rcc_clk_init;
  rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  rcc_osc_init.HSEState = RCC_HSE_ON;
  rcc_osc_init.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  rcc_osc_init.PLL.PLLState = RCC_PLL_ON;
  rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  rcc_osc_init.PLL.PLLMUL = pll;
  ret = HAL_RCC_OscConfig(&rcc_osc_init);

  if (ret != HAL_OK)
    hold();

  rcc_clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
  rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
  rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
  ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_2);
  if (ret != HAL_OK)
    hold();
}

void hold(void)
{
  while (1)
  {
  }
}