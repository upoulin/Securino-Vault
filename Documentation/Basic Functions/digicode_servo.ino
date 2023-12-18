#include <Keypad.h>
#include <Servo.h>

Servo servo;
int angle = 0;
int moteur = 13;

boolean locked = true;

char secretCode[] = { '1', '2', '3', '4' };

char numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

int compteur = 0;  // Permet de compte le nombre de touche appuyée

// Définit les 2 leds
const int led_rouge = 11;
const int led_verte = 12;

const byte Ligne = 4;    // 4 lignes sur le digicode
const byte Colonne = 4;  // 4 colonnes sur le digicode

// Définit maintenant les symboles correspondant à chaque bouton
char hexaBouton[Ligne][Colonne] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

char code[5];                                 // Contient les touches tapées par l'utilisateur
byte Ligne_Pins[Ligne] = { 9, 8, 7, 6 };      // Connecte la ligne du digicode
byte Colonne_Pins[Colonne] = { 5, 4, 3, 2 };  // Connecte la colonne du digicode
// Initialise la librairie avec nos paramètres (la taille de la matrice et symboles)

Keypad mon_keypad = Keypad(makeKeymap(hexaBouton), Ligne_Pins, Colonne_Pins, Ligne, Colonne);

void setup() {
  Serial.begin(9600);
  pinMode(led_rouge, OUTPUT);     // La led rouge est en sortie
  pinMode(led_verte, OUTPUT);     // La led verte est en sortie
  digitalWrite(led_rouge, HIGH);  // Met par défaut la led car le coffre est verouillé par défaut
  servo.attach(moteur);
  servo.write(angle);
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
      for (angle = 90; angle > 0; angle--) {
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
        Serial.println(keypad_matrix);

        secretCode[compteur] = keypad_matrix;  // Met la valeur dans la liste
        compteur += 1;}
      }

      //après avoir change le code on lock le coffre

      locked = true;
      compteur = 0;
      digitalWrite(led_rouge, HIGH);
      digitalWrite(led_verte, LOW);
      for (angle = 90; angle > 0; angle--) {
        servo.write(angle);
        delay(20);
      }
    }

    if (keypad_matrix == 'D') {                                                                           // Si on a 4 valeurs, on vérifie si le code est bon sinon on remet le compteur à 0
      if (code[0] == secretCode[0] && code[1] == secretCode[1] && code[2] == secretCode[2] && code[3] == secretCode[3]) {  // Si le code est bon
        locked = false;
        digitalWrite(led_rouge, LOW);   // Eteint la led rouge
        digitalWrite(led_verte, HIGH);  // Allume la led verte
        for (angle = 0; angle < 90; angle++) {
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
