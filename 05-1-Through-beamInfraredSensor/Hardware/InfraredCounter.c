#include "stm32f10x.h"                  // Device header

uint16_t InfraredSensor_Cnt;

void InfraredSensor_Init(void)
{
	//第一步，配置RCC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//第二步，配置GPIO 选择端口为输入模式
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//第三步，配置AFIO 选择所用的这一路GPIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	//第四步，配置EXTI 选择边沿触发方式 
	//打开exti.h文件
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	//第五步，配置NVIC 选择一个合适的优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//该函数一个工程出现一次就够了，可以只写在主程序里
	//或者在不同的模块里写多次但是都是一致的
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
	
}

uint16_t Get_InfraredSensorCnt(void)
{
	return InfraredSensor_Cnt;
}

void EXTI15_10_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET)
	{
		EXTI_ClearITPendingBit(EXTI_Line14);
		InfraredSensor_Cnt++;
	}
	
}


