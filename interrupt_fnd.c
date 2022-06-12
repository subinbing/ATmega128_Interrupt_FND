​#define F_CPU 7372800UL

#include <avr/interrupt.h> 

#include <util/delay.h> 

#include <avr/io.h> 

​

volatile int count = 0, flag = 0, plus = 0, n = 0;

unsigned char fnd[10] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f }; //0~9

int led1 = 0x01, led2 = 0x08, led3 = 0x01;

​

ISR(INT0_vect) //0번 스위치를 누르면

{

	_delay_ms(57);

	count = count + 1;

	if (count == 99) count = 0;

	flag = 1;

	_delay_ms(57);

}

ISR(INT1_vect) //1번 스위치를 누르면

{

	_delay_ms(57);

	count = count - 1;

	if (count == 0) count = 99;

	flag = 2;

	_delay_ms(57);

}

ISR(INT2_vect) //2번 스위치를 누르면

{

	_delay_ms(57);

	plus++;

	flag = 3;

	_delay_ms(57);

}

ISR(INT3_vect) //3번 스위치를 누르면

{

	_delay_ms(57);

	n++;

	flag = 4;

	_delay_ms(57);

}

​

void FND() //숫자 출력 함수

{

	PORTD = 0x20; //PD4

	PORTC = ~fnd[(count % 100) / 10]; //10의 자리

	_delay_ms(1);

	PORTD = 0x10; //PD5

	PORTC = ~fnd[(count % 10) / 1]; //1의 자리

	_delay_ms(1);

}

​

int main(void)

{

	DDRD = 0x30; //입력포트로 설정(스위치) - 00110000(하위 비트 입력으로 설정, 상위 비트 PD4,PD5를 출력으로 설정)

	DDRA = 0xff; //포트A 출력 (led)

	DDRC = 0xff; //포트C 출력 (fnd)

	​

		PORTC = 0xff; //FND 00으로 초기값 입력

	​

		EICRA = 0xbb; //INT0 상승엣지, INT1 하강엣지, INT2 상승엣지, INT3 하강엣지

	EIMSK = 0x0f; //INT0~3 사용

	sei(); //전역 인터럽트 허용

	​

		while (1)

		{

			if (flag == 1) //상승엣지

			{

				FND();

			}

			else if (flag == 2) //하강엣지

			{

				FND();

			}

			else if (flag == 3) //상승엣지

			{

				if (plus == 1)

				{

					_delay_ms(54);

					PORTA = ~led1;

					led1 = led1 << 1;

					if (led1 > 0x80) led1 = 0x01;

				}

				else if (plus == 2)

				{

					_delay_ms(54);

					PORTA = ~led2;

					led2 = led2 >> 1;

					if (led2 < 0x01) led2 = 0x80;

				}

				else if (plus > 2)

				{

					plus = 1;

				}

			}

			else if (flag == 4) //하강엣지

			{

				if (n == 1) {

					_delay_ms(200);

					PORTA = ~led3;

					led3 = led3 << 1; //1씩 왼쪽으로 시프트

					if (led3 > 0x80) led3 = 0x01; //8번째까지오면 led를 다시 초기화

				}

				else if (n == 2) {

					_delay_ms(200);

					PORTA = ~led3;

					led3 = led3 << 2; //2씩 왼쪽으로 시프트

					if (led3 > 0x80) //led가 8번째까지 오면

						led3 = led3 >> 0x08; //led를 8비트씩 오른쪽으로 시프트

				}

				else if (n == 3) {

					_delay_ms(100);

					PORTA = ~led3;

					led3 = led3 << 3; //3씩 왼쪽으로 시프트

					if (led3 > 0x80) //led가 8번째까지 오면 

						led3 = led3 >> 0x08; //led를 8비트씩 오른쪽으로 시프트

				}

				else if (n == 4) {

					_delay_ms(100);

					PORTA = ~led3;

					led3 = led3 << 4; //3씩 왼쪽으로 시프트

					if (led3 > 0x80) //led가 8번째까지 오면 

						led3 = led3 >> 0x08; //led를 8비트씩 오른쪽으로 시프트

				}

				else {

					n = 1;

				}

			}

			​

		}

}