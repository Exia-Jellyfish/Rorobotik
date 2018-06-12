// Numéro de l'interruption 0, il correspond à la pin 2
const int interrupt = 0;

// Pin 9 de l'Arduino Uno
const int canalB   = 9;


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
    Serial.println(compt);
  
}

void setup()
{
  // Permet un affichage du résultat sur la consol Série
  Serial.begin(9600);

  // Initialisation des pin 9 et 10 en entrèes
  pinMode(2, INPUT);
  attachInterrupt(interrupt, Reagir, RISING);
}
// Fin initialisation
//-----------------------------------------------------------

void loop()
{
  delay(5000);

  Serial.println(compt);

}


