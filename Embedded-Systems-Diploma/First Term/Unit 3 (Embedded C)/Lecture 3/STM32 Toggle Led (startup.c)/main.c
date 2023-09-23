/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *((volatile uint32_t*)(RCC_BASE+0x18))
#define GPIOA_CRH *((volatile uint32_t*)(GPIOA_BASE+0x04))
#define GPIOA_ODR *((volatile uint32_t*)(GPIOA_BASE+0x0c))

typedef union {
	volatile uint32_t all_fields;
	struct {
		volatile uint32_t pin_0:1;
		volatile uint32_t pin_1:1;
		volatile uint32_t pin_2:1;
		volatile uint32_t pin_3:1;
		volatile uint32_t pin_4:1;
		volatile uint32_t pin_5:1;
		volatile uint32_t pin_6:1;
		volatile uint32_t pin_7:1;
		volatile uint32_t pin_8:1;
		volatile uint32_t pin_9:1;
		volatile uint32_t pin_10:1;
		volatile uint32_t pin_11:1;
		volatile uint32_t pin_12:1;
		volatile uint32_t pin_13:1;
		volatile uint32_t pin_14:1;
		volatile uint32_t pin_15:1;
		volatile uint32_t pin_16:1;
		volatile uint32_t pin_17:1;
		volatile uint32_t pin_18:1;
		volatile uint32_t pin_19:1;
		volatile uint32_t pin_20:1;
		volatile uint32_t pin_21:1;
		volatile uint32_t pin_22:1;
		volatile uint32_t pin_23:1;
		volatile uint32_t pin_24:1;
		volatile uint32_t pin_25:1;
		volatile uint32_t pin_26:1;
		volatile uint32_t pin_27:1;
		volatile uint32_t pin_28:1;
		volatile uint32_t pin_29:1;
		volatile uint32_t pin_30:1;
		volatile uint32_t pin_31:1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE+0x0c);
uint32_t global_var[3]={1,2,3};
uint32_t const ro_var[3]={1,2,3};
uint32_t bss_var[3];

int main(void)
{
	int i =0;
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while(1)
	{
		GPIOA_ODR |= (1<<13);
		for(i=0;i<5000;i++);
		GPIOA_ODR &= ~(1<<13);
		for(i=0;i<5000;i++);
	}
	return 0;
}
