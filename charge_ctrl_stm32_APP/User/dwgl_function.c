//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#include "dwgl_function.h"

//*******************************************
//u16 ת�ַ�
//V1.1 20160401
//*******************************************
void u16toStr(u16 u_data,u8 *p)	 //u16 ת�ַ�
{
	u16 temp,j;
	u8 i;
	temp = u_data;
	if(temp==0)
	{
		*p = '0';
		p++;
	}
	else
	{
	j=10000;
	for(i=0;i<5;i++)
		{
		if(temp/j)
			{break;}
		j =j/10;
		}
	for(;i<5;i++)
		{
		*p=(temp/j)+0X30;
		p++;
		temp = temp%j;	
		j =j/10;
		}
	}
		*p = '\0';
}
//*******************************************
//u16 ת�ַ� ���Դ���λ��
//V1.1 20160401
//*******************************************
void u16toStr_unit(u16 u_data,u8 *p,u8 unit)
{
	u16 temp,j;
	u8 i;
	temp = u_data;
	if(temp==0)
	{
		*p = '0';
		p++;
	}
	else
	{
	j=10000;
	for(i=0;i<5;i++)
		{
		if(temp/j)
			{break;}
		j =j/10;
		}
	for(;i<5;i++)
		{
		*p=(temp/j)+0X30;
		p++;
		temp = temp%j;	
		j =j/10;
		}
	}
		*p = unit;
		p++;
		*p = '\0';
}

//*******************************************
//u16 ת�ַ� ���Դ���λ��
//V1.1 20160401
//*******************************************
void buffer_display(u16 *p,u8 gain,uint16_t color)
{
// 	u16 i,temp;
// 	LCD_Clear(0, 50, 320, 130, BACKGROUND);
// 	if(gain>8){ return;}
// 	for(i=0;i<320;i++)
// 	{
// 	temp = *p;
// 	temp >>=(gain);
// 	temp = wave_area_YD-1 - temp;	
// 	p++;
// 	point_display(i,temp,color);	
// 	}

}

//*******************************************
//u16 ת�ַ� ���Դ���λ��
//V1.1 20160401
//*******************************************
void continuous_display(u16 *p,u8 gain,uint16_t color)
{
// 	u16 i,j,num,temp1,temp2;
// 	LCD_Clear(0, 50, 320, 130, BACKGROUND);
// 	if(gain>8){ return;}
// 	for(i=0;i<320;i++)
// 	{
// 	temp1 = *(p+i);
// 	temp1 >>=(gain);
// 	temp1 = wave_area_YD-1 - temp1;	
// 	*(p+i) = temp1;	
// 	}
// 	for(i=0;i<319;i++)
// 	{
// 	temp1 = *p;
// 	temp2 = *(p+1);
// 	point_display(i,temp1,color);	
// 	if(temp1>temp2)
// 	{
// 		num = temp1- temp2;
// 	for(j=1;j<num;j++)
// 		{
// 				point_display(i,temp1-j,color);	
// 		}
// 	}
// 	else
// 	{
// 		num = temp2- temp1;
// 	for(j=1;j<num;j++)
// 		{
// 				point_display(i,temp1+j,color);	
// 		}
// 	}
// 	p++;
// 	}

}
//*******************************************
//u16 ת�ַ� ���Դ���λ��
//V1.1 20160401
//*******************************************

void point_display(u16 x,u16 y,uint16_t color)
{
// 	LCD_SetCursor(x, y);
// 	LCD_ILI9341_CMD(0x2c);	         /* д���� */
// 	LCD_WR_Data(color);
}


//*******************************************
//���˵�
//V1.1 20160401
//*******************************************
void TASK0_display(void)
{
// 	u16 zb_x,zb_y;
// 	if((TASK_state&0x80) == 0x80)  //�и�������״̬
// 	{
// 	TASK_state &=0x7f; 
//   LCD_Clear(0, 0, 320, 240, BACKGROUND);
//   LCD_Clear(0, 0, 39, 32, GREY);
//   LCD_DispStr(7, 10, (uint8_t *)"MENU", RED);
//   LCD_Clear(40, 0, 39, 32, GREY);
//   LCD_DispStr(47, 10, (uint8_t *)"CLR", RED);
//   LCD_Clear(80, 0, 39, 32, GREY);
//   LCD_DispStr(87, 10, (uint8_t *)"NEXT", RED);
// 	
//   LCD_DispStr(240, 1, (uint8_t *)"TIME:", RED);
// 	u16toStr_unit( time_s,str_buffer,'S');
//   LCD_Clear(240+6*6, 1, 6*6, 12, BACKGROUND);
// 	LCD_DispStr(240+6*6, 1, str_buffer, RED);
//   LCD_DispStr(240, 14, (uint8_t *)"STEP:", RED);
// 	u16toStr_unit( step,str_buffer,'T');
//   LCD_Clear(240+6*6, 14, 6*6, 12, BACKGROUND);
// 	LCD_DispStr(240+6*6, 14, str_buffer, RED);
// 		
//   LCD_Clear(0, 212, 320, 1, GREY);
//   LCD_Clear(0, 240, 320, 1, GREY);
//   LCD_Clear(0, 212, 1, 28, GREY);
//   LCD_Clear(320, 212, 1, 28, GREY);
//   LCD_DispStr(7, 214, (uint8_t *)"COM:", RED);
// 	
//   /* ��4��ֱ�� */
//   LCD_Clear(10, 50, 64, 48, BLUE);
//   LCD_DispStr(16, 80, (uint8_t *)"TASK1", RED);
//   LCD_Clear(10+75, 50, 64, 48, BLUE);
//   LCD_DispStr(16+75, 80, (uint8_t *)"TASK2", RED);
// 	
//   LCD_Clear(10+75*2, 50, 64, 48, BLUE);
//   LCD_DispStr(16+75*2, 80, (uint8_t *)"TASK3", RED);
//   LCD_Clear(10+75*3, 50, 64, 48, BLUE);
//   LCD_DispStr(16+75*3, 80, (uint8_t *)"TASK4", RED);
// 		
//   LCD_Clear(10, 130, 64, 48, BLUE);
//   LCD_DispStr(16, 160, (uint8_t *)"TASK5", RED);
//   LCD_Clear(10+75, 130, 64, 48, BLUE);
//   LCD_DispStr(16+75, 160, (uint8_t *)"TASK6", RED);
// 	
//   LCD_Clear(10+75*2, 130, 64, 48, BLUE);
//   LCD_DispStr(16+75*2, 160, (uint8_t *)"TASK7", RED);
//   LCD_Clear(10+75*3, 130, 64, 48, BLUE);
//   LCD_DispStr(16+75*3, 160, (uint8_t *)"TASK8", RED);
// }
// 	
//   if(touch_flag == 1)			/*������ʰ�����*/
// 		{
//       if(Get_touch_point(&display, Read_2046_2(), &touch_para ) !=DISABLE)      
//       {	
// 			/* �ڻ�����ȡɫ */
// 			zb_x = display.x;	
// 			zb_y = display.y;
// 				
// 				if((0<zb_x)&&(zb_x<40)&& (0<zb_y)&&(zb_y<33))			//������Ĳ˵�
// 				{
// 					Delay_ms(200);		//��һ����ʱ������
// 					TASK_state |= 0x80;	  //��ʼ�����ʼ��				
// 				}
// 				else
// 				if((40<zb_x)&&(zb_x<80)&& (0<zb_y)&&(zb_y<33))		//���������Clr
// 				{
// 					time_s = 0;
// 					u16toStr_unit( time_s,str_buffer,'S');
// 					LCD_Clear(240+6*6, 1, 6*6, 12, BACKGROUND);
// 					LCD_DispStr(240+6*6, 1, str_buffer, RED);
// 					
// 					step = 0;
// 					u16toStr_unit( step,str_buffer,'T');
// 					LCD_Clear(240+6*6, 14, 6*6, 12, BACKGROUND);
// 					LCD_DispStr(240+6*6, 14, str_buffer, RED);
// 				}
// 				else
// 				if((80<zb_x)&&(zb_x<120)&& (0<zb_y)&&(zb_y<33))		//���������NEXT
// 				{
// 					Delay_ms(200);		//��һ����ʱ������
// 					step++;
// 					u16toStr_unit( step,str_buffer,'T');
// 					LCD_DispStr(240+6*6, 14, str_buffer, RED);
// 				}
// 				else
// 				if((10<zb_x)&&(zb_x<74)&& (50<zb_y)&&(zb_y<98))		//���������TASK1
// 				{
// 					TASK_state =0x81; 
// 					Delay_ms(200);		//��һ����ʱ������
// 				}
// 				else
// 				if((85<zb_x)&&(zb_x<149)&& (50<zb_y)&&(zb_y<98))		//���������TASK2
// 				{
// 					TASK_state =0x82; 
// 					Delay_ms(200);		//��һ����ʱ������
// 				}
// 				else
// 				if((235<zb_x)&&(zb_x<299)&& (130<zb_y)&&(zb_y<178))		//���������TAsk8
// 				{
// 				  while(Touch_Calibrate() !=0);
// 					TASK_state |= 0x80;	  //��ʼ�����ʼ��				
// 				}
// 			}//end ������ʾ
// 				
// 		}//end ����
	
}

//*****************************************************
//hub_addr_set λԽС���ȼ�Խ��
//*****************************************************
//charge_addr_set���ź���=0��ʱ��Ϊ�ǵ�ַ����=1ʱ��ʾ�Ѿ�ȷ����ַ��
void Addr_Set(void)
{

}
//---------------------------------------------------------------------------------
void  Choose_uart2(u8 port)
{
		
}
//---------------------------------------------------------------------------------
void Device_Rst(void)
{
			NVIC_SystemReset();
}
void AllPort_PowerInfo(void)
{

}
	
//---------------------------------------------------------------------------------
void Device_Info(void)
{
// 	u8 i;
// 	if(GPIO_ReadInputDataBit(RJ45_IO1_PORT,RJ45_IO1_PIN)==1)
// 	{
// 		i = 1;
// 		UART1_TXBUFFER[0] =  frame_headerD;
// 		UART1_TXBUFFER[1] =  9;  //len
// 		UART1_TXBUFFER[2] =  PC_ADDR;
// 		UART1_TXBUFFER[3] =  hub_addr+i;
// 		UART1_TXBUFFER[4] =  cmd_set_addr;
// 		UART1_TXBUFFER[5] =  port_num;
// 		UART1_TXBUFFER[6] =  device.hub_id[0];
// 		UART1_TXBUFFER[7] =  device.hub_id[1];
// 		UART1_TXBUFFER[8] =  device.hub_id[2];
// 		UART1_TXBUFFER[9] =  device.hub_id[3];
// 		UART1_TXBUFFER[10] =  device.hub_id[4];
// 		UART1_TXBUFFER[11] =  device.hub_id[5];
// 		UART1_TXBUFFER[12] =  device.hub_id[6];
// 		UART1_TXBUFFER[13] =  device.hub_id[7];
// 		UART1_TXBUFFER[14] =  i*2 -2;
// 		UART1_TXBUFFER[15] =  i*2 -1;
// 		UART1_TXBUFFER[16] = 0;
// 		for(i=1;i<((UART1_TXBUFFER[1]<<1)-3);i++)
// 		{
// 			UART1_TXBUFFER[16] += UART1_TXBUFFER[i];
// 		}
// //		UART2_TXBUFFER[16] =  check;
// 		UART1_TXBUFFER[17] =  frame_last;
// 		
// 		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
// 	}

}
//---------------------------------------------------------------------------------
void cmd_Device_Info(void)
{
	u8 i;
	i= (device.addr>>4);
	i = i*2+4;
	while(time_sys-time_uart1>=i);
	Device_Info();	
}


//---------------------------------------------------------------------------------
void cmd_Erase_Flash(void)
{
	
}

//---------------------------------------------------------------------------------
void cmd_Read_Flash(void)
{
	u32 addr,i;
	u32 end_addr;
//	u8 flash_cs;
	
//	flash_cs = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
	addr =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
	addr <<= 8;
	addr +=  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
	addr <<= 8;
	
	end_addr =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
	end_addr <<= 8;
	end_addr +=  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
	end_addr <<= 8;
	
	for(i=addr;i<end_addr;)  //���ÿ�ʼҳ�������ҳ
	{
//		FLASH2_GPIOSPI_Read(i, str_buffer,1024,flash_cs);
		FLASH2_GPIOSPI_Read(i, str_buffer,1024);
		i+=1024;
		UART1_Send_Data(str_buffer,1024);
	}
		
}

//---------------------------------------------------------------------------------
void cmd_Write_Flash(void)
{
	u32 addr;
	u16 len,i;
//	u8 flash_cs;
	
//	flash_cs = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
	addr =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
	addr <<= 8;
	addr +=  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
	addr <<= 8; //���ÿ�ʼҳ

	if(addr>=Addr_info1)
		{
			FLASH2_GPIOSPI_SER(addr);
			
			len = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX];
			len <<= 1;
			len -= 10; //����ͷβЧ�ֽ�
			for(i=0;i<(len);i++)
			{
			str_buffer[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8+i)&UART1_RX_MAX];
			}
			FLASH2_GPIOSPI_Write(addr, str_buffer, len);
			
			UART1_TXBUFFER[0] =  frame_headerD;
			UART1_TXBUFFER[1] =  4;  //len
			UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
			UART1_TXBUFFER[3] =  device.addr;
			UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
			UART1_TXBUFFER[5] =  0xff;
				
			UART1_TXBUFFER[6] = 0;//check;
			for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
			{
				UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
			}
			UART1_TXBUFFER[7] =  frame_last;
			UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
}

//---------------------------------------------------------------------------------
void cmd_Power_on(void)
{
	u8 i,data;
		data = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];		
		if(data==device.port_id[0])
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  6;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[0];
		UART1_TXBUFFER[6] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
		UART1_TXBUFFER[7] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
		UART1_TXBUFFER[8] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		UART1_TXBUFFER[9] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]!=0)
		{
		Uport_PowerSetTime[0]	= UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		Uport_PowerSetTime[0]	<<= 8;
		Uport_PowerSetTime[0]	+= UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		Uport_PowerUseTime[0]	= Uport_PowerSetTime[0];
		Uport_PowerShowTime[0] = 0;
		}
		
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2) //��� �ϵ緽ʽѡ��2
		{
			Uport_PowerShowTime[0] = Uport_PowerUseTime[0];
			Dport_ChargeOFF(0);
			Dport_ChargeOFF(1);
			Dport_ChargeOFF(2);
			Delay_us(200);	
		GPIO_ResetBits(EN_KC0_PORT, EN_KC0_PIN); //��� 
//			Delay_us(100);	
			ADC_BUFFER[20] = 0;  
			checking_portB &= 0x0f; 
		}
		else 
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1) //USB �ϵ緽ʽѡ��1
		{ 
			Dport_ChargeOFF(0);
			Dport_ChargeOFF(1);
			Dport_ChargeOFF(2);
			Delay_us(200);	
		GPIO_SetBits(EN_KC0_PORT, EN_KC0_PIN); //USB�ϵ緽ʽ
//			Delay_us(100);	
			ADC_BUFFER[20] = 0;
			checking_portB &= 0x0f; 
		}
		
		UART1_TXBUFFER[10] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[10] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[11] =  frame_last;
		
		i= (device.addr>>4);
		i = i*2+4;
		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
		else
		if(data==device.port_id[1])
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  6;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[1];
		UART1_TXBUFFER[6] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
		UART1_TXBUFFER[7] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
		UART1_TXBUFFER[8] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		UART1_TXBUFFER[9] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]!=0)
		{
		Uport_PowerSetTime[1]	= UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		Uport_PowerSetTime[1]	<<= 8;
		Uport_PowerSetTime[1]	+= UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		Uport_PowerUseTime[1]	= Uport_PowerSetTime[1];
		Uport_PowerShowTime[1] = 0;
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2) //�ϵ緽ʽѡ��
		{
			Uport_PowerShowTime[1] = Uport_PowerUseTime[1];
			Dport_ChargeOFF(3);
			Dport_ChargeOFF(4);
			Dport_ChargeOFF(5);
			Delay_us(200);	
		GPIO_ResetBits(EN_KC1_PORT, EN_KC1_PIN); //��� 
//			Delay_us(100);	
			ADC_BUFFER[23] = 0;
			checking_portC &= 0x0f; 
		}
		else 
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1) //�ϵ緽ʽѡ��1
		{
			Dport_ChargeOFF(3);
			Dport_ChargeOFF(4);
			Dport_ChargeOFF(5);
			Delay_us(200);	
		GPIO_SetBits(EN_KC1_PORT, EN_KC1_PIN); //USB�ϵ緽ʽ
//			Delay_us(100);	
			ADC_BUFFER[23] = 0;
			checking_portC &= 0x0f; 
		}
		UART1_TXBUFFER[10] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[10] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[11] =  frame_last;
		
