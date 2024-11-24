/*
 * EEPROM.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Abdelrhman Marzoq
 */


#include "EEPROM.h"

I2C I2C_Instant;
void EEPROM_init()
{


	I2C_Instant.I2Cx = I2C1;
	I2C_Instant.Mode = SM_Mode;
	I2C_Instant.SCL_Speed = SCL_100KHz;

	I2C_INIT(&I2C_Instant);
}


void EEPROM_Write(uint16_t Memory_Address, uint8_t *bytes, uint8_t Length)
{
	uint8_t Buffer [256];
	Buffer[0] = (uint8_t)Memory_Address >> 8; 	// Upper Byte of address
	Buffer[1] = (uint8_t)Memory_Address; 		// Lower Byte of address

	for (uint16_t i = 2; i < Length+2; i++)
	{
		Buffer[i] = *bytes;
		bytes++;
	}

	I2C_Master_Write(&I2C_Instant, Bit_7, EEPROM_Slave_Address, bytes, Length+2, With_Stop,Start);
}

void EEPROM_Read(uint16_t Memory_Address, uint8_t *bytes, uint8_t Length)
{
	uint8_t Buffer[2];
	Buffer[0] = (uint8_t)Memory_Address >> 8; 	// Upper Byte of address
	Buffer[1] = (uint8_t)Memory_Address; 		// Lower Byte of address

	I2C_Master_Write(&I2C_Instant, Bit_7, EEPROM_Slave_Address, Buffer, 2, Without_Stop, Start);
	I2C_Master_Read(&I2C_Instant, Bit_7, EEPROM_Slave_Address, bytes, Length, With_Stop, Repeated);


}
