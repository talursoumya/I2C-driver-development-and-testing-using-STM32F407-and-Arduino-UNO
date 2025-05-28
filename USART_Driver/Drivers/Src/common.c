/*
 * common.c
 *
 *  Created on: Mar 12, 2025
 *      Author: talur
 */

#include"common.h"

uint16_t AHB_PreScaler[8]= {2,3,8,16,64,128,256,512};
uint16_t APB1_PreScaler[8]= {2,3,8,16,64,128,256,512};
uint16_t APB2_PreScaler[8]= {2,3,8,16,64,128,256,512};

uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1,systemClk;

	uint8_t clksrc,temp,ahbp,apb1;

	clksrc = ((RCC->CFGR >>2) & 0x3);

	if(clksrc == 0)
	{
		systemClk = 16000000;
	}
	else if(clksrc ==1)
	{
		systemClk= 8000000;
	}
	else if(clksrc ==2)
	{
		systemClk = RCC_GetPLLOutputClock();
	}
	 temp = ((RCC->CFGR >>4)& 0XF);

	 if(temp <8)
	 {
		 ahbp =1;
	 }

	 else
	 {
		 ahbp = AHB_PreScaler[temp-8];
	 }
	 //for ahb
	 temp = ((RCC->CFGR >>10)& 0XF);

	 if(temp <4)
	 {
		 apb1 =1;
	 }

	 else
	 {
		 ahbp = APB1_PreScaler[temp-4];
	 }

	 pclk1= (systemClk/ahbp)/apb1;

	return pclk1;


}

/*
*********************************************************************
 * @fn      		  - RCC_GetPCLK2Value
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint32_t RCC_GetPCLK2Value(void)
{
	uint32_t SystemClock=0,tmp,pclk2;
	uint8_t clk_src = ( RCC->CFGR >> 2) & 0X3;

	uint8_t ahbp,apb2p;

	if(clk_src == 0)
	{
		SystemClock = 16000000;
	}else
	{
		SystemClock = 8000000;
	}
	tmp = (RCC->CFGR >> 4 ) & 0xF;

	if(tmp < 0x08)
	{
		ahbp = 1;
	}else
	{
       ahbp = AHB_PreScaler[tmp-8];
	}

	tmp = (RCC->CFGR >> 13 ) & 0x7;
	if(tmp < 0x04)
	{
		apb2p = 1;
	}else
	{
		apb2p = APB1_PreScaler[tmp-4];
	}

	pclk2 = (SystemClock / ahbp )/ apb2p;

	return pclk2;
}

uint32_t  RCC_GetPLLOutputClock()
{

	return 0;
}

