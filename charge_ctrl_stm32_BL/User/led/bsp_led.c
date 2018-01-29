/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
 */


#include "bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);      /*ʹ��SWD ����JTAG*/

		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA| RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE, ENABLE); 
//-----------�����----------------
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		/*ѡ��Ҫ���Ƶ�GPIOB������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_14;	
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIOC������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_13;	
		GPIO_Init(GPIOC, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIOD������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
		
		/*ѡ��Ҫ���Ƶ�GPIOE������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_5;	
		GPIO_Init(GPIOE, &GPIO_InitStructure);	
//-----------������----------------
		/*��������ģʽΪͨ�ø�������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		
		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);	

		
		/*��������ģʽΪͨ��ģ������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		 
		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
				
		/*��������ģʽΪͨ�ø�������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  
		
		/*��������ģʽΪͨ�ø�������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   

		/*ѡ��Ҫ���Ƶ�GPIOE������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
		GPIO_Init(GPIOE, &GPIO_InitStructure);	

		 
		
		/* д1*/
//		GPIO_SetBits(GPIOB, GPIO_Pin_0);
		
		/* д0	*/
//		GPIO_ResetBits(GPIOC, GPIO_Pin_4|GPIO_Pin_13);	 

		GPIO_SetBits(HUB0_REST_PORT, HUB0_REST_PIN);  
		GPIO_SetBits(HUB1_REST_PORT, HUB1_REST_PIN);
		
		GPIO_SetBits(EN_KC0_PORT, EN_KC0_PIN); //USB�ϵ緽ʽ
		GPIO_SetBits(EN_KC1_PORT, EN_KC1_PIN); //USB�ϵ緽ʽ
		
		GPIO_ResetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
		GPIO_ResetBits(EN_485_PORT, EN_485_PIN);  //Ĭ�Ͻ���
		
		GPIO_SetBits(FLASH1CS_PORT, FLASH1CS);  //Ĭ�Ͻ���

		GPIO_ResetBits(LED_PORT, LED_PIN);
		GPIO_ResetBits(LED1_PORT, LED1_PIN);
		GPIO_ResetBits(LED2_PORT, LED2_PIN);

}

//-------------------------------------------------------------------
void GPIO_NegationBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) //dwgl  ȡ��
{
	  GPIOx->ODR = GPIOx->ODR^GPIO_Pin;
}


/*********************************************END OF FILE**********************/
