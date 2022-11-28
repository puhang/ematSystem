#include "display.h"

#include "emat_Struct.h"
#include "key_Logic.h"
#include <stdio.h>
#include <stdlib.h>

int InterfaceRefresh_Dynamic_Config_Menu(ematController *myEmat){
	double freq,phase,freqScaleFactor,phaseScaleFactor;
	unsigned int periods,periodsScaleFactor;
	unsigned int freqPrecision = myEmat->privatePara->freqPrecision;
	unsigned int phasePrecision = myEmat->privatePara->phasePrecision;
	unsigned int periodsPrecision = myEmat->privatePara->periodsPrecision;
	freq = 1.0*myEmat->publicPara->freq/freqPrecision;
	phase = 1.0*myEmat->publicPara->phase/myEmat->privatePara->phasePrecision;
	periods = (unsigned int)myEmat->publicPara->periods/periodsPrecision;
    freqScaleFactor = 1.0*myEmat->publicPara->freqScaleFactor/freqPrecision;
    phaseScaleFactor = 1.0*myEmat->publicPara->phaseScaleFactor/phasePrecision;
    periodsScaleFactor = (unsigned int)myEmat->publicPara->periodsScaleFactor/periodsPrecision;
	system("clear");
	printf("*****************************************************************************************\n");
	printf("**                                   KEY OPTIONS                                      \n");
	printf("** PUBLIC PARAMETERS CONFIGURATION:                                                    \n");
	printf("** current frequency = %.3f MHz: Increase %.3f MHz (key:%c) Decrease %.3f MHz (key:%c) \n",freq,freqScaleFactor,FREQ_INC,freqScaleFactor,FREQ_DEC);
	printf("** current phase = %.3f : Increase %.3f (key:%c)  - -  Decrease %.3f (key:%c)          \n",phase,phaseScaleFactor,PHASE_INC,phaseScaleFactor,PHASE_DEC);
	printf("** current periods = %d : Increase %d (key:%c) - -  Decrease %d (key:%c)               \n",periods,periodsScaleFactor,PERIODS_INC,periodsScaleFactor,PERIODS_DEC);
	printf("**                            			                                               \n");
	printf("** BACK TO MAIN MENU (key:%c)                                             			   \n",QUIT);
	printf("**                            			                                               \n");
	printf("*****************************************************************************************\n");
	printf("option: \n");
}

int InterfaceRefresh_Main_Menu(ematController *myEmat){

	double freq,phase,freqScaleFactor,phaseScaleFactor;
	unsigned int periods,periodsScaleFactor;
	unsigned int freqPrecision = myEmat->privatePara->freqPrecision;
	unsigned int phasePrecision = myEmat->privatePara->phasePrecision;
	unsigned int periodsPrecision = myEmat->privatePara->periodsPrecision;
	freq = 1.0*myEmat->publicPara->freq/freqPrecision;
	phase = 1.0*myEmat->publicPara->phase/myEmat->privatePara->phasePrecision;
	periods = (unsigned int)myEmat->publicPara->periods/periodsPrecision;
    freqScaleFactor = 1.0*myEmat->publicPara->freqScaleFactor/freqPrecision;
    phaseScaleFactor = 1.0*myEmat->publicPara->phaseScaleFactor/phasePrecision;
    periodsScaleFactor = (unsigned int)myEmat->publicPara->periodsScaleFactor/periodsPrecision;
	system("clear");
	printf("*****************************************************************************************\n");
	printf("							KEY OPTIONS                                             \n");
	printf(" DYNAMIC CONFIG MENU (key:%c)                                             		   \n",DYNAMIC_CONFIG);
	printf(" DEFAULT CONFIG MENU (key:%c)                                             	       \n",DEFAULT_CONFIG);
	printf(" SAVE MENU (key:%c)                                             				       \n",SAVE_MENU);
	printf(" EXIT PROGRAMM (key:%c)                                             				   \n",QUIT);
	printf("*****************************************************************************************\n");
	printf("							CURRENT STATE                                          \n");
	printf(" current frequency = %.2f MHz                                                        \n",freq);
	printf(" current phase = %.3f                                                                \n",phase);
	printf(" current periods = %d                                                                \n",periods);
	printf("*****************************************************************************************\n");
	printf("option: \n");
}

int InterfaceRefresh_Default_Config_Menu(ematController *myEmat){

}
int InterfaceRefresh_Save_Menu(ematController *myEmat){

}
