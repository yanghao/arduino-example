/*OJ Line Tracking Sensor
www.openjumper.com
*/

int Sensor_pin = 2;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = digitalRead(Sensor_pin);
  Serial.println(sensorValue);
  delay(100);
}
