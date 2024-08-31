#include <REGX52.H>
#include "..\lib\delay.h"
#include "..\lib\74595.h"

void main(){
	unsigned char buffer[3], i;
	while(1){
		for(i=0;i<3;i++){
			buffer[i] = 0;
		}
		ic74595Out(buffer,3);
		delay_ms(500);
		for(i=0;i<3;i++){
			buffer[i] = 0xFF;
		}
		ic74595Out(buffer,3);
		delay_ms(500);
	}
}