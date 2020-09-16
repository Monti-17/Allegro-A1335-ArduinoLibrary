//Example code for the Allegro A1335 sensor based on the library built by ScranchNew
//https://github.com/Monti-17/Allegro-A1335-ArduinoLibrary.git

#include <A1335.h>
#include <Wire.h>

A1335 angle;                                            //rename A1335 to 'angle' for ease of use


void setup() {
  Serial.begin(9600);
  A1335 start(int16_t);                                 //initiate sensor at 0x0C I2C address
}

void loop() {
  float Direction = angle.readAngle();
  int FieldRaw = angle.readFieldRaw();

  if (FieldRaw <= 10)                                   //magnetic field is less than 10mT
  {
    Direction = 0;                                      //if the magnet is too far away (less than 10mT flux density), return default 0º value
  }
  Serial.print("Direction: ");
  Serial.print(Direction);                              //prints angle in degrees
  Serial.print("º");
  Serial.print("\t\tInternal Temp: ");
  Serial.print(angle.readTemp() -273.15);               //prints internal temperature of chip in Celcius
  Serial.print("ºC");
  Serial.print("\t\tField Strength: ");
  Serial.print(angle.readField());                      //prints magnetic flux density in Tesla
  Serial.print("T");
  Serial.print("\t\tRaw Field Strength: ");
  Serial.print(angle.readFieldRaw());                   //prints magnetic flux density in milli Tesla
  Serial.println("mT");
  delay(500);                                           //take reading every half a second
}
