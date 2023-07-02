/*
 * main.c
 *
 *  Created on: 1 Jul 2023
 *      Author: george yaccoup
 */
#include "DIO_priv.h"
#include "DIO_int.h"
#include "stdTypes.h"
#include <util/delay.h>
#define SS1_display(num) DIO_GROUP_C=(DIO_GROUP_C&0xF0)|num
#define SS2_display(num) DIO_GROUP_C=(DIO_GROUP_C&0x0F)|(num<<4)

int main() {
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_0, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_1, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_2, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_3, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_4, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_5, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_6, DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_C, DIO_PIN_7, DIO_OUTPUT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_0, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_1, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_2, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_3, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_4, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_5, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_6, DIO_FLOAT);
	DIO_vidSetPinValue(DIO_GROUP_C, DIO_PIN_7, DIO_FLOAT);
	u8 SSG_RightDigit = 0;
	u8 SSG_LifrDigit = 0;
	u8 SSG_DisplayNum = 0;
	while (1) {
		if (SSG_DisplayNum < 10) {
			SS1_display(0);
			SS2_display(SSG_DisplayNum);
		}
		else {
			SSG_LifrDigit = SSG_DisplayNum % 10;
			SSG_RightDigit = SSG_DisplayNum / 10;
			SS1_display(SSG_LifrDigit);
			SS2_display(SSG_RightDigit);
		}
		SSG_DisplayNum++;
		_delay_ms(500);
	}
}

