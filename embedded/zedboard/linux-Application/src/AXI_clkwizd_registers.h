#ifndef AXI_CLKWIZD_REGISTERS
//GCLK based address
#define GCLK_BASE_ADDR 0x43c00000

// GCLK REGISTER_OFFSET
#define SRR        			0x00  /*software reset register:reset GCLK*/
#define SR         			0x04  /*status register: when MMCM locked bit[0] = 1*/
#define CLK_FREQ_REGISTER   0x200 /*clock configuration register 0:
					 	 default: 0x(01)(01)(0A)(00)
					 	 bit[7:0]: DIVCLK_DIVIDE 8 bits divide value applied to all output clocks
					 	 bit[15:8]: CLKFBOUT_MULT 8 bits multiplier value (integer part)
					 	 bit[25:16]: CLKFBOUT_FRAC 10 bits multiplier value (frac part)
					 	 for 8.125x CLKFBOUT_MULT = 8, CLKFBOUT_FRAC = 125
					 	 */
#define CLK0_FREQ_REGISTER   0x208 /**/
#define CLK0_PHASE_REGISTER  0x20C /**/
#define CLK1_FREQ_REGISTER   0x214 /**/
#define CLK1_PHASE_REGISTER  0x218 /*signed numbers 31 btis[30:0] configurable*/

#define RECONFIG_REGISTER 	   0x25c /**/

#define CLK_FREQ_DIV_MASK			255       //0x000000ff
#define CLK_FREQ_MULT_INT_MASK  	65280 	  //0x0000ff00
#define CLK_FREQ_MULT_FRAC_MASK  	67043328  //0x03ff0000
#define CLK_PHASE_MASK 				1048575 //0x000fffff  //phase config register is signed num, we need only positive phase here
															//and 360000 (0x00057e40)is the max
#define CLK_RECONFIG_REGISTER_VALUE 3
#define AXI_CLKWIZD_REGISTERS
#endif

