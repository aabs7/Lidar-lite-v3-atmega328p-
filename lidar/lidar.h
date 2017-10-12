/*
 * lidar.h
 *
 * Created: 10/12/2017 7:38:05 PM
 *  Author: abheesh
 */ 


#ifndef LIDAR_H_
#define LIDAR_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#define TRIG_DDR	DDRD                  //TRIG PORT
#define TRIG_PORT	PORTD
#define TRIG_PIN	PIND
#define TRIG_BIT	PD2                   //TRIG PIN

#define REC_DDR		DDRD                  //RECEIVING PORT
#define REC_PORT	PORTD
#define REC_PIN		PIND
#define REC_BIT		PD3                  //RECEIVING PIN

#define DELAY_BETWEEN_TEST	500			 //Delay of 500us between every test
#define TIMER_MAX			65535
#define SENSOR_TIMEOUT		

//constant for LIDAR TIME_PER_CM//

#define	TIME_PER_CM			10			 //10us time for a cm travel of light

//////////////////////////////////

#define TRIG_OUTPUT_MODE()		TRIG_DDR |= (1<<TRIG_BIT)
#define TRIG_LOW()				TRIG_PORT &= ~(1<<TRIG_BIT)
#define TRIG_HIGH()				TRIG_PORT |= (1<<TRIG_BIT)

#define REC_INPUT_MODE()		REC_PORT  &= ~(1<<REC_BIT)
#define REC_LOW()				REC_PORT  &= ~(1<<REC_BIT)
#define REC_HIGH()				REC_PORT  |=  (1<<REC_BIT)


/*
	@brief INITIALIZE PORTS FOR RECEIVING AND TRIGGER PINS
	@parameter void
	@return none
*/
void Init_Lidar(void);

/*
	@brief trigger light for continuous measurement
	@parameter	void
	@return		none
*/
void Trigger_Lidar(void);

/*
	@brief	calculate and return distance
	@parameter void
	@return unsigned int
*/
int Read_Lidar(void);





#endif /* LIDAR_H_ */