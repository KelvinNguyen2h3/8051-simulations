#include <REGX52.H>
#include "..\lib\delay.h"

sbit btn = P1^0;
sbit rl = P2^0;

void main(){
	rl = 0;
	while(1){
		if(btn==0){
			delay_ms(20);
			if(btn==0){
				rl = !rl;
				while(btn==0);
			}
		}
	}
}