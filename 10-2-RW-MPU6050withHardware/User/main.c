#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"

int16_t AX,AY,AZ,GX,GY,GZ;

int main()
{
	uint8_t ID;
	OLED_Init();
	MPU6050_Init();
	
	ID = MPU6050_GetID();
	
	OLED_ShowHexNum(1,1,ID,2);
	
	while(1)
	{
		MPU6050_GetData(&AX,&AY,&AZ,&GX,&GY,&GZ);
	
		OLED_ShowSignedNum(2,1,AX,5);
		OLED_ShowSignedNum(3,1,AY,5);
		OLED_ShowSignedNum(4,1,AZ,5);
		OLED_ShowSignedNum(2,7,GX,5);
		OLED_ShowSignedNum(3,7,GY,5);
		OLED_ShowSignedNum(4,7,GZ,5);
	}
}
