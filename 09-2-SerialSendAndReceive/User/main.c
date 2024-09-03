#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RXData;

int main()
{
	OLED_Init();
	Serial_Init();
	OLED_ShowString(1,1,"RxData:");
	
	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
			RXData = Serial_GetRxData();
			OLED_ShowHexNum(1,8,RXData,2);
			Serial_SendByte(RXData);
		}
		
	}
}
