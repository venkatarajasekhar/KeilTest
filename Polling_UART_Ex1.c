//#include <stdio.h>
//#include <stdint.h>
//#include <string.h>

//#include "ADuCM360_Regs.h"

//#define MyName "Jeong"

//int main(){
//	uint32_t i=0, j=0;
//	uint8_t reg_data = 0;
//	
//	//use to store string before printing to UART
//	unsigned char szTemp[] = "Hello UART World!";
//	
//	#ifdef FermiEmulation_Mode
//			ADuCM360_GPIORegsInt();
//	#endif
//	
//	//step 1. We should first disable watchdog timer.
//	*pT3CON = 0x0;
//	
//	//step 2. We should set up clock domain according to your plan.
//	//UART Speed rate will be 11520[bps] based on UCLK/DIV = 16[Mhz]
//	//COMDIV = 2, DIVM = 2, DIVN =348
//	*pCLKDIS = 0x03F7;			//UART System Clock enabling, It means UARTCLK is enabling.
//	*pCLKSYSDIV = 0x00;		//HFOSC isn't divided by 1/2. That means UCLK is 16Mhz
//	*pCLKCON0 = 0x0000;  //UCLK/DIV = 16Mhz, That means UARTCLK is 16Mhz
//	*pCLKCON1 = 0x0000;  //UCLK/DIV = 16Mhz, That means UARTCLK is 16Mhz
//	
//	//step 3. We can set up the behavior of UART you choose.
//	*pCOMCON = 0x00;			//UART peripheral is enabling.
//	*pGP0CON = 0x9000;		//P0.7 will be UART TX, P0.6 will be UART RX.
//  //*pGP0CON = 0x003C;		//P0.2 will be UART TX, P0.1 will be UART RX
//	*pCOMDIV = 0x0002;			//COMDIV = 2;
//	
//	*pCOMFBR = 0x915C;		//DIVM=2, DIVN = 348, In order to be 115200bps
//	*pCOMLCR = 0x0003;		// WordLength = 8 bits, stop bit = 1, No parity check.
//	
//	*pGP0OEN = 0x10;
//	
//	j = strlen((char *)szTemp)+1;		//문자열 길이를 가져온다.
//	for(i = 0; i<j; i++){
//		reg_data = *pCOMLSR;
//		reg_data = ((reg_data)&(0x1<<5))>>(5);		//THRE:COMTX가 비어있는 경우 interrupt가 발생한 것을 의미.
//		while(reg_data != 0x01){
//			reg_data = *pCOMLSR;
//			reg_data = ((reg_data)&(0x1<<5))>>(5);
//		}
//		*pCOMTX_RX = szTemp[i];
//		#ifdef FermiEmulation_Mode
//			__asm{ DSB}
//		#endif
//	}
//	while(1){							//P0.5에 연결된 LED를 계속 점멸 시킴.
//    *pGP0TGL = 0x10;
//			for(i = 0; i<400000; i++){
//			  __asm{ nop}
//		  }
//	}
//			return 1;
//}