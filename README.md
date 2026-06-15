# Stm32_Drivers
# STM32 DMA Driver

## Overview

This repository demonstrates my understanding of Embedded C programming and low-level peripheral access on STM32 microcontrollers. The project focuses on creating register-mapped structures for the DMA peripheral and accessing hardware registers through pointers.

The implementation was developed by studying the STM32 Reference Manual and manually mapping the DMA register layout into C structures. This approach helped me gain a deeper understanding of memory-mapped I/O, register-level programming, and peripheral architecture.

## Hardware Used

* STM32L432KC Nucleo Board
* PuTTY Serial Terminal

## Project Description

In this project, I used the STM32L432KC development board to transmit characters to a serial terminal using DMA. The transfer status is monitored using the polling method, where the DMA flag registers are continuously checked until the transfer is complete.

The DMA register definitions were implemented using C structures and accessed through pointers to the peripheral base address. Particular attention was given to matching the memory layout specified in the STM32 Reference Manual, including reserved memory regions and register offsets.

## Concepts Demonstrated

* Embedded C Programming
* Memory-Mapped I/O
* Register-Level Programming
* DMA Configuration
* Pointer-Based Peripheral Access
* Polling Method
* Register Structure Design
* STM32 Peripheral Mapping

## Development Notes

During development, I used ChatGPT primarily for arithmetic calculations involving hexadecimal register addresses and offset verification. This helped speed up calculations when working with register maps and memory layouts described in the STM32 Reference Manual.

However, the organization and design of the peripheral structures were not generated directly from AI suggestions. The register layouts and structure definitions were created and verified through my own analysis of the STM32 Reference Manual. In several cases, AI-generated examples followed the standard layouts commonly found in STM32 vendor libraries, whereas this project focuses on understanding and constructing the register mappings manually from the hardware documentation.

## Learning Outcomes

Through this project, I gained practical experience in:

* Reading and interpreting STM32 Reference Manuals
* Creating register-mapped peripheral structures
* Understanding DMA memory organization
* Working with pointers for hardware register access
* Performing low-level peripheral configuration without relying on high-level libraries
* Debugging and validating register layouts against hardware documentation

## References

* STM32L432 Reference Manual (RM0394)
* STM32L432 Datasheet
* STM32 DMA Peripheral Documentation
