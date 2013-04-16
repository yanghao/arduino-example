//Author:OPEN JUMPER-奈何col
//2012-11-17
 String Tilt(int T1,int T2,int T3,int T4) {
    pinMode(T3,OUTPUT);
    pinMode(T1,INPUT_PULLUP);
    pinMode(T2,INPUT);
    digitalWrite(T3,LOW);
    int F31=digitalRead(T1);
    if (F31==LOW) return "d";
    /*-------------------------*/ 
    pinMode(T1,OUTPUT);
    pinMode(T2,INPUT_PULLUP);
    pinMode(T4,INPUT);
    digitalWrite(T1,LOW);
    int F12=digitalRead(T2);
    if (F12==LOW) return "a";
    /*-------------------------*/
    pinMode(T2,OUTPUT);
    pinMode(T4,INPUT_PULLUP);
    pinMode(T3,INPUT);
    digitalWrite(T2,LOW);
    int F24=digitalRead(T4);
    if (F24==LOW) return "b"; 
    /*-------------------------*/
    pinMode(T4,OUTPUT);
    pinMode(T3,INPUT_PULLUP);
    pinMode(T1,INPUT);
    digitalWrite(T4,LOW);
    int F43=digitalRead(T3);
    if (F43==LOW) return "c"; 
    /*-------------------------*/
    return "0";
  }

  void setup() {                
    Serial.begin(9600);
  }
  void loop() {                
    String S=Tilt(2,3,4,5);//模块1234脚分别连接到arduino的D2D3D4D5数字IO上
    Serial.println(S);
    delay(100);
  }
