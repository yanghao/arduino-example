/*OJ Button module 
www.openjumper.com
*/

int pushButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(100);       
}
