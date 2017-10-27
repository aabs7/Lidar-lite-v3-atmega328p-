/*
 * lidar.cpp
 *
 * Created: 10/12/2017 7:39:41 PM
 *  Author: abheesh
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lidar.h"


volatile uint32_t Ofcounter = 0;
volatile uint32_t trig_counter = 0;
volatile uint32_t no_of_ticks = 0;

/************Initialises LIDAR by setting TRIG pin in AVR as output and REC as Input**********/
void Init_Lidar()
{
	TRIG_OUTPUT_MODE();		//set trigger as output
	TRIG_HIGH();
	REC_INPUT_MODE();
} 

void Trigger_Lidar()
{
	TRIG_LOW();				//clear trigger to send signal
	_delay_us(10);
}

/**********************		Increament timer for each overflow ************/
ISR (TIMER1_OVF_vect)
{
Ofcounter++;
TCNT1 = 0;
}

/********************** Calculate and return distance *****************
		Returns:	Distance : LIDAR Distance 
***********************************************************************/

 int Read_Lidar()
{
	uint32_t distance_in_cm = 0;
	Ofcounter = 0;
	Init_Lidar();
	Trigger_Lidar();
	sei();
	while(!(REC_PIN &(1<<REC_BIT)));//while rec bit is low
	
	/********************************************************/
	/*	Add if receive bit is high for much long time , it shows error */
	/*********************************************************/
	
	TCCR1B |= (1<<CS10);
	TIMSK1 |= (1<<TOIE1);
	TCNT1 = 0;
	
	while((REC_PIN &(1<<REC_BIT)));	  //while rec_bit is high
	
	TCCR1B = 0x00;			//stop 16 bit timer with no prescaler
	
	uint32_t TIME = ((Ofcounter*TIMER_MAX + TCNT1)*(1.00/(F_CPU))*1000000 );
	
	distance_in_cm = ((TIME/TIME_PER_CM));
	TRIG_PORT |= (1<<TRIG_BIT);
	return (distance_in_cm);
	
}

