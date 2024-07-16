/******************************************************************************
 * File: main.c
 * Author: Sanket Gunjal
 * Date: 28/03/24
 * Description: [Brief description of what the code does]

 * This file is part of the Data Acquisition System project.

 * Vector ID: V23BE4S13
 *****************************************************************************/
#include "misc.h"
#include "MCP3204.h"

unsigned short int adc_val, pot_val, ldr_val;
float amb_temp, conv_ldr, pot_conv;

const unsigned char amb_temp_msg[] = "Ambient Temperature: ", pot_msg[] = "Potentionmeter Value: ";
const unsigned char LDR_msg[] = "LDR value: ";


int main(){
	UART_init(9600);
	ADC_init();
	SPI_init();
	
	while(1){
		UART_string("Data Acquisition System\r\n");

		/***********************************
							Temperature 
		************************************/
		UART_string(amb_temp_msg);
		adc_val = ADC_Read(ADC_CH_AIN1);
		amb_temp = adc_temp(adc_val);
		UART_floating(amb_temp);
		UART_string("'C\r\n");
		/***********************************
							Potentiometer
		************************************/
		UART_string(pot_msg);
		pot_val = ADC_Read(ADC_CH_AIN2);
		pot_conv = (pot_val * 3.3) / 1023;
		UART_floating(pot_conv);
		UART_string("\r\n");
		/***********************************
							MCP3204 External ADC 
											LDR
		***********************************/
		UART_string(LDR_msg);
		ldr_val = MCP3204_read(2);
		conv_ldr = 100 - ((ldr_val * 100.0) / 4095);
		UART_floating(conv_ldr);
		UART_string("\r\n");
		
		UART_string("\r\n");
		delay_ms(1000);
	}
}
