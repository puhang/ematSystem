#include "emat_Struct.h"
#include "key_Logic.h"

#include "display.h"
#include "dynamic_Config_Menu.h"
#include "main_Menu.h"
#include "save_Menu.h"
#include "default_Config_Menu.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int Print_Key_Error(char ctrl){
	printf("\nError: Invalid Key Value for key = %c\n",ctrl);
	printf("please user the supported key value \n");
	return 0;
}

static int Common_ValidKey(char ctrl){
	if(ctrl==REFRESH) return KEY_VALID;
	return KEY_INVALID;
}
//dynamic conf menu
static int Dynamic_Config_Menu_ValidKey(char ctrl){
	if(ctrl==PERIODS_DEC||ctrl==PERIODS_INC||ctrl==PHASE_DEC||ctrl==PHASE_INC||ctrl==FREQ_DEC||ctrl==FREQ_INC){
		return KEY_VALID;
	}
	if(Common_ValidKey(ctrl)) return KEY_VALID;
	if(1){
		// interface for any range dynamic setup
	}
	return KEY_INVALID;
}
static int Dynamic_Config_Menu(ematController *myEmat){
	char ctrl = REFRESH;
	do{
		InterfaceRefresh_Dynamic_Config_Menu(myEmat);
		scanf(" %c",&ctrl);
		if(Dynamic_Config_Menu_ValidKey(ctrl)){
			Dynamic_Config_FixRange(ctrl,myEmat);
			//future upgrade: setup_Dynamic_anyRange();
		}
	}while(ctrl!='0');
	myEmat->state = MAIN_MENU;
	return 0;
}

//default conf menu
static int Default_Config_Menu_ValidKey(char ctrl){
	// public parameters config
	if(ctrl==PERIODS_CONF||ctrl==FREQ_CONF||ctrl==PHASE_CONF){
		return KEY_VALID;
	}
	if(ctrl==FREQ_SCALE_FACTOR_CONF||ctrl==PHASE_SCALE_FACTOR_CONF||ctrl==PERIODS_SCALE_FACTOR_CONF){
		return KEY_VALID;
	}
	// private parameters config
	if(ctrl==MAX_FREQ_CONF||ctrl==MAX_PERIODS_CONF||ctrl==MAX_PHASE_CONF){
		return KEY_VALID;
	}
	if(ctrl==MIN_FREQ_CONF||ctrl==MIN_PERIODS_CONF||ctrl==MIN_PHASE_CONF){
		return KEY_VALID;
	}
	if(ctrl==DUTY_CYCLE_CONF){
		return KEY_VALID;
	}
	if(Common_ValidKey(ctrl)) return KEY_VALID;
	return KEY_INVALID;
}
static int Default_Config_Menu(ematController *myEmat){
	char ctrl = REFRESH;
	do{
		InterfaceRefresh_Default_Config_Menu(myEmat);
		if(Default_Config_Menu_ValidKey(ctrl)){
			Default_Config_Logic(ctrl,myEmat);
			//future upgrade: setup_Dynamic_anyRange();
		}
		else{
			Print_Key_Error(ctrl);
		}
	    scanf(" %c",&ctrl);
	}while(ctrl!='0');
	myEmat->state = MAIN_MENU;
	return 0;
}
//save menu
static int Save_Menu_ValidKey(char ctrl){
	if(ctrl==SAVE||ctrl==SAVE_AS){
			return KEY_VALID;
	}
	if(Common_ValidKey(ctrl)) return KEY_VALID;
	return KEY_INVALID;
}
static int Save_Menu(ematController *myEmat){
	char ctrl = REFRESH;
	do{
		InterfaceRefresh_Save_Menu(myEmat);
		if(Save_Menu_ValidKey(ctrl)){
			Save_Logic(ctrl,myEmat);
		}
		scanf(" %c",&ctrl);
	}while(ctrl!='0');
	myEmat->state = MAIN_MENU;
	return 0;
}
//main menu
static int Main_Menu_ValidKey(char ctrl){
	if(ctrl==DYNAMIC_CONFIG||ctrl==DEFAULT_CONFIG||ctrl==SAVE ||ctrl==QUIT){
			return KEY_VALID;
	}
	if(Common_ValidKey(ctrl)) return KEY_VALID;
	return KEY_INVALID;
}
static int Main_Menu(ematController *myEmat){
	char ctrl = REFRESH;
	do{
		InterfaceRefresh_Main_Menu(myEmat);
		scanf(" %c",&ctrl);
		switch(ctrl){
			case DYNAMIC_CONFIG:myEmat->state = DYNAMIC_CONFIG_MENU;break;
			case DEFAULT_CONFIG:myEmat->state = DEFAULT_CONFIG_MENU;break;
			case SAVE:myEmat->state = SAVE_MENU;break;
			case QUIT:myEmat->state = QUIT;break;
			default: break;
		}
	}while(!Main_Menu_ValidKey(ctrl));

	return 0;
}


int Menu_Logic(ematController *myEmat){
	do{

		switch(myEmat->state)
		{
			case MAIN_MENU: Main_Menu(myEmat);break;
			case SAVE_MENU: Save_Menu(myEmat);break;
			case DYNAMIC_CONFIG_MENU: Dynamic_Config_Menu(myEmat);break;
			case DEFAULT_CONFIG_MENU: Default_Config_Menu(myEmat);break;
			default: break;
		 }
	}while(myEmat->state!=QUIT);
    return 0;
}
