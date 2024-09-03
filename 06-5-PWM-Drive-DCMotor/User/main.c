#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DCMotor.h"
#include "Key.h"

uint8_t KeyNum;
int8_t Speed;

int main()
{
	OLED_Init();
	DCMotor_Init();
	Key_Init();
	OLED_ShowString(2,1,"Speed:");
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 2)
		{
			Speed += 20;
			if(Speed > 100)
				Speed = 0;
			DCMotor_SetSpeed(Speed);
		}
		OLED_ShowNum(2,7,Speed,3);
	}
}
