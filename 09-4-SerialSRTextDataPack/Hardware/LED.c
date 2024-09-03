#include "stm32f10x.h"                  // Device header

/**
  * @brief GPIOA 引脚初始化为 推挽输出模式
  * @param 无
  * @retval 无
  **/
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_All);
	//GPIOA所有引脚都设置为低电平
}
/**
  * @brief 将所有GPIOA引脚置为低电平
  * @param 无
  * @retval 无
  **/

void LED_LightOnAll(void)
{
	GPIO_Write(GPIOA, 0x0000);
}
/**
  * @brief 将所有GPIOA引脚置为高电平
  * @param 无
  * @retval 无
  **/

void LED_LightOffAll(void)
{
	GPIO_Write(GPIOA, 0x1111);
}

/**
  * @brief 将一个GPIOA引脚置为低电平 
  * @param LED_Num 引脚编号 0-15
  * @retval 无
  **/
void LED_LightOn(unsigned char LED_Num)
{
	uint16_t LED_State = GPIO_ReadOutputData(GPIOA);

	GPIO_Write(GPIOA, ~(0x0001<<LED_Num) & LED_State);
}
/**
  * @brief 将一个GPIOA引脚置为高电平 
  * @param LED_Num 引脚编号 0-15
  * @retval 无
  **/
void LED_LightOff(unsigned char LED_Num)
{
	uint16_t LED_State = GPIO_ReadOutputData(GPIOA);

	GPIO_Write(GPIOA, (0x0001<<LED_Num) | LED_State);
}
/**
  * @brief 将一个GPIOA引脚取反 以此开关led 
  * @param LED_Num 引脚编号 0-15
  * @retval 无
  **/
void LED_Turn(unsigned char LED_Num)
{
	uint16_t LED_State = GPIO_ReadOutputData(GPIOA);
	
	uint16_t LED_State_Temp = LED_State & (0x0001<<LED_Num); 
	
	if(LED_State_Temp == 0)
		GPIO_Write(GPIOA, LED_State | (0x0001<<LED_Num));
	else
		GPIO_Write(GPIOA, LED_State & ~(0x0001<<LED_Num));
}

