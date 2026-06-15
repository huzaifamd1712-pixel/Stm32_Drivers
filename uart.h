/*
 * uart.h
 *
 *  Created on: Apr 24, 2026
 *      Author: 16022
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <dma.h>
#include <uart.h>
typedef enum{
	USART_2= 0,
	USART_3
}Usart_type;

void USART_Init(Usart_type utype, uint32_t pclk, uint32_t baud, uint16_t DMA_TX);
void USART_WriteBuffer(Usart_type utype,uint8_t *data, uint32_t len);
void USART_dma(Usart_type utype, Channel_struct *DMA);

#define USART_CR1_UE        (1U << 0)    // USART enable
#define USART_CR1_RE        (1U << 2)    // Receiver enable
#define USART_CR1_TE        (1U << 3)    // Transmitter enable

#define USART_CR1_PCE       (1U << 10)   // Parity control enable

#define USART_CR1_M0        (1U << 12)   // Word length bit 0
#define USART_CR1_M1        (1U << 28)   // Word length bit 1

#define USART_CR1_FIFOEN    (1U << 29)   // FIFO enable


#define USART_CR2_STOP      (3U << 12)   // STOP bits mask


#define USART_STOP_1        (0U << 12)
#define USART_STOP_0_5      (1U << 12)
#define USART_STOP_2        (2U << 12)
#define USART_STOP_1_5      (3U << 12)

#define USART_CR3_DMAT      (1U << 7)
#define USART_CR3_DMAR      (1U << 6)

/* FIFO threshold config positions */
#define USART_CR3_TXFTCFG_Pos   25
#define USART_CR3_RXFTCFG_Pos   29

/* Masks */
#define USART_CR3_TXFTCFG   (7U << USART_CR3_TXFTCFG_Pos)
#define USART_CR3_RXFTCFG   (7U << USART_CR3_RXFTCFG_Pos)

/* Individual bits for convenience */
#define USART_CR3_TXFTCFG_0 (1U << (USART_CR3_TXFTCFG_Pos + 0))
#define USART_CR3_TXFTCFG_1 (1U << (USART_CR3_TXFTCFG_Pos + 1))
#define USART_CR3_TXFTCFG_2 (1U << (USART_CR3_TXFTCFG_Pos + 2))

#define USART_CR3_RXFTCFG_0 (1U << (USART_CR3_RXFTCFG_Pos + 0))
#define USART_CR3_RXFTCFG_1 (1U << (USART_CR3_RXFTCFG_Pos + 1))
#define USART_CR3_RXFTCFG_2 (1U << (USART_CR3_RXFTCFG_Pos + 2))

/* FIFO interrupt enable (we keep these OFF) */
#define USART_CR3_TXFTIE    (1U << 23)
#define USART_CR3_RXFTIE    (1U << 27)

#define USART_ISR_TXE       (1U << 7)    // TX empty (non-FIFO)
#define USART_ISR_TC        (1U << 6)    // Transmission complete

#define USART_ISR_RXNE      (1U << 5)    // RX not empty (non-FIFO)

/* FIFO mode flags */
#define USART_ISR_TXFNF     (1U << 7)    // TX FIFO not full
// #define USART_ISR_RXFNE     (1U << 5)    // RX FIFO not empty

#define USART_ISR_TEACK     (1U << 21)
//  #define USART_ISR_REACK     (1U << 22)

#define USART_FIFO_THRESHOLD_1_8   (0U << USART_CR3_TXFTCFG_Pos)
#define USART_FIFO_THRESHOLD_1_4   (1U << USART_CR3_TXFTCFG_Pos)
#define USART_FIFO_THRESHOLD_1_2   (2U << USART_CR3_TXFTCFG_Pos)
#define USART_FIFO_THRESHOLD_3_4   (3U << USART_CR3_TXFTCFG_Pos)
#define USART_FIFO_THRESHOLD_7_8   (4U << USART_CR3_TXFTCFG_Pos)
#define USART_FIFO_THRESHOLD_FULL  (5U << USART_CR3_TXFTCFG_Pos)






#endif /* UART_H_ */
