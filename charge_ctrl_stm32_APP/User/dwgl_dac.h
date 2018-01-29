//*******************************************
//dwgl for stm32f1XX
//V1.1 20160401
//*******************************************
//#include "dwgl_dac.h"
#ifndef __DWGL_DAC_H
#define	__DWGL_DAC_H
#include "stm32f10x.h"


//#define
#define	dac_out_Normal//�ֶ����·�ʽ
//#define	dac_out_Sin      // DMA��ʽ
//#define	dac_out_Triangle 			//�ڲ����Ƿ�������ʽ
// #define	dac_out_Normal	 1//�ֶ����·�ʽ
// #define	dac_out_Sin      2// DMA��ʽ
// #define	dac_out_Triangle 3			//�ڲ����Ƿ�������ʽ
//#define	dac_mode dac_out_normal	 //�ֶ����·�ʽ

//����
 extern  u8  *DAC1_Pointer;
 extern  u8   DAC1_State;
 extern  u8   DAC1_Error;
 extern  u16  DAC1_Buffer;

 extern  u8  *DAC2_Pointer;
 extern  u8   DAC2_State;
 extern  u8   DAC2_Error;
 extern  u16  DAC2_Buffer;

//�ӳ���
extern void DAC1_Enable(void);
extern void DAC1_Disable(void);
extern void DAC1_Init(void);
extern void DAC1_Set(u8 baud,u8 work_mode);

extern void DAC2_Enable(void);
extern void DAC2_Disable(void);
extern void DAC2_Init(void);
extern void DAC2_Set(u8 baud,u8 work_mode);

extern void DAC_Configuration(void);


#endif

