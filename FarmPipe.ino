#define LIGHT_PIN 7
#define TANK_PIN  7
#define PIPES     7

#define ADDRESS_IN  0x21
#define ADDRESS_OUT 0x20

#include <pcf8574_esp.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include "Pipe.h"

Pipe pipe[PIPES];
PCF857x Pipe::pumps( ADDRESS_OUT, &Wire );
PCF857x Pipe::floats( ADDRESS_IN, &Wire );

void setup() {
  Wire.begin( D2, D1 );
  Wire.setClock( 100000L );
  Pipe::pumps.begin();
  Pipe::pumps.write8( 0 );
  Pipe::floats.begin();
  Pipe::floats.write8( 0 );

  for ( uint8_t i = 0; i < PIPES; i++ )
    pipe[i].config( i, 3 );
}

void loop() {
}
