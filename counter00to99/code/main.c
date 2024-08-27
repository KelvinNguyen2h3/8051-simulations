#include <REGX52.H>
#include "..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

sbit led1 = P3^0;
sbit led2 = P3^1;
#define ledPort P2

void main(){
	unsigned char count;
	unsigned char tenUnit, unit;
	unsigned int i;
	while(1){
		for(count=0;count<100;count++){
			tenUnit = count/10;
			unit = count%10;
			for(i=0;i<250;i++){ //250x2ms=500ms=0.5s per times count
				//tenUnit
				ledPort = Code7Seg[tenUnit];
				led1 = 0;
				delay_ms(1); //1ms
				led1 = 1;
				//Unit
				ledPort = Code7Seg[unit];
				led2 = 0;
				delay_ms(1); //1ms
				led2 = 1;
				//total 2ms
			}
		}
	}
}