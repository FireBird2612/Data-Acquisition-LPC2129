/******************************************************************************
 * File: timer.c
 * Author: Sanket Gunjal
 * Date: 28/03/24
 * Description: Timer functions implementations.
 *****************************************************************************/

 #include<LPC21xx.h>
 
 void delay_ms(unsigned int ms){
	 char check_clk[] = {15, 60, 30};
	 unsigned int clk = check_clk[VPBDIV] * 1000;
	 
	 T0TC = 0;
	 T0PC = 0;
	 T0PR = clk - 1;
	 
	 T0TCR = 1;
	 while(T0TC < ms);
	 T0TCR = 0;
 }
 
 void delay_sec(unsigned int sec){
	 char check_clk[] = {15, 60, 30};
	 unsigned int clk = check_clk[VPBDIV] * 1000000;
	 
	 T0TC = 0;
	 T0PC = 0;
	 T0PR = clk - 1;
	 
	 T0TCR = 1;
	 while(T0TC < sec);
	 T0TCR = 0;
}
