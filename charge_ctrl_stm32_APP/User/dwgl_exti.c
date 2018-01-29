//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#include "stm32f10x.h"

//����
  u8  *EXTI1_Pointer;
  u8   EXTI1_State;
  u8   EXTI1_Error;
  u16  EXTI1_Counter;

  u8  *EXTI15_10_Pointer;
  u8   EXTI15_10_State;
  u8   EXTI15_10_Error;
  u16  EXTI15_10_Counter;
 
//*********************************************************************
void EXTI_Configuration(void)
{
		EXTI1_Init();
//		EXTI2_Init();
		EXTI15_10_Init();
		EXTI1_Counter = 0;
		EXTI15_10_Counter = 0;
}

//*********************************************************************
void EXTI1_Init(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
//�õ��˸��ù��ܣ�Ҫ������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;                 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                  
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
	/* Connect EXTI Line1 to PB1 */
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	EXTI_ClearITPendingBit(EXTI_Line1);
	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	// 	�����ж�����
	// 	NVIC_Init(&NVIC_InitStructure);
}

//*********************************************************************
void EXTI15_10_Init(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
//�õ��˸��ù��ܣ�Ҫ������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                  
	GPIO_Init(GPIOC,&GPIO_InitStructure);	
	 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource12);
	
	EXTI_ClearITPendingBit(EXTI_Line12);
	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	// 	�����ж�����
	// 	NVIC_Init(&NVIC_InitStructure);
	
}

// ***********************************************************************
// �������ƣ�EXTI1_IRQHandler(void)
// ��    �ܣ�
// ���������
// ���������
// ��дʱ�䣺2013.4.25
// �� д �ˣ�
// ע    �⣺ 
// ***********************************************************************
void EXTI1_IRQHandler(void)
{
	u16 i ;
	if(EXTI_GetITStatus(EXTI_Line1) != RESET)
	{
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line1);
		/* Toggle LED1 */
		i = GPIOC->ODR;
		if((i & 0x0008) == 0x0000)
		{		GPIO_SetBits(GPIOC, GPIO_Pin_3);				}
		else
		{		GPIO_ResetBits(GPIOC, GPIO_Pin_3);				}
		EXTI1_Counter++;
	}
}
// ***********************************************************************
// �������ƣ�EXTI15_10_IRQHandler(void)
// ��    �ܣ�
// ���������
// ���������
// ��дʱ�䣺2013.4.25
// �� д �ˣ�
// ע    �⣺ 
// ***********************************************************************
void EXTI15_10_IRQHandler(void)
{
	u16 i ;
	if(EXTI_GetITStatus(EXTI_Line12) != RESET)
	{
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line12);
		/* Toggle LED1 */
		i = GPIOC->ODR;
		if((i & 0x0008) == 0x0000)
		{		GPIO_SetBits(GPIOC, GPIO_Pin_3);				}
		else
		{		GPIO_ResetBits(GPIOC, GPIO_Pin_3);				}
//		GPIOF->ODR ^= (1<<7);
		EXTI15_10_Counter++;
//		Link_count++;
//		Link_Exit1 = 1;
//		GPIO_SetBits(GPIOC, GPIO_Pin_3);
	}

}
