/*
 * stm32.c
 *
 *  Created on: Apr 18, 2026
 *      Author: 16022
 */


#include <stm32.h>
#include <stdint.h>
#include <register.h>

#define NULL (void*) 0x0
void gpio_init(GPIO_Port_t port,GPIO_Pin_t pin,GPIO_Mode_t mode,GPIO_OType_t otype,GPIO_Speed_t speed,GPIO_PuPd_t pupd, GPIO_state state,uint16_t * x, GPIO_AF_t afv)
{
	// Assigning the address to GPIO pin
    GPIO_TypeDef* gpio = NULL;

    // Port selection
    if (port == GPIO_PORT_A)      gpio = GPIOA;
    else if (port == GPIO_PORT_B) gpio = GPIOB;
    else if (port == GPIO_PORT_C) gpio = GPIOC;
    else if (port == GPIO_PORT_D) gpio = GPIOD;
    else if (port == GPIO_PORT_E) gpio = GPIOE;
    else if (port == GPIO_PORT_F) gpio = GPIOF;
    else if (port == GPIO_PORT_G) gpio = GPIOG;
    else if (port == GPIO_PORT_H) gpio = GPIOH;
    else if (port == GPIO_PORT_I) gpio = GPIOI;
    else return; // invalid port → exit early

    /* ---------------- MODE ---------------- */
    gpio->MODER &= ~(3U << (pin * 2U));   // clear bits

    if (mode == GPIO_MODE_OUTPUT)
        gpio->MODER |= (1U << (pin * 2U));
    else if (mode == GPIO_MODE_ALT)
        gpio->MODER |= (2U << (pin * 2U));
    else if (mode == GPIO_MODE_ANALOG)
        gpio->MODER |= (3U << (pin * 2U));
    // input = 00 → already cleared


    /* ---------------- OUTPUT TYPE ---------------- */
    gpio->OTYPER &= ~(1U << pin); // clear

    if (otype == GPIO_OTYPE_OD)
        gpio->OTYPER |= (1U << pin);
    // push-pull = 0 → already cleared


    /* ---------------- SPEED ---------------- */
    gpio->OSPEEDR &= ~(3U << (pin * 2U));

    if (speed == GPIO_SPEED_MEDIUM)
        gpio->OSPEEDR |= (1U << (pin * 2U));
    else if (speed == GPIO_SPEED_HIGH)
        gpio->OSPEEDR |= (2U << (pin * 2U));
    else if (speed == GPIO_SPEED_VERY_HIGH)
        gpio->OSPEEDR |= (3U << (pin * 2U));
    // low = 00


    /* ---------------- PULL-UP / PULL-DOWN ---------------- */
    gpio->PUPDR &= ~(3U << (pin * 2U));     // No Pull Up

    if (pupd == GPIO_PULL_UP)
        gpio->PUPDR |= (1U << (pin * 2U));  //  Pull-down
    else if (pupd == GPIO_PULL_DOWN)
        gpio->PUPDR |= (2U << (pin * 2U));   // Pull- up


    /* ALTERNATE FUNCTION */
       if (mode == GPIO_MODE_ALT) {
           if (pin <= 7U) {
               gpio->AFR[0] &= ~(15U << (pin * 4U));
               gpio->AFR[0] |=  ((uint32_t)afv << (pin * 4U));
           } else {
               gpio->AFR[1] &= ~(15U << ((pin - 8U) * 4U));
               gpio->AFR[1] |=  ((uint32_t)afv << ((pin - 8U) * 4U));
           }
       }

       if (x != NULL) {
              if (state == W_ODR) {
                  if (*x)
                    gpio->ODR |= (1U << pin);
                  else
                      gpio->ODR &= ~(1U << pin);
              }
              else if (state == R_ODR) {
                  *x = (uint16_t)((gpio->ODR >> pin) & 0x1U);
              }
              else if (state == R_IDR) {
                  *x = (uint16_t)((gpio->IDR >> pin) & 0x1U);
              }
          }
}


