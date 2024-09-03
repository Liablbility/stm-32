#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "LED.h"
#include <string.h>


int main()
{
	OLED_Init();
	LED_Init();
	Serial_Init();
	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");
	while(1)
	{
		if(Serial_RxFlag == 1)
		{
			OLED_ShowString(4,1,Serial_RxPacket);
			
			if(strcmp(Serial_RxPacket,"LED_ON") == 0)
			{
				LED_LightOn(1);
				Serial_SendString("LED_ON_OK\r\n");
			}
			else if(strcmp(Serial_RxPacket,"LED_OFF") == 0)
			{
				LED_LightOff(1);
				Serial_SendString("LED_OFF_OK\r\n");
			}
			else
			{
				OLED_ShowString(4,1,"            ");
				OLED_ShowString(4,1,"Command error");
				Serial_SendString("Command error\r\n");
			}
			Serial_RxFlag = 0;
			//读完之后再清零 下一个包才能开始收
		}
	}
}
