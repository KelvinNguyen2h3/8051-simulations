#include <REGX52.H>
#include "..\lib\delay.h"

sbit led = P2^0;
sbit btnOn = P1^0;
sbit btnOff = P1^4;

void main(){
	led = 0;
	while(1){
		if(btnOn==0){              
			delay_ms(20);          
			if(btnOn==0){           
				led = 1;      
				while(btnOn==0);    
			}
		}
		if(btnOff==0){               
			delay_ms(20);        
			if(btnOff==0){        
				led = 0;        
				while(btnOff==0);  
			}
		}
	}
}
