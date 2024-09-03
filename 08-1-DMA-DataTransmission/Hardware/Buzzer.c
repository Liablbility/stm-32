#include "stm32f10x.h"                  // Device header

/**
  * @brief GPIOB12引脚初始化为 推挽输出模式
  * @param 无
  * @retval 无
  **/
void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	//GPIOB12引脚设置为低电平
}

/**
  * @brief 将一个GPIOB12引脚置为低电平 
  * @param 无
  * @retval 无
  **/
void Buzzer_On(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}
/**
  * @brief 将一个GPIOB12引脚置为高电平 
  * @param 无
  * @retval 无
  **/
void Buzzer_Off(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
/**
  * @brief 将一个GPIOB12引脚取反 
  * @param 无
  * @retval 无
  **/
void Buzzer_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12) == 0)
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	else
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}
