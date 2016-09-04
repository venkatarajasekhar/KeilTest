#include <stdint.h>

#if FermiEmulation_Mode

#include "ADuCM360_Regs.h"


// Watchdog Timer Memory Mapped Registers(MMRs) : Base Address : 0x4000_2580
uint16_t T3LD	=0x1000,	*pT3LD;			
uint16_t T3VAL	=0x1000,	*pT3VAL;		
uint16_t T3CON	=0x00E9,	*pT3CON;		
uint16_t T3CLRI	=0x0000,	*pT3CLRI;		// Reset Value is not available!
uint16_t T3STA	=0x0000,	*pT3STA;		

// Clocking Memory Mapped Registers(MMRs) : Base Address : 0x4000_2000
uint16_t CLKCON0	=0x0004,	*pCLKCON0;		
uint16_t CLKCON1	=0x0000,	*pCLKCON1;  	
uint16_t CLKDIS		=0x01FF,	*pCLKDIS;		
uint16_t XOSCCON	=0x0000,	*pXOSCCON;		
uint16_t CLKSYSDIV	=0x0001,	*pCLKSYSDIV;

// GPIO Memory Mapped Registers(MMRs) : Base Address : 0x4000_6000
uint16_t GP0CON	=0x0000,*pGP0CON;	
uint8_t GP0OEN	=0x00,	*pGP0OEN;	
uint8_t GP0PUL	=0xFF,	*pGP0PUL;	
uint8_t GP0OCE	=0x00,	*pGP0OCE;	
uint8_t GP0IN	=0x00,	*pGP0IN;			// Reset Value is not available!
uint8_t GP0OUT	=0x00,	*pGP0OUT;	
uint8_t GP0SET	=0x00,	*pGP0SET;	
uint8_t GP0CLR	=0x00,	*pGP0CLR;	
uint8_t GP0TGL	=0x00,	*pGP0TGL;	

uint16_t GP1CON	=0x0000,*pGP1CON;	
uint8_t GP1OEN	=0x00,	*pGP1OEN;		
uint8_t GP1PUL	=0xFF,	*pGP1PUL;		
uint8_t GP1OCE	=0x00,	*pGP1OCE;		
uint8_t GP1IN	=0x00,	*pGP1IN;			// Reset Value is not available!	
uint8_t GP1OUT	=0x00,	*pGP1OUT;		
uint8_t GP1SET	=0x00,	*pGP1SET;		
uint8_t GP1CLR	=0x00,	*pGP1CLR;		
uint8_t GP1TGL	=0x00,	*pGP1TGL;		

uint16_t GP2CON	=0x0000,*pGP2CON;	
uint8_t GP2OEN	=0x00,	*pGP2OEN;		
uint8_t GP2PUL	=0xFF,	*pGP2PUL;		
uint8_t GP2OCE	=0x00,	*pGP2OCE;		
uint8_t GP2IN	=0x00,	*pGP2IN;			// Reset Value is not available!	
uint8_t GP2OUT	=0x00,	*pGP2OUT;		
uint8_t GP2SET	=0x00,	*pGP2SET;		
uint8_t GP2CLR	=0x00,	*pGP2CLR;		
uint8_t GP2TGL	=0x00,	*pGP2TGL;			

// UART Memory Mapped Registers(MMRs) : Base Address : 0x4000_5000
uint8_t COMTX_RX=0x0000, *pCOMTX_RX;	
uint8_t COMIEN=0x0000, *pCOMIEN;    
uint8_t COMIIR=0x0000, *pCOMIIR;    
uint8_t COMLCR=0x0000, *pCOMLCR;    
uint8_t COMMCR=0x0000, *pCOMMCR;    
uint8_t COMLSR=0x0000, *pCOMLSR;    
uint8_t COMMSR=0x0000, *pCOMMSR;    
uint16_t COMFBR=0x0000, *pCOMFBR;   
uint16_t COMDIV=0x0000, *pCOMDIV;   
uint8_t  COMCON=0x0000, *pCOMCON;   

void ADuCM360_GPIORegsInit(void)
{
	// Watchdog Timer Memory Mapped Registers(MMRs) : Base Address : 0x4000_2580
	pT3LD	=&T3LD;			
	pT3VAL	=&T3VAL;		
	pT3CON	=&T3CON;		
	pT3CLRI	=&T3CLRI;	
	pT3STA	=&T3STA;		

	// Clocking Memory Mapped Registers(MMRs) : Base Address : 0x4000_2000
	pCLKCON0	=&CLKCON0;	
	pCLKCON1	=&CLKCON1; 
	pCLKDIS		=&CLKDIS;	
	pXOSCCON	=&XOSCCON;	
	pCLKSYSDIV	=&CLKSYSDIV;

	// GPIO Memory Mapped Registers(MMRs) : Base Address : 0x4000_6000
	pGP0CON =&GP0CON;	
	pGP0OEN =&GP0OEN;		
	pGP0PUL =&GP0PUL;		
	pGP0OCE =&GP0OCE;		
	pGP0IN  =&GP0IN;		
	pGP0OUT =&GP0OUT;		
	pGP0SET =&GP0SET;		
	pGP0CLR =&GP0CLR;		
	pGP0TGL =&GP0TGL;		

	pGP1CON=&GP1CON;	
	pGP1OEN=&GP1OEN;		
	pGP1PUL=&GP1PUL;		
	pGP1OCE=&GP1OCE;		
	pGP1IN =&GP1IN;		
	pGP1OUT=&GP1OUT;		
	pGP1SET=&GP1SET;		
	pGP1CLR=&GP1CLR;		
	pGP1TGL=&GP1TGL;		

	pGP2CON=&GP2CON;	
	pGP2OEN=&GP2OEN;		
	pGP2PUL=&GP2PUL;		
	pGP2OCE=&GP2OCE;		
	pGP2IN =&GP2IN;		
	pGP2OUT=&GP2OUT;		
	pGP2SET=&GP2SET;		
	pGP2CLR=&GP2CLR;		
	pGP2TGL=&GP2TGL;		
	
	// UART Memory Mapped Registers(MMRs) : Base Address : 0x4000_5000
  pCOMTX_RX=&COMTX_RX;
  pCOMIEN  =&COMIEN; 
  pCOMIIR  =&COMIIR; 
  pCOMLCR  =&COMLCR; 
  pCOMMCR  =&COMMCR; 
  pCOMLSR  =&COMLSR; 
  pCOMMSR  =&COMMSR; 
  pCOMFBR  =&COMFBR;
  pCOMDIV  =&COMDIV;
  pCOMCON  =&COMCON;
}
#else

