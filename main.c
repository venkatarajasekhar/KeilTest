#include <stdint.h>
#include <string.h>

#include "ADuCM360_Regs.h"
#include "JongSuLib_V2.h"


void menu_display(void);

#define MyName "Jeong"
#define RETURN '\n'
#define Cap2Low(Ch)	(((Ch) >= 'A') && ((Ch) <= 'Z'))? (Ch-'A'+'a'):Ch

int main(){
	uint8_t szTemp[80];					//Used to stort string before printing to UART
	uint8_t d, addr;
	int state;
	
#ifdef	FermiEmulation_Mode
		ADuCM360_GPIORegsInit();
#endif
	
	//Step1. Watchdog Timer Disable
	*pT3CON = 0x0;
	
	//Step2. Clock Setting
	//UART Speed rate will be 115200bps, based on UCLK/DIV = 16Mhz
	//COMDIV = 2, DIVM = 2, DIVN = 348
	*pCLKDIS = 0x03F7;					//UART Clock Enable
	*pCLKSYSDIV = 0x00;			//HFOSC does not  devide(16Mhz)
	*pCLKCON0 = 0x0000;		//UCLK/DIV = 16Mhz
	*pCLKCON1 = 0x0000;		//UCLK/DIV = 16Mhz
	
	//Step3. UART Setting
	*pCOMCON = 0x00;				//UART peripheral Enable
	*pGP0CON = 0x9000;			//P0.7 will be UART TX, P0.6 will be UART RX.
	*pCOMDIV = 0x0002;			//COMDIV = 2;
	
	*pCOMFBR = 0x915C;		//DIVM=2, DIVN = 348, In order to be 115200bps
	*pCOMIEN = 0x0000;		//COMTX_RX interrupt are disabling
	*pCOMLCR = 0x0003;		// WordLength = 8 bits, stop bit = 1, No parity check.
	
	while(1){
		puts("LoveIRIS]");
		state = gets(szTemp);
		d = szTemp[0];
		if(d == 'm'){
			addr = d;
		}
		else if(d == RETURN){
			addr = 'r';
		}
		else if(Cap2Low(d) == 'g'){
			MemoryDump((char *)szTemp);
			addr = 'r';
		}
		else if(Cap2Low(d) == 's'){
			MemorySet((char *)szTemp);
			addr = 'r';
		}
		else {
			addr = hextoint(szTemp);
		}
		
		szTemp[0] = 0;
		switch(addr){
			case 0x1:
				puts("PWM Test\n");
				break;
			case 'm':
				menu_display();
				break;
			default:
				break;
		}
	}
	return 1;
}

void menu_display()
{
	puts("*************************************************************\n");
	puts("**                                                                                                       \n");		
	puts("**   Note :                                                                                           \n");					 
	puts("**   ADuCM360 EVM board Test Program                                           \n");		
	puts("**                                                                                                       \n");		
	puts("** Usage :                                                                                          \n");					 
	puts("** LoveJongSu]set addr val                                                               \n");					 
	puts("** LoveJongSu]get addr                                                                    \n");					 			 
	puts("**                                                                                                       \n");		
	puts("**                       2013, 10, 23  By Lim Jong Su                                    \n");	 
	puts("**                                                                                                       \n");		
	puts("*************************************************************\n");
	puts("*           1.  PWM Test                                                                        *\n");               
	puts("**                                                                                                      *\n");		
	puts("             ขั m.  Main Menu display                                                       \n");
	puts("***********************************************************\n\n");
}
