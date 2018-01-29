//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#include "stm32f10x.h"

  u8  *DAC1_Pointer;
  u8   DAC1_State;
  u8   DAC1_Error;
  u16  DAC1_Buffer =0;
	
  u8  *DAC2_Pointer;
  u8   DAC2_State;
  u8   DAC2_Error;
  u16  DAC2_Buffer =0;
//*******************************************
void DAC_Configuration(void)
{
	DAC1_Init();
//	DAC2_Init();
}
//*******************************************
#if defined (dac_out_Normal)
void DAC1_Init(void)  //
{
	DAC_InitTypeDef DAC_InitType;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,  ENABLE);	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,  ENABLE);	//ʹ��ʱ��
//DAC_Channl_1����̶�ΪPA4	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //���õ�ģ�����룬���������ⲿӰ��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);		   
		
	DAC_InitType.DAC_Trigger = DAC_Trigger_None; //��ʹ�ô������� TEN1=0
	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_None; //��ʹ�ò��η�����
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;//
	DAC_InitType.DAC_OutputBuffer = DAC_OutputBuffer_Enable; //����л�����������������
	DAC_Init(DAC_Channel_1,&DAC_InitType);	//��ʼ��DACͨ��1
	DAC_Cmd(DAC_Channel_1,ENABLE);	//ʹ��DAC1
	
	DAC_SetChannel1Data(DAC_Align_12b_R, 0xffff);//��ʼ��DAC������ⲽ����û��	
//	DAC_GetDataOutputValue(DAC_Channel_1);
}
#endif
#if defined  (dac_out_Sin)    
//DMA��ʽ  
//������ʽ
void DAC1_Init(void)   
{
	DAC_InitTypeDef DAC_InitType;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,  ENABLE);	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,  ENABLE);	//ʹ��ʱ��
//DAC_Channl_1����̶�ΪPA4	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //���õ�ģ�����룬���������ⲿӰ��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);		   
		
//	DAC_InitType.DAC_Trigger = DAC_Trigger_T2_TRGO; //��ʹ�ô������� TEN1=0
	DAC_InitType.DAC_Trigger = DAC_Trigger_Software; //��ʹ�ô������� TEN1=0
//	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_None; //��ʹ�ò��η�����
	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_Triangle; //ʹ�ò��η�����
//	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;//
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_TriangleAmplitude_2047;//�趨���ǲ��ķ�ֵ��0-4095����Ϊ4095ʱ���ֵΪ3.3v
	DAC_InitType.DAC_OutputBuffer = DAC_OutputBuffer_Enable; //����л�����������������
	DAC_Init(DAC_Channel_1,&DAC_InitType);	//��ʼ��DACͨ��1
	DAC_Cmd(DAC_Channel_1,ENABLE);	//ʹ��DAC1
	
	DAC_SetChannel1Data(DAC_Align_8b_R, 0xffff);//��ʼ��DAC������ⲽ����û��
	
	DAC_SoftwareTriggerCmd(DAC_Channel_1,ENABLE);//
	
//	DAC_GetDataOutputValue(DAC_Channel_1);

}
#endif
#if defined  (dac_out_Triangle)
void DAC1_Init(void)  //�е�ѹ����0������ԭ�򻹲���
{
	DAC_InitTypeDef DAC_InitType;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,  ENABLE);	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,  ENABLE);	//ʹ��ʱ��
//DAC_Channl_1����̶�ΪPA4	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //���õ�ģ�����룬���������ⲿӰ��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);		   
		
	DAC_InitType.DAC_Trigger = DAC_Trigger_Software; //ʹ�ô�������      
	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_Triangle; //ʹ�ò��η�����
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_TriangleAmplitude_2047;//�趨���ǲ��ķ�ֵ��0-4095����Ϊ4095ʱ���ֵΪ3.3v
	DAC_InitType.DAC_OutputBuffer = DAC_OutputBuffer_Enable; //����л�����������������
	DAC_Init(DAC_Channel_1,&DAC_InitType);	//��ʼ��DACͨ��1
	DAC_Cmd(DAC_Channel_1,ENABLE);	//ʹ��DAC1
	
	DAC_SetChannel1Data(DAC_Align_8b_R, 0xffff);//��ʼ��DAC������ⲽ����û��	
	DAC_SoftwareTriggerCmd(DAC_Channel_1,ENABLE);//	
//	DAC_GetDataOutputValue(DAC_Channel_1);

}
#endif

//*******************************************
void DAC2_Init(void)
{
//DAC_Channl_1����̶�ΪPA5	
	DAC_InitTypeDef DAC_InitType;
  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,  ENABLE);	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,  ENABLE);	//ʹ��ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; //���õ�ģ�����룬���������ⲿӰ��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);		   
	
	DAC_InitType.DAC_Trigger = DAC_Trigger_None; //��ʹ�ô������� TEN1=0
	DAC_InitType.DAC_WaveGeneration = DAC_WaveGeneration_None; //��ʹ�ò��η�����
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitType.DAC_OutputBuffer = DAC_OutputBuffer_Disable; //DAC1�������ر�
//	DAC_Init(DAC_Channel_2,&DAC_InitType);	//��ʼ��DACͨ��2
	DAC_Cmd(DAC_Channel_2,ENABLE);	//ʹ��DAC2
	
	DAC_SetChannel2Data(DAC_Align_12b_R, 0x000);//��ʼ��DAC������ⲽ����û��
//	DAC_GetDataOutputValue(DAC_Channel_2);

}
