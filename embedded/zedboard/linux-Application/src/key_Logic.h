#ifndef KEY_LOGIC

// Common Valid keys
#define REFRESH 'R'

// Dynamic_Config_Menu Valid Keys
#define PERIODS_DEC '1'
#define PERIODS_INC '3'
#define PHASE_DEC   '4'
#define PHASE_INC   '6'
#define FREQ_DEC 	'7'
#define FREQ_INC 	'9'

// Main_Menu Valid Keys
#define DYNAMIC_CONFIG 	'd'
#define SAVE 	's'
#define DEFAULT_CONFIG 	'l'

// Save_Menu Valid Keys
#define SAVE 	'y'
#define SAVE_AS 'n'
// Default_Config_Menu Valid Keys
#define PERIODS_CONF 				'q'
#define FREQ_CONF					'w'
#define PHASE_CONF					'e'
#define PERIODS_SCALE_FACTOR_CONF 	'Q'
#define FREQ_SCALE_FACTOR_CONF		'W'
#define PHASE_SCALE_FACTOR_CONF		'E'

#define MAX_FREQ_CONF				'1'
#define MIN_FREQ_CONF				'3'
#define MAX_PHASE_CONF 				'4'
#define MIN_PHASE_CONF				'6'
#define MAX_PERIODS_CONF			'7'
#define MIN_PERIODS_CONF			'9'

#define DUTY_CYCLE_CONF				'D'

// program state: myEmat->state
#define QUIT 				'0'
#define MAIN_MENU 			'1'
#define DYNAMIC_CONFIG_MENU '2'
#define DEFAULT_CONFIG_MENU	'3'
#define SAVE_MENU			'4'

// KEY VAILD JUDGEMENT
#define KEY_VALID 1
#define KEY_INVALID 0

int Menu_Logic(ematController *myEmat);

#define KEY_LOGIC
#endif
