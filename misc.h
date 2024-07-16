/******************************************************************************
 * File: misc.h
 * Author: Sanket Gunjal
 * Date: 28/03/24
 * Description: Contains all the macros, function prototypes, typedefs, etc
 *****************************************************************************/

#ifndef __MISC_H__
#define __MISC_H__


/*		UART Flags Macros		*/	
#define UART0_Tx_FLAG				((U0LSR >> 5) & 1)
#define UART0_Rx_FLAG				(U0LSR & 1)
#define UART_RBR_INT_EN			0x01
#define UART_THRE_INT_EN		0x02
#define UART_RXLS_INT_EN		0x03

/*		ADC Flags		*/
#define ADC_CH_AIN0					0
#define ADC_CH_AIN1					1
#define ADC_CH_AIN2					2
#define ADC_CH_AIN3					3
 
/*		TIMER Function Prototypes		*/ 
void delay_ms(unsigned int);
void delay_sec(unsigned int);

/*		UART Function Prototypes		*/ 
void UART_init(unsigned int);
void UART_tx(unsigned char);
unsigned char UART_rx(void);
void UART_INT_EN(unsigned char);
void UART_string(const unsigned char *str);
void UART_int(int);
void UART_floating(float number);

/*		ADC Function Prototypes		*/ 
void ADC_init(void);
unsigned short int ADC_Read(unsigned char);
float adc_temp(unsigned short int);

/*		SPIO Functon Prototypes		*/
void SPI_init(void);
unsigned char SPI_duplex(unsigned char);

#endif