// 		i= (device.addr>>4);
// 		i = i*2+4;
// 		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
		
		FLASH2_GPIOSPI_Read (Addr_04min, str_buffer, 64);  //��ȡͼƬ����
		if(str_buffer[0] == 0x67)//����Ч
		{
		LCDC.PNum = str_buffer[1];
		}
}

//---------------------------------------------------------------------------------
void cmd_Power_off(void)
{
	u8 i,data;
		data = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];		
		if(data==device.port_id[0])
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[0];
			
		Uport_PowerSetTime[0]	= 0;
		Uport_PowerUseTime[0]	= 0;
		Uport_PowerShowTime[0] = 0;
			UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		
		i= (device.addr>>4);
		i = i*2+4;
		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
		else
		if(data==device.port_id[1])
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[1];
			
		Uport_PowerSetTime[1]	= 0;
		Uport_PowerUseTime[1]	= 0;
		Uport_PowerShowTime[1] = 0;
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		
// 		i= (device.addr>>4);
// 		i = i*2+4;
// 		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
}

//------0x11---------------------------------------------------------------------------	
void cmd_File_Requst(void)
{
// 		str_buffer[0]=     // u8  0X67
// 		str_buffer[?]=     // u8  �ļ�����
// 		str_buffer[?]=     //u16  �´�ʼ����ʼҳ
// 		str_buffer[?]=     //u8  �ļ���
// 		str_buffer[?]=		 //u8  �ļ���
// 		str_buffer[?]=		 //u32 �ļ���С
// 		str_buffer[?]=		 //u64 �ļ���
// 		str_buffer[?]=		 //u32 �ļ����ַ
// 		str_buffer[?]=     //check
// 		str_buffer[?]=     //β0X99
	
	u16 i,EN,len,re_send;
	u32 f_size,f_temp;
	EN = Frame_check_cmd1();  //У��ȶԡ�
	if(EN!=0xff)
	{
		return;
	}
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1)  //��ά����
	{
		FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
// 		file_wr = 1;	//�ļ���������
// 		file_id = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];  //��ǰд��

		if((file_id == UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]) && ((file_wr&0X0F)==1))
		{
				re_send =0xff;//ȷ��Ϊ�ط�
		}
		else
		{
				re_send =0x00;//���ط�
		}
			
		if((str_buffer[0]==frame_headerC))
		{
			if(re_send==0x00)
			{
			len = str_buffer[1];		
			len = len*18+6;
			file_addr = str_buffer[2];//�´�ʼ����ʼҳ u16
			file_addr <<=8;
			file_addr += str_buffer[3];
			file_addr <<=8;
						
			f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
			f_size = file_addr+f_temp;	
			
			if((f_size<Addr_01max)&&(str_buffer[1]<=13))
				{
				EN  = 0xff;
				if((f_size&0xff)==0)
				{
				NextFileAddr = f_size;				
				}
				else
				{
				NextFileAddr = (f_size & 0xffffff00);				
				NextFileAddr += 0x100;
				}
				FLASH2_GPIOSPI_SER(Addr_01min);
				for(i=0;i<14;i++)   //
					{
				str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
					}
				str_buffer[len-2+6] += 4;//��д���ļ������̶���4���ļ�������ֽڡ�
					
				str_buffer[len-2+i]	= (file_addr>>24);
					i++;
				str_buffer[len-2+i]	= (file_addr>>16)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr>>8)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr)&0xff;
					
				str_buffer[0]	= frame_headerC;
				str_buffer[1]	+= 1;
				str_buffer[2]	= (NextFileAddr>>16)&0xff;
				str_buffer[3]	= (NextFileAddr>>8)&0xff;
				len = str_buffer[1];		
				len = len*18+6;
				str_buffer[len-1]	= 0;
				for(i=1;i<(len-2);i++)
					{
					str_buffer[len-1] += str_buffer[i];
					}
				str_buffer[len-1]	= frame_last;			
				FLASH2_GPIOSPI_Write(Addr_01min, str_buffer, len);	
				}
			else
				{
				EN  = 0x00;
				}
			}
			else   //���ط�
			{
				EN  = 0xff;
			}
		}
		else
		{
		str_buffer[0]= 0x67;	
		str_buffer[1]= 0x00;	
		//�ļ���ͷ��Addr_01min �ļ����ݴ�Addr_01min+0X1000	
		f_temp = Addr_01min + 0x1000;
		str_buffer[2]= ((f_temp>>16)&0xff);	
		str_buffer[3]= ((f_temp>>8)&0xff);	
		len = str_buffer[1];		
		len = len*18+6;
		file_addr = str_buffer[2];
		file_addr <<=8;
		file_addr += str_buffer[3];
		file_addr <<=8;
			
		f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		f_size = file_addr+f_temp;	
		
		if((f_size<Addr_01max)&&(str_buffer[1]<=13))
			{
			EN  = 0xff;
			if((f_size&0xff)==0)
			{
			NextFileAddr = f_size;				
			}
			else
			{
			NextFileAddr = (f_size & 0xffffff00);				
			NextFileAddr += 0x100;
			}
			FLASH2_GPIOSPI_SER(Addr_01min);
			for(i=0;i<14;i++)
				{
			str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
				}
				str_buffer[len-2+6] += 4;//��д���ļ������̶���4���ļ�������ֽڡ�
				
			str_buffer[len-2+i]	= (file_addr>>24);
				i++;
			str_buffer[len-2+i]	= (file_addr>>16)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr>>8)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr)&0xff;
				
			str_buffer[0]	= frame_headerC;
			str_buffer[1]	+= 1;
			str_buffer[2]	= (NextFileAddr>>16)&0xff;
			str_buffer[3]	= (NextFileAddr>>8)&0xff;
			len = str_buffer[1];		
			len = len*18+6;
			str_buffer[len-1]	= 0;
			for(i=1;i<(len-2);i++)
				{
				str_buffer[len-1] += str_buffer[i];
				}
			str_buffer[len-1]	= frame_last;			
			FLASH2_GPIOSPI_Write(Addr_01min, str_buffer, len);	
			}
		else
			{
			EN  = 0x00;
			}
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2)//������ addr:0x004000-0x00ffff�
	{
		FLASH2_GPIOSPI_Read (Addr_02min, str_buffer, 1024);
		
		if((file_id == UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]) && ((file_wr&0X0F)==1))
		{
				re_send =0xff;//ȷ��Ϊ�ط�
		}
		else
		{
				re_send =0x00;//���ط�
		}
			
		if((str_buffer[0]==frame_headerC))
		{
			if(re_send==0x00)
			{
			len = str_buffer[1];		
			len = len*18+6;
			file_addr = str_buffer[2];//�´�ʼ����ʼҳ u16
			file_addr <<=8;
			file_addr += str_buffer[3];
			file_addr <<=8;
						
			f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
			f_size = file_addr+f_temp;	
			
			if((f_size<Addr_02max)&&(str_buffer[1]<=52))
				{
				EN  = 0xff;
				if((f_size&0xff)==0)
				{
				NextFileAddr = f_size;				
				}
				else
				{
				NextFileAddr = (f_size & 0xffffff00);				
				NextFileAddr += 0x100;
				}
				FLASH2_GPIOSPI_SER(Addr_02min);
				for(i=0;i<14;i++)
					{
				str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
					}
					
				str_buffer[len-2+i]	= (file_addr>>24);
					i++;
				str_buffer[len-2+i]	= (file_addr>>16)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr>>8)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr)&0xff;
					
				str_buffer[0]	= frame_headerC;
				str_buffer[1]	+= 1;
				str_buffer[2]	= (NextFileAddr>>16)&0xff;
				str_buffer[3]	= (NextFileAddr>>8)&0xff;
				len = str_buffer[1];		
				len = len*18+6;
				str_buffer[len-2]	= 0;
				for(i=1;i<(len-2);i++)
					{
					str_buffer[len-2] += str_buffer[i];
					}
				str_buffer[len-1]	= frame_last;			
				for(i=0;i<1024;)
					{
					FLASH2_GPIOSPI_Write(Addr_02min+i, &str_buffer[i], 256);	
					i += 256;
					}
					
				}
			else
				{
				EN  = 0x00;
				}
			}
			else   //���ط�
			{
				EN  = 0xff;
			}
		
		}
		else
		{
		str_buffer[0]= frame_headerC;	
		str_buffer[1]= 0x00;	
		//�ļ���ͷ��Addr_02min �ļ����ݴ�Addr_02min+0X1000	
		f_temp = Addr_02min + 0x1000;
		str_buffer[2]= ((f_temp>>16)&0xff);	
		str_buffer[3]= ((f_temp>>8)&0xff);	
		len = str_buffer[1];		
		len = len*18+6;
		file_addr = str_buffer[2];
		file_addr <<=8;
		file_addr += str_buffer[3];
		file_addr <<=8;
			
		f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		f_size = file_addr+f_temp;	
		
		if((f_size<Addr_02max)&&(str_buffer[1]<=52))
			{
			EN  = 0xff;
			if((f_size&0xff)==0)
			{
			NextFileAddr = f_size;				
			}
			else
			{
			NextFileAddr = (f_size & 0xffffff00);				
			NextFileAddr += 0x100;
			}
			FLASH2_GPIOSPI_SER(Addr_02min);
			for(i=0;i<14;i++)
				{
			str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
				}
				
			str_buffer[len-2+i]	= (file_addr>>24);
				i++;
			str_buffer[len-2+i]	= (file_addr>>16)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr>>8)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr)&0xff;
				
			str_buffer[0]	= frame_headerC;
			str_buffer[1]	+= 1;
			str_buffer[2]	= (NextFileAddr>>16)&0xff;
			str_buffer[3]	= (NextFileAddr>>8)&0xff;
			len = str_buffer[1];		
			len = len*18+6;
			str_buffer[len-2]	= 0;
			for(i=1;i<(len-2);i++)
				{
				str_buffer[len-2] += str_buffer[i];
				}
			str_buffer[len-1]	= frame_last;			
// 			for(i=256;i<len;)
// 				{
// 				i -= 256;
// 				FLASH2_GPIOSPI_Write(0x4000, &str_buffer[i], 256);	
// 				i+= 512;
// 				}
// 			if((len&0xff)>0)
// 				{
// 				FLASH2_GPIOSPI_Write(0x4000, str_buffer, (len&0xff));
// 				}		
				
			for(i=0;i<1024;)
				{
				FLASH2_GPIOSPI_Write(Addr_02min+i, &str_buffer[i], 256);	
				i += 256;
				}
			}
		else
			{
			EN  = 0x00;
			}
		}

	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==3)//��ͼ��
	{
		FLASH2_GPIOSPI_Read (Addr_03min, str_buffer, 1024);
		
		if((file_id == UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]) && ((file_wr&0X0F)==1))
		{
				re_send =0xff;//ȷ��Ϊ�ط�
		}
		else
		{
				re_send =0x00;//���ط�
		}
			
		if((str_buffer[0]==frame_headerC))
		{
			if(re_send==0x00)
			{
			len = str_buffer[1];		
			len = len*18+6;
			file_addr = str_buffer[2];//�´�ʼ����ʼҳ u16
			file_addr <<=8;
			file_addr += str_buffer[3];
			file_addr <<=8;
						
			f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
			f_size = file_addr+f_temp;	
			
			if((f_size<Addr_03max)&&(str_buffer[1]<=52))
				{
				EN  = 0xff;
				if((f_size&0xff)==0)
				{
				NextFileAddr = f_size;				
				}
				else
				{
				NextFileAddr = (f_size & 0xffffff00);				
				NextFileAddr += 0x100;
				}
				FLASH2_GPIOSPI_SER(Addr_03min);
				for(i=0;i<14;i++)
					{
				str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
					}
					
				str_buffer[len-2+i]	= (file_addr>>24);
					i++;
				str_buffer[len-2+i]	= (file_addr>>16)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr>>8)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr)&0xff;
					
				str_buffer[0]	= frame_headerC;
				str_buffer[1]	+= 1;
				str_buffer[2]	= (NextFileAddr>>16)&0xff;
				str_buffer[3]	= (NextFileAddr>>8)&0xff;
				len = str_buffer[1];		
				len = len*18+6;
				str_buffer[len-2]	= 0;
				for(i=1;i<(len-2);i++)
					{
					str_buffer[len-2] += str_buffer[i];
					}
				str_buffer[len-1]	= frame_last;			
					
				for(i=0;i<1024;)
					{
					FLASH2_GPIOSPI_Write(Addr_03min+i, &str_buffer[i], 256);	
					i += 256;
					}
				}
			else
				{
				EN  = 0x00;
				}
			}
			else   //���ط�
			{
				EN  = 0xff;
			}
		}
		else
		{
		str_buffer[0]= frame_headerC;	
		str_buffer[1]= 0x00;	
		//�ļ���ͷ��Addr_03min �ļ����ݴ�Addr_03min+0X1000	
		f_temp = Addr_03min + 0x1000;
		str_buffer[2]= ((f_temp>>16)&0xff);	
		str_buffer[3]= ((f_temp>>8)&0xff);	
		len = str_buffer[1];		
		len = len*18+6;
		file_addr = str_buffer[2];
		file_addr <<=8;
		file_addr += str_buffer[3];
		file_addr <<=8;
			
		f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		f_size = file_addr+f_temp;	
		
		if((f_size<Addr_03max)&&(str_buffer[1]<=52))
			{
			EN  = 0xff;
			if((f_size&0xff)==0)
			{
			NextFileAddr = f_size;				
			}
			else
			{
			NextFileAddr = (f_size & 0xffffff00);				
			NextFileAddr += 0x100;
			}
			FLASH2_GPIOSPI_SER(Addr_03min);
			for(i=0;i<14;i++)
				{
			str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
				}
				
			str_buffer[len-2+i]	= (file_addr>>24);
				i++;
			str_buffer[len-2+i]	= (file_addr>>16)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr>>8)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr)&0xff;
				
			str_buffer[0]	= frame_headerC;
			str_buffer[1]	+= 1;
			str_buffer[2]	= (NextFileAddr>>16)&0xff;
			str_buffer[3]	= (NextFileAddr>>8)&0xff;
			len = str_buffer[1];		
			len = len*18+6;
			str_buffer[len-2]	= 0;
			for(i=1;i<(len-2);i++)
				{
				str_buffer[len-2] += str_buffer[i];
				}
			str_buffer[len-1]	= frame_last;			
