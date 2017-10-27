# Lidar-lite-v3-atmega328p-
This is header file for Lidar-lite-v3 for Atmega328p. For other microcontrollers, changing registers name will work.

WORKING PRINCIPLE USING MODE CONTROL PIN.
The mode control pin is shorted with rec_bit on microcontroller and mode control pin is connected to trig_bit through 1k resistor.
When the trig_bit is made low, the LIDAR acknowledges by sending LASER and pulling up the mode control pin and hence the rec_bit.

when the LASER returns back i.e. when obstacle is detected near, the mode control pin becomes low.

HOW TO PROGRAM?
 1) clear the trig_bit to send LASER through LIDAR.
 2) wait until the trig_bit is low.
 3) start timer.
 4) wait until the trig_bit is high. (i.e obstacle is detected)
 5) stop the timer.
 6) calculate the distance , given that the the LASER travels 1cm in 10us.
