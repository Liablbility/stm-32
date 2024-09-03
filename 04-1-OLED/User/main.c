#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main()
{
	OLED_Init();
	OLED_ShowChar(1, 1,'A');
	OLED_ShowString(1, 2," OLED!!");
	while(1)
	{
		
	}
}
