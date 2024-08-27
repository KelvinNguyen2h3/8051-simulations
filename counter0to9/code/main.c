#include <REGX52.H>
#include "..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main(){
	unsigned char i;
	while(1){
		for(i=0;i<10;i++){
			P2 = Code7Seg[i];
			delay_ms(1000);
		}
	}
}