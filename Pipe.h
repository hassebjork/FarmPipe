#ifndef _Pipe_h
#define _Pipe_h

#include <TimeLib.h>
#include <Wire.h>
#include <pcf8574_esp.h>

#define PUMP   1
#define SWITCH 2

#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

class Pipe {
public:
	static PCF857x pumps;
	static PCF857x floats;
	uint8_t _pin;
	uint8_t _state;	// Pipe state
	uint8_t _water_freq;	// Watering frequency per day
	time_t  _water_next;
	
	Pipe();
	void config( uint8_t pin, uint8_t freq );
	void pump_off();
	void pump_on();
	
	bool run( bool pump_available );
	
};

#endif
