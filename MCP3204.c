/******************************************************************************
 * File: MCP3204.c
 * Author: Sanket Gunjal
 * Date: 30/03/24
 * Description: MCP3204 Functions Implementation
 *****************************************************************************/
 
 #include<LPC21xx.h>
 #include "misc.h"
 
 unsigned short int MCP3204_read(unsigned char ch_num){
	 unsigned short int rx_data = 0;
	 unsigned char MSByte, LSByte;
	 
	 ch_num <<= 6;
	 IOCLR0 = (1 << 7);
	 SPI_duplex(0x06);
	 MSByte = SPI_duplex(ch_num);
	 LSByte = SPI_duplex(0x0);
	 IOSET0 = (1 << 7);
	 
	 rx_data = ((MSByte & 0x0F) << 8) | LSByte;
	 return rx_data;
 }
