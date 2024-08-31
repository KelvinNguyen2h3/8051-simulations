#include "74595.h"
#include "port.h"
#include <REGX52.H>
//need ds, shcp and stcp pins

void ic74595Out(unsigned char *p, unsigned n){
	unsigned char i, b, j;
	for(j=0;j<n;j++){
		b = *(p+n-j-1);
		for(i=0;i<8;i++){
			ic74595DS = b & (0x80>>i);
			ic74595SHCP = 0;
			ic74595SHCP = 1;
		}
	}
	ic74595STCP = 0;
	ic74595STCP = 1;
}