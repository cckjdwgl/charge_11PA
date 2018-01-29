//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
#ifndef  __DWGL_SPI_H
#define  __DWGL_SPI_H
#include "stm32f10x.h"

//define 
//#define	SPI1_init_Normal//�ֶ����·�ʽ
#define	SPI1_init_DMA      // DMA��ʽ

//����
 extern  u8  *SPI1_Receive_Pointer;
 extern  u16  SPI1_Receive_BufSize;
 extern  u16  SPI1_Receive_Length;
 extern  u8  *SPI1_Trans_Pointer;
 extern  u16  SPI1_Trans_BufSize;
 extern  u16  SPI1_Trans_Length;
 extern  u8   SPI1_TX_State;
 extern  u8   SPI1_RX_State;
 extern  u8   SPI1_Error;

 extern  u8  *SPI2_Receive_Pointer;
 extern  u16  SPI2_Receive_BufSize;
 extern  u16  SPI2_Receive_Length;
 extern  u8  *SPI2_Trans_Pointer;
 extern  u16  SPI2_Trans_BufSize;
 extern  u16  SPI2_Trans_Length;
 extern  u8   SPI2_TX_State;
 extern  u8   SPI2_RX_State;
 extern  u8   SPI2_Error;

//�ӳ���
extern void SPI1_Enable(void);
extern void SPI1_Disable(void);
extern void SPI1_Init(void);
extern void SPI1_Set(u8 baud,u8 work_mode);
//extern void SPI1_Send_Data(u8 * p,u16 len);
extern void SPI1_Send_Data(u8 * txp,u8 * rxp,u16 len);
extern void SPI1_Send_Data1(u8 * txp,u8 * rxp,u16 len);

extern void SPI2_Enable(void);
extern void SPI2_Disable(void);
extern void SPI2_Init(void);
extern void SPI2_Set(u8 baud,u8 work_mode);
extern void SPI2_Send_Data(u8 * p,u16 len);

extern void GPIOSPI_Init(void);
extern void GPIOSPI_Send_BYTE(u8 data);
extern void GPIOSPI_Send1_BYTE(u8 data);
extern void GPIOSPI_Send_Data(u8 * p,u16 len);
extern void GPIOSPI_Send1_Data(u8 * p,u16 len);

extern u8 GPIOSPI_Read_BYTE(void);
extern void GPIOSPI_Read_Data(u8 * p,u16 len);

extern u8 GPIOSPI_SR_BYTE(u8 data);
extern void GPIOSPI_SR_Data(u8 * tx,u8 * rx,u16 len);

extern void GPIOSPI_ESend_Data(u8 * p,u16 len);
extern void GPIOSPI_FSend_Data(u8 * p,u16 len);
extern void GPIOSPI_EFSend_Data(u8 * p,u16 len);
void FLASH2_GPIOSPI_Read (unsigned int write_addr, unsigned char *buffer, unsigned int len);//FLASH-����LEN���ֽ�-
void FLASH2_GPIOSPI_Write(unsigned int write_addr, unsigned char *desbuffer,unsigned int len); // reentrant//FLASH-д��LEN���ֽ�
void FLASH2_GPIOSPI_IsBusy(void); // 
void FLASH2_GPIOSPI_SER(unsigned int u32_addr);//��ҳ��������flash  ÿ�β���4K
void FLASH2_GPIOSPI_SE(unsigned int u32_addr);//�����������flash  ÿ�β���64K


extern void SPI_Configuration(void);

#endif

