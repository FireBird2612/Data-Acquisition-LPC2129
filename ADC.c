/******************************************************************************
 * File: ADC.c
 * Author: Sanket Gunjal
 * Date: 28/03/24
 * Description: ADC Functions Implementation
 *****************************************************************************/

 #include<LPC21xx.h>
 #include "misc.h"

 void ADC_init(void){
	 unsigned char sel_freq[] = {15, 60, 30};
	 unsigned int set_freq = sel_freq[VPBDIV];
	 
	 unsigned int div;
	 
	 for(div = 2; (set_freq/div) > 4; div++);
	 ADCR = 0;
	 ADCR |= (div << 8) | (1 << 21); 
 }
 
 unsigned short int ADC_Read(unsigned char ch_num){
	 /*		MCP9700 is connected to P0.28 channel number		*/
	 unsigned short int conversion;
	 
	 if(ch_num == ADC_CH_AIN0){
		 PINSEL1 |= (1 << 22);
	 }
	 else if(ch_num == ADC_CH_AIN1){
		 PINSEL1 |= (1 << 24);
	 }
	 else if(ch_num == ADC_CH_AIN2){
		 PINSEL1 |= (1 << 26);
	 }
	 else{
		 PINSEL1 |= (1 << 28);
	 }
	 
	 ADCR |= (1 << ch_num);
	 ADCR |= (1 << 24);
	 
	 while(((ADDR >> 31) & 1) == 0);
	 
	 ADCR &= ~(1 << 24);
	 ADCR &= ~(1 << ch_num);
	 conversion = (ADDR >> 6) & 0x3FF;
	 
	 return conversion;
 }
 
 float adc_temp(unsigned short int raw_adc_val){
	 float vol, temp;
	 
	 vol = ((float)raw_adc_val * 3.3) / 1023; 
	 temp = (vol - 0.5) / 0.01;
	 return temp;
 }
