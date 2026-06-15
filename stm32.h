/*
 * stm32.h
 *
 *  Created on: Apr 17, 2026
 *      Author: 16022
 */

#ifndef STM32_H_
#define STM32_H_


#include <stdint.h>
#define __IO volatile
/* GPIO Register Structure (based on STM32 reference manual Section 8.4.12) */
typedef struct
{
    volatile uint32_t MODER;    // Mode register
    volatile uint32_t OTYPER;   // Output type register
    volatile uint32_t OSPEEDR;  // Output speed register
    volatile uint32_t PUPDR;    // Pull-up/pull-down register
    volatile uint32_t IDR;      // Input data register
    volatile uint32_t ODR;      // Output data register
    volatile uint32_t BSRR;     // Bit set/reset register
    volatile uint32_t LCKR;     // Configuration lock register
    volatile uint32_t AFR[2];   // Alternate function registers AFR[0], AFR[1]
    volatile uint32_t BRR;      // Bit reset register
} GPIO_TypeDef;


/* Individual GPIO Base Addresses */
#define GPIOA_BASE       (GPIO_BASE + 0x0000)
#define GPIOB_BASE       (GPIO_BASE + 0x0400)
#define GPIOC_BASE       (GPIO_BASE + 0x0800)
#define GPIOD_BASE       (GPIO_BASE + 0x0C00)
#define GPIOE_BASE       (GPIO_BASE + 0x1000)
#define GPIOF_BASE       (GPIO_BASE + 0x1400)
#define GPIOG_BASE       (GPIO_BASE + 0x1800)
#define GPIOH_BASE       (GPIO_BASE + 0x1C00)
#define GPIOI_BASE       (GPIO_BASE + 0x2000)

/* GPIO Peripheral Declarations */
#define GPIOA            ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB            ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC            ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD            ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE            ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF            ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG            ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH            ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI            ((GPIO_TypeDef *) GPIOI_BASE)

#define GPIOA_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<0)
#define GPIOB_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<1)
#define GPIOC_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<2)
#define GPIOD_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<3)
#define GPIOE_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<4)
#define GPIOH_CLK_EN()   (RCC_Config->AHB2ENR |= 1<<5)

#define DMA1_CLOCK()   (RCC_Config->AHB1ENR |= 1<<0)
#define USART2_CLOCK()  (RCC_Config->APB1ENR1 |= 1<<17)


typedef struct {
  __IO uint32_t CR;           // 0x00: Clock control register
  __IO uint32_t ICSCR;        // 0x04: Internal clock sources calibration register
  __IO uint32_t CFGR;         // 0x08: Clock configuration register
  __IO uint32_t PLLCFGR;      // 0x0C: PLL configuration register
  __IO uint32_t PLLSAI1CFGR;  // 0x10: PLL SAI1 configuration register
  __IO uint32_t PLLSAI2CFGR;  // 0x14: PLL SAI2 configuration register
  __IO uint32_t CIER;         // 0x18: Clock interrupt enable register
  __IO uint32_t CIFR;         // 0x1C: Clock interrupt flag register
  __IO uint32_t CICR;         // 0x20: Clock interrupt clear register
  uint32_t RESERVED0;         // 0x24
  __IO uint32_t AHB1RSTR;     // 0x28: AHB1 peripheral reset register
  __IO uint32_t AHB2RSTR;     // 0x2C: AHB2 peripheral reset register
  __IO uint32_t AHB3RSTR;     // 0x30: AHB3 peripheral reset register
  uint32_t RESERVED1;         // 0x34
  __IO uint32_t APB1RSTR1;    // 0x38: APB1 peripheral reset register 1
  __IO uint32_t APB1RSTR2;    // 0x3C: APB1 peripheral reset register 2
  __IO uint32_t APB2RSTR;     // 0x40: APB2 peripheral reset register
  uint32_t RESERVED2;         // 0x44
  __IO uint32_t AHB1ENR;      // 0x48: AHB1 peripheral clock enable register
  __IO uint32_t AHB2ENR;      // 0x4C: AHB2 peripheral clock enable register
  __IO uint32_t AHB3ENR;      // 0x50: AHB3 peripheral clock enable register
  uint32_t RESERVED3;         // 0x54
  __IO uint32_t APB1ENR1;     // 0x58: APB1 peripheral clock enable register 1
  __IO uint32_t APB1ENR2;     // 0x5C: APB1 peripheral clock enable register 2
  __IO uint32_t APB2ENR;      // 0x60: APB2 peripheral clock enable register
  uint32_t RESERVED4;         // 0x64
  __IO uint32_t AHB1SMENR;    // 0x68: AHB1 peripheral clock enable in sleep mode
  __IO uint32_t AHB2SMENR;    // 0x6C: AHB2 peripheral clock enable in sleep mode
  __IO uint32_t AHB3SMENR;    // 0x70: AHB3 peripheral clock enable in sleep mode
  uint32_t RESERVED5;         // 0x74
  __IO uint32_t APB1SMENR1;   // 0x78: APB1 peripheral clock enable in sleep mode 1
  __IO uint32_t APB1SMENR2;   // 0x7C: APB1 peripheral clock enable in sleep mode 2
  __IO uint32_t APB2SMENR;    // 0x80: APB2 peripheral clock enable in sleep mode
  uint32_t RESERVED6;         // 0x84
  __IO uint32_t CCIPR;        // 0x88: Peripherals independent clock configuration register
  uint32_t RESERVED7;         // 0x8C
  __IO uint32_t BDCR;         // 0x90: Backup domain control register
  __IO uint32_t CSR;          // 0x94: Control/status register
  __IO uint32_t CRRCR;        // 0x98: Clock recovery RC register
  __IO uint32_t CCIPR2;       // 0x9C: Peripherals independent clock config reg 2
} RCC_reg;

