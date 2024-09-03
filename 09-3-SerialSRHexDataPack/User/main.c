#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "Key.h"

uint8_t KeyNum;

int main()
{
	OLED_Init();
	Serial_Init();
	Key_Init();
	
	OLED_ShowString(1,1,"TxPacket");
	OLED_ShowString(3,1,"RxPacket");
	
	Serial_TxPacket[0] = 0x01;
	Serial_TxPacket[1] = 0x02;
	Serial_TxPacket[2] = 0x03;
	Serial_TxPacket[3] = 0x04;
	
	
	
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 2)
		{
			Serial_TxPacket[0]++;
			Serial_TxPacket[1]++;
			Serial_TxPacket[2]++;
			Serial_TxPacket[3]++;
			Serial_SendPacket();
			OLED_ShowHexNum(2,1,Serial_TxPacket[0],2);
			OLED_ShowHexNum(2,4,Serial_TxPacket[1],2);
			OLED_ShowHexNum(2,7,Serial_TxPacket[2],2);
			OLED_ShowHexNum(2,10,Serial_TxPacket[3],2);
		}
		if(Serial_GetRxFlag() == 1)
		{
			OLED_ShowHexNum(4,1,Serial_RxPacket[0],2);
			OLED_ShowHexNum(4,4,Serial_RxPacket[1],2);
			OLED_ShowHexNum(4,7,Serial_RxPacket[2],2);
			OLED_ShowHexNum(4,10,Serial_RxPacket[3],2);
		}
		/*这样存在的问题，就是读取和写入的都是同一个数组
		可能会出现显示的数据包一部分是当前的一部分是下一个的
		*/
	}
}
