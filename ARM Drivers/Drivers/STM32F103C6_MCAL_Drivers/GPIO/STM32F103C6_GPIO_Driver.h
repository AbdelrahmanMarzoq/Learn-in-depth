/*
 * STM32F103C6_GPIO_Driver.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Abdelrhman Marzoq
 */

#ifndef STM32F103C6_GPIO_DRIVER_H_
#define STM32F103C6_GPIO_DRIVER_H_


//------------------------------------
//             Includes
//------------------------------------
#include "../STM32F103X6.h"


//------------------------------------
//             Typdef section
//------------------------------------

// @ref GPIO_PINS_DEFINE



typedef enum
{
	GPIO_PIN0  =				 1<<0,  // Pin 0 Selected
	GPIO_PIN1  =				 1<<1,  // Pin 1 Selected
	GPIO_PIN2  =				 1<<2,  // Pin 2 Selected
	GPIO_PIN3  =				 1<<3,  // Pin 3 Selected
	GPIO_PIN4  =				 1<<4,  // Pin 4 Selected
	GPIO_PIN5  =                 1<<5,  // Pin 5 Selected
	GPIO_PIN6  =	             1<<6,  // Pin 6 Selected
	GPIO_PIN7  =                 1<<7,  // Pin 7 Selected
	GPIO_PIN8  = 			     1<<8,  // Pin 8 Selected
	GPIO_PIN9  =				 1<<9,  // Pin 9 Selected
	GPIO_PIN10 = 				 1<<10,  // Pin 10 Selected
	GPIO_PIN11 =  			     1<<11,  // Pin 11 Selected
	GPIO_PIN12 =			  	 1<<12,  // Pin 12 Selected
	GPIO_PIN13 =		 	 	 1<<13,  // Pin 13 Selected
	GPIO_PIN14 = 				 1<<14,  // Pin 14 Selected
	GPIO_PIN15 =                 1<<15   // Pin 15 Selected
}PINy_t;


// @ref GPIO_MODE_DEFINE
/**
 * INPUT
 * 0: Analog mode
 * 1: Floating input
 * 2: Input with pull-up
 * 3: Input pull-down
 * OUTPUT
 * 4: General purpose output push-pull
 * 5: General purpose output Open-drain
 * 6: Alternate function output Push-pull
 * 7: Alternate function output Open-drain
 * 8: Alternate function input
 **/
typedef enum
{
	GPIO_MODE_ANALOG = 0,				// The selected pin is in analog mode
	GPIO_MODE_INPUT_FLO,				// input with floating mode
	GPIO_MODE_INPUT_PU,					// input with pull up
	GPIO_MODE_INPUT_PD,					// input with pull down
	GPIO_MODE_OUTPUT_PP,				// output with push-pull
	GPIO_MODE_OUTPUT_OD,				// output with open drain
	GPIO_MODE_OUTPUT_AF_PP,				// Alternative function output push-pull
	GPIO_MODE_OUTPUT_AF_OD,				// Alternative function output open drain
	GPIO_MODE_INPUT_AF	     			// Alternative function input
}DIR_MODE_t;

// @ref GPIO_SPEED_DEFINE
// 1: Output mode, max speed 10 MHz.
// 2: Output mode, max speed 2 MHz.
// 3: Output mode, max speed 50 MHz
typedef enum
{
	GPIO_SPEED_10M = 1,   // Output mode max speed 10 MHz
	GPIO_SPEED_2M ,   	  // Output mode max speed 2 MHz
	GPIO_SPEED_50M        // Output mode max speed 50 MHz
}SPEED_t;




typedef struct
{
	PINy_t GPIO_PinNumber;      //Specify the GPIO Pins to be configured
								//this paramater must be value based on @ref GPIO_PINS_DEFINE

	DIR_MODE_t GPIO_MODE;		//Specify the Operation mode for the selected Pin
								//this paramater must be value based on @ref GPIO_MODE_DEFINE

	SPEED_t GPIO_OUTPUT_Speed;	//Specify the speed for the selected Pin
								//this paramater must be value based on @ref GPIO_SPEED_DEFINE
}GPIO_PinConfig_t;

typedef enum
{
	LOW,
	HIGH
}Logic_t;

typedef enum
{
	NOK,
	OK
}RETURN_t;




/**================================================================
 * @Fn                 	- GPIO_INIT
 * @brief				- Initialize the GPIOx PINy according to the specified paramater in PinConfig
 * @param [in]			- myPin pointer to a GPIO_PinConfig_t structure that contatin
 * 						  the configuration information for the specified PORT & PIN.
 * @param [in]			- GPIOx where x can Be (A .... E)
 * @retval				- NONE
 * Note					- STM32F103C6 MCU has GPIO A,B,C,D,E,F,G
 * 						  but LQFP48 Package has only A,B and PART OF C,D
*/
void GPIO_INIT(GPIO_Periphral *GPIOx, GPIO_PinConfig_t *myPin);

/**================================================================
 * @Fn                 	- GPIO_deINIT
 * @brief				- reset all GPIO Register
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @retval				- NONE
 * Note					- NONE
*/
void GPIO_deINIT(GPIO_Periphral *GPIOx);

/**================================================================
 * @Fn                 	- GPIO_READ_PIN
 * @brief				- Read from specific Pin in port
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @param [in] 			- pin number in port
 * @retval				- NONE
 * Note					- NONE
*/
uint8_t GPIO_READ_PIN(GPIO_Periphral *GPIOx, PINy_t pinNumber);

/**================================================================
 * @Fn                 	- GPIO_READ_PORT
 * @brief				- Read From specific port
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @retval				- NONE
 * Note					- NONE
*/
uint16_t GPIO_READ_PORT(GPIO_Periphral *GPIOx);

/**================================================================
 * @Fn                 	- GPIO_WRITE_PIN
 * @brief				- Write logic on pin @specific port
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @retval				- NONE
 * Note					- NONE
*/
void GPIO_WRITE_PIN(GPIO_Periphral *GPIOx, PINy_t pinNumber, Logic_t Mode);

/**================================================================
 * @Fn                 	- GPIO_deINIT
 * @brief				- reset all GPIO Register
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @retval				- NONE
 * Note					- NONE
*/
void GPIO_WRITE_PORT(GPIO_Periphral *GPIOx, uint32_t value);

/**================================================================
 * @Fn                 	- GPIO_TOGGLE_PIN
 * @brief				- Toggle specific pin in Port
 * @param [in]			- GPIOx where x can Be (A .... E)]
 * @param [in] 			- pin number in port
 * @retval				- NONE
 * Note					- NONE
*/
void GPIO_TOGGLE_PIN(GPIO_Periphral *GPIOx, PINy_t pinNumber);

RETURN_t GPIO_LOCK_PIN(GPIO_Periphral *GPIOx, PINy_t pinNumber);



#endif /* STM32F103C6_GPIO_DRIVER_H_ */
