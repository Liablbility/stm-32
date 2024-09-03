#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "RotaryEncoder.h"

int main()
{
	OLED_Init();
	RotaryEncoder_Init();
	OLED_ShowString(1, 1," RotaryCnt:");
	while(1)
	{
		OLED_ShowSignedNum(1,12,RotartCnt_Get(),4);
	}
}
