#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "RotaryEncoder.h"

int16_t Speed;

int main()
{
	OLED_Init();
	Timer_Init();
	RotaryEncoder_Init();
	OLED_ShowString(1, 1,"Num:");
	while(1)
	{
		OLED_ShowSignedNum(1,5,Speed,4);
		//Delay_ms(1000);//由于是人转，比较慢，所以是用1s
	}
}
