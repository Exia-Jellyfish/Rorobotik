#include "Grove_I2C_Motor_Driver.h"
#define I2C_ADDRESS 0x0f
// Déclaration des constantess
//const byte interruptPin = 2;
// Fin déclaration des constantes

// Déclaration des fonctions

void Reagir();

// Fin déclaration des fonctions

//-----------------------------------------------------------

// Déclaration des variables globales

// Variables (compteurs) qui vont stocker le nombre de tics comptés pour chaque codeur
long compt= 0;

// Fin Déclaration des variables globales


//-----------------------------------------------------------
// Fonction d'interruption pour le codeur
// Fonction appelée par un tic du codeur.
void Reagir()
{
   compt++;
}

void setup()
{
  // Permet un affichage du résultat sur la consol Série
  Serial.begin(9600);
  Motor.begin(I2C_ADDRESS);

  // Initialisation des pin 9 et 10 en entrèes
  //pinMode(2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), Reagir, RISING);
   
}
// Fin initialisation
//-----------------------------------------------------------

void loop()
{
  Motor.speed(MOTOR1, -50);
  Motor.speed(MOTOR2, -50);
  delay(1000);
  Serial.println(compt);
  compt =0; 

}


