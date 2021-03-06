#ifndef __BARO_H
#define __BARO_H 

#include "include.h"
#include "mymath.h"
#include "i2c_soft.h"
#include "kalman.h"

#define MS5611_ADDR             0x77   //0xee //

#define CMD_RESET               0x1E // ADC reset command
#define CMD_ADC_READ            0x00 // ADC read command
#define CMD_ADC_CONV            0x40 // ADC conversion command
#define CMD_ADC_D1              0x00 // ADC D1 conversion
#define CMD_ADC_D2              0x10 // ADC D2 conversion
#define CMD_ADC_256             0x00 // ADC OSR=256
#define CMD_ADC_512             0x02 // ADC OSR=512
#define CMD_ADC_1024            0x04 // ADC OSR=1024
#define CMD_ADC_2048            0x06 // ADC OSR=2048
#define CMD_ADC_4096            0x08 // ADC OSR=4096
#define CMD_PROM_RD             0xA0 // Prom read command
#define PROM_NB                 8
#define MS5611_OSR							0x08	//CMD_ADC_4096

#define BARO_CALL_OFF_SET_TIME 10

#define BARO_fil_NUM  5

#define BARO_speed_fil_NUM  20
class BARO
{
public:
	BARO()
	{
		  high_filed_hz = 0.75;
		  speed_filed_hz = 1;
		  high_filed_hz2 = 0.6;
		  speed_filed_hz2 = 2.6;
	}
	float high_filed_hz  ;
	float speed_filed_hz ;
        float high_filed_hz2  ;
	float speed_filed_hz2 ;
        
        
	  short open_kalman ;
	  float high_kf_pos_acc;
	  float wz_kf_pos_acc;
	  float wz_kf_save[3];
	  float acc_z_kf;
	  float acc_z_feed_back;
	  GPS_BARO_ACC_KF gps_baro_kf;
	Pos_Acc_Kalman  height_pos_acc_kalman;
	//Pos_WZ_Kalman pos_wz_kalamn;
	  u8 ms5611_ok;
	  int32_t baroAlt; 
          float baroAltOld[2];
	  float baro_alt_speed;
	    float pressure;
	  float temperature_5611;
	  
	  int32_t baro_Offset;
	  uint32_t ms5611_ut;  // static result of temperature measurement
	  uint32_t ms5611_up;  // static result of pressure measurement
	  uint16_t ms5611_prom[PROM_NB];  // on-chip ROM
	  uint8_t t_rxbuf[3], p_rxbuf[3];
	   u8   sum_cnt  ;
	   float  offset; 
	   float  offset_sum;
	
	   char CALL_OFFSET;
	   float h_filt_buff[BARO_fil_NUM + 1];
	   unsigned   short h_filt_cnt[2];
	   
	   float speed_filt_buff[BARO_speed_fil_NUM + 1];
	   unsigned  short speed_filt_cnt[2];
	   float speed_filed;
	   float high_filed;
	   float high_filed_lf;
	


	//????????????????????????
	void MS5611_Init(void);
	//????????????????????????????
	int MS5611_Update(void);
	//????????????????????????

	int32_t MS5611_Get_BaroAlt(void);

	void MS5611_Reset(void);
	u8 MS5611_Read_Prom(void);
	void MS5611_Start_T(void);
	void MS5611_Start_P(void);
	void MS5611_Read_Adc_T(void);
	void MS5611_Read_Adc_P(void);
	void MS5611_BaroAltCalculate(void);

	void height_speed_filter(float T);
	void call_offset(void);
private:

};

extern BARO baro;

#endif
