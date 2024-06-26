#include <stdbool.h>
#include <stm8s.h>
//#include <stdio.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
#include "max7219.h"

#define DIN_PORT GPIOB
#define DIN_PIN GPIO_PIN_4
#define CS_PORT GPIOB
#define CS_PIN GPIO_PIN_3
#define CLK_PORT GPIOB
#define CLK_PIN GPIO_PIN_2

void init(void) {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz

    GPIO_Init(DIN_PORT, DIN_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(CS_PORT, CS_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW);
    GPIO_Init(CLK_PORT, CLK_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    init_milis();
    // init_uart1();
}

void display(uint8_t address, uint8_t data) {

    uint8_t mask;

    LOW(CS); // Začátek přenosu

    /*odesílání adresy*/
    mask = 128;
    mask = 0b10000000;
    mask = 1 << 7;
    while (mask) {
        if (mask & address) { // nachystám data
            HIGH(DIN);
        } else {
            LOW(DIN);
        }

        HIGH(CLK);
        mask = mask >> 1;
        LOW(CLK);
    }

    /*odesílání dat*/
    mask = 128;
    mask = 0b10000000;
    mask = 1 << 7;
    while (mask) {
        if (mask & data) { // nachystám data
            HIGH(DIN);
        } else {
            LOW(DIN);
        }

        HIGH(CLK);
        mask = mask >> 1;
        LOW(CLK);

       
    }
    
    HIGH(CS); // Konec přenosu
}

int main(void) {

    uint32_t time = 0;
    uint8_t number = 0;

    init();

    display(DECODE_MODE,0b11111111);    // zapíná znakocou sadu na jednotlivých cifrách
    display(SCAN_LIMIT, 7); // chci všech 8 cifer
    display(INTENSITY, 1);  // chci aby to moc nesvítilo
    display(DISPLAY_TEST, DISPLAY_TEST_OFF); // nechce aby tam byl test
    display(SHUTDOWN, SHUTDOWN_ON);          // zapnutí
    display(DIGIT0, 0x0F);
    display(DIGIT1, 0x0F);
    display(DIGIT2, 0x0F);
    display(DIGIT3, 0x0F);
    display(DIGIT4, 0x0F);
    display(DIGIT5, 0x0F);
    display(DIGIT6, 0x0F);
    display(DIGIT7, 0x0F);



    while (1) {
        if (milis() - time > 333) {
            time = milis();
            display(DIGIT0, number++);
        }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"