// 			for(i=256;i<len;)
// 				{
// 				i -= 256;
// 				FLASH2_GPIOSPI_Write(0x4000, &str_buffer[i], 256);	
// 				i+= 512;
// 				}
// 			if((len&0xff)>0)
// 				{
// 				FLASH2_GPIOSPI_Write(0x4000, str_buffer, (len&0xff));
// 				}		
				
			for(i=0;i<1024;)
				{
				FLASH2_GPIOSPI_Write(Addr_03min+i, &str_buffer[i], 256);	
				i += 256;
				}
			
			}
		else
			{
			EN  = 0x00;
			}
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==4)//ý��1��
	{
		FLASH2_GPIOSPI_Read (Addr_04min, str_buffer, 1280);
		
		if((file_id == UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]) && ((file_wr&0X0F)==1))
		{
				re_send =0xff;//ȷ��Ϊ�ط�
		}
		else
		{
				re_send =0x00;//���ط�
		}
			
		if((str_buffer[0]==frame_headerC))
		{
			if(re_send==0x00)
			{
			len = str_buffer[1];		
			len = len*18+6;
			file_addr = str_buffer[2];//�´�ʼ����ʼҳ u16
			file_addr <<=8;
			file_addr += str_buffer[3];
			file_addr <<=8;
						
			f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
			f_size = file_addr+f_temp;	
			
			if((f_size<Addr_04max)&&(str_buffer[1]<=60))
				{
				EN  = 0xff;
				if((f_size&0xff)==0)
				{
				NextFileAddr = f_size;				
				}
				else
				{
				NextFileAddr = (f_size & 0xffffff00);				
				NextFileAddr += 0x100;
				}
				FLASH2_GPIOSPI_SER(Addr_04min);
				for(i=0;i<14;i++)
					{
				str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
					}
					
				str_buffer[len-2+i]	= (file_addr>>24);
					i++;
				str_buffer[len-2+i]	= (file_addr>>16)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr>>8)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr)&0xff;
					
				str_buffer[0]	= frame_headerC;
				str_buffer[1]	+= 1;
				str_buffer[2]	= (NextFileAddr>>16)&0xff;
				str_buffer[3]	= (NextFileAddr>>8)&0xff;
				len = str_buffer[1];		
				len = len*18+6;
				str_buffer[len-2]	= 0;
				for(i=1;i<(len-2);i++)
					{
					str_buffer[len-2] += str_buffer[i];
					}
				str_buffer[len-1]	= frame_last;			
					
				for(i=0;i<(1280);)
					{
					FLASH2_GPIOSPI_Write(Addr_04min+i, &str_buffer[i], 256);	
					i += 256;
					}
				}
			else
				{
				EN  = 0x00;
				}
			}
			else   //���ط�
			{
				EN  = 0xff;
			}
		}
		else
		{
		str_buffer[0]= frame_headerC;	
		str_buffer[1]= 0x00;	
		//�ļ���ͷ��Addr_04min �ļ����ݴ�Addr_04min+0X1000	
		f_temp = Addr_04min + 0x1000;
		str_buffer[2]= ((f_temp>>16)&0xff);	
		str_buffer[3]= ((f_temp>>8)&0xff);	
		len = str_buffer[1];		
		len = len*18+6;
		file_addr = str_buffer[2];
		file_addr <<=8;
		file_addr += str_buffer[3];
		file_addr <<=8;
			
		f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		f_size = file_addr+f_temp;	
		
		if((f_size<Addr_04max)&&(str_buffer[1]<=60))
			{
			EN  = 0xff;
			if((f_size&0xff)==0)
			{
			NextFileAddr = f_size;				
			}
			else
			{
			NextFileAddr = (f_size & 0xffffff00);				
			NextFileAddr += 0x100;
			}
			FLASH2_GPIOSPI_SER(Addr_04min);
			for(i=0;i<14;i++)
				{
			str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
				}
				
			str_buffer[len-2+i]	= (file_addr>>24);
				i++;
			str_buffer[len-2+i]	= (file_addr>>16)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr>>8)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr)&0xff;
				
			str_buffer[0]	= frame_headerC;
			str_buffer[1]	+= 1;
			str_buffer[2]	= (NextFileAddr>>16)&0xff;
			str_buffer[3]	= (NextFileAddr>>8)&0xff;
			len = str_buffer[1];		
			len = len*18+6;
			str_buffer[len-2]	= 0;
			for(i=1;i<(len-2);i++)
				{
				str_buffer[len-2] += str_buffer[i];
				}
			str_buffer[len-1]	= frame_last;			
				
			for(i=0;i<(1280);)
				{
				FLASH2_GPIOSPI_Write(Addr_04min+i, &str_buffer[i], 256);	
				i += 256;
				}
			
			}
		else
			{
			EN  = 0x00;
			}
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==5)//ý��1��
	{
		FLASH2_GPIOSPI_Read (Addr_05min, str_buffer, 256);
		
		if((file_id == UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX]) && ((file_wr&0X0F)==1))
		{
				re_send =0xff;//ȷ��Ϊ�ط�
		}
		else
		{
				re_send =0x00;//���ط�
		}
			
		if((str_buffer[0]==frame_headerC))
		{
			if(re_send==0x00)
			{
			len = str_buffer[1];		
			len = len*18+6;
			file_addr = str_buffer[2];//�´�ʼ����ʼҳ u16
			file_addr <<=8;
			file_addr += str_buffer[3];
			file_addr <<=8;
						
			f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
			f_temp <<=	8;
			f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
			f_size = file_addr+f_temp;	
			
			if((f_size<Addr_05max)&&(str_buffer[1]<=13))
				{
				EN  = 0xff;
				if((f_size&0xff)==0)
				{
				NextFileAddr = f_size;				
				}
				else
				{
				NextFileAddr = (f_size & 0xffffff00);				
				NextFileAddr += 0x100;
				}
				FLASH2_GPIOSPI_SER(Addr_05min);
				for(i=0;i<14;i++)
					{
				str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
					}
					
				str_buffer[len-2+i]	= (file_addr>>24);
					i++;
				str_buffer[len-2+i]	= (file_addr>>16)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr>>8)&0xff;
					i++;
				str_buffer[len-2+i]	= (file_addr)&0xff;
					
				str_buffer[0]	= frame_headerC;
				str_buffer[1]	+= 1;
				str_buffer[2]	= (NextFileAddr>>16)&0xff;
				str_buffer[3]	= (NextFileAddr>>8)&0xff;
				len = str_buffer[1];		
				len = len*18+6;
				str_buffer[len-2]	= 0;
				for(i=1;i<(len-2);i++)
					{
					str_buffer[len-2] += str_buffer[i];
					}
				str_buffer[len-1]	= frame_last;			
					
			FLASH2_GPIOSPI_Write(Addr_05min, str_buffer, 256);	
				}
			else
				{
				EN  = 0x00;
				}
			}
			else   //���ط�
			{
				EN  = 0xff;
			}
		}
		else
		{
		str_buffer[0]= frame_headerC;	
		str_buffer[1]= 0x00;	
		//�ļ���ͷ��Addr_05min �ļ����ݴ�Addr_05min+0X1000	
		f_temp = Addr_05min + 0x1000;
		str_buffer[2]= ((f_temp>>16)&0xff);	
		str_buffer[3]= ((f_temp>>8)&0xff);	
		len = str_buffer[1];		
		len = len*18+6;
		file_addr = str_buffer[2];
		file_addr <<=8;
		file_addr += str_buffer[3];
		file_addr <<=8;
			
		f_temp  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		f_temp <<=	8;
		f_temp  += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		f_size = file_addr+f_temp;	
		
		if((f_size<Addr_05max)&&(str_buffer[1]<=13))
			{
			EN  = 0xff;
			if((f_size&0xff)==0)
			{
			NextFileAddr = f_size;				
			}
			else
			{
			NextFileAddr = (f_size & 0xffffff00);				
			NextFileAddr += 0x100;
			}
			FLASH2_GPIOSPI_SER(Addr_05min);
			for(i=0;i<14;i++)
				{
			str_buffer[len-2+i]=	UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6+i)&UART1_RX_MAX];
				}
				
			str_buffer[len-2+i]	= (file_addr>>24);
				i++;
			str_buffer[len-2+i]	= (file_addr>>16)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr>>8)&0xff;
				i++;
			str_buffer[len-2+i]	= (file_addr)&0xff;
				
			str_buffer[0]	= frame_headerC;
			str_buffer[1]	+= 1;
			str_buffer[2]	= (NextFileAddr>>16)&0xff;
			str_buffer[3]	= (NextFileAddr>>8)&0xff;
			len = str_buffer[1];		
			len = len*18+6;
			str_buffer[len-2]	= 0;
			for(i=1;i<(len-2);i++)
				{
				str_buffer[len-2] += str_buffer[i];
				}
			str_buffer[len-1]	= frame_last;			
				
			FLASH2_GPIOSPI_Write(Addr_05min, str_buffer, 256);	
			}
		else
			{
			EN  = 0x00;
			}
		}
	}
	
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		if(EN==0)
		{
		UART1_TXBUFFER[5] =  0;
		}
		else
		{
		UART1_TXBUFFER[5] =  0xff;
		file_wr = 1;	//�ļ���������
		file_id = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];  //��ǰд��
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1)  //д1����
		{
			file_wr |= 0x10;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2)	//д2����
		{
			file_wr |= 0x20;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==3)	//д3����
		{
			file_wr |= 0x30;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==4)	//д4����
		{
			file_wr |= 0x40;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==5)	//д4����
		{
			file_wr |= 0x50;
		}
		file_hook = 0;
		}
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
	
}

//-----0x12----------------------------------------------------------------------------
void cmd_File_Tx(void)
{
	u16 i,len,EN;
	
	EN = Frame_check_cmd1();  //У��ȶԡ�
	if(EN==0xff)
	{
		
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==file_hook)&& ((file_wr&0x01) ==1))//������û�ж���
	{
		file_hook++;
		file_wr |= 0x02;//��ʼд�ļ�
		len = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX]*2;
		EN  = 0xFF;
		if(len==266) //�ǲ�����ҳ
		{
			for(i=0;i<256;i++)
			{
			str_buffer[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7+i)&UART1_RX_MAX];
			}
			FLASH2_GPIOSPI_Write(file_addr, str_buffer, 256);
			
			FLASH2_GPIOSPI_Read(file_addr, &str_buffer[1000], 256);
			for(i=0;i<256;i++)
			{
			if(str_buffer[1000+i]!=str_buffer[i])
				{
					EN = 0; break;
				}
			}
			
			file_addr +=256;
		}
		else
		{
			for(i=0;i<(len-10);i++)
			{
			str_buffer[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7+i)&UART1_RX_MAX];
			}
		FLASH2_GPIOSPI_Write(file_addr, str_buffer, len-10);
			
			FLASH2_GPIOSPI_Read(file_addr, &str_buffer[1000], len-10);
			for(i=0;i<len-10;i++)
			{
			if(str_buffer[1000+i]!=str_buffer[i])
				{
					EN = 0; break;
				}
			}
			
			file_addr +=len-10;
		}
//		EN  = 0xFF;
	}
	else
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==(file_hook-1)))//������һ��
	{
		EN  = 0xFF;
	}
	else
	{
		EN  = 0x00;
//		EN  = file_hook;
	}
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==0xff))//�������
		{
			if((file_wr&0xF0)== 0x10)
			{
				device.use |=0x10;
				FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
			  len = str_buffer[1];	//����һ���ļ����ļ���	
			  len = len*18+6;
				str_buffer[len-2+6-18] -= 4;//��д���ļ������̶���4���ļ�������ֽڡ�
				
			  str_buffer[len-1]	= 0;
			  for(i=1;i<(len-2);i++)
				{
				str_buffer[len-1] += str_buffer[i];
				}
			  str_buffer[len-1]	= frame_last;	
				FLASH2_GPIOSPI_SER(Addr_01min);
			  FLASH2_GPIOSPI_Write(Addr_01min, str_buffer, len);	
			}
			file_wr = 0;			
		}
		
	}
		
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  5;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		UART1_TXBUFFER[6] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
		
		if(EN==0)
		{
		UART1_TXBUFFER[7] =  0;
		}
		else
		{
		UART1_TXBUFFER[7] =  0xff;
		}
		UART1_TXBUFFER[8] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[8] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[9] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
	
}

//----0x13-----------------------------------------------------------------------------
void cmd_File_Recall(void)
{
	u16 i,en,x_load,y_load;
	u32 f_addr,f_size;
	
		en = 0x00;
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1)//��ά����
	{
		FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>13)
		{	
			str_buffer[1] = 13;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[0])
			{
				display_flash_BMP (80,56,f_addr,1);
			}
			else
			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[1])
			{
				display_flash_BMP (80,56,f_addr,2);
			}
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2)//������
	{
		FLASH2_GPIOSPI_Read (Addr_02min, str_buffer, 1024);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>52)
		{	
			str_buffer[1] = 52;	
		}
//		UART1_Send_Data(str_buffer,str_buffer[1]*18+6);
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		if(f_size>0)
		{
			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[0])
			{
			FLASH2_GPIOSPI_Read (f_addr, LCD1_TxtBuffer, f_size);
			LCD1_TxtBuffer[2048]=0;
			LCD1_TxtBuffer[2049]=0;
			}
			else
			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[1])
			{
			FLASH2_GPIOSPI_Read (f_addr, LCD2_TxtBuffer, f_size);
			LCD2_TxtBuffer[2048]=0;
			LCD2_TxtBuffer[2049]=0;
			}
		}

	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==3)//��ͼ��
	{
		FLASH2_GPIOSPI_Read (Addr_03min, str_buffer, 1024);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>52)
		{	
			str_buffer[1] = 52;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, DISABLE);

			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[0])
			{
				if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX]>=7)
				{
				x_load = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
				x_load <<= 8;
				x_load += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
				y_load = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
				y_load <<= 8;
				y_load += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
				display_flash_BMP (x_load,y_load,f_addr,1);
				}
				else
				{	
				display_flash_BMP (0,0,f_addr,1);
				}
			}
			else
			if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==device.port_id[1])
			{
				if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX]>=7)
				{
				x_load = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
				x_load <<= 8;
				x_load += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
				y_load = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
				y_load <<= 8;
				y_load += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
				display_flash_BMP (x_load,y_load,f_addr,2);
				}
				else
				{	
				display_flash_BMP (0,0,f_addr,2);
				}
			}
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==5)//������
	{
		FLASH2_GPIOSPI_Read (Addr_05min, str_buffer, 256);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>13)
		{	
			str_buffer[1] = 13;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
			info2STR.item21[0] = 21;
			info2STR.item21[1] = 4;
			info2STR.item21_data[0] = 0x01;
			info2STR.item21_data[1] = 0x00;
			info2STR.item21_data[2] = 0x05;
			info2STR.item21_data[3] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
			
			if(device.Version[0]==Version_FLAG1)     //bl������
			{
				Check_CHIP_PRO();  //
			}
			else				//USER������
			{
				NVIC_SystemReset();    //��λ
			}						
		}
	}
	else
	{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
	}
}

//----0x14-----------------------------------------------------------------------------
void cmd_File_Erase(void)
{
	u8 i,EN;
	u32 temp;
	
	EN = Frame_check_cmd1();  //У��ȶԡ�
	if(EN!=0xff)
	{
		return;
	}	
	FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
	UART1_TXBUFFER[0] =  frame_headerD;
	UART1_TXBUFFER[1] =  4;  //len
	UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
	UART1_TXBUFFER[3] =  device.addr;
	UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	UART1_TXBUFFER[5] =  0x01;
	UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
	for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
	{
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
	}
	UART1_TXBUFFER[7] =  frame_last;
	UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));

	temp =0;
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX])==1)//��ά����
	{
	for(temp=Addr_01min;temp<Addr_01max;)	
		{
//			FLASH2_GPIOSPI_SER(temp);
//			temp +=4096;
			FLASH2_GPIOSPI_SE(temp);
			temp +=0x10000;
		}
		  info2STR.item11[0] = 11;
		  info2STR.item11[1] = 0;
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
	}
	else
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX])==2)//������
	{
	for(temp=Addr_02min;temp<Addr_02max;)	
		{
//			FLASH2_GPIOSPI_SER(temp);
//			temp +=4096;
			FLASH2_GPIOSPI_SE(temp);
			temp +=0x10000;
		}
		  info2STR.item12[0] = 12;
		  info2STR.item12[1] = 0;
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
	}
	else
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX])==3)//��ͼ��
	{
	for(temp=Addr_03min;temp<Addr_03max;)	
		{
//			FLASH2_GPIOSPI_SER(temp);
//			temp +=4096;
			FLASH2_GPIOSPI_SE(temp);
			temp +=0x10000;
		}
		  info2STR.item13[0] = 13;
		  info2STR.item13[1] = 0;
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
	}
	else
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX])==4)//��ͼ��
	{
	for(temp=Addr_04min;temp<Addr_04max;)	
		{
//			FLASH2_GPIOSPI_SER(temp);
//			temp +=4096;
			FLASH2_GPIOSPI_SE(temp);
			temp +=0x10000;
		}
		  info2STR.item14[0] = 14;
		  info2STR.item14[1] = 0;
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
	}
	if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX])==5)//
	{
	for(temp=Addr_05min;temp<Addr_05max;)	
		{
//			FLASH2_GPIOSPI_SER(temp);
//			temp +=4096;
			FLASH2_GPIOSPI_SE(temp);
			temp +=0x10000;
		}
		  info2STR.item15[0] = 15;
		  info2STR.item15[1] = 0;
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
	}
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  0xff;
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));	
}

