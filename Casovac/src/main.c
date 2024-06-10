#include <stdbool.h>
#include <stm8s.h>
//#include <stdio.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
#include "daughterboard.h"

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz

    GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);


    init_milis();
    //init_uart1();

    TIM2_TimeBaseInit(TIM2_PRESCALER_1024, 37114 - 1);
    TIM2_Cmd(ENABLE); // povolém/rozběhnu TIM2
    TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE); // povolé přerušní od TIM2
    enableInterrupts();  // celko povolí přerušovací systém
}

int moje_f(void) {
   return 314; 
}

int main(void)
{
  
    uint32_t time = 0;

    init();
    while (1) {
        
        
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
