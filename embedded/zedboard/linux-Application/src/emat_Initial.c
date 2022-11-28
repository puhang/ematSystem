#include "emat_Struct.h"
#include "ematController_terminal.h"
#include "key_Logic.h"
#include "register_Config.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define PRIVATE_PARAMETERS_LEN 11
#define PUBLIC_PARAMETERS_LEN 12

int Initial_Emat_Struct(ematController *myEmat,char confFile[FILENAME_LEN]){
	privateParameters *pri = (privateParameters *)malloc(sizeof(privateParameters));
	publicParameters *pub = (publicParameters *)malloc(sizeof(publicParameters));
	myEmat->privatePara = pri;
	myEmat->publicPara = pub;
	char str[1024];
	unsigned int priPara[PRIVATE_PARAMETERS_LEN];
	unsigned int pubPara[PUBLIC_PARAMETERS_LEN];
	system("clear");
	printf("\n ....... EMAT initializing from configuration file: '%s'  .......\n",confFile);
	FILE *fp = fopen("default.txt","r");
	fgets(str,1024,fp);

	for(int i=0;i<PRIVATE_PARAMETERS_LEN;i++){
		fscanf(fp," %d",priPara+i);
	}
	myEmat->privatePara->dutyCycle = priPara[0];
	myEmat->privatePara->dutyCyclePrecision = priPara[1];
	myEmat->privatePara->baseFreq = priPara[2];
	myEmat->privatePara->freqPrecision = priPara[3];
	myEmat->privatePara->phasePrecision = priPara[4];
	myEmat->privatePara->periodsPrecision = priPara[5];
	myEmat->privatePara->clkMasterDiv = priPara[6];
	myEmat->privatePara->clkSlaveDiv = priPara[7];
	myEmat->privatePara->transStartInterval = priPara[8];
	myEmat->privatePara->transStopInterval = priPara[9];
	myEmat->privatePara->receiveInterval = priPara[10];
	//jump 2 line
	fgets(str,1024,fp);
	fgets(str,1024,fp);
	for(int i=0;i<PUBLIC_PARAMETERS_LEN;i++){
		fscanf(fp,"%d",pubPara+i);
	}
	myEmat->publicPara->freq = pubPara[0];
	myEmat->publicPara->phase = pubPara[1];
	myEmat->publicPara->periods = pubPara[2];
	myEmat->publicPara->freqScaleFactor = pubPara[3];
	myEmat->publicPara->phaseScaleFactor = pubPara[4];
	myEmat->publicPara->periodsScaleFactor = pubPara[5];
	myEmat->publicPara->maxFreq = pubPara[6];
	myEmat->publicPara->minFreq = pubPara[7];
	myEmat->publicPara->maxPhase = pubPara[8];
	myEmat->publicPara->minPhase = pubPara[9];
	myEmat->publicPara->maxPeriods = pubPara[10];
	myEmat->publicPara->minPeriods = pubPara[11];

	myEmat->state = MAIN_MENU;
	fclose(fp);

	controlTiming_Register(myEmat,'W');
	return 0;

}
