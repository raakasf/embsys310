#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#define SYS_CLOCK_HZ 4000000u // Default clock after startup
			      // Section 3.11 in STM32L475 datasheet DS10969

uint32_t delayInMillisecs = 0;

void SysTick_Initialize(void);

void main(void)
{
#if 1
	SysTick_Initialize();
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER &= GPIO_MODER_MODE14_0;
	/*
	For me uncommenting the code for LED1 was making the board get stuck.
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= GPIO_MODER_MODE5_0;
	*/

	while (1)
	{
		GPIOB->ODR ^= GPIO_ODR_OD14;
		/*
		GPIOA->ODR ^= GPIO_ODR_OD5;
		*/
		delayInMillisecs = 1000u;
		delay(delayInMillisecs);
	}
#endif
}

void SysTick_Initialize(void)
{
	SysTick->LOAD = SYS_CLOCK_HZ / 1000 - 1; // 0xE000E014 - Counts down to 0.
	SysTick->VAL = 0x0;			 // 0xE000E018 - Clears initial value
	SysTick->CTRL = 0x7;			 // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
	delayInMillisecs--;
}
