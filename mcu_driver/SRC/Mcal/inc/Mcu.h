/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  Mcu
 *
 *  Description:  Header file for Mcu Module     
 *  
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Mcu_Cfg.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "BitOperations.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 typedef enum{ 
	 
  MCU_MOSC_FAILURE_RESET =0x00010000		,
  MCU_WDT_1_RESET        =0x00000020    ,
  MCU_SOFTWARE_RESET  	 =0x00000010    ,
  MCU_WDT_0_RESET     	 =0x00000004    ,
  MCU_BROWN_OUT_RESET 	 =0x00000003    ,
  MCU_POWER_ON_RESET  	 =0x00000002    ,
  MCU_EXTERNAL_RESET  	 =0x00000001
	
 }Mcu_RawResetType;
 
 typedef enum
{
	
	  MCU_PLL_UNLOCKED,
    MCU_PLL_LOCKED,             
    MCU_PLL_STATUS_UNDEFINED,
	
}Mcu_PllStatusType;
 
  typedef enum {
	 
  MCU_CLOCK_SOURCE_MOSC,
	MCU_CLOCK_SOURCE_PIOSC,
	MCU_CLOCK_SOURCE_PIOSC_Div4,
	MCU_CLOCK_SOURCE_LFIOSC,
	MCU_CLOCK_SOURCE_HibOSC	
 
 }McuClockSourceType;
  
 typedef enum {
	 WDT0=3,
	 HIB=6 ,
	 MAXADC0SPD_0=8,
	 MAXADC0SPD_1,
	 MAXADC1SPD_0,
	 MAXADC1SPD_1,
	 ADC0=16,
	 ADC1,
	 PWM0=20,
	 CAN0=24,	
	 CAN1	,
	 WDT1=28,
	 UART0=32,
	 UART1,
	 UART2,
	 SSI0=36,
	 SSI1,
	 QEI1=40,
	 QEI0,
	 I2C1=44,
	 I2C0=46,
	 TIMER3=48,
	 TIMER2,
	 TIMER1,
	 TIMER0,
	 COMP1=56,
	 COMP0,
	 GPIOA=64,
	 GPIOB, 
	 GPIOC, 
	 GPIOD, 
	 GPIOE, 
	 GPIOF ,
	 UDMA=77,
	 USB0=80
 }RCGC_reg;

  typedef enum {
	 
	_5_MHz   =0x09  ,   
	_6_MHz   =0x0B  ,   
  _8_MHz   =0x0E  ,   
  _10_MHz  =0x10  ,   
  _12_MHz  =0x11  ,   
  _16_MHz  =0x15  ,   
  _18_MHz  =0x17  ,   
  _20_MHz  =0x18  ,   
  _24_MHz  =0x19  ,   
  _25_MHz  =0x1A 
		
 }McuFreqType;
	
typedef uint8 Mcu_ClockTypes;


typedef uint32 Mcu_FreqType;


typedef struct
{
   Mcu_ClockTypes ClockSource;
   boolean PllUse;
   Mcu_FreqType Freq_KHz;
	
}Mcu_ConfigType;
 
 
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 extern RCGC_reg Mcu_ActivatedClockGates[];
 void McuUser(void);
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init (void);


/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset (void);

/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )        
* \Description     : The service reads the reset type from the hardware, if supported.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType   Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue( void );
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( void );

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*                    E_OK: Command has been accepted
*                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock( void );

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : This service provides the lock status of the PLL.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void );

 
#endif  /* MCU_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
