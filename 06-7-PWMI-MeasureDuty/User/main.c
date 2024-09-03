#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

uint8_t i;

int main()
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1,1,"Freq:     Hz");
	OLED_ShowString(2,1,"Duty:     %");
	
	PWM_SetPrescaler(7200-1);//Freq = 72MHz/(PSC+1)/100
	PWM_SetCompare1(80);//Duty = CCR / 100
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
		OLED_ShowNum(2,7,IC_GetDuty(),3);
	}
}