//---------------------------------------------------------------------------------
void cmd_Port_Info(void)   //PC��Ҫ���ϵ������Ϣ
{
	u8 i,data;
		data = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		data %= 2;
		if(data==0)
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  6;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[0];
		UART1_TXBUFFER[6] =  (Uport_PowerSetTime[0]>>8);
		UART1_TXBUFFER[7] =  (Uport_PowerSetTime[0]&0xff);
		UART1_TXBUFFER[8] =  (Uport_PowerUseTime[0]>>8);
		UART1_TXBUFFER[9] =  (Uport_PowerUseTime[0]&0xff);
		UART1_TXBUFFER[10] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[10] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[11] =  frame_last;
		
		i= (device.addr>>4);
		i = i*2+4;
		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
		else
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  6;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  device.port_id[1];
		UART1_TXBUFFER[6] =  (Uport_PowerSetTime[1]>>8);
		UART1_TXBUFFER[7] =  (Uport_PowerSetTime[1]&0xff);
		UART1_TXBUFFER[8] =  (Uport_PowerUseTime[1]>>8);
		UART1_TXBUFFER[9] =  (Uport_PowerUseTime[1]&0xff);
		UART1_TXBUFFER[10] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[10] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[11] =  frame_last;
		
// 		i= (device.addr>>4);
// 		i = i*2+4;
// 		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
}
//---------------------------------------------------------------------------------
//��ȡ����ٶ� 0x54
void cmd_Get_charge_speed(void)   //��ȡ����ٶ�
{
	u8 i;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  5;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
//		UART1_TXBUFFER[6] =  charge_speed[0];
	
		if(UART1_TXBUFFER[5]==device.port_id[0])
		{
			if(ADC_BUFFER[20]-ADC_Base0[6]>0xD00)		 //0XD00=560MA
			{
			UART1_TXBUFFER[6] =  2;
			}
			else
			if(ADC_BUFFER[20]-ADC_Base0[6]>0x200)   //0x200=80MA
			{
			UART1_TXBUFFER[6] =  1;
			}
			else
			{
			UART1_TXBUFFER[6] =  0;
			}
			
		UART1_TXBUFFER[7] =  0;
			
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		else
		if(UART1_TXBUFFER[5]==device.port_id[1])
		{
			if(ADC_BUFFER[23]-ADC_Base0[7]>0xD00)   //0XD00=560MA
			{
			UART1_TXBUFFER[6] =  2;
			}
			else
			if(ADC_BUFFER[23]-ADC_Base0[7]>0x200)  //0x200=80MA
			{
			UART1_TXBUFFER[6] =  1;
			}
			else
			{
			UART1_TXBUFFER[6] =  0;
			}
			
		UART1_TXBUFFER[7] =  0;
			
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
}
//---------------------------------------------------------------------------------
//�·�:67  0D  XX(????)  F0  55  02(�˿ڸ���)  XX(�˿ں�)  U64(??????)  XX(�˿ں�)  U64(??????)  XX(???)  99
//����:68  0D  F0  XX(???)  55  02(????)  XX(???X1)  U64(??????)  XX(???X2)  U64(??????)  XX(???)  99
// 		str_buffer[0]=     // u8  0X67
// 		str_buffer[?]=     // u8  �ļ�����
// 		str_buffer[?]=     //u16  �´�ʼ����ʼҳ
// 		str_buffer[?]=     //u8  �ļ���
// 		str_buffer[?]=		 //u8  �ļ���
// 		str_buffer[?]=		 //u32 �ļ���С
// 		str_buffer[?]=		 //u64 �ļ���
// 		str_buffer[?]=		 //u32 �ļ����ַ
// 		str_buffer[?]=     //check
// 		str_buffer[?]=     //β0X99

void cmd_Device_Check(void)//�˶���Ϣ
{
	//ͬʱ�������˿ڵĶ�ά����к˶�
	u16 i;
//	u32 f_temp;
		FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
		
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  0x0d;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  0x02;
	
		if((str_buffer[0]==frame_headerC))
		{			
			if(str_buffer[1]>0)
			{
			UART1_TXBUFFER[6] = str_buffer[5];
				
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[7+i] = str_buffer[10+i];
				}
			}
			else
			{
			UART1_TXBUFFER[6] = 0;
				
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[7+i] = 0;
				}
			}
			
			if(str_buffer[1]>1)
			{
			UART1_TXBUFFER[15] = str_buffer[5+18];
				
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[16+i] = str_buffer[10+18+i];
				}
			}
			else
			{
			UART1_TXBUFFER[15] = 0;
				
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[16+i] = 0;
				}
			}			
		}
		else
		{
			UART1_TXBUFFER[6] = 0;				
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[7+i] = 0;
				}
				
			UART1_TXBUFFER[15] = 0;
				for(i=0;i<8;i++)
				{
					UART1_TXBUFFER[16+i] = 0;
				}
		}
		UART1_TXBUFFER[24] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[24] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[25] =  frame_last;
		
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
}
//---------------------------------------------------------------------------------
void cmd_MediaCtrl(void)
{
		u8 i,en;

		en = 0x01;
//		FLASH2_GPIOSPI_Read (Addr_info2, str_buffer, sizeof(info2STR));
		FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
		
			info2STR.head[0] = frame_headerC;
			info2STR.head[1] = sizeof(info2STR); 
			info2STR.head[1] >>=1;
			info2STR.temp[0] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
			info2STR.temp[1] = device.addr;
			info2STR.temp[2] = 0xff;//��Ŀ����ȷ��ֵ
			
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==1)  //��Ŀ��
		{
			for(i=0;i<5;i++)
			{
				info2STR.item1[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
			LCDC.PSwitch = info2STR.item1_data[0];
			LCDC.LCDPTimeSet = info2STR.item1_data[1];	
			LCDC.LCDPTimeSet <<= 8;	
			LCDC.LCDPTimeSet += info2STR.item1_data[2];	
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==2)  //��Ŀ��
		{
			for(i=0;i<5;i++)
			{
				info2STR.item2[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
			LCDC.SPSwitch = info2STR.item2_data[0];
			LCDC.LCDSPTimeSet = info2STR.item2_data[1];	
			LCDC.LCDSPTimeSet <<= 8;	
			LCDC.LCDSPTimeSet += info2STR.item2_data[2];	
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==3)  //��Ŀ����ʾ�ֿ���
		{
			for(i=0;i<4;i++)
			{
				info2STR.item3[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
			for(i=0;i<sizeof(info2STR);i++)
			{
				str_buffer[i] =info2STR.head[i];
			}

			en = 0xff;
			FLASH2_GPIOSPI_Read (Addr_info2, &str_buffer[1024], sizeof(info2STR));			
		 for(i=0;i<sizeof(info2STR);i++)
			{
				if(str_buffer[i]!=str_buffer[1024+i])
				{
					en = 0;
				}
			}
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  en;
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));

		FLASH2_GPIOSPI_Read (Addr_04min, str_buffer, 64);  //��ȡͼƬ����
		LCDC.PNum = str_buffer[1];
		LCDC.LCD1PTime=0;		//����ʱ
		LCDC.LCD2PTime=0;		//����ʱ

}

//---------------------------------------------------------------------------------
//���汾���� 0X32
void cmd_Set_Version(void)
{
		u8 i,en;

		en = 0x01;
		FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
		
			info2STR.head[0] = frame_headerC;
			info2STR.head[1] = sizeof(info2STR); 
			info2STR.head[1] >>=1;
			info2STR.temp[0] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
			info2STR.temp[1] = device.addr;
			info2STR.temp[2] = 0xff;//��Ŀ����ȷ��ֵ
			
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==11)  //��Ŀ��
		{
			for(i=0;i<18;i++)
			{
				info2STR.item11[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==12)  //��Ŀ��
		{
			for(i=0;i<18;i++)
			{
				info2STR.item12[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==13)  //��Ŀ��
		{
			for(i=0;i<18;i++)
			{
				info2STR.item13[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==14)  //��Ŀ��
		{
			for(i=0;i<18;i++)
			{
				info2STR.item14[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==15)  //��Ŀ��
		{
			for(i=0;i<18;i++)
			{
				info2STR.item15[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
			}
		}
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
			for(i=0;i<sizeof(info2STR);i++)
			{
				str_buffer[i] =info2STR.head[i];
			}

			en = 0xff;
			FLASH2_GPIOSPI_Read (Addr_info2, &str_buffer[1024], sizeof(info2STR));			
		 for(i=0;i<sizeof(info2STR);i++)
			{
				if(str_buffer[i]!=str_buffer[1024+i])
				{
					en = 0;
				}
			}			
			
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  en;
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
}

//---------------------------------------------------------------------------------
//���汾��ȡ 0X33
void cmd_Get_Version(void)
{
		u8 i;

		FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
					
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==11)  //��Ŀ��
		{
			for(i=0;i<128;i++)
			{
					UART1_TXBUFFER[i] = 0;
			}
			if(info2STR.item11[1]<=16)
			{
				for(i=0;i<(info2STR.item11[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item11[i] ;
				}
			}
			else
			{
				info2STR.item11[1] =0 ;
				for(i=0;i<(info2STR.item11[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item11[i] ;
				}
			}
		
		i = 9+ info2STR.item11[1];
		i >>= 1;
		i += (9+ info2STR.item11[1])%2;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  i;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==12)  //��Ŀ��
		{
			for(i=0;i<128;i++)
			{
					UART1_TXBUFFER[i] = 0;
			}
			if(info2STR.item12[1]<=16)
			{
				for(i=0;i<(info2STR.item12[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item12[i] ;
				}
			}
			else
			{
				info2STR.item12[1] =0 ;
				for(i=0;i<(info2STR.item12[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item12[i] ;
				}
			}
		
		i = 9+ info2STR.item12[1];
		i >>= 1;
		i += (9+ info2STR.item12[1])%2;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  i;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==13)  //��Ŀ��
		{
			for(i=0;i<128;i++)
			{
					UART1_TXBUFFER[i] = 0;
			}
			if(info2STR.item13[1]<=16)
			{
				for(i=0;i<(info2STR.item13[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item13[i] ;
				}
			}
			else
			{
				info2STR.item13[1] =0 ;
				for(i=0;i<(info2STR.item13[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item13[i] ;
				}
			}
		
		i = 9+ info2STR.item13[1];
		i >>= 1;
		i += (9+ info2STR.item13[1])%2;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  i;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==14)  //��Ŀ��
		{
			for(i=0;i<128;i++)
			{
					UART1_TXBUFFER[i] = 0;
			}
			if(info2STR.item14[1]<=16)
			{
				for(i=0;i<(info2STR.item14[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item14[i] ;
				}
			}
			else
			{
				info2STR.item14[1] =0 ;
				for(i=0;i<(info2STR.item14[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item14[i] ;
				}
			}
		
		i = 9+ info2STR.item14[1];
		i >>= 1;
		i += (9+ info2STR.item14[1])%2;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  i;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==15)  //��Ŀ��
		{
			for(i=0;i<128;i++)
			{
					UART1_TXBUFFER[i] = 0;
			}
			if(info2STR.item15[1]<=16)
			{
				for(i=0;i<(info2STR.item15[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item15[i] ;
				}
			}
			else
			{
				info2STR.item15[1] =0 ;
				for(i=0;i<(info2STR.item15[1]+2);i++)
				{
					UART1_TXBUFFER[5+i]= info2STR.item15[i] ;
				}
			}
		
		i = 9+ info2STR.item15[1];
		i >>= 1;
		i += (9+ info2STR.item15[1])%2;
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  i;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		}
		
}
//---------------------------------------------------------------------------------
//��ȡ������ 0X34
void cmd_Get_AD_count(void) 
{
	u8 i;
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] == 129)
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  5+LCDC.PNum;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		UART1_TXBUFFER[6] =  (LCDC.PNum<<1);
	
		for(i=0;i<LCDC.PNum;i++)
		{
			UART1_TXBUFFER[7+i*2] = (AD_count[i]&0xff);
			UART1_TXBUFFER[7+i*2+1] = ((AD_count[i]>>8)&0xff);
		}	
		UART1_TXBUFFER[7+i*2]= 0;
		for(i=0;i<60;i++)
		{
			AD_count[i] = 0;
		}
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
	}
}

//---------------------------------------------------------------------------------
void cmd_Device_num(void)
{
		u8 i,en,temp;

		en = 0x0;
		FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
		temp = info2STR.item81[1];
		if(temp>16)
		{		temp = 16;		}
		else
		if(temp==0)
		{		temp = 8;		}
			
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==81)  //��Ŀ��
		{
			en = 0xff;
			for(i=0;i<(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]+2);i++)  //�ж�Ҫ��Ҫ��д
			{
				if(info2STR.item81[i] != UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX])
				{
						en = 0;
				}
			}
			
			if(en == 0)  //Ҫ��д
			{				
			info2STR.head[0] = frame_headerC;
			info2STR.head[1] = sizeof(info2STR); 
			info2STR.head[1] >>=1;
			info2STR.temp[0] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
			info2STR.temp[1] = device.addr;
			info2STR.temp[2] = 0xff;//��Ŀ����ȷ��ֵ

				if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]==81)  //��Ŀ��
			{
				for(i=0;i<(18);i++)
				{
					info2STR.item81[i] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5+i)&UART1_RX_MAX];
				}
			}
				FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
				FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
			}
			for(i=0;i<sizeof(info2STR);i++)
			{
				str_buffer[i] =info2STR.head[i];
			}

			en = 0xff;
			FLASH2_GPIOSPI_Read (Addr_info2, &str_buffer[1024], sizeof(info2STR));			
		 for(i=0;i<sizeof(info2STR);i++)
			{
				if(str_buffer[i]!=str_buffer[1024+i])
				{
					en = 0;
				}
			}
		}
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  en;
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));		
		
		if(info2STR.item81[1]<=16)
		{
			for(i=0;i<info2STR.item81[1];i++)
			{
					device_num[i]= info2STR.item81_data[i];
			}
		}
		else			
		{
			info2STR.item81[1] = 8;
			for(i=0;i<info2STR.item81[1];i++)
			{
					device_num[i]= '?';
			}
		}
				device_num[i++]= 0;
		
		if(LCDC.LCD1SPPID==1)
		{
			for(i=0;i<temp;i++)
			{		UART_BUFFER[i] = ' ';  }
			UART_BUFFER[i] = 0;
			tft_DisplayStr(15, 125, UART_BUFFER,POINT_COLOR, BACK_COLOR,1);
		tft_DisplayStr(15, 125, device_num,0x0000,0xffff,1);
		}
		else
		if(LCDC.LCD1SPPID==0)
		{
			for(i=0;i<temp;i++)
			{		UART_BUFFER[i] = ' ';  }
			UART_BUFFER[i] = 0;
			tft_DisplayStr(270, 125, UART_BUFFER,POINT_COLOR, BACK_COLOR,1);
		tft_DisplayStr(270, 125, device_num,0x0000,0xffff,1);
		}
		
		if(LCDC.LCD2SPPID==1)
		{
			for(i=0;i<temp;i++)
			{		UART_BUFFER[i] = ' ';  }
			UART_BUFFER[i] = 0;
			tft_DisplayStr(15, 125, UART_BUFFER,POINT_COLOR, BACK_COLOR,2);
		tft_DisplayStr(15, 125, device_num,0x0000,0xffff,2);
		}
		else
		if(LCDC.LCD2SPPID==0)
		{
			for(i=0;i<temp;i++)
			{		UART_BUFFER[i] = ' ';  }
			UART_BUFFER[i] = 0;
			tft_DisplayStr(270, 125, UART_BUFFER,POINT_COLOR, BACK_COLOR,2);
		tft_DisplayStr(270, 125, device_num,0x0000,0xffff,2);
		}
}
//---------------------------------------------------------------------------------
void cmd_ShakeHands(void)
{
	u16 i;
	u8 temp;
	
		temp = 0;
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==1)
		{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				UART_BUFFER[0] = 'C';
				UART_BUFFER[1] = 0;
				tft_DisplayStr(0, 0, UART_BUFFER,0XFFFF, 0X0000,3);
				LCDC.LCD1SPTime = 0;
				LCDC.LCD2SPTime = 0;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==2)
		{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				UART_BUFFER[0] = 'S';
				UART_BUFFER[1] = 0;
				tft_DisplayStr(0, 0, UART_BUFFER,0XFFFF, 0X0000,3);
				LCDC.LCD1SPTime = 0;
				LCDC.LCD2SPTime = 0;
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==3)//APP MODE
		{
				if(device.Version[0]!=Version_FLAG1)
				{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				}
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==4) //BL MODE
		{
				if(device.Version[0]==Version_FLAG1)
				{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				}
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==0x1f)  //BL����
		{
				if(device.Version[0]==Version_FLAG1)   
				{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				KEEP_EN = 0xff;
				}
		}
		else
		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] ==0x10) //BL�˳�
		{
				if(device.Version[0]==Version_FLAG1)
				{
				temp = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
				KEEP_EN = 0x00;
				}
		}
		
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  temp;
	
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		
// 		i= (device.addr>>4);
// 		i = i*2+4;
// 		while((time_sys-time_uart1) <i);
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
}//---------------------------------------------------------------------------------
void Hub_Rst(u8 addr,u8 port)
{
		

}
//---------------------------------------------------------------------------------
void cmd_Hub_Rst(void)
{
	u8 i;
	
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0x01)  //��HUB��λ
	{
		if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX] ==0xff)||((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]>>4)==(device.addr>>4)))
		{
		GPIO_ResetBits(HUB0_REST_PORT, HUB0_REST_PIN);  
		GPIO_ResetBits(HUB1_REST_PORT, HUB1_REST_PIN);  
		Delay_us(100);	
		GPIO_SetBits(HUB0_REST_PORT, HUB0_REST_PIN);  			
		GPIO_SetBits(HUB1_REST_PORT, HUB1_REST_PIN);  			
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0x02)  //��HUB��λ
	{
		if(((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]/2)==(device.addr/2)))
		{
		GPIO_ResetBits(HUB0_REST_PORT, HUB0_REST_PIN);  
		GPIO_ResetBits(HUB1_REST_PORT, HUB1_REST_PIN);  
		Delay_us(100);	
		GPIO_SetBits(HUB0_REST_PORT, HUB0_REST_PIN);  			
		GPIO_SetBits(HUB1_REST_PORT, HUB1_REST_PIN);  			
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0x04)  //��HUB��λ
	{
		if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]==device.addr))
		{
			if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]==device.port_id[0]))
			{
			GPIO_ResetBits(HUB0_REST_PORT, HUB0_REST_PIN);  
			Delay_us(100);	
			GPIO_SetBits(HUB0_REST_PORT, HUB0_REST_PIN);  			
			}
			else
			if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]==device.port_id[1]))
			{
			GPIO_ResetBits(HUB1_REST_PORT, HUB1_REST_PIN);  
			Delay_us(100);	
			GPIO_SetBits(HUB1_REST_PORT, HUB1_REST_PIN);  			
			}
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0x40)  //��Ƭ����λE
	{
		if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX] ==0xff)||(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]==device.addr))
		{
		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
			Delay_us(200);	
		//��ȡ����
		Get_ADC_BaseLine();
		FLASH2_GPIOSPI_Read (Addr_info1, str_buffer, 64);
		global_u8p = (u8*)ADC_Base0;
		for(i=0;i<16;i++)
		{
			str_buffer[6+i] = global_u8p[i];
		}
		
		str_buffer[0] = 0x67;
		str_buffer[1] = 0x16;
		str_buffer[2] = device.addr;
		str_buffer[3] = 0xf0;
		str_buffer[(str_buffer[1]<<1)-2] = 0;//check;
		for(i=1;i<((str_buffer[1]<<1)-2);i++)
		{
			str_buffer[(str_buffer[1]<<1)-2] += str_buffer[i];
		}
		str_buffer[(str_buffer[1]<<1)-1] = 0x99;
		
		FLASH2_GPIOSPI_SER(Addr_info1);  ////ÿ�β���4K
		FLASH2_GPIOSPI_Write(Addr_info1, str_buffer, (str_buffer[1]<<1));
			NVIC_SystemReset();
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0x80)  //��Ƭ����λ
	{
		if((UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX] ==0xff)||(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+2)&UART1_RX_MAX]==device.addr))
		{
			NVIC_SystemReset();
		}
	}
	
}

