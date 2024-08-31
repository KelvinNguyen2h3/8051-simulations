#include <REGX52.H>
#include "..\lib\delay.h"

#define lcdData P3
sbit lcdRS = P2^6;
sbit lcdEN = P2^7;

void lcdCmd(unsigned char cmd){
	lcdRS = 0;
	lcdData = cmd;
	lcdEN = 0;
	lcdEN = 1;
	delay_ms(2);
}

void lcdCharCP(char c){
	lcdRS = 1;
	lcdData = c;
	lcdEN = 0;
	lcdEN = 1;
	delay_ms(2);
}

void lcdOutCP(char *str){
	unsigned char i = 0;
	while(str[i]!=0){
		lcdCharCP(str[i]);
		i++;
	}
}

void lcdInit(){
	lcdCmd(0x38);
	delay_ms(5);
	lcdCmd(0x38);
	delay_ms(1);
	lcdCmd(0x38);
	
	lcdCmd(0x38);
	lcdCmd(0x01);
	lcdCmd(0x0C);
}

void lcdChar(unsigned char row, unsigned char col, char c){
	lcdCmd((row==1?0x80:0xC0) + col - 1);
	lcdCharCP(c);
}

void lcdOut(unsigned char row, unsigned char col, char *str){
	lcdCmd((row==1?0x80:0xC0) + col - 1);
	lcdOutCP(str);
}

void main(){
	//lcdCmd(0x0C);
	//lcdOutCP("Hello LCD");
	
	//delay_ms(50);
	//lcdInit();
	//lcdOutCP("Line 1");
	//lcdCmd(0xC0);
	//lcdOutCP("Line 2");
	
	//lcdInit();
	//lcdChar(1,1,'K');
	//lcdChar(2,2,'K');
	//lcdChar(1,3,'K');
	//lcdChar(2,4,'K');
	//lcdChar(1,5,'K');
	//lcdChar(2,6,'K');
	
	lcdInit();
	lcdOut(1,1,"PLEASE LIKE AND SUBCRIBE");
	
	while(1){
		delay_ms(1000);
		lcdCmd(0x18);
		//lcdCmd(0x1C);
	}
}