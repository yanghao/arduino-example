/*OPEN JUMPER L298 Shield*/
	int INA = 4; //电机A正反转控制端
	int PWMA = 5; //电机A调速端
	int INB = 7; //电机B正反转控制端
	int PWMB = 6; //电机B调速端
        int cPin = 3;
	void setup(){
	pinMode(INA,OUTPUT);
	pinMode(INB,OUTPUT);
	}
	void loop(){
	int value;
        int dir;
        value = analogRead(cPin);
        value = value / 2;
        if (value > 255) {
          dir = HIGH;
          value = value - 255;
          if (value > 255)
            value = 255;
        } else {
          dir = LOW;
          value = 255 - value;
        }
        digitalWrite(INA, dir);
        digitalWrite(INB, dir);
        analogWrite(PWMA, value);
        analogWrite(PWMB, value);
        return;
	for(value = 0 ; value <= 255; value+=5){
	  digitalWrite(INA,LOW);
	  digitalWrite(INB,LOW);
	  analogWrite(PWMA,value);
	  analogWrite(PWMB,value);
	  delay(50);
	  }
	}

