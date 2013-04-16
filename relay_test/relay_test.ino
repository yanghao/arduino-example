/*OJ relay module 
www.openjumper.com
*/

int Relay_pin = 12;            //连接模块至arduino信号脚13

void setup() {                
  pinMode(Relay_pin, OUTPUT);      
}

void loop() {
  digitalWrite(Relay_pin, HIGH);   // 常开触点闭合，常闭触点断开
  delay(1000);               
  digitalWrite(Relay_pin, LOW);    // 常闭触点闭合，常开触点断开
  delay(1000);               
}
