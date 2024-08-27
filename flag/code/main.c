#include <REGX52.H>
#include "..\lib\delay.h"

sbit btn = P1^0;
#define led P2

bit pressedFlag=0;

unsigned char delay1sAndCheckFlag(){
	unsigned char i;
	for(i=0;i<100;i++){
		delay_ms(10);
		if(btn==0){
			if(pressedFlag==0){
				pressedFlag = 1;
				return 1;
			}
		}
		else {
			pressedFlag = 0;
		}
	}
	return 0;
}

void main(){
	unsigned char i;
	while(1){
		led = 0x00;
		for(i=0;i<20;i++){
			if(delay1sAndCheckFlag()) break;
			led = ~led;
		}
		led = 0x0F;
		for(i=0;i<20;i++){
			if(delay1sAndCheckFlag()) break;
			led = ~led;
		}
		led = 0x55;
		for(i=0;i<20;i++){
			if(delay1sAndCheckFlag()) break;
			led = ~led;
		}
	}
}