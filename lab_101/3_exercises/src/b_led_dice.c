/*
 * b_led_dice.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// map the led to GPIO PA8
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};
gpio_pin_t led4 = {PA_8, GPIOA, GPIO_PIN_8};
gpio_pin_t led5 = {PB_8, GPIOB, GPIO_PIN_8};


// this is the main method
int main()
{
//initialise the HAL library and the system clock frequency

  HAL_Init();
  init_sysclk_216MHz();

// initialise the GPIO
  init_gpio(led, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
	init_random();
	
	while(1)
	{
		uint32_t rnd = (get_random_int() % 6) + 1;
		
		if( rnd == 1)										// if random number = 1
		{
			//turn LEDs ON for a second
			write_gpio (led4,HIGH);
			HAL_Delay(1000);
			//turn LEDs OFF for a second
			write_gpio (led4,LOW);
			HAL_Delay(1000);
		}
		if (rnd == 2)										// if random number = 2
		{
			//turn LEDs ON for a second
			write_gpio (led,HIGH);
			write_gpio (led2,HIGH);
			HAL_Delay(1000);
			//turn LEDs OFF for a second
			write_gpio (led,LOW);
			write_gpio (led2,LOW);
			HAL_Delay(1000);
		}
		if (rnd == 3)										// if random number = 3
		{
			//turn LEDs ON for a second
			write_gpio (led,HIGH);
			write_gpio (led2,HIGH);
			write_gpio (led4,HIGH);
			HAL_Delay(1000);
			//turn LEDs OFF for a second
			write_gpio (led,LOW);
			write_gpio (led2,LOW);
			write_gpio (led4,LOW);
			HAL_Delay(1000);
		}
		if (rnd == 4)											// if random number = 4
		{
			//turn LEDs ON for a second
			write_gpio (led,HIGH);
			write_gpio (led2,HIGH);
			write_gpio (led3,HIGH);
			write_gpio (led5,HIGH);
			HAL_Delay(1000);
			//turn LEDs OFF for a second
			write_gpio (led,LOW);
			write_gpio (led2,LOW);
			write_gpio (led3,LOW);
			write_gpio (led5,LOW);
			HAL_Delay(1000);

		}
		if (rnd == 5)												// if random number = 5
		{
			//turn LEDs ON for a second
			write_gpio (led,HIGH);
			write_gpio (led2,HIGH);
			write_gpio (led3,HIGH);
			write_gpio (led5,HIGH);
			write_gpio (led4,HIGH);
			HAL_Delay(1000);
			//turn LEDs OFF for a second
			write_gpio (led,LOW);
			write_gpio (led2,LOW);
			write_gpio (led3,LOW);
			write_gpio (led5,LOW);
			write_gpio (led4,LOW);
			HAL_Delay(1000);

		}
		
	}
	
}
