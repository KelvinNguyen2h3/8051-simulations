#include <REGX52.H>
#include "..\lib\delay.h"

#define ledPort P2
sbit btn = P1^0;

void main(){
	unsigned char i;
	ledPort = 0;
	while(1){
		if(btn==0){
			delay_ms(20);
			if(btn==0){
				for(i=0;i<8;i++){
					ledPort = 1<<i;
					delay_ms(1000);
				}
				ledPort = 0;
				while(btn==0);
			}
		}
	}
}