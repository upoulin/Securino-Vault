#include <Keypad.h>
#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN A1
#define RST_PIN A0
    
#define AccesFlag_PIN 2
#define Gate_PIN 3
#define Max_Acces 3

byte Count_acces=0; 
byte CodeVerif=0; 
byte Code_Acces[4]={0x12, 0xE5, 0xA2, 0x34}; //Celui de la carte blanche (pour le badge bleu c'est E9 D1 77 C1)

MFRC522 rfid(SS_PIN, RST_PIN); // Instance de la classe

byte nuidPICC[4];

Servo servo;
int angle = 0;

boolean locked = true;

char secretCode[] = { '1', '2', '3', '4' };

char numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

int compteur = 0;  // Permet de compte le nombre de touche appuyée

// Définit les 2 leds
const int led_rouge = 10;
const int led_verte = 19;

const byte Ligne = 4;    // 4 lignes sur le digicode
const byte Colonne = 4;  // 4 colonnes sur le digicode

// Définit maintenant les symboles correspondant à chaque bouton
char hexaBouton[Ligne][Colonne] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

char code[4];                                 // Contient les touches tapées par l'utilisateur
byte Ligne_Pins[Ligne] = { 9, 8, 7, 6 };      // Connecte la ligne du digicode
byte Colonne_Pins[Colonne] = { 5, 4, 3, 2 };  // Connecte la colonne du digicode
// Initialise la librairie avec nos paramètres (la taille de la matrice et symboles)

Keypad mon_keypad = Keypad(makeKeymap(hexaBouton), Ligne_Pins, Colonne_Pins, Ligne, Colonne);

void setup() {
  Serial.begin(9600);
  pinMode(led_rouge, OUTPUT);     // La led rouge est en sortie
  pinMode(led_verte, OUTPUT);     // La led verte est en sortie
  digitalWrite(led_rouge, HIGH);  // Met par défaut la led car le coffre est verouillé par défaut
  servo.write(angle);

  // Init SPI bus
  SPI.begin(); 

  // Init MFRC522 
  rfid.PCD_Init(); 

  // Init LEDs 
  pinMode(AccesFlag_PIN, OUTPUT);
  pinMode(Gate_PIN, OUTPUT);
  
  digitalWrite(AccesFlag_PIN, LOW);
  digitalWrite(Gate_PIN, LOW);

}

void loop() {
  char keypad_matrix = mon_keypad.getKey();  // Récupère la touche appuyé
  if (keypad_matrix) {                       // Si une touche est appuyée

    Serial.println(keypad_matrix);

    code[compteur] = keypad_matrix;  // Met la valeur dans la liste
    compteur += 1;                   // Incrémente pour que l'on se déplace dans la liste des valeurs

    if (keypad_matrix == 'A') {  // Si on appuie sur A, on réintialise les valeurs
      locked = true;
      compteur = 0;
    }

    if (keypad_matrix == 'B') {  // Si on appuie sur B, on vérouille le coffre
      locked = true;
      compteur = 0;
      digitalWrite(led_rouge, HIGH);
      digitalWrite(led_verte, LOW);
      for (angle = 180; angle > 0; angle--) {
        servo.write(angle);
        delay(20);
      }
    }

    if (keypad_matrix == 'C' && locked == false) {
      digitalWrite(led_verte, HIGH);
      digitalWrite(led_rouge, HIGH);

      compteur = 0;

      while (compteur < 4){
      
      char keypad_matrix = mon_keypad.getKey();  // Récupère la touche appuyé
      if (keypad_matrix){
        //vérifier si le code contient bien que des nombres et # et *
        Serial.println(keypad_matrix);

        secretCode[compteur] = keypad_matrix;  // Met la valeur dans la liste
        compteur += 1;}
      }

      //après avoir change le code on lock le coffre

      locked = true;
      compteur = 0;
      digitalWrite(led_rouge, HIGH);
      digitalWrite(led_verte, LOW);
      for (angle = 180; angle > 0; angle--) {
        servo.write(angle);
        delay(20);
      }
    }

    if (keypad_matrix == 'D') {                                                                           // Si on a 4 valeurs, on vérifie si le code est bon sinon on remet le compteur à 0
      if (code[0] == secretCode[0] && code[1] == secretCode[1] && code[2] == secretCode[2] && code[3] == secretCode[3]) {  // Si le code est bon
        locked = false;
        digitalWrite(led_rouge, LOW);   // Eteint la led rouge
        digitalWrite(led_verte, HIGH);  // Allume la led verte
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(20);
        }
      }

      if (code[0] != secretCode[0] || code[1] != secretCode[1] || code[2] != secretCode[2] || code[3] != secretCode[3]) {  // Si le code n'est pas bon
        locked = true;
        digitalWrite(led_rouge, LOW);
        delay(100);
        digitalWrite(led_rouge, HIGH);
        delay(100);
        digitalWrite(led_rouge, LOW);
        delay(100);
        digitalWrite(led_rouge, HIGH);
        delay(100);
        digitalWrite(led_rouge, LOW);
        delay(100);
        digitalWrite(led_rouge, HIGH);
        delay(100);
      }
      compteur = 0;  // Rétablit le compteur à 0 si l'utilisateur veut retenter sa chance
    }
  }
}

byte GetAccesState(byte *CodeAcces,byte *NewCode) 
{
  byte StateAcces=0; 
  if ((CodeAcces[0]==NewCode[0])&&(CodeAcces[1]==NewCode[1])&&
  (CodeAcces[2]==NewCode[2])&& (CodeAcces[3]==NewCode[3]))
    return StateAcces=1; 
  else
    return StateAcces=0; 
}
