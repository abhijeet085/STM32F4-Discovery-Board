#include "stm32f4xx_hal.h"

static void configureLED(void);
static void msDelay(uint32_t msTime);


int main(void)
{
	
	configureLED();
	while(1)
	{
		GPIOD->ODR ^= (0x0FUL << 12);
		msDelay(1000);
	}
}

void configureLED(void)
{
	RCC->AHB1ENR |= (1 << 3);
	
	GPIOD->MODER &= ~((unsigned int)0xFF000000);
	GPIOD->MODER |= ((unsigned int)0x55000000);
	return;
}

void msDelay(uint32_t msTime)
{
	for(uint32_t i=0; i<msTime*4000; i++);
	return;
}
