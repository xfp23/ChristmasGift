#ifndef __OLED_H
#define __OLED_H 

#include "main.h"
#include "stdlib.h"	
#include "stdint.h"

//-----------------测试LED端口定义---------------- 

#define LED_ON HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2)
#define LED_OFF HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2)

//-----------------OLED端口定义---------------- 

#define OLED_SCLK_Clr() HAL_GPIO_WritePin(OLED_DI_Port,OLED_DO_Pin,0)//SCL
#define OLED_SCLK_Set() HAL_GPIO_WritePin(OLED_DI_Port,OLED_DO_Pin,1)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(OLED_DI_Port,OLED_DI_Pin,0)//DIN
#define OLED_SDIN_Set() HAL_GPIO_WritePin(OLED_DI_Port,OLED_DI_Pin,1)

#define OLED_RST_Clr() HAL_GPIO_WritePin(OLED_RES_Port,OLED_RES_Pin,0)//RES
#define OLED_RST_Set() HAL_GPIO_WritePin(OLED_RES_Port,OLED_RES_Pin,1)

#define OLED_DC_Clr() HAL_GPIO_WritePin(OLED_DC_Port,OLED_DC_Pin,0)//DC
#define OLED_DC_Set() HAL_GPIO_WritePin(OLED_DC_Port,OLED_DC_Pin,1)
 		     
#define OLED_CS_Clr()  HAL_GPIO_WritePin(OLED_CS_Port,OLED_CS_Pin,0)//CS
#define OLED_CS_Set()  HAL_GPIO_WritePin(OLED_CS_Port,OLED_CS_Pin,1)


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define uint8_t unsigned char
#define uint32_t unsigned int

void OLED_ClearPoint(uint8_t x,uint8_t y);
void OLED_ColorTurn(uint8_t i);
void OLED_DisplayTurn(uint8_t i);
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y);
void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);
void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1);
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1);
void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1);
void OLED_ScrollDisplay(uint8_t num,uint8_t space);
void OLED_WR_BP(uint8_t x,uint8_t y);
void OLED_ShowPicture(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1,uint8_t BMP[]);
void OLED_Init(void);

#endif