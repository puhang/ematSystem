#include "emat_Struct.h"
#include "dynamic_Config_Menu.h"
#include "register_Config.h"
#include "AXI_clkwizd_registers.h"
#include "AXI_timerLogic_registers.h"
#include "key_Logic.h"
#include <stdio.h>


static int freqConfig(ematController *myEmat,int flag,int setupFreq){
	unsigned int freq = (flag==0?setupFreq:(myEmat->publicPara->freq+flag*myEmat->publicPara->freqScaleFactor));
	unsigned int maxFreq = myEmat->publicPara->maxFreq;
	unsigned int minFreq = myEmat->publicPara->minFreq;

	if (freq>maxFreq){
		return OVERFLOW_FREQ_MAX;
	}
	else if(freq<minFreq){
		return OVERFLOW_FREQ_MIN;
	}
	else {
		myEmat->publicPara->freq = (unsigned int)freq;
	}
	controlTiming_Register(myEmat,'W'); //change frequency through GLOBAL clk frequency
	return 0;
}
static int phaseConfig(ematController *myEmat,int flag,int setupPhase){
	unsigned int phase = flag==0?setupPhase:myEmat->publicPara->phase+flag*myEmat->publicPara->phaseScaleFactor;
	unsigned int maxPhase = myEmat->publicPara->maxPhase;
	unsigned int minPhase = myEmat->publicPara->minPhase;
	if (phase>maxPhase){
		return OVERFLOW_PHASE_MAX;
	}
	else if(phase<minPhase){
		return OVERFLOW_PHASE_MIN;
	}
	else {
		myEmat->publicPara->phase = (unsigned int)phase;
	}
	return controlTiming_Register(myEmat,'W'); //change phase through clk1 phase control register
}
static int periodsConfig(ematController *myEmat,int flag,int setupPeriods){
	int periods = flag==0?setupPeriods:myEmat->publicPara->periods+flag*myEmat->publicPara->periodsScaleFactor;
	unsigned int maxPeriods = myEmat->publicPara->maxPeriods;
	unsigned int minPeriods = myEmat->publicPara->minPeriods;
	if (periods>maxPeriods){
		return OVERFLOW_PERIODS_MAX;
	}
	else if(periods<minPeriods){
		return OVERFLOW_PERIODS_MIN;
	}
	else {
		myEmat->publicPara->periods = (unsigned int)periods;
	}
	return controlTiming_Register(myEmat,'W'); //change periods through timerLogic control register
}

int Dynamic_Config_FixRange(char ctrl,ematController *myEmat){
	printf("Dynamic_Config_FixRange\n");
	switch(ctrl)
	{
		case FREQ_INC:    return freqConfig(myEmat,1,0);
		case FREQ_DEC:    return freqConfig(myEmat,-1,0);
		case PHASE_INC:   return phaseConfig(myEmat,1,0);
		case PHASE_DEC:   return phaseConfig(myEmat,-1,0);
		case PERIODS_INC: return periodsConfig(myEmat,1,0);
		case PERIODS_DEC: return periodsConfig(myEmat,-1,0);
		case REFRESH: 	  return 0;
		default: break;
	}
	return 0;
}

int setup_Dynamic_anyRange(){
	return 0;
}

