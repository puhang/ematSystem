#include "emat_Struct.h"
#include "register_Config.h"
#include "AXI_clkwizd_registers.h"
#include "AXI_timerLogic_registers.h"
#include "mem_Access.h"
#include <stdio.h>


static int clkwizd_Register_Write(ematController *myEmat){
	printf("clkwizd_Register_Write\n");
	unsigned int freqDivMaster = myEmat->privatePara->clkMasterDiv;
	unsigned int freqDivSlave = myEmat->privatePara->clkSlaveDiv;
	unsigned int freqDiv = freqDivMaster*freqDivSlave;
	unsigned int freq = myEmat->publicPara->freq;
	unsigned int freqPrecision = myEmat->privatePara->freqPrecision;
	unsigned int freqMult = (unsigned int)(freq*freqDiv/myEmat->privatePara->baseFreq);
	unsigned int freqMultInteger = (unsigned int)freqMult/freqPrecision;
	unsigned int freqMultFrac = (unsigned int)freqMult%freqPrecision;

	unsigned int phase = myEmat->publicPara->phase;
	// master clock frequency configuration register value
	unsigned int clkFreqRegisterValue = (CLK_FREQ_DIV_MASK & freqDivMaster) | \
						  (CLK_FREQ_MULT_INT_MASK & (freqMultInteger << 8)) | \
						  (CLK_FREQ_MULT_FRAC_MASK & (freqMultFrac << 16));
	// slave clock 0 frequency configuration register value
	unsigned int clk0FreqRegisterValue = (CLK_FREQ_DIV_MASK & freqDivSlave);
	// slave clock 1 frequency configuration register value
	unsigned int clk1FreqRegisterValue = (CLK_FREQ_DIV_MASK & freqDivSlave);
	// slave clock 1 phase configuration register value
	unsigned int clk1PhaseRegisterValue = (CLK_PHASE_MASK & phase);

	Mem_Write(GCLK_BASE_ADDR,CLK_FREQ_REGISTER,clkFreqRegisterValue);
	Mem_Write(GCLK_BASE_ADDR,CLK0_FREQ_REGISTER,clk0FreqRegisterValue);
	Mem_Write(GCLK_BASE_ADDR,CLK1_FREQ_REGISTER,clk1FreqRegisterValue);
	Mem_Write(GCLK_BASE_ADDR,CLK1_PHASE_REGISTER,clk1PhaseRegisterValue);
	Mem_Write(GCLK_BASE_ADDR,RECONFIG_REGISTER,CLK_RECONFIG_REGISTER_VALUE);

	return 0;

}
static int timingLogic_Register_Write(ematController *myEmat){
	printf("timingLogic_Register_Write\n");
	unsigned int periods = myEmat->publicPara->periods;
	unsigned int periodsPrecision = myEmat->privatePara->periodsPrecision;
	unsigned int transStartInterval = myEmat->privatePara->transStartInterval;
	unsigned int transStopInterval = myEmat->privatePara->transStopInterval;
	unsigned int receiveInterval = myEmat->privatePara->receiveInterval;
	unsigned int dutyCycle = myEmat->privatePara->dutyCycle;
	unsigned int dutyCyclePrecision = myEmat->privatePara->dutyCyclePrecision;
	unsigned int idleRegisterValue = (unsigned int)(1.0*periods/periodsPrecision)/(1.0*dutyCycle/dutyCyclePrecision);
	unsigned int transRegisterValue = (TRANS_START_INTERVAL_MASK & transStartInterval) | \
			(TRANS_INTERVAL_MASK & (periods<<4)) | \
			(TRANS_STOP_INTERVAL_MASK & (transStopInterval<<8)) | \
			(RECEIVE_INTERVAL_MASK & (receiveInterval<<12));

	Mem_Write(TIMER_BASE_ADDR,TRAN_CTRL,transRegisterValue);
	Mem_Write(TIMER_BASE_ADDR,IDLE_CTRL,idleRegisterValue);
}


int controlTiming_Register(ematController *myEmat,char flag){
	printf("controlTiming_Register\n");
	switch(flag){
		case 'R':break;
		case 'W':clkwizd_Register_Write(myEmat);timingLogic_Register_Write(myEmat); break;
	}
	return 0;
}
