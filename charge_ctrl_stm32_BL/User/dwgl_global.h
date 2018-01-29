//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#ifndef __DWGL_GLOBAL_H
#define	__DWGL_GLOBAL_H

#include "stm32f10x.h"

#if defined (STM32F10X_LD)
 #error " target STM32F10x device used (STM32F10X_LD) (in dwgl_global.h file)"
#endif

#if defined (STM32F10X_LD_VL)
 #error " target STM32F10x device used (STM32F10X_LD_VL) (in dwgl_global.h file)"
#endif
#if defined (STM32F10X_MD)
 #error " target STM32F10x device used (STM32F10X_MD) (in dwgl_global.h file)"
#endif
#if defined (STM32F10X_MD_VL) 
 #error " target STM32F10x device used (STM32F10X_MD_VL) (in dwgl_global.h file)"
#endif
#if !defined (STM32F10X_HD)
 #error " target STM32F10x device used (STM32F10X_HD) (in dwgl_global.h file)"
#endif
#if defined (STM32F10X_HD_VL)
 #error " target STM32F10x device used (STM32F10X_HD_VL) (in dwgl_global.h file)"
#endif
#if defined (STM32F10X_XL)
 #error " target STM32F10x device used (STM32F10X_XL) (in dwgl_global.h file)"
#endif
#if defined (STM32F10X_CL)
 #error " target STM32F10x device used (STM32F10X_CL) (in dwgl_global.h file)"
#endif
//cmd
#define frame_headerC			  0x67
#define frame_headerD			  0x68
#define frame_last			    0x99
#define Version_FLAG1			  ('B')  //�汾��־1
//#define port_num    			  0x02
#define cmd_set_addr			  0xe2  //������ư��ַ����

#define  Addr_01min		0x000000   //��ά���ַʼ
#define  Addr_01max		0x01ffff   //��ά���ַĩ
#define  Addr_02min		0x080000   //СͼƬ��ַʼ
#define  Addr_02max		0x09FFFF   //СͼƬ��ַĩ
#define  Addr_03min		0x100000   //��ͼƬ��ַʼ
#define  Addr_03max		0x2FFFFF   //��ͼƬ��ַĩ
#define  Addr_04min		0x400000   //��ͼƬ��ַʼ
#define  Addr_04max		0xBFFFFF   //��ͼƬ��ַĩ
#define  Addr_05min		0xE00000   //�����ַ��
#define  Addr_05max		0xEFFFFF   //�����ַĩ
#define  Addr_info1   0xF00000   //��Ϣ��ַ1
#define  Addr_info2   0xF10000   //��Ϣ��ַ2

#define GLOBLE_ADDR			  0xE0
#define PC_ADDR			      0xF0
#define Broadcast   			0xFF

#define ADC_LINE1   			0x0c0  //����Щ��ѹ��Ϊ���ֻ�;=0xc0����Ϊ310mV,�������Ҫ������
#define ADC_LINE2   			0x080  //����������Χ ;=0x80 ����Ϊ20mA
#define ADC_LINE3   			0x060  //����������Χ ;=0x60 ����Ϊ15mA  ����С�ڴ�ֵ��ʾû��ʹ��
//#define ADC_LINE2   			0x0100  //����������Χ ;=0x100 ����Ϊ40mA

#define UART1_RXBUFFER_SIZE		 0x200
#define UART1_RX_MAX		       0x1FF
#define UART3_RXBUFFER_SIZE		 0x80
#define UART3_RX_MAX		       0x7f

struct  Addr_info2STR {
				u8		head[2];
				u8		temp[3];
				u8		item1[2];	  	     //�������������ֳ� 
				u8		item1_data[4]; 
				u8		item2[2];	  	    //���������������ֳ�      
				u8		item2_data[4]; 
				u8		item3[2];	  	    //��Ļ��ʾ������ʾ����  =1������    
				u8		item3_data[2]; 
				u8		item11[2];	  	    //ͼƬ�汾�����������ֳ�      
				u8		item11_data[16]; 
				u8		item12[2];	  	    //ͼƬ�汾�����������ֳ�      
				u8		item12_data[16]; 
				u8		item13[2];	  	    //ͼƬ�汾�����������ֳ�      
				u8		item13_data[16]; 
				u8		item14[2];	  	    //ͼƬ�汾�����������ֳ�      
				u8		item14_data[16]; 
				u8		item15[2];	  	    //ͼƬ�汾�����������ֳ�      
				u8		item15_data[16]; 
				u8		item21[2];	  	    //��������趨��
				u8		item21_data[4];     //
				u8		item81[2];	  	    //�豸����
				u8		item81_data[16]; 
				u8		item31[2];	  	    //B�����汾�������ֳ� 
				u8		item31_data[16];     //
				u8		item32[2];	  	    //A�����汾�������ֳ� 
				u8		item32_data[16];     //
				};	

struct  device_table {
				u8		head;
				u8		addr;
				u16		Toolname;	  	        
				u8		Version[12];   //
				u8    port_num; 
				u8		hub_id[8];   //
				u8		port_id[8]; //ֻ����ǰ����������˿ں�
				u8	  use;			//ʹ����� bit0=1���Ӷϣ� bit1=1��ַ���ά���ͻ�� bit2=1��0���޶�ά�� �� bit3=1��1���޶�ά�� ��bit4=1����ά���и���
				u8	  TASK_state;  //��������Գ���
				};	  

