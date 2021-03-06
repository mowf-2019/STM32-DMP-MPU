#ifndef _I2C_SOFT_H
#define	_I2C_SOFT_H

#include "stm32f4xx.h"
#include "time.h"
 

#define  I2C_DELAY_TIME 3;

///***************I2C GPIO定义******************/
//#define ANO_GPIO_I2C	   GPIOB
//#define I2C_Pin_SCL		IIC_SCL_Pin
//#define I2C_Pin_SDA		 IIC_SDA_Pin
//#define ANO_RCC_I2C		//RCC_AHB1Periph_GPIOB
///*********************************************/

/***************I2C GPIO定义******************/
#define ANO_GPIO_I2C	   GPIOC
#define I2C_Pin_SCL		IIC2_SCL_Pin
#define I2C_Pin_SDA		 IIC2_SDA_Pin
#define ANO_RCC_I2C		//RCC_AHB1Periph_GPIOB
/*********************************************/


#define SCL_H         ANO_GPIO_I2C->BSRR = I2C_Pin_SCL
#define SCL_L        ANO_GPIO_I2C->BSRR =  (uint32_t)I2C_Pin_SCL << 16U
#define SDA_H        ANO_GPIO_I2C->BSRR = I2C_Pin_SDA
#define SDA_L        ANO_GPIO_I2C->BSRR=  (uint32_t)I2C_Pin_SDA << 16U
#define SCL_read        ANO_GPIO_I2C->IDR  & I2C_Pin_SCL
#define SDA_read        ANO_GPIO_I2C->IDR  & I2C_Pin_SDA

class I2c_SOFT
{
public:
	 
	

	//int I2c_Soft_Single_Write(u8 SlaveAddress,u8 REG_Address,u8 REG_data);
	//int I2c_Soft_Single_Read(u8 SlaveAddress,u8 REG_Address);
	//int I2c_Soft_Mult_Read(u8 SlaveAddress,u8 REG_Address,u8 * ptChar,u8 size);

	u8 IIC_Write_1Byte(u8 SlaveAddress, u8 REG_Address, u8 REG_data);
	u8 IIC_Read_1Byte(u8 SlaveAddress, u8 REG_Address, u8 *REG_data);
	u8 IIC_Write_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);
	u8 IIC_Read_nByte(u8 SlaveAddress, u8 REG_Address, u8 len, u8 *buf);


private:
	volatile u8 I2C_FastMode;
	
	u8 I2c_Soft_ReadByte(u8);
	void   I2c_Soft_delay();
	int  I2c_Soft_Start();
	void  I2c_Soft_Stop();
	void I2c_Soft_Ask();
	void  I2c_Soft_NoAsk();
	int  I2c_Soft_WaitAsk(void); 	 //返回为:=1无ASK,=0有ASK
	void I2c_Soft_Init(void);
	void I2c_Soft_SendByte(u8 SendByte);
};
 
extern I2c_SOFT i2c_soft;


#endif
