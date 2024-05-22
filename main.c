#include "COMUNICATION_PROTOCOLS/SPI/SPI.h"
#include "ecu/LCD/LCD.h"

SPI_Configuration_t confg;
SPI_Configuration_t *ptr = &confg;

LCD_4_BITConfiguration_t confg_4_BIT;
LCD_4_BITConfiguration_t *ptr_4_BIT = &confg_4_BIT;

int main(void)
{
    uint8_t data = 'b';
    confg.interrupt = INT_DIS;
    confg.data_order = LSB;
    confg.trans_speed = normal_speed;
    confg.clk_rate  = normal_speed_freq_16;
    confg.clk_phase = sample;
    confg.clk_polarity = rising;
    confg.mode = master;


    confg_4_BIT.PORT_NUMBER = PORT_A;
    confg_4_BIT.PORT_NUMBER_control = PORT_A;
    confg_4_BIT.PINS[0] = 4;
    confg_4_BIT.PINS[1] = 5;
    confg_4_BIT.PINS[2] = 6;
    confg_4_BIT.PINS[3] = 7;
    confg_4_BIT.en = PIN0;
    confg_4_BIT.rs = PIN1;
    confg_4_BIT.rw = PIN2;

    SPI_INIT(ptr);
    LCD_4_BIT_INIT(ptr_4_BIT);
    LCD_4_BIT_SEND_CHAR(ptr_4_BIT , data);
    SPI_TRANS('*' , &data);
    LCD_4_BIT_SEND_CHAR(ptr_4_BIT , data);
    while (1)
    {




    }

}