//---------------------------------------------------------------------------------
void Hub_ID_Info(void)
{
		
}

//---------------------------------------------------------------------------------
void cmd3_Get_State(void)
{
	u8 i;
		UART3_TXBUFFER[0] =  frame_headerD;
		UART3_TXBUFFER[1] =  9;  //len
		UART3_TXBUFFER[2] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+3)&UART3_RX_MAX];
		UART3_TXBUFFER[3] =  device.addr;
		UART3_TXBUFFER[4] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+4)&UART3_RX_MAX];
		UART3_TXBUFFER[5] =  device.port_num;
		UART3_TXBUFFER[6] =  device.hub_id[0];
		UART3_TXBUFFER[7] =  device.hub_id[1];
		UART3_TXBUFFER[8] =  device.hub_id[2];
		UART3_TXBUFFER[9] =  device.hub_id[3];
		UART3_TXBUFFER[10] =  device.hub_id[4];
		UART3_TXBUFFER[11] =  device.hub_id[5];
		UART3_TXBUFFER[12] =  device.hub_id[6];
		UART3_TXBUFFER[13] =  device.hub_id[7];
		UART3_TXBUFFER[14] =  device.port_id[0];
		UART3_TXBUFFER[15] =  device.port_id[1];
		UART3_TXBUFFER[16] = 0;
		for(i=1;i<((UART3_TXBUFFER[1]<<1)-2);i++)
		{
			UART3_TXBUFFER[16] += UART3_TXBUFFER[i];
		}
//		UART3_TXBUFFER[16] =  check;
		UART3_TXBUFFER[17] =  frame_last;
		
		UART3_Send_Data(UART3_TXBUFFER,(UART3_TXBUFFER[1]<<1));
}

//---------------------------------------------------------------------------------
void cmd3_Set_State(void)
{
	u8 i;
	
	testcmd3_time = time_s;
	device.head = 0x67;
	device.addr = UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+2)&UART3_RX_MAX];
	device.port_num = UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+5)&UART3_RX_MAX];
	device.hub_id[0]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+6)&UART3_RX_MAX];
	device.hub_id[1]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+7)&UART3_RX_MAX];
	device.hub_id[2]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+8)&UART3_RX_MAX];
	device.hub_id[3]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+9)&UART3_RX_MAX];
	device.hub_id[4]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+10)&UART3_RX_MAX];
	device.hub_id[5]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+11)&UART3_RX_MAX];
	device.hub_id[6]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+12)&UART3_RX_MAX];
	device.hub_id[7]= UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+13)&UART3_RX_MAX];
	device.port_id[0] = UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+14)&UART3_RX_MAX];
	device.port_id[1] = UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+15)&UART3_RX_MAX];
	
		FLASH2_GPIOSPI_Read (0, str_buffer, 128);
// 		str_buffer[0]=     //ͷ0X67
// 		str_buffer[?]=     //LEN
// 		str_buffer[?]=     //�ļ���u8
// 		str_buffer[?]=		 //�ļ���u8
// 		str_buffer[?]=		 //�ļ���u64
// 		str_buffer[?]=		//�ļ���Сu32
// 		str_buffer[?]=		//�ļ����ַu32
// 		str_buffer[?]=     //check
// 		str_buffer[?]=     //β0X99
	
		UART3_TXBUFFER[0] =  frame_headerD;
		UART3_TXBUFFER[1] =  4;  //len
		UART3_TXBUFFER[2] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+3)&UART3_RX_MAX];
		UART3_TXBUFFER[3] =  device.addr;
		UART3_TXBUFFER[4] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+4)&UART3_RX_MAX];
		GPIO_SetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
  		if(device.port_id[0]==str_buffer[3])   //��ַ�����ж�
		{
		UART3_TXBUFFER[5] =  0xff;
		device.use &= (~0x02);
// 		GPIO_SetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
		}
 		else
		{
		UART3_TXBUFFER[5] =  0x00;
		device.use |= (0x02);	
//		GPIO_ResetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
		}
		UART3_TXBUFFER[6] = 0;
		for(i=1;i<((UART3_TXBUFFER[1]<<1)-2);i++)
		{
			UART3_TXBUFFER[6] += UART3_TXBUFFER[i];
		}
		UART3_TXBUFFER[7] =  frame_last;
		
		UART3_Send_Data(UART3_TXBUFFER,(UART3_TXBUFFER[1]<<1));
		
