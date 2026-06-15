#include <stdint.h>
#include <stm32.h>
#include <register.h>
#include <uart.h>
#include <string.h>
#include "dma.h"
#define NULL ((void *)0)
uint8_t string_lenght(char*x);

int main(void)
{
	/* Enabling GPIOA Clk*/
	GPIOA_CLK_EN();
	/*Defining my string*/
	char x[]="Huzaifa is chutiya";
	/* Setting Up the ALt functio for the GPOIA and GPIOB*/
	gpio_init(GPIO_PORT_A,GPIO_PIN_2,GPIO_MODE_ALT,GPIO_OTYPE_PP,GPIO_SPEED_MEDIUM,GPIO_NO_PUPD,W_ODR,NULL,GPIO_AF7);
	gpio_init(GPIO_PORT_A,GPIO_PIN_3,GPIO_MODE_ALT,GPIO_OTYPE_PP,GPIO_SPEED_MEDIUM,GPIO_NO_PUPD,W_ODR,NULL,GPIO_AF7);
	/* Enabling Usart2_clock*/
	USART2_CLOCK();
	/* USARt Initilisation*/
	USART_Init(USART_2, 4000000, 9600,1);
    DMA1_CLOCK ();
    /*Usart_2 TDR 0x28 +0x40004400UL */
    DMA1_Channel1_Config(DMA1,DMA_CH7,2,0x40004428UL,(uint32_t)x,string_lenght(x),DMA_CCR_NOMEM2MEM|DMA_CCR_PL_MEDIUM|DMA_CCR_MSIZE_8BIT|DMA_CCR_PSIZE_8BIT|DMA_CCR_DIR|DMA_CCR_MINC|DMA_CCR_NPINC);

    USART_dma(USART_2, DMA1);

	return 0;
 }

uint8_t string_lenght(char*x)
{
	uint8_t i=0;
	while(x[i]!= '\0'){
		i++;
	}
	return i;
}


