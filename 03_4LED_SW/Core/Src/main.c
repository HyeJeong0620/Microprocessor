#include "main.h"

void Delay_Timer(uint32_t time) {
	for (; time > 0; time--) {
	}
}

void set_led(uint8_t n) {
	switch (n) {
	case 1:
		GPIOA->BSRR |= 0x1 << 12; // PA12 LED set
		break;
	case 2:
		GPIOA->BSRR |= 0x1 << 11; // PA11 LED set
		break;
	case 3:
		GPIOB->BSRR |= 0x1 << 12; // PB12 LED set
		break;
	case 4:
		GPIOB->BSRR |= 0x1 << 11; // PB11 LED set
		break;
	}
}

void reset_led() {
	GPIOA->BSRR |= (0x1 << 27) | (0x1 << 28); //PA11, PA12 LED reset
	GPIOB->BSRR |= (0x1 << 27) | (0x1 << 28); //PB11, PB12 LED reset
}

int main(void) {
	RCC->APB2ENR |= 0x1C;   // port A, B, C
	GPIOA->CRH &= ~0x44000; // ~0x10001<<14
	GPIOA->CRH |= 0x11000;  // 0x10001<<12   // PORT A11, A12 output
	GPIOB->CRH &= ~0x44000; // 0x10001<<14
	GPIOB->CRH |= 0x11000;  // 0x10001<<12   // PORT B11, B12 output
	GPIOC->CRH &= ~0x4;     // 0x<<2
	GPIOC->CRH |= ~0x8;     // 0x1<<3        // PORT C8 input
	GPIOC->ODR |= 0x1 << 8;                  // 입력일 때 추가 설정
	uint8_t i = 1;

	while (1) {
		if (GPIOC->IDR & 0x1 << 8) {
			reset_led();
		} else {
			set_led(i);
			Delay_Timer(250000);
			reset_led();
			Delay_Timer(250000);
			i++;
			if (i == 5) {
				i = 1;
			}
		}
	}
}
