// ******************************************************************************************* //
//
// File:         exercise5.c
// Date:         09-02-2014
// Authors:      Garrett Vanhoy
// ******************************************************************************************* //

// Include file for PIC24FJ64GA002 microcontroller. This include file defines
// MACROS for special function registers (SFR) and control bits within those
// registers.

#include "p24fj64ga002.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// Make sure "Configuration Bits set in code." option is checked in MPLAB.
// This option can be set by selecting "Configuration Bits..." under the Configure
// menu in MPLAB.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )


// ******************************************************************************************* //
// Configuration bits for CONFIG2 settings.
// Make sure "Configuration Bits set in code." option is checked in MPLAB.
// This option can be set by selecting "Configuration Bits..." under the Configure
// menu in MPLAB.

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

// ******************************************************************************************* //
#define LARGE_NUMBER 1000000

int main(void)
{
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB15 = 0;
    PORTBbits.RB15 = 1;
    CNPU1bits.CN6PUE = 1;
    CNEN1bits.CN6IE = 1;
    AD1PCFGbits.PCFG4 = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;

    while(1){
    }
	return 0;
}

void __attribute__((interrupt)) _CNInterrupt(void){
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB2 == 1){
        PORTBbits.RB15 = 1;
    }
    else{
        PORTBbits.RB15 = 0;
    }
}