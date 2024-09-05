#include "main.h"

void Delay_Timer(uint32_t time) {
	for (; time > 0; time--){
	}
}

int main(void) { // 앞에 있는 0은 생략 가능
	RCC->APB2ENR |= 0x01 << 2;     // == 0x4 PortA를 버스 탑승
	GPIOA->CRL &=  ~(0x1 << 22);   // == 0x400000
	GPIOA->CRL |=   0x1 << 20;     // == 0x100000 PA5 출력 선택, 10MHz 선택

	while(1){
		GPIOA->BSRR |= 0x1 << 5;    // == 0x20 led on
		Delay_Timer(100000);
		GPIOA->BSRR |= 0x1 << 21; // == 0x200000 led off
		Delay_Timer(100000);
	}
}
