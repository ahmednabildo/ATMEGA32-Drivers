/*
 * interrupts.c
 *
 * Created: 31/03/2024 09:16:28
 *  Author: DELL
 */ 
#include "interrupts.h"
#include "../TIMERS/timers.h"
void external_interrupts_enable()
{
    SET_BIT(SREG , 7);
}
void external_interrupt0_enable()
{
    SET_BIT(GICR , 6);
}
void external_interrupt1_enable()
{
    SET_BIT(GICR , 7);
}
void external_interrupt2_enable()
{
    SET_BIT(GICR , 5);
}

void external_interrupts_configuration(external_interruptConfiguration_t *confg)
{
    if (confg->interrupt_channel == INT_0)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR , 0);
            CLEAR_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR , 0);
            CLEAR_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR , 0);
            SET_BIT(MCUCR , 1);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR , 0);
            SET_BIT(MCUCR , 1);
        }

    }
    else if (confg->interrupt_channel == INT_1)
    {
        if (confg->Sense_control == LOW_LEVEL)
        {
            CLEAR_BIT(MCUCR , 2);
            CLEAR_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == ANY_LOGICAL_CHANGE)
        {
            SET_BIT(MCUCR , 2);
            CLEAR_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCR , 2);
            SET_BIT(MCUCR , 3);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCR , 2);
            SET_BIT(MCUCR , 3);
        }
    }
    else if (confg->interrupt_channel == INT_2)
    {
        if (confg->Sense_control == FALLING_EDGE)
        {
            CLEAR_BIT(MCUCSR , 6);
        }
        else if (confg->Sense_control == RISING_EDGE)
        {
            SET_BIT(MCUCSR , 6);
        }
    }
}
void external_interrupts_flag_status(external_interruptConfiguration_t *confg , uint8_t *state)
{
    if (confg->interrupt_channel == INT_0)
    {
        *state = READ_BIT(GIFR , 6);
    }
    else if (confg->interrupt_channel == INT_1)
    {
        *state = READ_BIT(GIFR , 7);
    }
    else if (confg->interrupt_channel == INT_2)
    {
        *state = READ_BIT(GIFR , 5);
    }
}
void external_interrupts_flag_clear(external_interruptConfiguration_t *confg)
{
    if (confg->interrupt_channel == INT_0)
    {
        SET_BIT(GIFR , 6);
    }
    else if (confg->interrupt_channel == INT_1)
    {
        SET_BIT(GIFR , 7);
    }
    else if (confg->interrupt_channel == INT_2)
    {
        SET_BIT(GIFR , 5);
    }

}


ISR(EXT_INT_0)
{
    SET_BIT(DDRA , 0);
    SET_BIT(PORTA , 0);
    delay(1000);
    CLEAR_BIT(PORTA , 0);
}

ISR(EXT_INT_1)
{
    SET_BIT(DDRA , 1);
    SET_BIT(PORTA , 1);
    delay(1000);
    CLEAR_BIT(PORTA , 1);
}

ISR(EXT_INT_2)
{
    SET_BIT(DDRB , 0);
    SET_BIT(PORTB , 0);
    delay(1000);
    CLEAR_BIT(PORTB , 0);
}