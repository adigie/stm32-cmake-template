/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MFX_IRQ_OUT_Pin GPIO_PIN_13
#define MFX_IRQ_OUT_GPIO_Port GPIOC
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define MFX_WAKEUP_Pin GPIO_PIN_1
#define MFX_WAKEUP_GPIO_Port GPIOA
#define LD_R_Pin GPIO_PIN_5
#define LD_R_GPIO_Port GPIOA
#define ePD1_RESET_Pin GPIO_PIN_2
#define ePD1_RESET_GPIO_Port GPIOB
#define ePD1_PWR_ENn_Pin GPIO_PIN_10
#define ePD1_PWR_ENn_GPIO_Port GPIOB
#define ePD1_D_C_Pin GPIO_PIN_11
#define ePD1_D_C_GPIO_Port GPIOB
#define NFC_NSS_Pin GPIO_PIN_12
#define NFC_NSS_GPIO_Port GPIOB
#define NFC_SCK_Pin GPIO_PIN_13
#define NFC_SCK_GPIO_Port GPIOB
#define NFC_MISO_Pin GPIO_PIN_14
#define NFC_MISO_GPIO_Port GPIOB
#define NFC_MOSI_Pin GPIO_PIN_15
#define NFC_MOSI_GPIO_Port GPIOB
#define ePD1_BUSY_Pin GPIO_PIN_8
#define ePD1_BUSY_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_9
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_10
#define USART_RX_GPIO_Port GPIOA
#define USB1_DM_Pin GPIO_PIN_11
#define USB1_DM_GPIO_Port GPIOA
#define USB1_DP_Pin GPIO_PIN_12
#define USB1_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define ePD1_CS_Pin GPIO_PIN_15
#define ePD1_CS_GPIO_Port GPIOA
#define ePD1_SCK_Pin GPIO_PIN_3
#define ePD1_SCK_GPIO_Port GPIOB
#define LD_G_Pin GPIO_PIN_4
#define LD_G_GPIO_Port GPIOB
#define ePD1_MOSI_Pin GPIO_PIN_5
#define ePD1_MOSI_GPIO_Port GPIOB
#define MFX_I2C_SCL_Pin GPIO_PIN_8
#define MFX_I2C_SCL_GPIO_Port GPIOB
#define MFX_I2C_SDA_Pin GPIO_PIN_9
#define MFX_I2C_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
