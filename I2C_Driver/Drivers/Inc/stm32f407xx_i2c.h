/*
 * stm32f407xx_i2c.h
 *
 *  Created on: Jan 22, 2025
 *      Author: talur
 */

#ifndef INC_STM32F407XX_I2C_H_
#define INC_STM32F407XX_I2C_H_

#include"common.h"





/*Step 1:*/
/* base address of peripherals hanging on APB1 bus */
#define I2C1_BASEADDR	  (APB1_PERIPHBASEADDR+0x5400)
#define I2C2_BASEADDR     (APB1_PERIPHBASEADDR+0x5800)
#define I2C3_BASEADDR     (APB1_PERIPHBASEADDR+0x5C00)






/*Step 2:*/
/*peripheral register definition structure for I2C*/

typedef struct
{
  __vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x00 */
  __vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x04 */
  __vo uint32_t OAR1;       /*!< TODO,     										Address offset: 0x08 */
  __vo uint32_t OAR2;       /*!< TODO,     										Address offset: 0x0C */
  __vo uint32_t DR;         /*!< TODO,     										Address offset: 0x10 */
  __vo uint32_t SR1;        /*!< TODO,     										Address offset: 0x14 */
  __vo uint32_t SR2;        /*!< TODO,     										Address offset: 0x18 */
  __vo uint32_t CCR;        /*!< TODO,     										Address offset: 0x1C */
  __vo uint32_t TRISE;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32_t FLTR;       /*!< TODO,     										Address offset: 0x24 */
}I2C_RegDef_t;




/*Step 3:*/
/*peripheral definitions I2Cx( Peripheral base addresses typecasted to xxx_RegDef_t)*/

#define I2C1  				((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2  				((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3  				((I2C_RegDef_t*)I2C3_BASEADDR)




/*Step 4:*/
/*Clock Enable Macros I2Cx peripherals*/

#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))




/*Step 5:*/
/*Bit position definitions of I2C peripheral*/

/* Bit position definitions I2C_CR1*/
#define I2C_CR1_PE						0
#define I2C_CR1_NOSTRETCH  				7
#define I2C_CR1_START 					8
#define I2C_CR1_STOP  				 	9
#define I2C_CR1_ACK 				 	10
#define I2C_CR1_SWRST  				 	15

/*Bit position definitions I2C_CR2*/
#define I2C_CR2_FREQ				 	0
#define I2C_CR2_ITERREN				 	8
#define I2C_CR2_ITEVTEN				 	9
#define I2C_CR2_ITBUFEN 			    10

/* Bit position definitions I2C_OAR1*/
#define I2C_OAR1_ADD0    				 0
#define I2C_OAR1_ADD71 				 	 1
#define I2C_OAR1_ADD98  			 	 8
#define I2C_OAR1_ADDMODE   			 	15

/* Bit position definitions I2C_SR1*/
#define I2C_SR1_SB 					 	0
#define I2C_SR1_ADDR 				 	1
#define I2C_SR1_BTF 					2
#define I2C_SR1_ADD10 					3
#define I2C_SR1_STOPF 					4
#define I2C_SR1_RXNE 					6
#define I2C_SR1_TXE 					7
#define I2C_SR1_BERR 					8
#define I2C_SR1_ARLO 					9
#define I2C_SR1_AF 					 	10
#define I2C_SR1_OVR 					11
#define I2C_SR1_TIMEOUT 				14

/*Bit position definitions I2C_SR2*/
#define I2C_SR2_MSL						0
#define I2C_SR2_BUSY 					1
#define I2C_SR2_TRA 					2
#define I2C_SR2_GENCALL 				4
#define I2C_SR2_DUALF 					7

/* Bit position definitions I2C_CCR*/
#define I2C_CCR_CCR 					 0
#define I2C_CCR_DUTY 					14
#define I2C_CCR_FS  				 	15


/* @I2C_AckControl */
#define  I2C_ACK_ENABLE   1
#define  I2C_ACK_DISABLE  0

#define IRQ_NO_I2C1_EV       31
#define IRQ_NO_I2C1_ER       32


#endif /* INC_STM32F407XX_I2C_H_ */


#include"stm32f407xx_i2c_driver.h"
