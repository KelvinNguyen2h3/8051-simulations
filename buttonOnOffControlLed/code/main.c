#include <REGX52.H>
#include "..\lib\delay.h"

sbit btn = P1^0;
sbit led = P2^0;

void main(){
	led = 0;
	while(1){
		if(btn==0){
			delay_ms(20); //bounce
			if(btn==0){
				led = !led;
				while(btn==0); //hold
			}
		}
		
	}
}