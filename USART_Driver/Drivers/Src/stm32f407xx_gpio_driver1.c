/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Nov 26, 2024
 *      Author: talur
 */

#include"stm32f407xx_gpio_driver.h"


/*Step13*/
/*Create function definitions of API*/
/*Function1 GPIO_CONTROL*/
/*Which PORT's clock should be enabled or disabled*/

/********************************************************
 * @fn					- 	GPIO_PeriClockControl
 *
 * @brief				-   This function enables or disables peripheral clock for given GPIO port
 *
 * @param[in]			-   Base address of GPIO peripheral
 * @param[in]			-   ENABLE or DISABLE macros
 * @param[in]			-
 *
 * @return				-   none
 *
 * @Note				-   none
 *
 */



void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}

	}

}



/*Function2*/
/* GPIO pin General register configuration*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//enable peripheral clock
	 GPIO_PeriClockControl(pGPIOHandle->pGPIOx,ENABLE);

	//1.configure the mode of gpio pin

	uint32_t temp=0;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_ANALOG)
	{
		//non interrupt mode

		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x30 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;

	}
	else
	{
        /*Step16*/
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//1.configure (FTSR)falling trigger selection register
			EXTI->FTSR |= (1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//clear the corresponding RTSR bit
			EXTI->RTSR &= ~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1.configure the RTSR
			EXTI->RTSR |= (1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//clear the corresponding FTSR bit
			EXTI->FTSR &= ~(1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}
		else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//1.Configure both FTSR and RTSR


					//1.configure (RTSR)falling trigger selection register and (FTSR)
					EXTI->RTSR |= (1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
					//clear the corresponding RTSR bit
					EXTI->FTSR |= (1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}


		/*2 Configure the GPIO port selection in SYSCFG_EXTICR*/
             /*Step 17*/
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
        SYSCFG->EXTICR[temp1]= portcode << (temp2 *4);

		 /*3. Enable the EXTI interrupt delivery through EXTI*/
		EXTI->IMR |= 1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
	}
	temp=0;


	//2.configure the speed

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x30 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp=0;

	//3.configure the pupd settings

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x30 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->PUPDR |= temp;


	temp=0;

	//4.configure the optype

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	pGPIOHandle->pGPIOx->OTYPER |= temp;

	//5.configure the alt functionality

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode<=GPIO_MODE_ALTFN)
		{
			//configure the alt function registers
            uint8_t temp1,temp2 ;

            temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
            temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
            pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));

            pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<(4 * temp2));
		}
		else
		{

		}

}


/*Function 3*/
/*Reset GPIO PORT A and its complete registers*/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	        if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOD)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOE)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOF)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOG)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOH)
			{
				GPIOA_REG_RESET();
			}

}

/* Read and write value from and to Data register*/
/*Function4*/
/* Data read from input pin */
/********************************************************
 * @fn					- 	GPIO_ReadFromInputPin
 *
 * @brief				-
 *
 * @param[in]			-
 * @param[in]			-
 * @param[in]			-
 *
 * @return				- 0 or 1
 *
 * @Note				-
 *
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;
	//pass the read value bit to lsb(INput data register) using shift and return
	value = (uint8_t)((pGPIOx->IDR >> PinNumber)& 0x00000001);
	return value;
}

/*Function5*/
/*Data Read from input Port*/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}


/*Function6*/
/*Write to output Port*/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
       //write 1 to input data register at the bit field corresponding pin number
		pGPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
       //write 0
		pGPIOx->ODR &= (1<<PinNumber);
	}

}

/*Function7*/
/*Toggle outputpin*/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
    pGPIOx->ODR ^=(1<<PinNumber);
}

/* IRQ Configuration and ISR handling*/

/*Step 21*/
/*Function8*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber,uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{

	   if(IRQNumber <=31)
	   {
		   //pgm ISER0 register
		   *NVIC_ISER0 |= (1<< IRQNumber);
	   }

	   else if(IRQNumber >31 && IRQNumber <64)
	   {
		   //pgm ISER1 register
		   *NVIC_ISER1 |= (1<< (IRQNumber%32));
	   }

	   else if(IRQNumber >= 64 && IRQNumber <96)
	   {
		   //pgm ISER2 register
		   *NVIC_ISER2 |= (1<< (IRQNumber%64));
	   }


    }
	else
	{
		if(IRQNumber <=31)
		{
		    //pgm ICER0 register
			*NVIC_ICER0 |= (1<< IRQNumber);
		}

	    else if(IRQNumber >31 && IRQNumber <64)
		{
			//pgm ICER1 register
	    	*NVIC_ICER1 |= (1<< (IRQNumber%32));
		}

		else if(IRQNumber >= 64 && IRQNumber <96)
		{
		    //pgm ICER2 register
			*NVIC_ICER2 |= (1<< (IRQNumber%64));
		}
	}
}
/* Step 22*/
/*Function9*/
/* GPIO interrupt priority configuration */
/********************************************************
 * @fn					- 	GPIO_IRQPriorityConfig
 *
 * @brief				-
 *
 * @param[in]			-
 * @param[in]			-
 * @param[in]			-
 *
 * @return				-
 *
 * @Note				-
 *
 */

void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority)
{
    //1. Find out IPR register
	uint8_t iprx =         IRQNumber /4;
	uint8_t iprx_section = IRQNumber %4;

    uint8_t shiftamount= (8*iprx_section)+(8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR+(iprx))|= (IRQPriority << shiftamount);


}

/*Step22*/
/*Function9*/
void GPIO_IRQHandling(uint8_t PinNumber)
{
	//IRQ handling is seen in below way

	//clear the EXTI PR register corresponding to the number,which is aldreadt set
	if(EXTI->PR &(1<<PinNumber))
	{
		//clear it by writing 1.Therefore
		EXTI->PR |=(1<<PinNumber);
	}
}

