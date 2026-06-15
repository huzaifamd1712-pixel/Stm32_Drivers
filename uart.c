/*
 * uart.c
 *
 *  Created on: Apr 24, 2026
 *      Author: 16022
 */
#include "uart.h"
#include "stm32.h"
#include "register.h"
#include "dma.h"
#define NULL (void*) 0x0

void USART_Init(Usart_type utype, uint32_t pclk, uint32_t baud, uint16_t DMA_TX)
{
    USART_TypeDef *USARTx = NULL;

    if (utype == USART_2)
    {
        USARTx = USART2;
    }

    else if (utype == USART_3)
    {
        USARTx = USART3;
    }

    else
    {
        return;
    }

#ifdef USART_CR1_UE
    USARTx->CR1 &= ~USART_CR1_UE;
#endif

    USARTx->CR1 = 0U;
    USARTx->CR2 = 0U;
    USARTx->CR3 = 0U;

#ifdef USART_CR1_M1
    USARTx->CR1 &= ~USART_CR1_M1;
#endif

#ifdef USART_CR1_M0
    USARTx->CR1 &= ~USART_CR1_M0;
#endif

#ifdef USART_CR1_PCE
    USARTx->CR1 &= ~USART_CR1_PCE;
#endif
    /* Setting up the BAUD rate*/
    USARTx->BRR = pclk / baud;

#ifdef USART_CR2_STOP
    USARTx->CR2 &= ~USART_CR2_STOP;
#endif

    /*Enabling the FIFO*/
#ifdef USART_CR1_FIFOEN
    USARTx->CR1 |= USART_CR1_FIFOEN;
#endif

#ifdef USART_CR3_TXFTCFG
    USARTx->CR3 &= ~USART_CR3_TXFTCFG;
    USARTx->CR3 |= (0x0U << USART_CR3_TXFTCFG_Pos);
#endif
   /**/
#ifdef USART_CR3_RXFTCFG
    USARTx->CR3 &= ~USART_CR3_RXFTCFG;
    USARTx->CR3 |= (0x0U << USART_CR3_RXFTCFG_Pos);
#endif

#ifdef USART_CR3_TXFTIE
    USARTx->CR3 &= ~USART_CR3_TXFTIE;
#endif

#ifdef USART_CR3_RXFTIE
    USARTx->CR3 &= ~USART_CR3_RXFTIE;
#endif

#ifdef USART_CR3_DMAT

    if (DMA_TX != 0U)
    {
        USARTx->CR3 |= USART_CR3_DMAT;
    }

    if (DMA_TX == 0U)
    {
        USARTx->CR3 &= ~USART_CR3_DMAT;
    }

#endif

#ifdef USART_CR3_DMAR
    USARTx->CR3 &= ~USART_CR3_DMAR;
#endif

#ifdef USART_CR1_TE
    USARTx->CR1 |= USART_CR1_TE;
#endif

#ifdef USART_CR1_RE
    USARTx->CR1 |= USART_CR1_RE;
#endif

#ifdef USART_CR1_UE
    USARTx->CR1 |= USART_CR1_UE;
#endif

#ifdef USART_ISR_TEACK
    while ((USARTx->ISR & USART_ISR_TEACK) == 0U)
    {
    }
#endif

#ifdef USART_ISR_REACK
    while ((USARTx->ISR & USART_ISR_REACK) == 0U)
    {
    }
#endif
}


void USART_WriteBuffer(Usart_type utype,uint8_t *data, uint32_t len)
{
	USART_TypeDef* USARTx= NULL;
    uint16_t i=0;
	 if (utype == USART_2)
	        USARTx = USART2;
    else if (utype == USART_3)
	        USARTx = USART3;

    while (i < len)
    {
#ifdef USART_ISR_TXFNF
        /* FIFO mode: write whenever TX FIFO is not full */
        while ((USARTx->ISR & USART_ISR_TXFNF) == 0U) {}
#else
        /* Non-FIFO fallback */
        while ((USARTx->ISR & USART_ISR_TXE) == 0U) {}
#endif

        USARTx->TDR = data[i++];
    }

    /* Wait until the very last frame is fully transmitted */
    while ((USARTx->ISR & USART_ISR_TC) == 0U) {}
}

void USART_dma(Usart_type utype, Channel_struct *DMA)
{
    USART_TypeDef *USARTx = NULL;

    if (utype == USART_2)
    {
        USARTx = USART2;
    }
    else if (utype == USART_3)
    {
        USARTx = USART3;
    }
    else
    {
        return;
    }

    /* Wait until DMA channel 7 transfer complete flag is set */
    while ((DMA->ISR & DMA_ISR_TCIF7) == 0U)
    {
    }

    /* Clear all DMA channel 7 flags */
    DMA->IFCR = DMA_IFCR_CGIF7;

#ifdef USART_CR3_DMAT
    USARTx->CR3 &= ~USART_CR3_DMAT;
#endif

#ifdef USART_ISR_TC
    while ((USARTx->ISR & USART_ISR_TC) == 0U)
    {
    }
#endif
}
