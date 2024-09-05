#include "main.h"

int main(void){
	RCC->APB2ENR |= 0x14;             // 0x101 << 2; (0x1 << 2) | 0x1 << 4)
	GPIOA->CRL &= ~(0x1<<22);
	GPIOA->CRL |= 0x1<<20;          // PA5 output
	GPIOC->CRH &= ~(0x1<<22);
	GPIOC->CRH |= 0x1<<23;          // PC13 input
	GPIOC->ODR |= 0x1<<13;

	while(1) {
		if(GPIOC->IDR & 0x1<<13){   // 비교시에는 & 사용
			GPIOA->BSRR |= 0x1<<21; // LED reset
		} else {
			GPIOA->BSRR |= 0x1<<5;  // LED set
		}
	}
}
