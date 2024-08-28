#include <REGX52.H>
#include "..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

#define ledPort P2
sbit led1 = P3^0;
sbit led2 = P3^1;

sbit col1 = P1^0;
sbit col2 = P1^1;
sbit col3 = P1^2;
sbit col4 = P1^3;

sbit row1 = P1^4;
sbit row2 = P1^5;
sbit row3 = P1^6;
sbit row4 = P1^7;

unsigned char keyPress(){
	unsigned char key = 0;
	
	col1 = 0;
	if(row1==0) key = 1;
	if(row2==0) key = 2;
	if(row3==0) key = 3;
	if(row4==0) key = 4;
	col1 = 1;
	
	col2 = 0;
	if(row1==0) key = 5;
	if(row2==0) key = 6;
	if(row3==0) key = 7;
	if(row4==0) key = 8;
	col2 = 1;
	
	col3 = 0;
	if(row1==0) key = 9;
	if(row2==0) key = 10;
	if(row3==0) key = 11;
	if(row4==0) key = 12;
	col3 = 1;
	
	col4 = 0;
	if(row1==0) key = 13;
	if(row2==0) key = 14;
	if(row3==0) key = 15;
	if(row4==0) key = 16;
	col4 = 1;
	
	return key;
}

void main(){
	unsigned char key, tmp;
	while(1){
		key = keyPress();
		if(key!=0){
			tmp = key;
		}
		
		ledPort = Code7Seg[tmp/10];
		led1 = 0;
		delay_ms(1);
		led1 = 1;
		
		ledPort = Code7Seg[tmp%10];
		led2 = 0;
		delay_ms(1);
		led2 = 1;
	}
}