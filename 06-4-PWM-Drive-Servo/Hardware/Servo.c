#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle(float Angle)
{
	/*
	0 - 500
	180 - 2500
	所以x度 为 x/180 * 2000 + 500
	*/
	PWM_SetCompare2(Angle/180*2000 + 500);
	
}

