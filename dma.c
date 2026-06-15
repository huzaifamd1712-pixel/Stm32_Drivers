/*
 * dma.c
 *
 *  Created on: May 11, 2026
 *      Author: 16022
 */


#include "dma.h"
#include "stm32.h"
#include "stdint.h"

DMA_Channel_TypeDef* DMA_GetChannel(Channel_struct* DMA, DMA_Channel_Num ch)
{
    switch (ch)
    {
        case DMA_CH1: return &DMA->Channel1;
        case DMA_CH2: return &DMA->Channel2;
        case DMA_CH3: return &DMA->Channel3;
        case DMA_CH4: return &DMA->Channel4;
        case DMA_CH5: return &DMA->Channel5;
        case DMA_CH6: return &DMA->Channel6;
        case DMA_CH7: return &DMA->Channel7;
        default:      return 0;
    }
}


void DMA1_Channel1_Config(Channel_struct* DMA,
                DMA_Channel_Num ch,
				uint32_t channel_value,
                uint32_t peripheral_address,
                uint32_t memory_address,
                uint16_t data_count,
                uint32_t dma_config)
{

    DMA_Channel_TypeDef* Channel = DMA_GetChannel(DMA, ch);

    if (Channel == 0)
        return;

    Channel->CCR &= ~DMA_CCR_EN;

    Channel->CPAR = peripheral_address;
    Channel->CMAR = memory_address;
    Channel->CNDTR = data_count;

    Channel->CCR  = dma_config;

    DMA -> DMA_CSELR  &= ~(0xF << (4*(ch-1)));
    DMA -> DMA_CSELR  |=  (channel_value << (4*(ch-1)));

    Channel->CCR |= DMA_CCR_EN;
}