// Watchdog Timer Memory Mapped Registers(MMRs) : Base Address : 0x4000_2580
volatile uint16_t *pT3LD	=(volatile uint16_t *)0x40002580;			
volatile uint16_t *pT3VAL	=(volatile uint16_t *)0x40002584;		
volatile uint16_t *pT3CON	=(volatile uint16_t *)0x40002588;		
volatile uint16_t *pT3CLRI=(volatile uint16_t *)0x4000258C;	
volatile uint16_t *pT3STA	=(volatile uint16_t *)0x40002598;		

// Clocking Memory Mapped Registers(MMRs) : Base Address : 0x4000_2000
volatile uint16_t *pCLKCON0	=(volatile uint16_t *)0x40002000;	
volatile uint16_t *pCLKCON1	=(volatile uint16_t *)0x40002004; 
volatile uint16_t *pCLKDIS	=(volatile uint16_t *)0x4000202C;	
volatile uint16_t *pXOSCCON	=(volatile uint16_t *)0x40002410;	
volatile uint16_t *pCLKSYSDIV=(volatile uint16_t *)0x40002444;

// GPIO Memory Mapped Registers(MMRs) : Base Address : 0x4000_6000
volatile uint16_t *pGP0CON=(volatile uint16_t *)0x40006000;	
volatile uint8_t *pGP0OEN	=(volatile uint8_t *)0x40006004;		
volatile uint8_t *pGP0PUL	=(volatile uint8_t *)0x40006008;		
volatile uint8_t *pGP0OCE	=(volatile uint8_t *)0x4000600C;		
volatile uint8_t *pGP0IN	=(volatile uint8_t *)0x40006014;		
volatile uint8_t *pGP0OUT	=(volatile uint8_t *)0x40006018;		
volatile uint8_t *pGP0SET	=(volatile uint8_t *)0x4000601C;		
volatile uint8_t *pGP0CLR	=(volatile uint8_t *)0x40006020;		
volatile uint8_t *pGP0TGL	=(volatile uint8_t *)0x40006024;		

volatile uint16_t *pGP1CON=(volatile uint16_t *)0x40006030;	
volatile uint8_t *pGP1OEN	=(volatile uint8_t *)0x40006034;		
volatile uint8_t *pGP1PUL	=(volatile uint8_t *)0x40006038;		
volatile uint8_t *pGP1OCE	=(volatile uint8_t *)0x4000603C;		
volatile uint8_t *pGP1IN	=(volatile uint8_t *)0x40006044;		
volatile uint8_t *pGP1OUT	=(volatile uint8_t *)0x40006048;		
volatile uint8_t *pGP1SET	=(volatile uint8_t *)0x4000604C;		
volatile uint8_t *pGP1CLR	=(volatile uint8_t *)0x40006050;		
volatile uint8_t *pGP1TGL	=(volatile uint8_t *)0x40006054;		

volatile uint16_t *pGP2CON=(volatile uint16_t *)0x40006060;	
volatile uint8_t *pGP2OEN	=(volatile uint8_t *)0x40006064;		
volatile uint8_t *pGP2PUL	=(volatile uint8_t *)0x40006068;		
volatile uint8_t *pGP2OCE	=(volatile uint8_t *)0x4000606C;		
volatile uint8_t *pGP2IN	=(volatile uint8_t *)0x40006074;		
volatile uint8_t *pGP2OUT	=(volatile uint8_t *)0x40006078;		
volatile uint8_t *pGP2SET	=(volatile uint8_t *)0x4000607C;		
volatile uint8_t *pGP2CLR	=(volatile uint8_t *)0x40006080;		
volatile uint8_t *pGP2TGL	=(volatile uint8_t *)0x40006084;		


volatile uint8_t *pCOMTX_RX =(volatile uint8_t *)0x40005000; 
volatile uint8_t *pCOMIEN =(volatile uint8_t *)0x40005004;
volatile uint8_t *pCOMIIR =(volatile uint8_t *)0x40005008;
volatile uint8_t *pCOMLCR =(volatile uint8_t *)0x4000500C;
volatile uint8_t *pCOMMCR =(volatile uint8_t *)0x40005010;
volatile uint8_t *pCOMLSR =(volatile uint8_t *)0x40005014;
volatile uint8_t *pCOMMSR =(volatile uint8_t *)0x40005018;
volatile uint16_t *pCOMFBR =(volatile uint16_t *)0x40005024; 
volatile uint16_t *pCOMDIV =(volatile uint16_t *)0x40005028; 
volatile uint8_t *pCOMCON =(volatile uint8_t *)0x40005030; 

#endif
