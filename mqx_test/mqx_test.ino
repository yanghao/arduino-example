/*
MQ-X Gas Sensors
www.openjumper.com
*/
int Gas_Sensors = A0;  // connect your Gas Sensors to A0
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

int n = 0;

void loop() {
  // read the analog in value:
  int sensorValue = analogRead(Gas_Sensors);                      
  // print the value of Gas Sensors:
  Serial.print(n);
  Serial.print(" Gas Sensors = ");                       
  Serial.println(sensorValue);       
  delay(500);
  n++;  
}