//  		if(device.port_id[0]!=str_buffer[3])   //��ַ�����ж�
// 		{
// 		GPIO_ResetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
// 		}
		

}
//---------------------------------------------------------------------------------
void cmd3_ShakeHands(void)
{
	u8 i;
		testcmd3_time = time_s;
		UART3_TXBUFFER[0] =  frame_headerD;
		UART3_TXBUFFER[1] =  4;  //len
		UART3_TXBUFFER[2] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+3)&UART3_RX_MAX];
		UART3_TXBUFFER[3] =  device.addr;
		UART3_TXBUFFER[4] =  UART3_RXBUFFER[(UART3_RXBUFFE_HEAD+4)&UART3_RX_MAX];
		UART3_TXBUFFER[5] =  0x00;
		UART3_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART3_TXBUFFER[1]<<1)-2);i++)
		{
			UART3_TXBUFFER[6] += UART3_TXBUFFER[i];
		}
		UART3_TXBUFFER[7] =  frame_last;
		
		i= (device.addr>>4);
		i = i*2+4;
		while((time_sys-time_uart1) <i);
		UART3_Send_Data(UART3_TXBUFFER,(UART3_TXBUFFER[1]<<1));
}
//---------------------------------------------------------------------------------
void Dport_ChargeState(void)
{
	u8 i;
	u8 flag;
			
	for(i=0;i<3;i++)
	{
			flag = 0xff;
	if((Dport_State[i]&0x0c)==0x0c)
		{
			flag = i;
			break;
		}	
	}
	Dport_State[0] = 0;
	Dport_State[1] = 0;
	Dport_State[2] = 0;
	if(flag==0xff)	//û�п�ʹ�ó�硣  
	{
		for(i=0;i<3;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] = 0x0c;
				break;
			}
		}
		for(i=0;i<3;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] |= 0x08;
			}
		}
	}
	else		//�п�ʹ�ö������
	{
		Dport_State[flag] = 0x0c;
		if(ADC_BUFFER[20]<(ADC_Base0[6]+ADC_LINE2))
		{
			Dport_State[flag] &= ~0x04;
		}
		
		for(i=0;i<3;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] |= 0x08;
			}
		}
	}
	
	
	for(i=3;i<6;i++)
	{
			flag = 0xff;
	if((Dport_State[i]&0x0c)==0x0c)
		{
			flag = i;
			break;
		}	
	}
	Dport_State[3] = 0;
	Dport_State[4] = 0;
	Dport_State[5] = 0;
	if(flag==0xff)	//û�п�ʹ�ó�硣  
	{
		for(i=3;i<6;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] = 0x0c;
				break;
			}
		}
		for(i=3;i<6;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] |= 0x08;
			}
		}
	}
	else		//�п�ʹ�ö������
	{
		Dport_State[flag] = 0x0c;
		if(ADC_BUFFER[23]<(ADC_Base0[7]+ADC_LINE2))
		{
			Dport_State[flag] &= ~0x04;
		}
		for(i=3;i<6;i++)
		{
			if(ADC_BUFFER[i*3+2]<(ADC_Base0[i]-ADC_LINE1))
			{
				Dport_State[i] |= 0x08;
			}
		}
		
	}
	
}
//---------------------------------------------------------------------------------
//0x00  ��ʼ����
//0x01  ���200ms�Ӽ��
//0x02  ���300ms�Ӽ�ȷ���˿�
//0x03  ���2000ms�Ӽ�ȷ���˿�
//0x04  ���100ms�Ӽ��������
//0x05  ���100ms�Ӽ������Ƿ���ȫ��
//0x06  ���100ms�Ӽ������Ƿ��󡣹ض�ԭ��û���õĶ˿�
void Dport_ChargeStateB(void)
{	
	u8 i;
	u8 flag;
	if(Uport_PowerShowTime[0]>0)
	{
		if((checking_portB&0xf0)==0x00)  //�������
		{
			time_sys_temp4 = time_sys;
			checking_portB = 0x10+0x0f;  //��USB�ÿ�
			flag = checking_portB&0x0f;
			Dport_State[0] = 0x01;
			Dport_State[1] = 0x01;
			Dport_State[2] = 0x01;
			ChargeCtrl_B();
				Dport_ChargeON(0);
				Dport_ChargeON(1);
				Dport_ChargeON(2);

		}
		else  //������豸
		if((checking_portB&0xf0)==0x10)  
		{
			if(time_sys-time_sys_temp4>=200)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
					{
						flag = 0;
						Dport_State[flag] = 0x0c;
						checking_portB = 0x20+flag;		//��⵽�˿�
						Dport_ChargeOFF(flag);
					}
			}
		}
		else  //���ȷ���˿�
		if((checking_portB&0xf0)==0x20)  
		{
			if(time_sys-time_sys_temp4>=500)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]<(ADC_Base0[6]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portB = 0x30+flag;		//��⵽�˿�
						ChargeCtrl_B();  //�����ϵ��USB
					}
				else
					{
						Dport_State[flag] = 0x00;
						if((flag>=2))  
						{
							checking_portB=0;		
						}
						else
						{
							checking_portB=0x20+flag+1;
							Dport_ChargeOFF(flag+1);
						}
					}
					
			}
		}
		else  //�ٴ�ȷ���˿�
		if((checking_portB&0xf0)==0x30)  
		{
			if(time_sys-time_sys_temp4>=1500)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portB = 0x40+flag;		//��⵽�˿�
					}
				else
					{
						Dport_State[flag] = 0x00;
						checking_portB = 0;		//��ⲻ���˿�
					}
			}
		}
		else  //������ڳ����豸
		if((checking_portB&0xf0)==0x40) 
		{
			if(time_sys-time_sys_temp4>=100)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]<(ADC_Base0[6]+ADC_LINE3))
					{
						LOW_portB++;
						if(LOW_portB>3)
						{
						Dport_State[0] = 0x03;
						Dport_State[1] = 0x03;
						Dport_State[2] = 0x03;
						Dport_State[flag] = 0x0c;
	//					Dport_ChargeOFF(flag);
						checking_portB = 0x50+flag;		//��ⲻ���˿�
						Dport_ChargeON(0);
						Dport_ChargeON(1);
						Dport_ChargeON(2);		
						}
					}
				else
					{
						Dport_State[0] = 0x02;
						Dport_State[1] = 0x02;
						Dport_State[2] = 0x02;
						Dport_State[flag] = 0x0c;
						LOW_portB=0;
					}
			}
		}		
		else  //������豸
		if((checking_portB&0xf0)==0x50) 
		{
			if(time_sys-time_sys_temp4>=50)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portB = 0x60+flag;		//��⵽�˿�
						for(i=0;i<3;i++)
						{
							if(Dport_State[i]==0x03)
							{
								Dport_ChargeOFF(i);
								Dport_State[i]=0x04;
								break;
							}
						}
					}
			}
		}		
		else  //���ȷ���˿�
		if((checking_portB&0xf0)==0x60) 
		{
			if(time_sys-time_sys_temp4>=50)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				
				if(ADC_BUFFER[20]<(ADC_Base0[6]+ADC_LINE3))
					{
					for(i=0;i<3;i++)
						{
							if(Dport_State[i]==0x04)//���������״̬
							{
								flag = i;
								Dport_State[0] = 0x06;
								Dport_State[1] = 0x06;
								Dport_State[2] = 0x06;
								Dport_State[flag] = 0x0c;
	//							checking_portB = 0x30+flag;		//��⵽�˿�
								checking_portB = 0x10+flag;		//��⵽�˿�
								ChargeCtrl_B();  //�����ϵ��USB
								Dport_ChargeON(0);
								Dport_ChargeON(1);
								Dport_ChargeON(2);
								break;
							}
						}					
					}
				else
					{
						for(i=0;i<3;i++)//���������״̬
						{
							if(Dport_State[i]==0x04)
							{
								Dport_State[i] = 0x05;
							}
						}
						
						for(i=0;i<3;i++)
						{						
							if(Dport_State[i]==0x03)
							{
								Dport_ChargeOFF(i);
								Dport_State[i]=0x04;
								break;
							}						
						}
						if(i>=3)//û�д����Ķ˿�
						{
						Dport_State[flag] = 0x0c;
						Dport_ChargeON(flag);
						checking_portB = 0x40+flag;		//�����
						}
						
					}
				
			}
		}
		else
		{
				checking_portB = 0;		//��ͷ��ʼ
		}
	}
	else     //������
	{
		if((checking_portB&0xf0)==0x00)  //�������
		{
			time_sys_temp4 = time_sys;
			checking_portB = 0x10+0;  //��USB��1��
			flag = checking_portB&0x0f;
			Dport_State[0] = 0x01;
			Dport_State[1] = 0x01;
			Dport_State[2] = 0x01;
			
			Dport_State[flag] = 0x0C;
			ChargeCtrl_B();
		}
		else  //������豸
		if((checking_portB&0xf0)==0x10)  
		{
			if(time_sys-time_sys_temp4>=1500)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portB = 0x30+flag;		//��⵽�˿�
						ChargeCtrl_B();
					}
					else 
					if(flag<2)
					{
						Dport_State[flag] = 0x01;
						Dport_State[flag+1] = 0x0c;
						checking_portB += 1;		
						ChargeCtrl_B();
					}
					else
					{
						Dport_State[flag] = 0x01;
						Dport_State[0] = 0x0c;
						checking_portB = 0x10;
						ChargeCtrl_B();
					}
			}
		}
		else  //�ٴ�ȷ���˿�
		if((checking_portB&0xf0)==0x30)  
		{
			if(time_sys-time_sys_temp4>=500)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portB = 0x40+flag;		//��⵽�˿�
					}
				else
					{
						Dport_State[flag] = 0x00;
						checking_portB = 0;		//��ⲻ���˿�
					}
			}
		}
		else  //������ڳ����豸
		if((checking_portB&0xf0)==0x40) 
		{
			if(time_sys-time_sys_temp4>=100)
			{
				time_sys_temp4 = time_sys;
				flag = checking_portB&0x0f;
				if(ADC_BUFFER[20]<(ADC_Base0[6]+ADC_LINE3))
					{
						LOW_portB++;
						if(LOW_portB>3)
						{
						Dport_State[0] = 0x03;
						Dport_State[1] = 0x03;
						Dport_State[2] = 0x03;
						Dport_State[flag] = 0x0c;
	//					Dport_ChargeOFF(flag);
						checking_portB = 0x10+flag;		//��ⲻ���˿�
						ChargeCtrl_B();
						}
					}
				else
					{
						Dport_State[0] = 0x02;
						Dport_State[1] = 0x02;
						Dport_State[2] = 0x02;
						Dport_State[flag] = 0x0c;
						LOW_portB=0;
					}
			}
		}
		else
		{
				checking_portB = 0;		//��ͷ��ʼ
		}
	}
}
//------------------------------------------------------
void Dport_ChargeStateC(void)
{
	u8 i;
	u8 flag;
	if(Uport_PowerShowTime[1]>0)
	{
		if((checking_portC&0xf0)==0x00)  //�������
		{
			time_sys_temp5 = time_sys;
			checking_portC = 0x10+0x0f;  //��USB�ÿ�
			flag = checking_portC&0x0f;
				Dport_State[3] = 0x01;
				Dport_State[4] = 0x01;
				Dport_State[5] = 0x01;
			ChargeCtrl_C();
				Dport_ChargeON(3);
				Dport_ChargeON(4);
				Dport_ChargeON(5);

		}
		else  //������豸
		if((checking_portC&0xf0)==0x10)  
		{
			if(time_sys-time_sys_temp5>=200)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
					{
						flag = 3;
						Dport_State[flag] = 0x0c;
						checking_portC = 0x20+flag;		//��⵽�˿�
						Dport_ChargeOFF(flag);
					}
			}
		}
		else  //���ȷ���˿�
		if((checking_portC&0xf0)==0x20)  
		{
			if(time_sys-time_sys_temp5>=500)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]<(ADC_Base0[7]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portC = 0x30+flag;		//��⵽�˿�
						ChargeCtrl_C();  //�����ϵ��USB
					}
				else
					{
						Dport_State[flag] = 0x00;
						if((flag>=5))  
						{
							checking_portC=3;		
						}
						else
						{
							checking_portC=0x20+flag+1;
							Dport_ChargeOFF(flag+1);
						}
					}
					
			}
		}
		else  //�ٴ�ȷ���˿�
		if((checking_portC&0xf0)==0x30)  
		{
			if(time_sys-time_sys_temp5>=1500)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portC = 0x40+flag;		//��⵽�˿�
					}
				else
					{
						Dport_State[flag] = 0x00;
						checking_portC = 3;		//��ⲻ���˿�
					}
			}
		}
		else  //������ڳ����豸
		if((checking_portC&0xf0)==0x40) 
		{
			if(time_sys-time_sys_temp5>=100)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]<(ADC_Base0[7]+ADC_LINE3))
					{
						LOW_portC++;
						if(LOW_portC>3)
						{
						Dport_State[3] = 0x03;
						Dport_State[4] = 0x03;
						Dport_State[5] = 0x03;						
						Dport_State[flag] = 0x0c;
						checking_portC = 0x50+flag;		//��ⲻ���˿�//�������п���
						Dport_ChargeON(3);
						Dport_ChargeON(4);
						Dport_ChargeON(5);		
						}
					}
				else
					{
						Dport_State[3] = 0x02;
						Dport_State[4] = 0x02;
						Dport_State[5] = 0x02;
						Dport_State[flag] = 0x0c;
						LOW_portC=0;
					}
			}
		}		
		else  //������豸
		if((checking_portC&0xf0)==0x50) 
		{
			if(time_sys-time_sys_temp5>=50)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portC = 0x60+flag;		//��⵽�˿�
						for(i=3;i<6;i++)
						{
							if(Dport_State[i]==0x03)
							{
								Dport_ChargeOFF(i);    //ȷ���ǲ���ԭ�˿�
								Dport_State[i]=0x04;
								break;
							}
						}
					}
			}
		}		
		else  //���ȷ���˿�
		if((checking_portC&0xf0)==0x60) 
		{
			if(time_sys-time_sys_temp5>=50)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				
				if(ADC_BUFFER[23]<(ADC_Base0[7]+ADC_LINE3))
					{
					for(i=3;i<6;i++)
						{
							if(Dport_State[i]==0x04)//���������״̬
							{
								flag = i;
								Dport_State[3] = 0x06;
								Dport_State[4] = 0x06;
								Dport_State[5] = 0x06;
								Dport_State[flag] = 0x0c;
	//							checking_portC = 0x30+flag;		//��⵽�˿�
								checking_portC = 0x10+flag;		//��⵽�˿�
								ChargeCtrl_C();  //�����ϵ��USB
								Dport_ChargeON(3);
								Dport_ChargeON(4);
								Dport_ChargeON(5);
								break;
							}
						}					
					}
				else
					{
						for(i=3;i<6;i++)//���������״̬
						{
							if(Dport_State[i]==0x04)
							{
								Dport_State[i] = 0x05;
							}
						}
						
						for(i=3;i<6;i++)
						{						
							if(Dport_State[i]==0x03)
							{
								Dport_ChargeOFF(i);
								Dport_State[i]=0x04;
								break;
							}						
						}
						if(i>=6)//û�д����Ķ˿�
						{
						Dport_State[flag] = 0x0c;
						Dport_ChargeON(flag);
						checking_portC = 0x40+flag;		//�����
						}
						
					}
				
			}
		}
		else
		{
				checking_portC = 0;		//��ͷ��ʼ
		}
	}
	else  //������
	{
		if((checking_portC&0xf0)==0x00)  //�������
		{
			time_sys_temp5 = time_sys;
			checking_portC = 0x10+3;  //��USB�ÿ�1��
			flag = checking_portC&0x0f;
				Dport_State[3] = 0x01;
				Dport_State[4] = 0x01;
				Dport_State[5] = 0x01;
			
			Dport_State[flag] = 0x0C;
			ChargeCtrl_C();

		}
		else  //������豸
		if((checking_portC&0xf0)==0x10)  
		{
			if(time_sys-time_sys_temp5>=1500)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portC = 0x30+flag;		//��⵽�˿�
						ChargeCtrl_C();
					}
					else 
					if(flag<5)
					{
						Dport_State[flag] = 0x01;
						Dport_State[flag+1] = 0x0c;
						checking_portC += 1;		
						ChargeCtrl_C();
					}
					else
					{
						Dport_State[flag] = 0x01;
						Dport_State[3] = 0x0c;
						checking_portC = 0x13;
						ChargeCtrl_C();
					}
							
			}
		}
		else  //�ٴ�ȷ���˿�
		if((checking_portC&0xf0)==0x30)  
		{
			if(time_sys-time_sys_temp5>=500)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
					{
						Dport_State[flag] = 0x0c;
						checking_portC = 0x40+flag;		//��⵽�˿�
					}
				else
					{
						Dport_State[flag] = 0x00;
						checking_portC = 0;		//��ⲻ���˿�
					}
			}
		}
		else  //������ڳ����豸
		if((checking_portC&0xf0)==0x40) 
		{
			if(time_sys-time_sys_temp5>=100)
			{
				time_sys_temp5 = time_sys;
				flag = checking_portC&0x0f;
				if(ADC_BUFFER[23]<(ADC_Base0[7]+ADC_LINE3))
					{
						LOW_portC++;
						if(LOW_portC>3)
						{
						Dport_State[3] = 0x03;
						Dport_State[4] = 0x03;
						Dport_State[5] = 0x03;						
						Dport_State[flag] = 0x0c;
						checking_portC = 0x10+flag;		//��ⲻ���˿�
						ChargeCtrl_C();
						}
					}
				else
					{
						Dport_State[3] = 0x02;
						Dport_State[4] = 0x02;
						Dport_State[5] = 0x02;
						Dport_State[flag] = 0x0c;
						LOW_portC=0;
					}
			}
		}
		else
		{
				checking_portC = 0;		//��ͷ��ʼ
		}

	}
	
}
//-----------------------------------------------------
void Get_ADC_BaseLine(void)
{
	u8 i;
	for(i=0;i<8;i++)
	{
	ADC_Base0[i] = ADC_BUFFER[i*3+2];
	}
}
//-----------------------------------------------------
void ChargeCtrl_B(void)
{
	u8 i;
	u8 flag;
			flag = 0xff;
	if(Uport_PowerUseTime[0]>0)
		{
			flag = 0xff;
		for(i=0;i<3;i++)
			{
			if((Dport_State[i]&0x0c)==0x0c)
				{
				flag = i;
				}
			}
		}
		
	if(flag==0)	//û�п�ʹ�ó�硣  
	{
//		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);

//		GPIO_SetBits(USB_DB0_PORT, USB_DB0_PIN);
		GPIO_ResetBits(USB_DB0_PORT, USB_DB0_PIN);
		GPIO_SetBits(USB_DB1_PORT, USB_DB1_PIN);
//		GPIO_ResetBits(USB_DB1_PORT, USB_DB1_PIN);
		
		GPIO_ResetBits(SSB0_PORT, SSB0_PIN);
	}
	else
	if(flag==1)	//û�п�ʹ�ó�硣  
	{
		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
//		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
		
		GPIO_SetBits(USB_DB0_PORT, USB_DB0_PIN);
//		GPIO_ResetBits(USB_DB0_PORT, USB_DB0_PIN);
//		GPIO_SetBits(USB_DB1_PORT, USB_DB1_PIN);
		GPIO_ResetBits(USB_DB1_PORT, USB_DB1_PIN);
		
		GPIO_ResetBits(SSB1_PORT, SSB1_PIN);
	}
	else
	if(flag==2)	//û�п�ʹ�ó�硣  
	{
		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
//		GPIO_SetBits(SSB2_PORT, SSB2_PIN);

		GPIO_SetBits(USB_DB0_PORT, USB_DB0_PIN);
//		GPIO_ResetBits(USB_DB0_PORT, USB_DB0_PIN);
		GPIO_SetBits(USB_DB1_PORT, USB_DB1_PIN);
//		GPIO_ResetBits(USB_DB1_PORT, USB_DB1_PIN);
		
		GPIO_ResetBits(SSB2_PORT, SSB2_PIN);
	}
	else
	{
//		GPIO_SetBits(USB_DB0_PORT, USB_DB0_PIN);
		GPIO_ResetBits(USB_DB0_PORT, USB_DB0_PIN);
//		GPIO_SetBits(USB_DB1_PORT, USB_DB1_PIN);
		GPIO_ResetBits(USB_DB1_PORT, USB_DB1_PIN);

		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
	}
	
}
//-----------------------------------------------------
void ChargeCtrl_C(void)
{
	u8 i;
	u8 flag;
			flag = 0xff;
	if(Uport_PowerUseTime[1]>0)
		{
			flag = 0xff;
		for(i=3;i<6;i++)
			{
			if((Dport_State[i]&0x0c)==0x0c)
				{
				flag = i;
				}
			}
		}
		
	if(flag==3)	//û�п�ʹ�ó�硣  
	{
//		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
		
		GPIO_SetBits(USB_DC0_PORT, USB_DC0_PIN);
//		GPIO_ResetBits(USB_DC0_PORT, USB_DC0_PIN);
//		GPIO_SetBits(USB_DC1_PORT, USB_DC1_PIN);
		GPIO_ResetBits(USB_DC1_PORT, USB_DC1_PIN);

		GPIO_ResetBits(SSC0_PORT, SSC0_PIN);
	}
	else
	if(flag==4)	//û�п�ʹ�ó�硣  
	{
		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
//		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
		
		GPIO_SetBits(USB_DC0_PORT, USB_DC0_PIN);
//		GPIO_ResetBits(USB_DC0_PORT, USB_DC0_PIN);
		GPIO_SetBits(USB_DC1_PORT, USB_DC1_PIN);
//		GPIO_ResetBits(USB_DC1_PORT, USB_DC1_PIN);

		GPIO_ResetBits(SSC1_PORT, SSC1_PIN);
	}
	else
	if(flag==5)	//û�п�ʹ�ó�硣  
	{
		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
//		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
		
//		GPIO_SetBits(USB_DC0_PORT, USB_DC0_PIN);
		GPIO_ResetBits(USB_DC0_PORT, USB_DC0_PIN);
		GPIO_SetBits(USB_DC1_PORT, USB_DC1_PIN);
//		GPIO_ResetBits(USB_DC1_PORT, USB_DC1_PIN);

		GPIO_ResetBits(SSC2_PORT, SSC2_PIN);
	}
	else
	{
//		GPIO_SetBits(USB_DC0_PORT, USB_DC0_PIN);
		GPIO_ResetBits(USB_DC0_PORT, USB_DC0_PIN);
//		GPIO_SetBits(USB_DC1_PORT, USB_DC1_PIN);
		GPIO_ResetBits(USB_DC1_PORT, USB_DC1_PIN);

		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
	}
		
}
void Dport_ChargeON(u8 port)
{
//	u8 flag;
	if(port==0)	//0��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSB0_PORT, SSB0_PIN);
	}
	else
	if(port==1)	//1��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSB1_PORT, SSB1_PIN);
	}
	else
	if(port==2)	//2��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSB2_PORT, SSB2_PIN);
	}
	else
	if(port==3)	//3��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSC0_PORT, SSC0_PIN);
	}
	else
	if(port==4)	//4��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSC1_PORT, SSC1_PIN);
	}
	else
	if(port==5)	//5��ʹ�ó�硣  
	{
		GPIO_ResetBits(SSC2_PORT, SSC2_PIN);
	}
}
void Dport_ChargeOFF(u8 port)
{
	if(port==0)	//0��ʹ�öϵ硣  
	{
		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
// 		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
// 		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
	}
	else
	if(port==1)	//1��ʹ�öϵ硣    
	{
// 		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
//		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
	}
	else
	if(port==2)	//2��ʹ�öϵ硣  
	{
//		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
//		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
	}
	else
	if(port==3)	//3��ʹ�öϵ硣   
	{
		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
// 		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
// 		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
	}
	else
	if(port==4)	//4��ʹ�öϵ硣   
	{
//		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
//		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
	}
	else
	if(port==5)	//5��ʹ�öϵ硣    
	{
//		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
//		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
	}
}
void DisplayADC_BL(unsigned int x, unsigned int y, u16 *s,u16 PenColor, u16 BackColor,u8 cs)
{
	u8 i,j;
	u32 temp;
	for(i=0;i<3;i++)
	{
		temp = *s++;
		j=0;
		temp *= 6600;//1000���Ŵ�
		temp /=4096;
		UART_BUFFER[j++] = temp%10000/1000+'0';
		UART_BUFFER[j++] = temp%1000/100+'0';
		UART_BUFFER[j++] = temp%100/10+'0';
		UART_BUFFER[j++] = temp%10+'0';
		UART_BUFFER[j++] = 0;
		tft_DisplayStr(x-i*20, y, UART_BUFFER,POINT_COLOR, BACK_COLOR,cs);
	}
// 	for(i=0;i<3;i++)
// 	{
// 		temp = *s++;
// 		temp *= 66;//10���Ŵ�
// 		temp /=4096;
// 		UART_BUFFER[i++] = temp%100/10;
// 		UART_BUFFER[i++] = '.';
// 		UART_BUFFER[i++] = temp%10;
// 		UART_BUFFER[i++] = 0;
// 		tft_DisplayStr(x-i*20, 0, UART_BUFFER,POINT_COLOR, BACK_COLOR,2);
// 	}
}

