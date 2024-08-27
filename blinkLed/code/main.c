#include <REGX52.H>

sbit LED_PIN = P0^0;

//datatype of t is unsignedint
//16bit from 0 to 65535
//mean max_delay is 65s
void Delay_ms(unsigned int t){
	unsigned int x, y;
	for(x=0;x<t;x++){
		for(y=0;y<123;y++); //delay 1ms
	}
}

void main(){
		while(1){
			LED_PIN = !LED_PIN;
			Delay_ms(500);
		}
}