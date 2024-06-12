#include <M5Stack.h>
#include <Arduino.h>
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
void setup() {
  M5.Lcd.setTextSize(4);
  M5.begin();
  Serial.begin(115200);      
  Dabble.begin("MyEsp32");
  pinMode(1 , OUTPUT);
  pinMode(2 , OUTPUT); 
  pinMode(3 , OUTPUT);       
  pinMode(5 , OUTPUT); 
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
}

void loop() {
  /**digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);*/

  M5.Lcd.setCursor( 50, 50);
  Dabble.processInput();             
  Serial.print("KeyPressed: ");
  //m5.lcd.println("tu vas tout droit");
  
  int a = GamePad.getAngle(); 
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();

  /**if (!GamePad.isSquarePressed() && !GamePad.isCirclePressed() && !GamePad.isCrossPressed() &&
      !GamePad.isTrianglePressed() && !((0 < a && 180 >= a )) && !(( 180 < a && 360 >= a )))
      {
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(5,LOW);*/

  //else {

  //if ((0 < a && 180 >= a ))// tout droit
  //{
    //m5.lcd.println("tu vas tout droit");
    //M5.Lcd.clear(BLACK);
    analogWrite(1, (int)36*d);
    analogWrite(2, (int)36*d);

  }
  //if (( 180 < a && 360 >= a )) 
  //{
    //m5.lcd.println("tu vas en arriere");// en arriere 
    //    M5.Lcd.clear(BLACK);
    /**digitalWrite(1,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);*/
    analogWrite(1, (int)36*d);
    analogWrite(2, (int)36*d);
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);


  
  /**if (a == 0 ){
  digitalWrite(1, LOW);   
  digitalWrite(3, LOW);
  }*/
}
   
    /**digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(5,HIGH);
    Serial.printf("roule\n");*/
    analogWrite(1, (int)36*d-c);
    analogWrite(2, (int)36*d+c);

    /**digitalWrite(2,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(3,HIGH);
    Serial.printf("roule\n");*/
    analogWrite(1, (int)36*d+c);
    analogWrite(2, (int)36*d-c);

if (GamePad.isCrossPressed())//stop
{
  
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    Serial.printf("stop\n");
}  
}
