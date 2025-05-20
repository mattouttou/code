//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//robot-5e
//mattis cordier 5e A
//hardware: feather + screen + 3 BP +
//09/04/2025
//°°°°°°°°°°°°°°°°°°°°°°°librairie°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <Adafruit_SH110X.h>
//°°°°°°°°°°°°°°°°°°°°°°°°°objet°°°°°°°°°°°°°°°°°°°°°°°°°°°°
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
//°°°°°°°°°°°°°°°°definition des consatnte°°°°°°°°°°°°°°°°°°
#define LED_rouge 13
#define BP_A 9
#define BP_B 6
#define BP_C 5
#define MODE_BT 1
#define MODE_AUTO 2
//°°°°°°°°°°°°°°°°°°°°°°°°variable°°°°°°°°°°°°°°°°°°°°°°°°°°
byte mode = 0;
unsigned int d_c1 = 50 ; 
unsigned int d_c2 = 100 ;
char caractere_recu;
char action ; 
//°°°°°°°°°°°°°°°°°°°°°°initialisation°°°°°°°°°°°°°°°°°°°°°°
void setup() {

  display.begin(0x3C, true);
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setRotation(1);

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(BP_A, INPUT_PULLUP);
  pinMode(BP_B, INPUT_PULLUP);
  pinMode(BP_C, INPUT_PULLUP);

  display.clearDisplay();
  display.setCursor(0, 8);
  display.print("mode bluetooth");
  display.setCursor(0, 45);
  display.print("mode automatique");
  display.display();

  while (mode == 0)
  {
    if (!digitalRead(BP_A))
    {
      mode = MODE_BT;
      display.clearDisplay();
      display.setCursor(0, 25);
      display.print("mode bt selectioner");
      display.display();
      delay(500);
    }
    if (!digitalRead(BP_C))
    {
      mode = MODE_AUTO;
      display.clearDisplay();
      display.setCursor(0, 25);
      display.print("mode auto selectioner");
      display.display();
      delay(500);
    }
  }
  display.clearDisplay();
}

void loop() 
{
  display.clearDisplay();
  display.setCursor(0, 8);
  display.printf("cm: %d \n", d_c1);
  display.setCursor(85, 8);
  display.printf("cm: %d \n", d_c2);
  display.display();
  
  display.print("blabla teste git");


}
  
