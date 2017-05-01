#include "Pipe.h"

Pipe::Pipe() {
	_water_freq = 0;
	_water_next = now();
	pump_off();
}

void Pipe::config( uint8_t pin, uint8_t freq ){
	_pin        = pin;
	_water_next-= _water_freq * 86400;
	_water_freq = freq;
	_water_next += 86400 / _water_freq;
}

void Pipe::pump_off() {
	BIT_CLEAR( _state, PUMP );
	pumps.write( _pin, LOW );
}

void Pipe::pump_on() {
	BIT_SET( _state, PUMP );
	pumps.write( _pin, LOW );
	_water_next += 86400 / _water_freq;
}

bool Pipe::run( bool pump_available ) {
	
	// Pump running
	if( BIT_CHECK( _state, PUMP ) ) {
		if( floats.read( _pin ) == LOW )
			pump_off();
	} else {
		if( pump_available && _water_freq > 0 && now() > _water_next )
			pump_on();
	}
	
	return BIT_CHECK( _state, PUMP );
}

