#include <M5Stack.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>


int angle;
int radian; 
float axeX; 
float axeY,axeY_brut;
int moteurG;
int moteurD;

void setup() {
  // put your setup code here, to run once:
  m5.begin();
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("Robot_Matiss");       //set bluetooth name of your device


//tu dois choisir les bonnes pin pour piloter tes moteur 
//  pinMode(XXxXXXXXXXx, OUTPUT);   
 // pinMode(XXXXXXXXXXX, OUTPUT);
 //  pinMode(XXxXXXXXXXx, OUTPUT);
 // pinMode(XXXXXXXXXXX, OUTPUT);

  m5.lcd.print ("Coucou Peruche");

}

void loop() {
 

  
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
 // Serial.print("KeyPressed: ");

  if (GamePad.isUpPressed())  {    Serial.print("Up");  }

  if (GamePad.isDownPressed())  {    Serial.print("Down");  }

  if (GamePad.isLeftPressed())  {    Serial.print("Left");  }

  if (GamePad.isRightPressed())  {    Serial.print("Right");  }

  if (GamePad.isSquarePressed())  {    Serial.print("Square");  }

  if (GamePad.isCirclePressed())  {    Serial.print("Circle");  }

  if (GamePad.isCrossPressed())  {    Serial.print("Cross");  }

  if (GamePad.isTrianglePressed())  {    Serial.print("Triangle");  }

  if (GamePad.isStartPressed())  {    Serial.print("Start");  }

  if (GamePad.isSelectPressed())  {    Serial.print("Select");  }
  //Serial.print('\t');

 // angle = GamePad.getAngle();         //recupération de l'information de l'angle dans la variable angle
 // radian = GamePad.getRadius();       //recupération de l'information du radian dans la variable radian
  axeX = GamePad.getXaxisData();        //recupération de l'information de la valeur de l'axe X
  axeY_brut= GamePad.getYaxisData();    //recupération de l'information de la valeur de l'axe Y
  axeY=axeY_brut; //on stock la valeur pour calcul et traitement


/*
  Serial.printf("Angle: %d \t",angle);    //affichage des données sur le terminal serie
  Serial.printf("Radius: %d\t",radian);   //affichage des données sur le terminal serie
  Serial.printf("axeY: %f\t",axeY);       //affichage des données sur le terminal serie
  Serial.printf("axeY: %f\n",axeX);       //affichage des données sur le terminal serie

*/

  axeY=abs((int)axeY*36);   //on multiplie la valeur du joystick par 36 et on garde uniquement la valeur absolue pour ne pas envoyer de valeur negatif dans la xommande moteur.
  axeX=(int)(axeX*5);   //on recupère la valeur de l'axeX pour piloter l'orientation des moteur, on garde la valeur flotant multiplié par 5 et on retire les nombre a virgule de la fin

  moteurG=(int)(axeY+axeX);  //vitesse moteur gauche
  moteurD=(int)(axeY-axeX);  //vitesse moteur droite

  if(moteurG<0)   //filtre pour empecher une valeur negatif, si c'est negatif, on force la valeur à 0
    moteurG=0;
  
  if(moteurD<0) //filtre pour empecher une valeur negatif, si c'est negatif, on force la valeur à 0
    moteurD=0;

  Serial.printf("moteurG: %3d moteurD: %3d axeY: %3.0f axeX: %3.0f\n",moteurG,moteurD,axeY,axeX);       //affichage des données sur le terminal serie
  
 if(axeY_brut>0) //on test si on veut avancer et donc la valeur de l'axe y est positif
 {
   
   //c'est ici que tu vas envoyer les configuration de tes moteurs pour avancer

  }
  else  if(axeY_brut<0) //l'axe Y est negatif 
  {
  
        //c'est ici que tu vas envoyer les configuration de tes moteurs pour reculer

  }
  delay(5);
}

