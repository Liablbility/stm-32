#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t AD_Value;
float Voltage;

int main()
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"ADValue:");
	OLED_ShowString(2,1,"Voltage:0.00V");
	while(1)
	{
		AD_Value = AD_GetValue();
		Voltage = (float)AD_Value / 4095 * 3.3;
		OLED_ShowNum(1,9,AD_Value,4);
		OLED_ShowNum(2,9,Voltage,1);
		OLED_ShowNum(2,11,(uint16_t)(Voltage*100) % 100,2);
		Delay_ms(100);
	}
}
