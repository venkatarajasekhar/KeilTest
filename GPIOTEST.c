//#include <stdio.h>
//#include <stdint.h>
//#include "ADuCM360_Regs.h"

//#define MyName	"IRIS"

//int main(){
//	uint32_t  i = 0;
//	
//	#ifdef FermiEmulation_Mode
//		ADuCM360_RegsInit();
//	#endif
//	
//	//step 1. We should first disable watchdog timer.
//	*pT3CON = 0x0;
//	
//	//step 2. We should set up clock domain according to your plan.
//	*pCLKDIS = 0x03FF;			//all clock disable
//	*pCLKCON0 = 0x0043;	//	
//	*pCLKSYSDIV = 0x01;   //클럭 1/2를 수행함 
//	
//	//step 3. We can set up the behaviior of GPIOs you choose.
//	*pGP0CON = 0x0000;
//	*pGP0OEN = 0x10;
//	
//	while(1){
//		*pGP0TGL = 0x10;
//		for(i = 0; i<40000; i++){
//			__asm{ nop}
//		}
//	}
//	
//	return 1;
//}

