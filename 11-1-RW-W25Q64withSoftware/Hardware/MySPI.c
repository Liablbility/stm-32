#include "stm32f10x.h"// Device header

void MySPI_W_SS(uint8_t BitValue)//CS
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)BitValue);
}

void MySPI_W_SCK(uint8_t BitValue)//CLK
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)BitValue);
}
void MySPI_W_MOSI(uint8_t BitValue)//DI
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)BitValue);
}
uint8_t MySPI_R_MOSI(void)//DO
{
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}

void MySPI_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	/*PA6为上拉输入 PA5 PA4 PA7 为推挽输出*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	//上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	
	MySPI_W_SS(1);
	MySPI_W_SCK(0);
	
}
void MySPI_Start(void)
{
	MySPI_W_SS(0);
	
}
void MySPI_Stop(void)
{
	MySPI_W_SS(1);
}
uint8_t MySPI_ExchangeByte(uint8_t ByteSend)
{
	uint8_t i,ByteReceive = 0x00;
	for(i = 0; i < 8; i++)
	{
		MySPI_W_MOSI(ByteSend & (0x80>>i));
		MySPI_W_SCK(1);
		ByteReceive |= MySPI_R_MOSI()*(0x80>>i);
		MySPI_W_SCK(0);
	}
	return ByteReceive;
}
uint8_t MySPI_MoveByte(uint8_t Byte)
{//与上面MySPI_ExchangeByte功能相同 
 //但是只用1个字节效率更高
	uint8_t i,ByteReceive = 0x00;
	for(i = 0; i < 8; i++)
	{
		MySPI_W_MOSI(Byte & 0x80);
		Byte = Byte<<1;
		MySPI_W_SCK(1);
		Byte |= MySPI_R_MOSI()*(0x80>>i);
		MySPI_W_SCK(0);
	}
	return Byte;
}
