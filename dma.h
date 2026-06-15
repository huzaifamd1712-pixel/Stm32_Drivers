/*
 * dma.h
 *
 *  Created on: May 11, 2026
 *      Author: 16022
 */

#ifndef DMA_H_
#define DMA_H_

/* DMA CCR Register Bit Definitions */
#include "stm32.h"
#include "stdint.h"
/* Bit 0 : Channel Enable */
#define DMA_CCR_EN            (1U << 0)

/* Bit 1 : Transfer Complete Interrupt Enable */
#define DMA_CCR_TCIE          (1U << 1)

/* Bit 2 : Half Transfer Interrupt Enable */
#define DMA_CCR_HTIE          (1U << 2)

/* Bit 3 : Transfer Error Interrupt Enable */
#define DMA_CCR_TEIE          (1U << 3)

/* Bit 4 : Data Transfer Direction
   0 = Peripheral -> Memory
   1 = Memory -> Peripheral
*/
#define DMA_CCR_DIR           (1U << 4)

/* Bit 5 : Circular Mode Enable */
#define DMA_CCR_CIRC          (1U << 5)

/* Bit 6 : Peripheral Increment Mode */
#define DMA_CCR_NPINC          (0U << 6)

/* Bit 7 : Memory Increment Mode */
#define DMA_CCR_MINC          (1U << 7)

/* Bits 8-9 : Peripheral Size */
#define DMA_CCR_PSIZE_8BIT    (0U << 8)
#define DMA_CCR_PSIZE_16BIT   (1U << 8)
#define DMA_CCR_PSIZE_32BIT   (2U << 8)

/* Bits 10-11 : Memory Size */
#define DMA_CCR_MSIZE_8BIT    (0U << 10)
#define DMA_CCR_MSIZE_16BIT   (1U << 10)
#define DMA_CCR_MSIZE_32BIT   (2U << 10)
#define DMA_CCR_MSIZE_RESERVED  (3U << 10)


/* Bits 12-13 : Channel Priority */
#define DMA_CCR_PL_LOW        (0U << 12)
#define DMA_CCR_PL_MEDIUM     (1U << 12)
#define DMA_CCR_PL_HIGH       (2U << 12)
#define DMA_CCR_PL_VERY_HIGH  (3U << 12)

/* Bit 14 : Memory-to-Memory Mode */
#define DMA_CCR_MEM2MEM       (1U << 14)
#define DMA_CCR_NOMEM2MEM       (0U << 14)


/* =========================================================
   DMA ISR REGISTER FLAGS
   ========================================================= */

/* Channel 1 */
#define DMA_ISR_GIF1      (1U << 0)
#define DMA_ISR_TCIF1     (1U << 1)
#define DMA_ISR_HTIF1     (1U << 2)
#define DMA_ISR_TEIF1     (1U << 3)

/* Channel 2 */
#define DMA_ISR_GIF2      (1U << 4)
#define DMA_ISR_TCIF2     (1U << 5)
#define DMA_ISR_HTIF2     (1U << 6)
#define DMA_ISR_TEIF2     (1U << 7)

/* Channel 3 */
#define DMA_ISR_GIF3      (1U << 8)
#define DMA_ISR_TCIF3     (1U << 9)
#define DMA_ISR_HTIF3     (1U << 10)
#define DMA_ISR_TEIF3     (1U << 11)

/* Channel 4 */
#define DMA_ISR_GIF4      (1U << 12)
#define DMA_ISR_TCIF4     (1U << 13)
#define DMA_ISR_HTIF4     (1U << 14)
#define DMA_ISR_TEIF4     (1U << 15)

/* Channel 5 */
#define DMA_ISR_GIF5      (1U << 16)
#define DMA_ISR_TCIF5     (1U << 17)
#define DMA_ISR_HTIF5     (1U << 18)
#define DMA_ISR_TEIF5     (1U << 19)

/* Channel 6 */
#define DMA_ISR_GIF6      (1U << 20)
#define DMA_ISR_TCIF6     (1U << 21)
#define DMA_ISR_HTIF6     (1U << 22)
#define DMA_ISR_TEIF6     (1U << 23)

/* Channel 7 */
#define DMA_ISR_GIF7      (1U << 24)
#define DMA_ISR_TCIF7     (1U << 25)
#define DMA_ISR_HTIF7     (1U << 26)
#define DMA_ISR_TEIF7     (1U << 27)

/* =========================================================
   DMA IFCR REGISTER FLAGS
   ========================================================= */

/* Channel 1 */
#define DMA_IFCR_CGIF1     (1U << 0)
#define DMA_IFCR_CTCIF1    (1U << 1)
#define DMA_IFCR_CHTIF1    (1U << 2)
#define DMA_IFCR_CTEIF1    (1U << 3)

/* Channel 2 */
#define DMA_IFCR_CGIF2     (1U << 4)
#define DMA_IFCR_CTCIF2    (1U << 5)
#define DMA_IFCR_CHTIF2    (1U << 6)
#define DMA_IFCR_CTEIF2    (1U << 7)

/* Channel 3 */
#define DMA_IFCR_CGIF3     (1U << 8)
#define DMA_IFCR_CTCIF3    (1U << 9)
#define DMA_IFCR_CHTIF3    (1U << 10)
#define DMA_IFCR_CTEIF3    (1U << 11)

/* Channel 4 */
#define DMA_IFCR_CGIF4     (1U << 12)
#define DMA_IFCR_CTCIF4    (1U << 13)
#define DMA_IFCR_CHTIF4    (1U << 14)
#define DMA_IFCR_CTEIF4    (1U << 15)

/* Channel 5 */
#define DMA_IFCR_CGIF5     (1U << 16)
#define DMA_IFCR_CTCIF5    (1U << 17)
#define DMA_IFCR_CHTIF5    (1U << 18)
#define DMA_IFCR_CTEIF5    (1U << 19)

/* Channel 6 */
#define DMA_IFCR_CGIF6     (1U << 20)
#define DMA_IFCR_CTCIF6    (1U << 21)
#define DMA_IFCR_CHTIF6    (1U << 22)
#define DMA_IFCR_CTEIF6    (1U << 23)

/* Channel 7 */
#define DMA_IFCR_CGIF7     (1U << 24)
#define DMA_IFCR_CTCIF7    (1U << 25)
#define DMA_IFCR_CHTIF7    (1U << 26)
#define DMA_IFCR_CTEIF7    (1U << 27)

typedef enum {
    DMA_CH1 = 1,
    DMA_CH2,
    DMA_CH3,
    DMA_CH4,
    DMA_CH5,
    DMA_CH6,
    DMA_CH7
} DMA_Channel_Num;

void DMA1_Channel1_Config(Channel_struct* DMA,DMA_Channel_Num ch,uint32_t channel_value,uint32_t peripheral_address,
                          uint32_t memory_address,
                          uint16_t data_count,
                          uint32_t dma_config);
#endif /* DMA_H_ */
