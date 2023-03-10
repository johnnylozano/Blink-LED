#include "stm32f4xx.h"

#define GPIOAEN (1U << 0)
#define PIN5 (1U << 5)
#define LED_PIN PIN5

int main(void)
{
    /* Enable Clock Access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set GPIOA as Output */
    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER &= ~(1U << 11);

    while (1)
    {
        /* Toggle LED */
        GPIOA->ODR ^= LED_PIN;
        for (int i = 0; i < 1000000; i++)
        {
        }
    }

    return 0;
}