#include "stm8s.h"
#include "main.h"
#include "milis.h"
#include "daughterboard.h"
#include "time.h"
//#include "delay.h"
//#include <stdio.h>
//#include "uart1.h"

void setup(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz

    GPIO_Init(LED4_PORT, LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(S1_PORT,S1_PIN,GPIO_MODE_IN_PU_NO_IT);



    init_milis();
    //init_uart1();
}


int main(void)
{
    
    uint32_t time = 0;
    uint8_t minule;
    uint16_t stav = 1;
    
    setup();

    while (1) {
        if (milis() - time > 33){
            time = milis();
            
            
            if (PUSH(S1)){
                if (minule == 0){
                    if (stav == 1){
                        REVERSE(LED2);
                        stav = 2;
                        }
                    else if (stav == 2){
                        REVERSE(LED2);
                        stav = 3;
                    }
                    else if (stav == 3){
                        REVERSE(LED4);
                        stav = 4;
                    }
                    else if (stav == 4)
                    {
                        REVERSE(LED4);
                        stav = 5;
                    }
                    else if (stav == 5)
                    {
                        REVERSE(LED1);
                        stav = 6;
                    }
                    else if (stav == 6)
                    {
                        REVERSE(LED1);
                        stav = 1;
                    }      
                }
                minule = 1;
            }else{
                minule = 0;
            }
        
    }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"