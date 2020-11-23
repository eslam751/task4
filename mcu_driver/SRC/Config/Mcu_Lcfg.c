#include "Mcu_Cfg.h"


RCGC_reg Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_GATES_SIZE]=
{
	GPIOA,
	GPIOB,
	GPIOC,
	WDT0
};
Mcu_ConfigType McuConfig[MCU_CLOCK_SETTINGS_SIZE]=
{
	/* ClockSource 		  							  PllUse   							 Freq_KHz  */
	{	MCU_CLOCK_SOURCE_MOSC				,			ENABLE					,			 25000 },
	{	MCU_CLOCK_SOURCE_PIOSC			,			DISABLE   			,			 16000 }
};

#if(Mcu_ClockType==0) 
Mcu_ConfigType *ConfigPtr = &McuConfig[0];
#elif(Mcu_ClockType==1)
Mcu_ConfigType *ConfigPtr = &McuConfig[1];
#endif


