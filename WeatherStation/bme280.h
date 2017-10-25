/**
 * \file bme280.h
 * \brief BME280 simple drivers
 * \author Florent Colinet
 * \version 1.0
 * \date October 24, 2017
 *
 */
#ifndef __BME280_H__

  #define __BME280_H__

	#include "Arduino.h"

	#define BME280_ADDRESS      					0x77	// define the default I2C address

	// Name of Registers used in the BME280
	#define BME280_DIG_T1_REG   					0x88
	#define BME280_DIG_T2_REG   					0x8A
	#define BME280_DIG_T3_REG   					0x8C
	#define BME280_DIG_P1_REG   					0x8E
	#define BME280_DIG_P2_REG   					0x90
	#define BME280_DIG_P3_REG   					0x92
	#define BME280_DIG_P4_REG   					0x94
	#define BME280_DIG_P5_REG   					0x96
	#define BME280_DIG_P6_REG   					0x98
	#define BME280_DIG_P7_REG   					0x9A
	#define BME280_DIG_P8_REG   					0x9C
	#define BME280_DIG_P9_REG   					0x9E

	#define BME280_DIG_H1_REG   					0xA1
	#define BME280_DIG_H2_REG   					0xE1
	#define BME280_DIG_H3_REG   					0xE3
	#define BME280_DIG_H4_REG   					0xE4
	#define BME280_DIG_H5_REG   					0xE5
	#define BME280_DIG_H6_REG   					0xE7

	#define BME280_REGISTER_CHIPID       	0xD0
	#define BME280_REGISTER_VERSION      	0xD1
	#define BME280_REGISTER_SOFTRESET    	0xE0
	#define BME280_REGISTER_CAL26        	0xE1
	#define BME280_REGISTER_CONTROLHUMID 	0xF2
	#define BME280_REGISTER_CONTROL      	0xF4
	#define BME280_REGISTER_CONFIG       	0xF5
	#define BME280_REGISTER_PRESSUREDATA 	0xF7
	#define BME280_REGISTER_TEMPDATA     	0xFA
	#define BME280_REGISTER_HUMIDDATA    	0xFD
	
	struct bme280_Calibration_Data {

		public:
			uint16_t dig_T1;
			int16_t  dig_T2;
			int16_t  dig_T3;
			
			uint16_t dig_P1;
			int16_t  dig_P2;
			int16_t  dig_P3;
			int16_t  dig_P4;
			int16_t  dig_P5;
			int16_t  dig_P6;
			int16_t  dig_P7;
			int16_t  dig_P8;
			int16_t  dig_P9;

			uint8_t  dig_H1;
			int16_t  dig_H2;
			uint8_t  dig_H3;
			int16_t  dig_H4;
			int16_t  dig_H5;
			int8_t   dig_H6;

	};

  class bme280 {

    private:
			bme280_Calibration_Data c_data;

			void initialize(void);

			void readTemperature(void);
			void readPressure(void);
			void readHumidity(void);
			void readAltitude(void);
			void readSensorCoefficients(void);

			float tempOffset;			// stores the temp offset
			float seaLevel;				// stores the sea level
			float temperature;    // stores temperature value
			float humidity;       // stores humidity value
			float pressure;       // stores pressure value
			float altitude;       // stores altitude value

			// functions used for sensor communications
			void write8(byte reg, byte value);
			uint8_t read8(byte reg);
			uint16_t read16(byte reg);
			uint32_t read24(byte reg);
			int16_t readS16(byte reg);
			uint16_t read16_LE(byte reg);
			int16_t readS16_LE(byte reg);

			uint8_t _i2cAddr;
			int32_t _sensorID;
			int32_t t_fine;
		
    public:
      bme280(void);
      bme280(uint8_t);

			bool begin(void);

			void setTempOffset(float);
			void setSeaLevel(float);

			void readSensor(void);

			float getTemperature_C(void);
			float getTemperature_F(void);

			float getHumidity(void);

			float getPressure_HP(void);
			float getPressure_MB(void);

			float getAltitude(void);

  };

#endif