//-------------------------------------
void cmd_Get_ADC(void)
{
		u8 i;
		for(i=0;i<8;i++)
		{
			UART1_TXBUFFER[2*i] = (ADC_BUFFER[3*i+2]>>8);
			UART1_TXBUFFER[2*i+1] = (ADC_BUFFER[3*i+2]&0xff);
		}
	
		for(i=0;i<8;i++)
		{
			UART1_TXBUFFER[16+2*i] = (ADC_Base0[i]>>8);
			UART1_TXBUFFER[16+2*i+1] = (ADC_Base0[i]&0xff);
		}
		UART1_Send_Data(UART1_TXBUFFER,32);

}
//-------------------------------------
void cmd_RGB888_565(void)
{
	u16 i,en;
	u32 f_addr,f_size;
	
		en = 0x00;
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==1)//��ά����
	{
		FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>10)
		{	
			str_buffer[1] = 10;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			//	display_flash_BMP (0,0,f_addr,2);
				RGB888_565(f_addr);
		}
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==2)//������
	{
		FLASH2_GPIOSPI_Read (Addr_02min, str_buffer, 2048);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>100)
		{	
			str_buffer[1] = 100;	
		}
//		UART1_Send_Data(str_buffer,str_buffer[1]*18+6);
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		if(f_size>0)
		{
			//	display_flash_BMP (0,0,f_addr,2);
				RGB888_565(f_addr);
		}

	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX]==3)//��ͼ��
	{
		FLASH2_GPIOSPI_Read (Addr_03min, str_buffer, 256);
				en = 0x00;
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>10)
		{	
			str_buffer[1] = 10;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			//	display_flash_BMP (0,0,f_addr,2);
				RGB888_565(f_addr);
		}
	}
	else
	{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
	}
}
//-------------------------------------
void RGB888_565(unsigned int addr)
{
  u32 i=0,j=0;//
  u32 offset,x_offset,y_offset;  //
  u32 x_wide;  //ͼƬʵ��ȡ��Ŀ�� ��Ϊ32�ı���
//  u32 x_offset1;  //ʵ��Ҫ�Ĵ��ڳ���
  u32 pix;  //��ʾ�����ӽ���
	unsigned int pix_temp;
		FLASH2_GPIOSPI_Read (addr, str_buffer, 64);
	if(str_buffer[28] ==0x18)   //24bit
	{
		offset = str_buffer[13];
		offset <<= 8;
		offset += str_buffer[12];
		offset <<= 8;
		offset += str_buffer[11];
		offset <<= 8;
		offset += str_buffer[10];
		
		x_offset = str_buffer[21];
		x_offset <<= 8;
		x_offset += str_buffer[20];
		x_offset <<= 8;
		x_offset += str_buffer[19];
		x_offset <<= 8;
		x_offset += str_buffer[18];
		
		if((x_offset%2)!=0)  //�涨ɨ��һ�����ݱ���4�ֽڵı���������Ĳ�0
		{
			x_wide = x_offset + 2;
			x_wide &= ~0x01;			
		}
		else
		{
				x_wide = x_offset;
		}
		y_offset = str_buffer[25];
		y_offset <<= 8;
		y_offset += str_buffer[24];
		y_offset <<= 8;
		y_offset += str_buffer[23];
		y_offset <<= 8;
		y_offset += str_buffer[22];
			
		if((str_buffer[0]!='B')||(str_buffer[1]!='M'))  //������Ϊ��Ч
			{
				x_offset = 0;
			}
		if(y_offset>320)  //������Ϊ��Ч
			{
				x_offset = 0;
			}
		
		i = x_wide*y_offset*2+66;
		str_buffer[2] = (i&0xff);  			//SIZELL
		str_buffer[3] = ((i>>8)&0xff);  //SIZELH
		str_buffer[4] = ((i>>16)&0xff);  //SIZEHL
		str_buffer[5] = ((i>>24)&0xff);  //SIZEHH
		str_buffer[10] = 0x42;  //ƫ��ֵ
		str_buffer[28] = 0x10;  //rgb565
		str_buffer[30] = 0x03;  //��ѹ��
			
		str_buffer[54] = 0x00;
		str_buffer[55] = 0xf8;
		str_buffer[56] = 0x00;
		str_buffer[57] = 0x00;
		str_buffer[58] = 0xe0;
		str_buffer[59] = 0x07;
		str_buffer[60] = 0x00;
		str_buffer[61] = 0x00;
		str_buffer[62] = 0x1f;
		str_buffer[63] = 0x00;
		str_buffer[64] = 0x00;
		str_buffer[65] = 0x00;
		UART1_Send_Data(str_buffer,66);
			
		if((x_offset>0)&&(x_offset<=240))
		{
			
//			x_offset1 = x_offset;
				
			global_u16p = (u16*)str_buffer;  //����ȡһ��ȡ16λ
							
			for(i=0;i<y_offset;i++)	
			{
				for(j=0;j<(x_offset);j++)	
				{
					pix = i*(x_wide)+j;  //���ؼ�1
					if(pix%1024==0)
					{
					if(pix>0)
					{
					UART1_Send_Data(str_buffer,2048);
					}
					FLASH2_GPIOSPI_Read (addr+offset+(pix*3), str_buffer, 3072);  //����������
					pix_temp = pix;
					}
					
	// 				g16_temp = str_buffer[pix+1-pix_temp];	
	// 				g16_temp <<= 8;		
	// 				g16_temp += str_buffer[pix-pix_temp];		
					global_u16temp = (str_buffer[(pix-pix_temp)*3+2]>>3);
					global_u16temp <<= 6;
					global_u16temp += (str_buffer[(pix-pix_temp)*3+1]>>2);
					global_u16temp <<= 5;
					global_u16temp += (str_buffer[(pix-pix_temp)*3]>>3);
					
					global_u16p[pix-pix_temp]=global_u16temp;
					

				}
			}			 
			
			UART1_Send_Data(str_buffer,(pix-pix_temp+1)<<1);
		}
	}
}
void cmd_RGB_clear(void)
{
	u16 colour_t,x_l,y_l,x_o, y_o;
	 if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX]>=9)
	 {		 		 
		colour_t  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];
		colour_t <<= 8; 
		colour_t += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
		 
		x_l  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+8)&UART1_RX_MAX];
		x_l <<= 8; 
		x_l += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+9)&UART1_RX_MAX];
		y_l  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+10)&UART1_RX_MAX];
		y_l <<= 8; 
		y_l += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+11)&UART1_RX_MAX];
		 
		x_o  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+12)&UART1_RX_MAX];
		x_o <<= 8; 
		x_o += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+13)&UART1_RX_MAX];
		y_o  = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+14)&UART1_RX_MAX];
		y_o <<= 8; 
		y_o += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+15)&UART1_RX_MAX];
//void tft_Clear(u16 x,u16 y,u16 x_offset,u16 y_offset,u16 Color,u8 cs)
 		tft_Clear(x_l,y_l,x_o,y_o,colour_t,UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX]);		//		
	}
}

