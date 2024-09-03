#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

uint8_t i;

int main()
{
	OLED_Init();
	PWM_Init();
	OLED_ShowString(2,1,"PWM:");
	while(1)
	{
		
		for(i = 0; i <= 100; i++)
		{
			Delay_ms(20);
			PWM_SetCompare1(i);
			OLED_ShowNum(2,5,i,3);
		}
		for(i = 100; i > 0; i--)
		{
			Delay_ms(20);
			PWM_SetCompare1(i);
			OLED_ShowNum(2,5,i,3);
		}
	}
}