struct  file_table {
				u8		f_class;
				u8		f_unm;
				u8		f_name[8];	  	        
				u8		f_size[4]; 
				u8		f_addr[4]; 
				};	        
// 		str_buffer[0]=     //ͷ0X67
// 		str_buffer[?]=     //LEN
// 		str_buffer[?]=     //�ļ���u8
// 		str_buffer[?]=		 //�ļ���u8
// 		str_buffer[?]=		 //�ļ���u64
// 		str_buffer[?]=		//�ļ���Сu32
// 		str_buffer[?]=		//�ļ����ַu32
// 		str_buffer[?]=     //check
// 		str_buffer[?]=     //β0X99

struct  LCDREG {
				u8		Head;    //ͷ
				u8		LCD1POFFTime;	  //�ϵ�ʱ��        
				u8		LCD2POFFTime;	  //�ϵ�ʱ��     
				u8		SPSwitch;    //��������
				u16	  LCDSPTimeSet;	  //�������        
				u16	  LCD1SPTime;	  	//�����������       
				u16	  LCD2SPTime;	  	//�����������         
				u8	  LCD1SPPID;	  	//����ID      
				u8	  LCD2SPPID;	  	//����ID     
				u8		PSwitch;    //��濪��
				u8		PNum;       //������
				u16		LCDPTimeSet;	  //�����        
				u16		LCD1PTime;	  	//���������         
				u16		LCD2PTime;	  	//���������         
				u8		LCD1PID;	  	//���ͼƬID        
				u8		LCD2PID;	  	//���ͼƬID       
				};	 

extern  struct  device_table device;
extern  struct  file_table * file_p;
extern  struct  file_table file_t;
extern  struct  Addr_info2STR info2STR;
extern  struct  LCDREG  LCDC;
extern 	u16 step;
extern 	u16 time_s;
extern 	u16 testcmd1_time;
extern 	u16 testcmd3_time;
extern 	u32 time_s_temp;
extern 	u32 time_sys_temp1;
extern 	u32 time_sys_temp2;
extern 	u32 time_sys_temp3;
extern 	u32 time_sys_temp4;
extern 	u32 time_sys_temp5;
extern 	u32 time_sys;
extern 	u8 global_u8temp;
extern 	u8 *global_u8p;
extern 	u16 global_u16temp;
extern 	u16 *global_u16p;
extern 	u16 global_u16BUFFER[128];
extern 	u8 global_u8BUFFER[128];

extern volatile unsigned char touch_flag;
extern 	u32 time_uart1;
extern 	u32 time_uart3;
extern  u8  str_buffer[4100];   //����ʾ���ڴ�
extern  u8  LCD1_TxtBuffer[2050];   //����ʾ���ڴ�
extern  u8  LCD2_TxtBuffer[2050];   //����ʾ���ڴ�
extern 	u16 Uport_PowerSetTime[2];
extern 	u16 Uport_PowerUseTime[2];
extern 	u16 Uport_PowerShowTime[2];
extern 	u16 Dport_PowerSetTime[6];
extern 	u16 Dport_PowerUseTime[6];
extern 	u8 Dport_State[6];  //
extern 	u8 checking_portB;  //���׶�
extern 	u8 checking_portC;
extern 	u8 LOW_portB;		//�͵�������
extern 	u8 LOW_portC;
// extern 	u8 LOW_portB;		//
// extern 	u8 LOW_portC;
// extern  u8  LCD1_CTRL8[8];   //��LCD1������
// extern  u8  LCD2_CTRL8[8];   //��LCD2������

extern 	u32 file_addr;  //д�ļ�ʱ��ַ
extern 	u32 Rfile_addr; //���ļ�ʱ��ַ
extern 	u8 file_hook;
extern 	u8 file_wr;
extern 	u8 file_id;  //��ǰ��д�ļ���ID
extern 	u32 NextFileAddr;
extern 	u32 check_time;
extern 	u32 KEY_time;
//extern 	u32 display_time;
extern 	u8  UART_BUFFER[128];
extern 	u8  UART1_TXBUFFER[128];
extern 	u8  UART1_RXBUFFER[UART1_RXBUFFER_SIZE];
extern 	u16  UART1_RXBUFFE_HEAD;   //��Ч���ݵĵ�һ��
extern 	u16  UART1_RXBUFFE_LAST;	//��Ч���ݵ����һ��
extern 	u8  UART2_TXBUFFER[128];
extern 	u8  UART2_RXBUFFER[128];
extern 	u8  UART3_TXBUFFER[128];
extern 	u8  UART3_RXBUFFER[UART3_RXBUFFER_SIZE];
extern 	u16  UART3_RXBUFFE_HEAD;   //��Ч���ݵĵ�һ��
extern 	u16  UART3_RXBUFFE_LAST;	//��Ч���ݵ����һ��
extern 	u8  SPI_BUFFER[128];
extern 	u16 ADC_BUFFER[320];
extern 	u8 AINx_ADCch[18];
extern  u16 ADC_Base0[18];  //ADC��ֵ̬
extern 	u8 device_num[20];  //

extern 	u8  SF_REG;
extern 	u8  GAIN_REG;

/* �������� ---------------------------------------------------------*/
extern  uint16_t Sine12bit[32];
/* �������� ---------------------------------------------------------*/
extern  uint16_t co_x[10];
/* �������� ---------------------------------------------------------*/
extern  uint16_t co_y[10];
/* �Ź����� ---------------------------------------------------------*/
extern  uint16_t xy_3[3][3];

extern void NVIC_Configuration(void);
#endif
