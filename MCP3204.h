/******************************************************************************
 * File: MCP3204.h
 * Author: Sanket Gunjal
 * Date: 30/03/24
 * Description: MCP3204 header file
 *****************************************************************************/
 
 #ifndef __MCP3204_H__
 #define __MCP3204_H__
 
 #define MCP3204_CH0	0x0
 #define MCP3204_CH1	0x1
 #define MCP3204_CH2	0x2
 #define MCP3204_CH3	0x3


 /*			MCP3204 External ADC Function Prototypes		*/
 unsigned short int MCP3204_read(unsigned char);

 
 #endif
