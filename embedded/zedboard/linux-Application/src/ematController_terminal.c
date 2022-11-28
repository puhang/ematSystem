// author: puhang
// 32位数据，32位地址 数据类型： int
// 写内存方法：mmap映射到用户空间，msync读写
//

#include "emat_Struct.h"
#include "ematController_terminal.h"
#include "AXI_clkwizd_registers.h"
#include "AXI_timerLogic_registers.h"
#include "key_Logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char configFile[FILENAME_LEN];
	strcpy(configFile,"default.txt");
	ematController *myEmat;
	myEmat = (ematController *)malloc(sizeof(ematController));
	Initial_Emat_Struct(myEmat,configFile);
    printf("configured correct!\n");
    printf("press any key to enter the application\n");
    getchar();
    Menu_Logic(myEmat);
    system("clear");
    return 0;
}
