#ifndef EMAT_STRUCT


typedef struct{
    unsigned int dutyCycle;				//1e3
    unsigned int dutyCyclePrecision;	//1e6
    unsigned int baseFreq; 				//normalize to 1 MHz
    unsigned int freqPrecision;
    unsigned int phasePrecision;
    unsigned int periodsPrecision;
	unsigned int clkMasterDiv;			//
    unsigned int clkSlaveDiv;
    unsigned int transStartInterval; //normalize to periods
    unsigned int transStopInterval;
    unsigned int receiveInterval;
}privateParameters;
typedef struct{
	unsigned int freq; 					//freq = RealFreq(MHz)*freqPrecision
	unsigned int phase;					//phase= RealPhase(degree)*phasePrecision
	unsigned int periods;				//periods = RealPeridos*periodsPrecision

	unsigned int freqScaleFactor;
	unsigned int phaseScaleFactor;
	unsigned int periodsScaleFactor;

    unsigned int maxFreq;
    unsigned int minFreq;
    unsigned int maxPhase;
    unsigned int minPhase;
    unsigned int maxPeriods;
    unsigned int minPeriods;
}publicParameters;
typedef struct{
	privateParameters *privatePara;
	publicParameters *publicPara;
	char state;
	int *fd;
}ematController;
#endif
#define EMAT_STRUCT
