#include <REGX52.H>
#include "..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

#define ledPort P2
sbit ledH1 = P3^0; //led display hour ten-unit
sbit ledH2 = P3^1; //led display hour unit
sbit ledM1 = P3^2; //led display minute ten-unit
sbit ledM2 = P3^3; //led display minute unit
sbit ledS1 = P3^4; //led display second ten-unit
sbit ledS2 = P3^5; //led display second unit

void main(){
	unsigned char hour, min, sec;
	unsigned char tenUnit, unit;
	unsigned int i;
	hour = min = sec = 0;
	while(1){
		for(i=0;i<166;i++){ //6x166 same 1000ms = 1s
			//display hour
			tenUnit = hour/10;
			unit = hour%10;
			ledPort = Code7Seg[tenUnit];
			ledH1 = 0;
			delay_ms(1);
			ledH1 = 1;
			ledPort = Code7Seg[unit];
			ledH2 = 0;
			delay_ms(1);
			ledH2 = 1;
			//display min
			tenUnit = min/10;
			unit = min%10;
			ledPort = Code7Seg[tenUnit];
			ledM1 = 0;
			delay_ms(1);
			ledM1 = 1;
			ledPort = Code7Seg[unit];
			ledM2 = 0;
			delay_ms(1);
			ledM2 = 1;
			//display sec
			tenUnit = sec/10;
			unit = sec%10;
			ledPort = Code7Seg[tenUnit];
			ledS1 = 0;
			delay_ms(1);
			ledS1 = 1;
			ledPort = Code7Seg[unit];
			ledS2 = 0;
			delay_ms(1);
			ledS2 = 1;
		}
		//logic process count clock
		sec++;
		if(sec==60){
			sec=0;
			min++;
			if(min==60){
				min=0;
				hour++;
				if(hour==24){
					hour=0;
				}
			}
		}
	}
}
