#include "stm8s.h"
#include "main.h"
#include "milis.h"
#include "daughterboard.h"
#include "stdbool.h"

//#include "delay.h"
//#include <stdio.h>
//#include "uart1.h"

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz

    GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED3_PORT, LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED4_PORT, LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED5_PORT, LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED6_PORT, LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED7_PORT, LED7_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED8_PORT, LED8_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(S1_PORT, S1_PIN, GPIO_MODE_IN_PU_NO_IT);

    init_milis();
    //init_uart1();
}

uint32_t time = 0;
/*uint8_t cube [7] = {
        0b00000000, //0
        0b00100000, //1
        0b10000001, //2
        0b10100001, //3
        0b11000011, //4 
        0b11100011, //5
        0b11011011, //6 
    }; */
uint8_t cube [8] = {
        0b00000000, //0
        0b00100000, //1
        0b10000001, //2
        0b10100001, //3
        0b11000011, //4 
        0b11100011, //5
        0b11011011, //6
        0b11111011, //7
    };

GPIO_TypeDef * cube_PORT[] = {
    LED1_PORT,
    LED2_PORT,
    LED3_PORT,
    LED4_PORT,
    LED5_PORT,
    LED6_PORT,
    LED7_PORT,
    LED8_PORT,
};
GPIO_Pin_TypeDef cube_PIN[] = {
    LED1_PIN,
    LED2_PIN,
    LED3_PIN,
    LED4_PIN,
    LED5_PIN,
    LED6_PIN,
    LED7_PIN,
    LED8_PIN,
};

//zautomatizovaná verze
    void cube_write(uint8_t number) {
    for (uint8_t i = 0; i < 8; i++) {
        if (cube[number] & 1 << i) {
            GPIO_WriteHigh(cube_PORT[i], cube_PIN[i]);
        } else {
            GPIO_WriteLow(cube_PORT[i], cube_PIN[i]);
        }
    }
}


//Verze s několika IFy
    /*void cube_write_loser(uint8_t number) {
        if (number > 7)
            return;

        if (cube[number] & 1<< 0) {
            HIGH(LED1);
        } else {
            LOW(LED1);
        }

        if (cube[number] & 1<< 1) {
            HIGH(LED2);
        } else {
            LOW(LED2);
        }

        /// LED3 je mimo

        if (cube[number] & 1<< 3) {
            HIGH(LED4);
        } else {
            LOW(LED4);
        }

        if (cube[number] & 1<< 4) {
            HIGH(LED5);
        } else {
            LOW(LED5);
        }

        if (cube[number] & 1<< 5) {
            HIGH(LED6);
        } else {
            LOW(LED6);
        }

        if (cube[number] & 1<< 6) {
            HIGH(LED7);
        } else {
            LOW(LED7);
        }

        if (cube[number] & 1<< 7) {
            HIGH(LED8);
        } else {
            LOW(LED8);
        }
    }*/

int main(void) {

    init();
    int i = 0;

    while (1) {
        if (milis() - time > 444) {
            //if (PUSH(S1)) {      (na tlačítko)
                time = milis();
                //i++;   (na tlačítko)
                cube_write(i++);  //samo se mění
                if (i > 6)
                    i = 1; 
            }
            //else {
                //GPIO_Write(GPIOG, cube[i]);     (na tlačítko)
            }
        }
    //}
//}
/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
