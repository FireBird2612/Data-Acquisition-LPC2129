/******************************************************************************
 * File: UART.c
 * Author: Sanket Gunjal
 * Date: 28/03/24
 * Description: UART Functions Implementation
 *****************************************************************************/
 
 #include<LPC21xx.h>
 #include "misc.h"
 
 void UART_init(unsigned int baudrate){
	 char set_clk[] = {15, 60, 30};
	 unsigned int set_baud = (set_clk[VPBDIV] * 1000000) / (16 * baudrate);
	 
	 PINSEL0 |= (5 << 0);
	 U0LCR = 0x83;
	 U0DLL = (set_baud & 0xFF);
	 U0DLM = (set_baud >> 8) & 0xFF;
	 U0LCR = 0x03;
 }
 
 void UART_tx(unsigned char data){
	 U0THR = data;
	 while(UART0_Tx_FLAG == 0);
 }

 unsigned char UART_rx(void){
	 while(UART0_Rx_FLAG == 0);
	 return U0RBR;
}
 
 void UART_INT_EN(unsigned char interrupt){
	 U0IER = interrupt;
 }
 
 void UART_string(const unsigned char *str){
	 while(*str){
		 UART_tx(*str);
		 str++;
	 } 
 }
 
 void UART_int(int number){
	 unsigned char index;
	 unsigned char conv_arr[10];
	 int mod, counter, temp_index;
	 
	 if(number > 0){
		 index = 0;
		 counter = 0;
	 }
	 else if(number == 0){
		 UART_tx('0');
		 return;
	 }
	 else{
		 index = 1;
		 conv_arr[0] = '-';
		 counter = 1;
		 number = -(number);
	 }
	 
	 while(number){
		 mod = number % 10;
		 mod = mod + 48;
		 conv_arr[index] = mod;
		 index++;
		 number /= 10;
	 }
	 temp_index = index;
	 index--;
	 
	 for( ; counter <= index; counter++, index--){
		 int temp = conv_arr[counter];
		 conv_arr[counter] = conv_arr[index];
		 conv_arr[index] = temp;
	 }
	 conv_arr[temp_index] = '\0';
	 
	 /*
	 for(counter = 0; counter < temp_index; counter++){
		 UART_tx(conv_arr[counter]);
	 }
	 */
	 UART_string(conv_arr);
 }
 
 void UART_floating(float number){
	 unsigned char index;
	 unsigned char conv_arr[10];
	 int decimal, integer;
	 
	 if(number > 0){
		 index = 0;
	 }
	 else{
		 index = 1;
		 conv_arr[0] = '-';
		 number = -(number);
	 }
	 
	 integer = (int)number;
	 decimal = (number - integer) * 100;
	 
	 conv_arr[index++] = (integer / 10) + 48;
	 conv_arr[index++] = (integer % 10) + 48;
	 conv_arr[index++] = '.';
	 conv_arr[index++] = (decimal / 10) + 48;
	 conv_arr[index++] = (decimal % 10) + 48;
	 conv_arr[index] = '\0';
	 
	 UART_string(conv_arr);
 }
