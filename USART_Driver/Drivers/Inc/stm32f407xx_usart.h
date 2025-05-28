/*
 * stm32f407xx_usart.h
 *
 *  Created on: Mar 11, 2025
 *      Author: talur
 */

#ifndef INC_STM32F407XX_USART_H_
#define INC_STM32F407XX_USART_H_

#include"common.h"

typedef struct
{
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GPTR;

}USART_RegDef_t;

/* base address of peripherals hanging on APB2 bus*/
#define USART1_BASEADDR    (APB2_PERIPHBASEADDR+0x13FF)
#define USART2_BASEADDR    (APB1_PERIPHBASEADDR+0x47FF)
#define USART3_BASEADDR    (APB1_PERIPHBASEADDR+0x4BFF)
#define UART4_BASEADDR    (APB1_PERIPHBASEADDR+0x4FFF)
#define UART5_BASEADDR    (APB1_PERIPHBASEADDR+0x53FF)
#define USART6_BASEADDR    (APB2_PERIPHBASEADDR+0x53FF)
#define UART7_BASEADDR    (APB1_PERIPHBASEADDR+0x7BFF)
#define UART8_BASEADDR    (APB1_PERIPHBASEADDR+0x7FFF)

#define USART1 		((USART_RegDef_t*)USART1_BASEADDR)
#define USART2		((USART_RegDef_t*)USART2_BASEADDR)
#define USART3		((USART_RegDef_t*)USART3_BASEADDR)
#define UART4		((USART_RegDef_t*)UART4_BASEADDR)
#define UART5		((USART_RegDef_t*)UART5_BASEADDR)
#define USART6		((USART_RegDef_t*)USART6_BASEADDR)
#define UART7		((USART_RegDef_t*)UART7_BASEADDR)
#define UART8		((USART_RegDef_t*)UART8_BASEADDR)


/* Clock enable macros for USART peripheral */
#define USART1_PCLK_EN()	(RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()	(RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN()	(RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_EN()		(RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_EN()		(RCC->APB1ENR |= (1<<20))
#define USART6_PCLK_EN()	(RCC->APB2ENR |= (1<<5))
#define UART7_PCLK_EN()		(RCC->APB1ENR |= (1<<30))
#define UART8_PCLK_EN()		(RCC->APB1ENR |= (1<<31))


/* Clock disable macros for USART peripheral */
#define USART1_PCLK_DI()	(RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI()	(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()	(RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DI()		(RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DI()		(RCC->APB1ENR &= ~(1<<20))
#define USART6_PCLK_DI()	(RCC->APB2ENR &= ~(1<<5))
#define UART7_PCLK_DI()		(RCC->APB1ENR &= ~(1<<30))
#define UART8_PCLK_DI()		(RCC->APB1ENR &= ~(1<<31))


/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK					0
#define USART_CR1_RWU 					1
#define USART_CR1_RE  					2
#define USART_CR1_TE 					3
#define USART_CR1_IDLEIE 				4
#define USART_CR1_RXNEIE  				5
#define USART_CR1_TCIE					6
#define USART_CR1_TXEIE					7
#define USART_CR1_PEIE 					8
#define USART_CR1_PS 					9
#define USART_CR1_PCE 					10
#define USART_CR1_WAKE  				11
#define USART_CR1_M 					12
#define USART_CR1_UE 					13
#define USART_CR1_OVER8  				15



/*
 * Bit position definitions USART_CR2
 */
#define USART_CR2_ADD   				0
#define USART_CR2_LBDL   				5
#define USART_CR2_LBDIE  				6
#define USART_CR2_LBCL   				8
#define USART_CR2_CPHA   				9
#define USART_CR2_CPOL   				10
#define USART_CR2_STOP   				12
#define USART_CR2_LINEN   				14


/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE   				0
#define USART_CR3_IREN   				1
#define USART_CR3_IRLP  				2
#define USART_CR3_HDSEL   				3
#define USART_CR3_NACK   				4
#define USART_CR3_SCEN   				5
#define USART_CR3_DMAR  				6
#define USART_CR3_DMAT   				7
#define USART_CR3_RTSE   				8
#define USART_CR3_CTSE   				9
#define USART_CR3_CTSIE   				10
#define USART_CR3_ONEBIT   				11

/*
 * Bit position definitions USART_SR
 */

#define USART_SR_PE        				0
#define USART_SR_FE        				1
#define USART_SR_NE        				2
#define USART_SR_ORE       				3
#define USART_SR_IDLE       			4
#define USART_SR_RXNE        			5
#define USART_SR_TC        				6
#define USART_SR_TXE        			7
#define USART_SR_LBD        			8
#define USART_SR_CTS					9


#include"stm32f407xx_usart_driver.h"

#endif /* INC_STM32F407XX_USART_H_ */
