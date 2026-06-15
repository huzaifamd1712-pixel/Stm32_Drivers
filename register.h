/*
 * register.h
 *
 *  Created on: Apr 17, 2026
 *      Author: 16022
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include "stm32.h"
typedef enum
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
	GPIO_PORT_F,
    GPIO_PORT_G,
	GPIO_PORT_H,
	GPIO_PORT_I
} GPIO_Port_t;

typedef enum
{
    GPIO_PIN_0 = 0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} GPIO_Pin_t;

typedef enum
{
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALT,
    GPIO_MODE_ANALOG
} GPIO_Mode_t;

typedef enum
{
    GPIO_OTYPE_PP = 0,   // Push-pull
    GPIO_OTYPE_OD        // Open-drain (1)
} GPIO_OType_t;

typedef enum
{
    GPIO_SPEED_LOW = 0,      // 00
    GPIO_SPEED_MEDIUM,       // 01
    GPIO_SPEED_HIGH,         // 10
    GPIO_SPEED_VERY_HIGH     // 11
} GPIO_Speed_t;

typedef enum
{
    GPIO_NO_PUPD = 0,   // 00
    GPIO_PULL_UP,       // 01
    GPIO_PULL_DOWN      // 10
} GPIO_PuPd_t;

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH
} GPIO_State_t;

typedef enum
{
    GPIO_AF0 = 0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15
} GPIO_AF_t;

typedef enum
{
	W_ODR,
	R_ODR,
	R_IDR
}GPIO_state;



/*
 * Note the clock that we use for GPIO peripheral is connected to AHB , APB Bus and last these are connected to Sysclk (
 * Default value of System clk is 4mhz because it connected to MSI
 * */
void clock_init(GPIO_Port_t ,uint16_t);

/*This function is use to initialize the GPIO Ports*/
void gpio_init(GPIO_Port_t,GPIO_Pin_t,GPIO_Mode_t,GPIO_OType_t,GPIO_Speed_t,GPIO_PuPd_t,GPIO_state,uint16_t *,GPIO_AF_t);



#endif /* REGISTER_H_ */