//-----------------------------------------
 void cmd_CHIP_PRO(void)
{
	u16 i,en;
	u32 f_addr,f_size;
	
				en = 0x00;
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==1)
	{
	FLASH2_GPIOSPI_Read (Addr_01min, str_buffer, 256);
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==2)
	{
	FLASH2_GPIOSPI_Read (Addr_02min, str_buffer, 256);
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==3)
	{
	FLASH2_GPIOSPI_Read (Addr_03min, str_buffer, 256);
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==4)
	{
	FLASH2_GPIOSPI_Read (Addr_04min, str_buffer, 256);
	}
	else
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==5)
	{
	FLASH2_GPIOSPI_Read (Addr_05min, str_buffer, 256);
	}
	if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX] ==0XE0)
	{
		en = 0xff;
		str_buffer[0] = 0;
		str_buffer[1] = 0;
		FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
		info2STR.item21[0] = 21;
		info2STR.item21[1] = 4;
		info2STR.item21_data[0] = 0xE0;  //�Ի�
		info2STR.item21_data[1] = 0x00;
		info2STR.item21_data[2] = 0;  
		info2STR.item21_data[3] = 0;
		FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
		FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
		
			if(device.Version[0]==Version_FLAG1)     //bl������
			{
				Check_CHIP_PRO();  //
			}
			else				//USER������
			{
				UART1_TXBUFFER[0] =  frame_headerD;
				UART1_TXBUFFER[1] =  4;  //len
				UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
				UART1_TXBUFFER[3] =  device.addr;
				UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
			
				UART1_TXBUFFER[5] =  en;
			
				UART1_TXBUFFER[6] = 0;//check;
				for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
				{
					UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
				}
				UART1_TXBUFFER[7] =  frame_last;
				UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
				NVIC_SystemReset();    //��λ
			}						
	}
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>13)
		{	
			str_buffer[1] = 13;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX])//ȷ���ļ���
				{
					en = 0xff; 
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
	
		UART1_TXBUFFER[5] =  en;
	
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		
		if(f_size>0)
		{
			FLASH2_GPIOSPI_Read (Addr_info2, &info2STR.head[0], sizeof(info2STR));  //ý�ݳ�ʼ��
			info2STR.item21[0] = 21;
			info2STR.item21[1] = 4;
			info2STR.item21_data[0] = 0x01;
			info2STR.item21_data[1] = 0x00;
			info2STR.item21_data[2] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+6)&UART1_RX_MAX];   //
			info2STR.item21_data[3] = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+7)&UART1_RX_MAX];
			FLASH2_GPIOSPI_SER(Addr_info2);  ////ÿ�β���4K
			FLASH2_GPIOSPI_Write(Addr_info2, &info2STR.head[0], sizeof(info2STR));
			
			if(device.Version[0]==Version_FLAG1)     //bl������
			{
				Check_CHIP_PRO();  //
			}
			else				//USER������
			{
				NVIC_SystemReset();    //��λ
			}						
		}

}
//-----------------------------------------
 void cmd_PRO_Version(void)
{
	u8 i;
//		if(UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX] == 130)
		{
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  9;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+5)&UART1_RX_MAX];
		UART1_TXBUFFER[6] =  9;
		UART1_TXBUFFER[7] =  device.Version[0];
		UART1_TXBUFFER[8] =  device.Version[1];
		UART1_TXBUFFER[9] =  device.Version[2];
		UART1_TXBUFFER[10] =  device.Version[3];
		UART1_TXBUFFER[11] =  device.Version[4];
		UART1_TXBUFFER[12] =  device.Version[5];
		UART1_TXBUFFER[13] =  device.Version[6];
		UART1_TXBUFFER[14] =  device.Version[7];
		UART1_TXBUFFER[15] =  device.Version[8];
		
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-2] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[(UART1_TXBUFFER[1]<<1)-1] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));
		}
}
//-------------------------------------
void cmd_Save_ADC(void)
{
		u8 i,en;
		GPIO_SetBits(SSB0_PORT, SSB0_PIN);
		GPIO_SetBits(SSB1_PORT, SSB1_PIN);
		GPIO_SetBits(SSB2_PORT, SSB2_PIN);
		GPIO_SetBits(SSC0_PORT, SSC0_PIN);
		GPIO_SetBits(SSC1_PORT, SSC1_PIN);
		GPIO_SetBits(SSC2_PORT, SSC2_PIN);
			Delay_us(200);	
		//��ȡ����
		Get_ADC_BaseLine();
		FLASH2_GPIOSPI_Read (Addr_info1, str_buffer, 64);
		global_u8p = (u8*)ADC_Base0;
		for(i=0;i<16;i++)
		{
			str_buffer[6+i] = global_u8p[i];
		}
		
		str_buffer[0] = 0x67;
		str_buffer[1] = 0x16;
		str_buffer[2] = device.addr;
		str_buffer[3] = 0xf0;
		str_buffer[(str_buffer[1]<<1)-2] = 0;//check;
		for(i=1;i<((str_buffer[1]<<1)-2);i++)
		{
			str_buffer[(str_buffer[1]<<1)-2] += str_buffer[i];
		}
		str_buffer[(str_buffer[1]<<1)-1] = 0x99;
		
		FLASH2_GPIOSPI_SER(Addr_info1);  ////ÿ�β���4K
		FLASH2_GPIOSPI_Write(Addr_info1, str_buffer, (str_buffer[1]<<1));
		
		en = 0xff;
		FLASH2_GPIOSPI_Read (Addr_info1, str_buffer, 64);			
	 for(i=0;i<16;i++)
		{
			if(str_buffer[6+i]!=global_u8p[i])
			{
				en = 0;
			}
		}
			
		UART1_TXBUFFER[0] =  frame_headerD;
		UART1_TXBUFFER[1] =  4;  //len
		UART1_TXBUFFER[2] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+3)&UART1_RX_MAX];
		UART1_TXBUFFER[3] =  device.addr;
		UART1_TXBUFFER[4] =  UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+4)&UART1_RX_MAX];
		UART1_TXBUFFER[5] =  en;
		
		UART1_TXBUFFER[6] = 0;//check;
		for(i=1;i<((UART1_TXBUFFER[1]<<1)-2);i++)
		{
			UART1_TXBUFFER[6] += UART1_TXBUFFER[i];
		}
		UART1_TXBUFFER[7] =  frame_last;
		UART1_Send_Data(UART1_TXBUFFER,(UART1_TXBUFFER[1]<<1));

}
//-----------------------------------------
void Dport_ChargeHB_ON (void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
//-----------�����----------------
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
}
//-----------------------------------------
void Dport_ChargeHB_OFF (void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
//-----------������----------------
		/*��������ģʽΪͨ�ø�������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_SetBits(GPIOA, GPIO_Pin_12);

}
//-----------------------------------------
void Dport_ChargeHC_ON (void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
//-----------�����----------------
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
}
//-----------------------------------------
void Dport_ChargeHC_OFF (void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
//-----------������----------------
		/*��������ģʽΪͨ�ø�������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*ѡ��Ҫ���Ƶ�GPIOA������*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_SetBits(GPIOA, GPIO_Pin_11);
}
//-----------------------------------------
u8 Frame_check_cmd1(void)
{
	u8 temp;
	u16 i,len;
	len = UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+1)&UART1_RX_MAX];
	len <<= 1;
	temp = 0;
	for(i=1;i<len-2;i++)
	{
		temp += UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+i)&UART1_RX_MAX];
	}
	if(temp==UART1_RXBUFFER[(UART1_RXBUFFE_HEAD+i)&UART1_RX_MAX])
	{
		temp = 0xff;    //У��ͨ��
	}
	else
	{
		temp = 0x00;
	}
	return temp;
}
//-----------------------------------------------------
void FiletoBuffer_ID(u8 area,u8 id,u8 *p)//��ID��ʽ�����ļ���BUFFER��
{
	u16 i;
	u32 f_addr,f_size;
	
	if(area==2)//������
	{
		FLASH2_GPIOSPI_Read (Addr_02min, str_buffer, 1024);
				f_addr = 0;
				f_size = 0;
	if(str_buffer[1]>52)
		{	
			str_buffer[1] = 52;	
		}
		
		for(i=0;i<str_buffer[1];i++)
		{
		if(str_buffer[0]!=frame_headerC)	
			{		break;	}			
				if(str_buffer[4+18*i+1]==id)//ȷ���ļ���
				{
				f_size = str_buffer[4+18*i+2];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+3];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+4];
				f_size <<= 8;
				f_size += str_buffer[4+18*i+5];	
					
				f_addr = str_buffer[4+18*i+14];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+15];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+16];
				f_addr <<= 8;
				f_addr += str_buffer[4+18*i+17];
				break;
				}
		}
				
		if(f_size>0)
		{
			FLASH2_GPIOSPI_Read (f_addr, p, f_size);
		}

	}

}
void LCD_TEST(void)
{
//0xE0 set_pll ;Start the PLL. Before the start, the system was operated with the crystal oscillator or clock input 
//0xE2  set_pll_mn;  Set the PLL 
//0xE3  get_pll_mn;  Get the PLL settings 
//0xE4  get_pll_status;  Get the current PLL status 	
	u8 i;
	u8 lcd1;
	u8 lcd2;
	u16 temp;
	u32 temp1,temp2;
//	0x0036
	LCDC.LCDError =0;
	lcd1 = 0x00;
	lcd2 = 0x00;
	if(device.Version[2] =='1')
	{
			GPIO_ResetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
			LCD_REG= 0XB7; 
			i=10;
			while(i--);
			temp= LCD_RAM; 
			temp<<= 8; 
			temp+= LCD_RAM; 
			GPIO_SetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
		
			i=10;
			while(i--);	
			GPIO_ResetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
			LCD_REG= 0XE3; 
			i=100;
			while(i--);
			temp1= LCD_RAM; 
			temp1<<= 8; 
			temp1+= LCD_RAM; 
			temp1<<= 8; 
			temp1+= LCD_RAM; 
			GPIO_SetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
		
			i=10;
			while(i--);	
			GPIO_ResetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
			LCD_REG= 0XE7; 
			i=100;
			while(i--);
			temp2= LCD_RAM; 
			temp2<<= 8; 
			temp2+= LCD_RAM; 
			temp2<<= 8; 
			temp2+= LCD_RAM; 
			GPIO_SetBits(LCD_CS1_PORT, LCD_CS1_PIN);	
//			if((temp!=VT)||(temp1!=0x230204)||(temp2!=0x0293e0))
			if((temp!=VT)||(temp1!=0x230204)||(temp2!=0x00DB00))
			{
				lcd1 = 0xFF;
				lcd2 = 0xFF;
				LCDC.LCDError |= 0x01; 
				LCD_InitAll();
				time_rst_lcd1 = LCDC.LCD1SPTime;
				time_rst_lcd2 = LCDC.LCD2SPTime;
			}		
	}
	if(LCDC.LCD1SPPID==2)
	{
		time_rst_lcd1 = LCDC.LCD1SPTime;
	}
	else
	{
		if((LCDC.LCD1SPTime - time_rst_lcd1)>(LCDC.LCDSPTimeSet/3))   //����ʱ���3��֮һ��ʼһ��
		{
			lcd1 = 0xFF;
			LCD_Init1();
			time_rst_lcd1 = LCDC.LCD1SPTime;
		}
	}
				
	if(device.Version[2] =='1')
	{
			GPIO_ResetBits(LCD_CS2_PORT, LCD_CS2_PIN);	
			LCD_REG= 0XB7; 
			i=10;
			while(i--);
			temp= LCD_RAM; 
			temp<<= 8; 
			temp+= LCD_RAM; 
			GPIO_SetBits(LCD_CS2_PORT, LCD_CS2_PIN);
		
			i=10;
			while(i--);	
			GPIO_ResetBits(LCD_CS2_PORT, LCD_CS2_PIN);	
			LCD_REG= 0XE3; 
			i=100;
			while(i--);
			temp1= LCD_RAM; 
			temp1<<= 8; 
			temp1+= LCD_RAM; 
			temp1<<= 8; 
			temp1+= LCD_RAM; 
			GPIO_SetBits(LCD_CS2_PORT, LCD_CS2_PIN);	
		
			i=10;
			while(i--);	
			GPIO_ResetBits(LCD_CS2_PORT, LCD_CS2_PIN);	
			LCD_REG= 0XE7; 
			i=100;
			while(i--);
			temp2= LCD_RAM; 
			temp2<<= 8; 
			temp2+= LCD_RAM; 
			temp2<<= 8; 
			temp2+= LCD_RAM; 
			GPIO_SetBits(LCD_CS2_PORT, LCD_CS2_PIN);	
//			if((temp!=VT)||(temp1!=0x230204)||(temp2!=0x0293e0))
			if((temp!=VT)||(temp1!=0x230204)||(temp2!=0x00DB00))
			{
				lcd1 = 0xFF;
				lcd2 = 0xFF;
				LCDC.LCDError |= 0x02; 
				LCD_InitAll();
				time_rst_lcd1 = LCDC.LCD1SPTime;
				time_rst_lcd2 = LCDC.LCD2SPTime;
			}
	}	
	if(LCDC.LCD2SPPID==2)
	{
			time_rst_lcd2 = LCDC.LCD2SPTime;
	}
	else
	{
		if((LCDC.LCD2SPTime - time_rst_lcd2)>(LCDC.LCDSPTimeSet/3))   //����ʱ���3��֮һ��ʼһ��
		{
			lcd2 = 0xff;
			LCD_Init2();		
			time_rst_lcd2 = LCDC.LCD2SPTime;
		}
	}
	
	if(lcd1 == 0xff)
	{
		if(LCDC.LCD1SPPID==1)
		{
		display_flash_BMPE (0,0,3,LCDC.LCD1SPPID,1);//��ɫ��ɫ��֧�� ������
		DisplayPROT_EWM(115,56,0,1);  //128
		tft_DisplayStr(15, 125, device_num,0x0000,0xffff,1);
		}
		else
		if(LCDC.LCD1SPPID==0)
		{
		display_flash_BMPE (0,0,3,LCDC.LCD1SPPID,1);//��ɫ��ɫ��֧�� ������
		DisplayPROT_EWM(80,56,0,1);  //128
		tft_DisplayStr(270, 125, device_num,0x0000,0xffff,1);
		}
		else
		if(LCDC.LCD1SPPID==2)
		{			display_flash_BMPE (0,0,3,LCDC.LCD1SPPID,1);		}//��ɫ��ɫ��֧�� ������
	}
	if(lcd2 == 0xff)
	{
		if(LCDC.LCD2SPPID==1)
		{
		display_flash_BMPE (0,0,3,LCDC.LCD2SPPID,2);//��ɫ��ɫ��֧�� ������
		DisplayPROT_EWM(115,56,1,2);  //128
		tft_DisplayStr(15, 125, device_num,0x0000,0xffff,2);
		}
		else
		if(LCDC.LCD2SPPID==0)
		{
		display_flash_BMPE (0,0,3,LCDC.LCD2SPPID,2);//��ɫ��ɫ��֧�� ������
		DisplayPROT_EWM(80,56,1,2);  //128
		tft_DisplayStr(270, 125, device_num,0x0000,0xffff,2);
		}
		else
		if(LCDC.LCD2SPPID==2)
		{				display_flash_BMPE (0,0,3,LCDC.LCD2SPPID,2);		}//��ɫ��ɫ��֧�� ������
	}		
}

void Version_display(u16 x,u8 *p)
{
	UART_BUFFER[0] = 'V';
	UART_BUFFER[1] = 'e';
	UART_BUFFER[2] = 'r';
	UART_BUFFER[3] = 's';
	UART_BUFFER[4] = 'i';
	UART_BUFFER[5] = 'o';
	UART_BUFFER[6] = 'n';
	UART_BUFFER[7] = ':';
	UART_BUFFER[8] = p[0];
	UART_BUFFER[9] = p[1];
	UART_BUFFER[10] = p[2];
	UART_BUFFER[11] = p[3];
	UART_BUFFER[12] = p[4];
	UART_BUFFER[13] = p[5];
	UART_BUFFER[14] = p[6];
	UART_BUFFER[15] = p[7];
	UART_BUFFER[16] = p[8];
	UART_BUFFER[17] = 0;
	tft_DisplayStr(x, (240-8*17)/2, UART_BUFFER,POINT_COLOR, BLUE,3);
}
//״̬��Ϣ֪ͨ��
void State_Message(unsigned int x, unsigned int y, u16 UpColor, u16 DownColor,u16 ChargeColor)
{
	u8 j,i;
		
//		if((time_s-testcmd1_time)>=30)  //30��û�յ���ȷ������Ϊ�Ͽ�����
//			tft_Clear(u16 x,u16 y,u16 x_offset,u16 y_offset,u16 Color,u8 cs);
			tft_Clear(2,1,5,6,WHITE,3);
			tft_Clear(2,1,(LCDC.LCDError%5),1,RED,3);	
		if((time_sys-time_uart1)>=30000)  //30��û�մ���
		{
			tft_Clear(6,2,((device.addr&0x0f)/5),1,LGRAY,3);
			tft_Clear(2,2,((device.addr&0x0f)%5),1,LGRAY,3);
			tft_Clear(2,3,1,1,LGRAY,3);
			tft_Clear(2,4,1,1,LGRAY,3);
			tft_Clear(2,5,5,1,LGRAY,3);
			tft_Clear(4,6,3,1,LGRAY,3);
			tft_Clear(2,7,1,1,LGRAY,3);
		}
		else
		{
			tft_Clear(6,2,((device.addr&0x0f)/5),1,GREEN,3);
			tft_Clear(2,2,((device.addr&0x0f)%5),1,GREEN,3);
			tft_Clear(2,3,1,1,GREEN,3);
			tft_Clear(2,4,1,1,GREEN,3);
			tft_Clear(2,5,5,1,GREEN,3);
			tft_Clear(4,6,3,1,GREEN,3);
			tft_Clear(2,7,1,1,GREEN,3);
		}
//����	
		if(UpColor!=NULL)
		{
			tft_Clear(0,12,5,1,UpColor,3);
			tft_Clear(5,10,1,5,UpColor,3);
			tft_Clear(6,11,1,3,UpColor,3);
			tft_Clear(7,12,1,1,UpColor,3);	
		}			
//����		
		if(DownColor!=NULL)
		{
			tft_Clear(3,19,5,1,DownColor,3);
			tft_Clear(2,17,1,5,DownColor,3);
			tft_Clear(1,18,1,3,DownColor,3);
			tft_Clear(0,19,1,1,DownColor,3);		
		}
//���	
	 if(ADC_BUFFER[20]>(ADC_Base0[6]+ADC_LINE2))
		{
			ChargeColor = GREEN;
		}
		else
		{
			ChargeColor = LGRAY;
		}			
		tft_Clear(0,26,1,1,ChargeColor,1);
		tft_Clear(1,26,1,2,ChargeColor,1);
		tft_Clear(2,26,1,3,ChargeColor,1);
		tft_Clear(3,26,1,4,ChargeColor,1);
		tft_Clear(4,23,1,4,ChargeColor,1);
		tft_Clear(5,24,1,3,ChargeColor,1);
		tft_Clear(6,25,1,2,ChargeColor,1);		
		tft_Clear(7,26,1,1,ChargeColor,1);	
		
	 if(ADC_BUFFER[23]>(ADC_Base0[7]+ADC_LINE2))
		{
			ChargeColor = GREEN;
		}
		else
		{
			ChargeColor = LGRAY;
		}
		tft_Clear(0,26,1,1,ChargeColor,2);
		tft_Clear(1,26,1,2,ChargeColor,2);
		tft_Clear(2,26,1,3,ChargeColor,2);
		tft_Clear(3,26,1,4,ChargeColor,2);
		tft_Clear(4,23,1,4,ChargeColor,2);
		tft_Clear(5,24,1,3,ChargeColor,2);
		tft_Clear(6,25,1,2,ChargeColor,2);		
		tft_Clear(7,26,1,1,ChargeColor,2);	
//		
		
//��������		
		if((time_s-testcmd3_time)>=5)  //0x16 0xe2����ȷ�����ӹ���
		{
			UART_BUFFER[0] = 'U';
			UART_BUFFER[1] = 'n';
			UART_BUFFER[2] = 'l';
			UART_BUFFER[3] = 'i';
			UART_BUFFER[4] = ':';
			UART_BUFFER[5] = (device.addr>>4)+'0';
			UART_BUFFER[6] = (device.addr&0x0f)+'0';
			UART_BUFFER[7] = 0;
			if(info2STR.item3_data[1]==0x01)
			{
			tft_DisplayStr(0, 7*5, UART_BUFFER,POINT_COLOR, BACK_COLOR,3);
			}
			GPIO_ResetBits(RJ45_IO1_PORT, RJ45_IO1_PIN);
		}
		else
		{
			UART_BUFFER[0] = 'L';
			UART_BUFFER[1] = 'i';
			UART_BUFFER[2] = 'n';
			UART_BUFFER[3] = 'k';
			UART_BUFFER[4] = ':';
			UART_BUFFER[5] = (device.addr>>4)+'0';
			UART_BUFFER[6] = (device.addr&0x0f)+'0';
			UART_BUFFER[7] = 0;
			if(info2STR.item3_data[1]==0x01)
			{
			tft_DisplayStr(0, 7*5, UART_BUFFER,POINT_COLOR, BACK_COLOR,3);
			}
		}
//���˿�		
		i=0;
		UART_BUFFER[i++] ='1';  //����1����
		UART_BUFFER[i++] =':';  //
		for(j=0;j<3;j++)
		{
			UART_BUFFER[i++] = Dport_State[j]+'0';
		}
		UART_BUFFER[i++] =0;
		if(info2STR.item3_data[0]==0x01)
		{
		tft_DisplayStr(0, 7*5+8*8, UART_BUFFER,POINT_COLOR, BACK_COLOR,1);
		}
		
		i=0;
		UART_BUFFER[i++] ='2';  //����2����
		UART_BUFFER[i++] =':';  //
		for(j=0;j<3;j++)
		{
			UART_BUFFER[i++] = Dport_State[3+j]+'0';
		}
		UART_BUFFER[i++] =0;
	if(info2STR.item3_data[0]==0x01)
		{
		tft_DisplayStr(0, 7*5+8*8, UART_BUFFER,POINT_COLOR, BACK_COLOR,2);
		}

}
			