typedef struct
{
    volatile uint32_t CR1;    // Control register 1        (0x00)
    volatile uint32_t CR2;    // Control register 2        (0x04)
    volatile uint32_t CR3;    // Control register 3        (0x08)
    volatile uint32_t BRR;    // Baud rate register        (0x0C)
    volatile uint32_t GTPR;   // Guard time & prescaler    (0x10)
    volatile uint32_t RTOR;   // Receiver timeout          (0x14)
    volatile uint32_t RQR;    // Request register          (0x18)
    volatile uint32_t ISR;    // Interrupt & status        (0x1C)
    volatile uint32_t ICR;    // Interrupt clear           (0x20)
    volatile uint32_t RDR;    // Receive data              (0x24)
    volatile uint32_t TDR;    // Transmit data             (0x28)
    volatile uint32_t PRSC;
} USART_TypeDef;


#define __IO volatile


typedef struct
{
    volatile uint32_t CCR;      // Channel Configuration Register
    volatile uint32_t CNDTR;    // Number of Data Register
    volatile uint32_t CPAR;     // Peripheral Address Register
    volatile uint32_t CMAR;     // Memory Address Register
    volatile uint32_t RESERVED;
}DMA_Channel_TypeDef;

typedef struct
{
    volatile uint32_t ISR;      // Interrupt Status Register
    volatile uint32_t IFCR;     // Interrupt Flag Clear Register
	DMA_Channel_TypeDef Channel1;
	DMA_Channel_TypeDef Channel2;
	DMA_Channel_TypeDef Channel3;
	DMA_Channel_TypeDef Channel4;
	DMA_Channel_TypeDef Channel5;
	DMA_Channel_TypeDef Channel6;
	DMA_Channel_TypeDef Channel7;
	volatile uint32_t RESERVED[5];
	volatile uint32_t  DMA_CSELR;
}Channel_struct;


/* Base Address for GPIO Peripheral Block */
#define GPIO_BASE        0x48000000UL
/*DMA1 Base Register*/
#define DMA1_BASE_ADDR   0x40020000UL
#define DMA2_BASE_ADDR   0x40020400UL

#define DMA1 ((Channel_struct*)DMA1_BASE_ADDR)
#define DMA2 ((Channel_struct*)DMA2_BASE_ADDR)


#define USART1_BASE   0x40013800UL
#define USART2_BASE   0x40004400UL
#define USART3_BASE   0x40004800UL
#define UART4_BASE    0x40004C00UL
#define UART5_BASE    0x40005000UL

#define USART1      (USART_TypeDef*) USART1_BASE
#define USART2      (USART_TypeDef*) USART2_BASE
#define USART3      (USART_TypeDef*) USART3_BASE
#define UART4       (USART_TypeDef*) UART4_BASE
#define UART5       (USART_TypeDef*) UART5_BASE


#define RCC_Config        ((RCC_reg*)RCC_BASE)
#define RCC_BASE                   0x40021000U



#endif /* STM32_H_ */
