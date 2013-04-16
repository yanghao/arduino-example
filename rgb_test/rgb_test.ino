/*OJ RGB LED
 www.openjumper.com
 */

 #define R 3
 #define G 5
 #define B 6
 int brightness = 0;    // how bright the LED is
 int fadeAmount = 5;    // how many points to fade the LED by

 void setup()  { 
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
 } 
 void loop()  { 
   analogWrite(R, brightness);    
   analogWrite(G, brightness);  
   analogWrite(B, brightness);    

   brightness = brightness + fadeAmount;

   if (brightness == 0 || brightness == 255) {
     fadeAmount = -fadeAmount ; 
   }     

   delay(30);                            
 }
