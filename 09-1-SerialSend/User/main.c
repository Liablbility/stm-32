#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main()
{
	OLED_Init();
	Serial_Init();
	//Serial_SendByte(0x41);
	
	//uint8_t MyArray[] = {0x42,0x43,0x44,0x45};
	//Serial_SendArray(MyArray,4);
	
	//Serial_SendString("HelloWorld!!!!\r\n");
	//只有\r加上\n才会换行
	
	//Serial_SendNumber(12345,5);
	
	//printf("Num=%d\r\n",666);
	
	//Serial_Printf("Num=%d\r\n",666);
	
	Serial_Printf("你好，世界");
	
	while(1)
	{
		
	}
}
