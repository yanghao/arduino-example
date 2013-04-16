/*
  RotaryEncoder

  Read a rotary encoder with interrupts
  Read the press action with digitalread
  Encoder&Switch hooked up with common to +5V
  ENCODER_A_PIN to pin 2
  ENCODER_A_PIN to pin 3
  SWITCH_PIN to pin 4  

  Published by ArduinoCN&OpenJumper.For surport 
  materials and a full range of system boards &
  periphrals please visit :http://www.openjumper.com
  created & modified 15 Dec 2012
  by i3water
*/

#define ENCODER_A_PIN 2
#define ENCODER_B_PIN 3
#define SWITCH_PIN    4
long position;

void setup(){
  //初始化我们的需要的引脚
  pinMode(ENCODER_A_PIN, INPUT);
  pinMode(ENCODER_B_PIN, INPUT);
  pinMode(SWITCH_PIN, INPUT);

  attachInterrupt(0, read_quadrature, CHANGE);

  //初始化Arduino串口
  Serial.begin(9600);
}

void loop(){
   if (digitalRead(SWITCH_PIN) == LOW){
     delay(10);
     if (digitalRead(SWITCH_PIN) == LOW){
       Serial.println("Switch Pressed");
     }
   }
   Serial.print("Position: ");
   Serial.println(position, DEC);
   delay(1000);
}

void read_quadrature(){  
  //A ENA脚下降沿中断触发
  if (digitalRead(ENCODER_A_PIN) == LOW){   
    //查询ENB的电平以确认是顺时针还是逆时针旋转
    if (digitalRead(ENCODER_B_PIN) == LOW)
      position++;
  }
  //ENA脚上升沿中断触发
  else{
    //查询ENB的电平以确认是顺时针还是逆时针旋转
    if (digitalRead(ENCODER_B_PIN) == LOW)
      position--;
  }
}
