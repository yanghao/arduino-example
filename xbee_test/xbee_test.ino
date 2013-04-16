/*
  Xbee1
  D. Thiebaut
 
  Makes Arduino send 1 character via XBee wireless to another XBee connected
  to a computer via a USB cable. 
 
  The circuit: 
  * RX is digital pin 2 (connect to TX of XBee)
  * TX is digital pin 3 (connect to RX of XBee)
 
  Based on a sketch created back in the mists of time by Tom Igoe
  itself based on Mikal Hart's example
 
*/
 
#include <SoftwareSerial.h>
 
//#SoftwareSerial xbee(2, 3); // RX, TX
char c = 'A';
int  pingPong = 1;
 
void setup()  {
   Serial.begin(9600);
   Serial.println( "Arduino started sending bytes via XBee" );
 
   // set the data rate for the SoftwareSerial port
   Serial1.begin(9600);

}
 
void loop()  {
  if (Serial.available()) {
    c = Serial.read();
    Serial1.write(c);
  }
  if (Serial1.available()) {
    c = Serial1.read();
    Serial.write(c);
    if (c == '\n') {
      Serial.write('\r');
    }
  }
}
