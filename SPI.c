/******************************************************************************
 * File: SPI.c
 * Author: Sanket Gunjal
 * Date: 29/03/24
 * Description: SPI Functions Implementation
 *****************************************************************************/

 #include<LPC21xx.h>
 #include "misc.h"
 
 void SPI_init(void){
	 PINSEL0 |= 0x00001500;
	 IODIR0 = (1 << 7);
	 IOSET0 = (1 << 7);
	 
	 S0SPCCR = 15;					// freq of clock is 15MHz
	 S0SPCR = 0x20;
 }
 
 unsigned char SPI_duplex(unsigned char data){
	 S0SPDR = data;
	 while(((S0SPSR >> 7) & 1) == 0);
	 return S0SPDR;
 }
