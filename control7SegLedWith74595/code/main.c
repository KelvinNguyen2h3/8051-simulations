#include <REGX52.H>
#include "..\lib\delay.h"
#include "..\lib\74595.h"
#include "port.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main(){
	unsigned char i;
	unsigned char buffer[2];
	while(1){
		for(i=0;i<100;i++){
			buffer[0] = Code7Seg[i/10];
			buffer[1] = Code7Seg[i%10];
		
			ic74595Out(buffer,2);
			delay_ms(1000);
		}
	}
}