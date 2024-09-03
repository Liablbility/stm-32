#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"

int main()
{
	unsigned char Key_Num;
	LED_Init();
	Key_Init();
	Buzzer_Init();
	while(1)
	{
		//GPIO_Write(GPIOA, ~0x0001);// 0000 0000 0000 0001
		//Key_Num = Key_GetNum();
		//if(Key_Num == 1)
		//	LED_Turn(1);
		//if(Key_Num == 2)
		//	Buzzer_Turn();
		if(LightSensor_Get() == 1)
			Buzzer_On();
		else
			Buzzer_Off();
	}
}
