#include "Mcu.h"

void McuUser(void)
{
	Mcu_Init();
	Mcu_InitClock();
	while(Mcu_GetPllStatus() == MCU_PLL_UNLOCKED);
	Mcu_DistributePllClock();
	
	while(1)
	{
	
	}
	
}
