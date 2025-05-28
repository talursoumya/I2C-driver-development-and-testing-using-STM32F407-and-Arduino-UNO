/*
 * common.h
 *
 *  Created on: Dec 4, 2024
 *      Author: talur
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include<stdint.h>

#define __vo volatile

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);

uint32_t  RCC_GetPLLOutputClock(void);

/*Step 1*/
/* base address of bus peripherals */
#define PERIPH_BASEADDR    	  0x40000000U
#define APB1_PERIPHBASEADDR	  PERIPH_BASEADDR
#define APB2_PERIPHBASEADDR	  0x40010000U
#define AHB1_PERIPHBASEADDR	  0x40020000U


/*Create Generic structure for RCC Peripheral registers*/
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t      RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t      RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
	__vo uint32_t CKGATENR;
	 __vo uint32_t DCKCFGR2;
}RCC_RegDef_t;


/*Access RCC peripheral registers inside RCC_RegDef_t*/
#define RCC_BASEADDR      (AHB1_PERIPHBASEADDR+0x3800)
#define RCC               ((RCC_RegDef_t*)RCC_BASEADDR)


/*Step 8*/
/*some generic macros */
#define __vo           volatile
#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define FLAG_RESET      RESET
#define FLAG_SET        SET



/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_PR_BASE_ADDR ((__vo uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED 4
#endif /* INC_COMMON_H_ */


/*IRQ (Interrupt Request)Number of STM32F407x MCU*/

#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1        7
#define IRQ_NO_EXTI2        8
#define IRQ_NO_EXTI3        9
#define IRQ_NO_EXTI4        10
#define IRQ_NO_EXTI9_5      23
#define IRQ_NO_EXTI10_15    40
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4	        84
#define IRQ_NO_I2C1_EV     31
#define IRQ_NO_I2C1_ER     32
#define IRQ_NO_USART1	    37
#define IRQ_NO_USART2	    38
#define IRQ_NO_USART3	    39
#define IRQ_NO_UART4	    52
#define IRQ_NO_UART5	    53
#define IRQ_NO_USART6	    71


/*
 * macros for all the possible priority levels
 */

#define NVIC_IRQ_PRIO15      15



/*
 * Arm Cortex Mx Processor NVIC ISERx register Addresses
 */
#define NVIC_ISER0  ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1  ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2  ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3  ((__vo uint32_t*)0xE000E10C)



/*
 * Arm Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0  ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1  ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2  ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3  ((__vo uint32_t*)0xE000E18C)
