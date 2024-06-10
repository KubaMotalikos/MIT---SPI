/**
  ******************************************************************************
  * @file    stm8s_flash.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the FLASH peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
#include "stm8s_flash.h"



/**
  * @brief  Select the Flash behaviour in low power mode
  * @param  FLASH_LPMode Low power mode selection
  *         This parameter can be any of the @ref FLASH_LPMode_TypeDef values.
  * @retval None
  */
void FLASH_SetLowPowerMode(FLASH_LPMode_TypeDef FLASH_LPMode)
{
  /* Check parameter */
  assert_param(IS_FLASH_LOW_POWER_MODE_OK(FLASH_LPMode));
  
  /* Clears the two bits */
  FLASH->CR1 &= (uint8_t)(~(FLASH_CR1_HALT | FLASH_CR1_AHALT)); 
  
  /* Sets the new mode */
  FLASH->CR1 |= (uint8_t)FLASH_LPMode; 
}