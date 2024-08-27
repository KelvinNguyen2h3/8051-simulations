#include<REGX52.H>

sbit ledPin0 = P0^0;
sbit ledPin1 = P0^1;
sbit ledPin2 = P0^2;
sbit ledPin3 = P0^3;
sbit ledPin4 = P0^4;
sbit ledPin5 = P0^5;
sbit ledPin6 = P0^6;
sbit ledPin7 = P0^7;

void delay_ms(unsigned int t){
	unsigned int x, y;
	for(x=0;x<t;x++){
		for(y=0;y<123;y++);
	}
}

void main(){
	while(1){
		ledPin0 = 1;
		delay_ms(500);
		ledPin1 = 1;
		delay_ms(500);
		ledPin2 = 1;
		delay_ms(500);
		ledPin3 = 1;
		delay_ms(500);
		ledPin4 = 1;
		delay_ms(500);
		ledPin5 = 1;
		delay_ms(500);
		ledPin6 = 1;
		delay_ms(500);
		ledPin7 = 1;
		delay_ms(500);
		ledPin0 = 0;
		delay_ms(500);
		ledPin1 = 0;
		delay_ms(500);
		ledPin2 = 0;
		delay_ms(500);
		ledPin3 = 0;
		delay_ms(500);
		ledPin4 = 0;
		delay_ms(500);
		ledPin5 = 0;
		delay_ms(500);
		ledPin6 = 0;
		delay_ms(500);
		ledPin7 = 0;
		delay_ms(500);
	}
}