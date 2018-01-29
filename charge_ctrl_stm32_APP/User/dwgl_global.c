//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#include "stm32f10x.h"
	struct  device_table device;
  struct  file_table file_t;
  struct  Addr_info2STR info2STR;
  struct  LCDREG  LCDC;
	u32 time_sys =0;
 	u16 step;
 	u16 time_s;
 	u16 testcmd1_time;
 	u16 testcmd3_time;
 	u32 time_s_temp;
 	u32 time_sys_temp1;
 	u32 time_sys_temp2;
 	u32 time_sys_temp3;
 	u32 time_sys_temp4;
 	u32 time_sys_temp5;
  u32 time_rst_lcd1;
  u32 time_rst_lcd2;
  u8 global_u8temp;
  u8 *global_u8p;
  u16 global_u16temp;
 	u16 *global_u16p;
	
  u16 global_u16BUFFER[128];
  u8 global_u8BUFFER[128];
	
 volatile unsigned char touch_flag;
  u32 time_uart1;
  u32 time_uart3;
  u8 str_buffer[4100];
  u8  LCD1_TxtBuffer[2050];   //����ʾ���ڴ�
  u8  LCD2_TxtBuffer[2050];   //����ʾ���ڴ�
 	u16 Uport_PowerSetTime[2];
 	u16 Uport_PowerUseTime[2];
 	u16 Uport_PowerShowTime[2];
 	u16 Dport_PowerSetTime[6];
 	u16 Dport_PowerUseTime[6];
	u8 Dport_State[6];
  u8 checking_portB;
  u8 checking_portC;
  u8 LOW_portB;
  u8 LOW_portC;
//   u8  LCD1_CTRL8[8];   //��LCD1������
//   u8  LCD2_CTRL8[8];   //��LCD2������
	
	u32 file_addr;  //
	u32 Rfile_addr;
 	u8 file_hook;
 	u8 file_wr;
	u8 file_id;  //��ǰ��д�ļ���ID
 	u32 NextFileAddr;
 	u32 check_time;
//u32 display_time;
	u8  UART_BUFFER[128];
  u8  UART1_TXBUFFER[128];
  u8  UART1_RXBUFFER[UART1_RXBUFFER_SIZE];
  u16  UART1_RXBUFFE_HEAD =0;   //��Ч���ݵĵ�һ��
  u16  UART1_RXBUFFE_LAST =0;	//��Ч���ݵ����һ��
  u8  UART2_TXBUFFER[128];
  u8  UART2_RXBUFFER[128];
  u8  UART3_TXBUFFER[128];
  u8  UART3_RXBUFFER[UART3_RXBUFFER_SIZE];
  u16  UART3_RXBUFFE_HEAD;   //��Ч���ݵĵ�һ��
  u16  UART3_RXBUFFE_LAST;	//��Ч���ݵ����һ��
 	u8  SPI_BUFFER[128];
 	u16 ADC_BUFFER[320];
// 	u8 AINx_ADCch[18]={ADC_Channel_13,ADC_Channel_12,ADC_Channel_0,ADC_Channel_1,ADC_Channel_3,ADC_Channel_2,ADC_Channel_11,ADC_Channel_10,0};
 	u8 AINx_ADCch[18]={ADC_Channel_13,ADC_Channel_12,ADC_Channel_0,ADC_Channel_1,ADC_Channel_3,ADC_Channel_2,ADC_Channel_2,ADC_Channel_1,0};
  u16 ADC_Base0[18];  //ADC��ֵ̬
	u8 device_num[20];  //
	u16 AD_count[64];   //������
	u8 charge_speed[2];   //����ٶ�	
	
	u8  SF_REG = 7;  //0-7. =7ʱ�������ٶ����� 
	u8  GAIN_REG;


/* �������� ---------------------------------------------------------*/
 uint16_t Sine12bit[32] = {
	2448,2832,3186,3496,3751,3940,4057,4095,4057,3940,
	3751,3496,3186,2832,2448,2048,1648,1264,910,600,345,
	156,39,0,39,156,345,600,910,1264,1648,2048
};
/* �������� ---------------------------------------------------------*/
 uint16_t co_x[10] = {
	103,152,201,
	103,152,201,
	103,152,201,
	0
};
/* �������� ---------------------------------------------------------*/
 uint16_t co_y[10] = {
	50,50,50,
	99,99,99,
	148,148,148,
	0
};
/* �Ź����� ---------------------------------------------------------*/
 uint16_t xy_3[3][3] = {
	0,1,2,
	3,4,5,
	6,7,8
};


//Ҫ�����жϵ����ȼ�����
void NVIC_Configuration(void)
{
	////��Ƕ�ϵ�����
  NVIC_InitTypeDef   NVIC_InitStructure;
	//�趨������������λ�ã������ڷ���ǰ���úã�Ĭ�ϵ���NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
  // Set the Vector Table base location at 0x08000000
 // NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);

  // 2 bit for pre-emption priority, 2 bits for subpriority 
	//��λ��Ĭ��Ϊ����0,������ֻ����һ��
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
    
  // Enable the USART1 global Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
  // Enable the USART2 global Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 
	
  // Enable the USART3 global Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
  // Enable the SPI1 global Interrupt 
// 	NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;	  
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);
	
  // Enable the ADC1_2 global Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
  // Enable the DMA1_Channel1 global Interrupt. ADC1 DMA �жϷ�ʽ
// 	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;	  
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure); 
	
  // Enable the TIM3 global Interrupt 
//     NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;	  
//     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
//     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//     NVIC_Init(&NVIC_InitStructure);
		
	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
// 	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);

	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
// 	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
// 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
// 	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
// 	NVIC_Init(&NVIC_InitStructure);
}
