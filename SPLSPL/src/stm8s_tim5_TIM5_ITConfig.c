/**
  ******************************************************************************
  * @file    stm8s_tim5.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    16-June-2017
  * @brief   This file contains all the functions for the TIM5 peripheral.
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
#include "stm8s_tim5.h"



/**
  * @brief  Enables or disables the specified TIM5 interrupts.
  * @param   NewState new state of the TIM5 peripheral.
  * This parameter can be: ENABLE or DISABLE.
  * @param   TIM5_IT specifies the TIM5 interrupts sources to be enabled or disabled.
  * This parameter can be any combination of the following values:
  *                       - TIM5_IT_UPDATE: TIM5 update Interrupt source
  *                       - TIM5_IT_CC1: TIM5 Capture Compare 1 Interrupt source
  *                       - TIM5_IT_CC2: TIM5 Capture Compare 2 Interrupt source
  *                       - TIM5_IT_CC3: TIM5 Capture Compare 3 Interrupt source
  * @param   NewState new state of the TIM5 peripheral.
  * @retval None
  */
void TIM5_ITConfig(TIM5_IT_TypeDef TIM5_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM5_IT_OK(TIM5_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TIM5->IER |= (uint8_t)TIM5_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TIM5->IER &= (uint8_t)(~TIM5_IT);
  }
}