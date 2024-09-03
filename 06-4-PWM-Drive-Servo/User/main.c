#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

uint8_t KeyNum;
float Angle;

int main()
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	OLED_ShowString(2,1,"Angle:");
	
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 2)
		{
			Angle += 30;
			if(Angle > 180)
			{
				Angle = 0;
			}
			Servo_SetAngle(Angle);
			OLED_ShowNum(2,7,Angle,3);
		}
	}
}
