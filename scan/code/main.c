#include <REGX52.H>
#include "..\lib\delay.h"

#define led P2
sbit start = P1^0;
sbit stop = P1^1;

unsigned char delay1sAndScan(){
	unsigned char i;
	for(i=0;i<100;i++){
		delay_ms(10);
		if(stop==0){
			led = 0x00;
			return 1;
		}
	}
	return 0;
}

void main(){
	led = 0x00;
	while(1){
		if(start==0){
			while(1){
				led = ~led;
				if(delay1sAndScan()){
					break;
				}
			}
		}
	}
}