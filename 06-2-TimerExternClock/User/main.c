#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Num;

int main()
{
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1, 1,"Num:");
	OLED_ShowString(1, 1,"Cnt:");
	while(1)
	{
		OLED_ShowNum(2,5,Timer_GetCounter(),5);
	}
}
