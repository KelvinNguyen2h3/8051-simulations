#include <REGX52.H>
#include "..\lib\delay.h"

void main(){
	int i;
	while(1){
		//scan column form right to left
		/*for(i=0;i<8;i++){
			P3 = 1<<i;
			P0 = 0;
			delay_ms(300);
		}*/
		//scan column form left to right
		/*for(i=0;i<8;i++){
			P3 = 0x80>>i; //0x80 = 0b10000000
			P0 = 0;
			delay_ms(300);
		}*/
		//scan row form top to bottom
		/*for(i=0;i<8;i++){
			P3 = 0xFF; //0xFF = 0b11111111
			P0 = ~(0x80>>i);
			delay_ms(300);
		}*/
		//scan row form bottom to top
		/*for(i=0;i<8;i++){
			P3 = 0xFF; //0xFF = 0b11111111
			P0 = ~(1<<i);
			delay_ms(300);
		}*/
		//reverse of scanning row form bottom to top
		/*for(i=0;i<8;i++){
			P3 = 0xFF; //0xFF = 0b11111111
			P0 = 1<<i;
			delay_ms(300);
		}*/
		//same with another reverse
		//scan per led
		int j;
		for(j=0;j<8;j++){
			for(i=0;i<8;i++){
				P3 = 0x80>>i;
				P0 = ~(1<<j);
				delay_ms(300);
			}
		}
	}
}