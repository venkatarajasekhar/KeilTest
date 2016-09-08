//#include <stdint.h>
//#include <string.h>

//#include "ADuCM360_Regs.h"
//#include "JongSuLib.h"

//uint8_t getc(void);
//void putc(uint8_t Ch);
//void puts(const char* str);
//int gets(uint8_t *s);
//void menu_display(void);
//int hextoint(unsigned char *hex);

//#define MyName "Jeong"
//#define RETURN '\n'

//int main(){
//	uint8_t szTemp[80];					//Used to stort string before printing to UART
//	uint8_t d, addr;
//	int state;
//	
//#ifdef	FermiEmulation_Mode
//		ADuCM360_GPIORegsInit();
//#endif
//	
//	//Step1. Watchdog Timer Disable
//	*pT3CON = 0x0;
//	
//	//Step2. Clock Setting
//	//UART Speed rate will be 115200bps, based on UCLK/DIV = 16Mhz
//	//COMDIV = 2, DIVM = 2, DIVN = 348
//	*pCLKDIS = 0x03F7;					//UART Clock Enable
//	*pCLKSYSDIV = 0x00;			//HFOSC does not  devide(16Mhz)
//	*pCLKCON0 = 0x0000;		//UCLK/DIV = 16Mhz
//	*pCLKCON1 = 0x0000;		//UCLK/DIV = 16Mhz
//	
//	//Step3. UART Setting
//	*pCOMCON = 0x00;				//UART peripheral Enable
//	*pGP0CON = 0x9000;			//P0.7 will be UART TX, P0.6 will be UART RX.
//	
//	*pCOMDIV = 0x0002;			//COMDIV = 2;
//	
//	*pCOMFBR = 0x915C;		//DIVM=2, DIVN = 348, In order to be 115200bps
//	*pCOMLCR = 0x0003;		// WordLength = 8 bits, stop bit = 1, No parity check.
//	
//	while(1){
//		puts("LoveIRIS]");
//		state = gets(szTemp);
//		d = szTemp[0];
//		if(d == 'm'){
//			addr = d;
//		}
//		else if(d == RETURN){
//			addr = 'r';
//		}
//		else {
//			addr = hextoint(szTemp);
//		}
//		
//		szTemp[0] = 0;
//		switch(addr){
//			case 0x1:
//				puts("PWM Test\n");
//				break;
//			case 'm':
//				menu_display();
//				break;
//			default:
//				break;
//		}
//	}
//	return 1;
//}

//int hextoint(unsigned char *hex){
//	unsigned char r =0;
//	unsigned char d;
//	while(1){
//		d = *hex++;
//		if(d == 0)
//			break;
//		r <<=4;
//		
//		if((d>= '0') && (d<='9'))
//			r += d - '0';
//		else if((d>='A') && (d<='F'))
//			r += d - 'A'+10;
//		else if((d>='a') && (d<='f'))
//			r += d - 'a'+10;
//		else
//			return -1;
//	}
//	return r;
//}

//int gets(uint8_t *s){
//	int len = 0;
//	while(1){
//		s[len] = getc();
//		if(s[len] == '\n' || s[len] == '\r'){
//			putc('\r');
//			putc('\n');
//			s[len] = '\0';
//			break;
//		}
//		else if(s[len] == 0x7F || s[len] == 0x08){
//			if(len > 0){
//				puts("\b \b");
//				len--;
//			}
//		}
//		else{
//			putc(s[len]);
//			len++;
//		}
//	}
//	return 1;
//}


//uint8_t getc(void){
//	uint8_t reg_data=0, tmp;
//	reg_data = *pCOMLSR;
//	reg_data = ((reg_data)&(0x1<<0)) >>(0);
//	while(reg_data != 0x1){
//		reg_data = *pCOMLSR;
//		reg_data = ((reg_data)&(0x1<<0)) >>(0);
//	}
//	tmp = *pCOMTX_RX;
//#ifdef FermiEmulation_Mode
//		__asm{ DSB}
//#endif
//	return tmp;
//}


//void puts(const char* str){
//	while(*str){
//		putc(*str);
//		++str;
//	}
//}

//void putc(uint8_t Ch){
//	if(Ch == '\n'){
//		while((((read_reg(0x40005014)&(0x1<<5)))>>(5)) != 0x1);
//		*pCOMTX_RX = '\n';
//	}
//	while((((read_reg(0x40005014)&(0x1<<5)))>>(5)) != 0x1);
//	*pCOMTX_RX = Ch;
//	
//#ifdef FermiEmulation_Mode
//		__asm{ DSB}
//#endif
//}

//void menu_display()
//{
//	puts("*************************************************************\n");
//	puts("**                                                           \n");		
//	puts("**   Note :                                                  \n");					 
//	puts("**   ADuCM360 EVM board Test Program                       \n");		
//	puts("**                                                           \n");		
//	puts("** Usage :                                                   \n");					 
//	puts("** LoveJongSu]set addr val                                   \n");					 
//	puts("** LoveJongSu]get addr                                       \n");					 			 
//	puts("**                                                           \n");		
//	puts("**                       2013, 10, 23  By Lim Jong Su        \n");	 
//	puts("**                                                           \n");		
//	puts("*************************************************************\n");
//	puts("*           1.  PWM Test                             *\n");               
//	puts("**                                                          *\n");		
//	puts("             ขั m.  Main Menu display                        \n");
//	puts("***********************************************************\n\n");
//}



