#include "main.h"

void Delay_Timer(uint32_t time) {
	for (; time > 0; time--){
	}
}

void set_led(uint8_t n){
	switch(n){
	case 1:
		GPIOA->BSRR |= 0x1<<12; // PA12 LED set
		Delay_Timer(100000);
		GPIOA->BSRR |= 0x1<<28; // PA12 LED reset
		Delay_Timer(100000);
		break;
	case 2:
		GPIOA->BSRR |= 0x1<<11; // PA11 LED set
		Delay_Timer(100000);
		GPIOA->BSRR |= 0x1<<27; // PA11 LED reset
		Delay_Timer(100000);
		break;
	case 3:
		GPIOB->BSRR |= 0x1<<12; // PB12 LED set
		Delay_Timer(100000);
		GPIOB->BSRR |= 0x1<<28; // PB12 LED reset
		Delay_Timer(100000);
		break;
	case 4:
		GPIOB->BSRR |= 0x1<<11; // PB11 LED set
		Delay_Timer(100000);
		GPIOB->BSRR |= 0x1<<27; // PB11 LED reset
		Delay_Timer(100000);
		break;
	}
}

int main(void){
	RCC->APB2ENR |= 0x4; // port A
	RCC->APB2ENR |= 0x8; // port B
	GPIOA->CRH &= ~(0x10001<<14); // ~(0x44000)
	GPIOA->CRH |= ~(0x10001<<12); // ~(0x11000)
	GPIOB->CRH &= ~(0x10001<<14); // ~(0x44000)
	GPIOB->CRH |= ~(0x10001<<12); // ~(0x11000)

	while(1) {
		for(uint8_t i=1;i<5;i++){
			set_led(i);
		}
	}
}
