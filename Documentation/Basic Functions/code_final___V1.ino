#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Keypad.h>

#define SS_PIN 9
#define RST_PIN 10
#define Servo_B 18
#define Servo_A 19
#define buzzer 8

// Partie Servo Moteur
Servo servo_A; //servo a désigne le servo de la porte glissante
Servo servo_B; //servo b désigne le verrou de la porte
int angle = 0;

// Partie RFIDs
byte Count_acces=0; 
byte CodeVerif=0; 
byte Code_Acces[4]={0x12, 0xE5, 0xA2, 0x34}; //Celui de la carte blanche (pour le badge bleu c'est E9 D1 77 C1)

MFRC522 rfid(SS_PIN, RST_PIN); // Instance de la classe

byte nuidPICC[4];

// Partie digicode 
const byte Ligne = 4; //quatre ligne sur le digicode
const byte Colonne = 4; //quatre colonne sur le digicode

//On définit maintenant les symboles correspondant à chaque bouton
char hexaBouton[Ligne][Colonne] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte Ligne_Pins[Ligne] = {15, 14, 7, 6}; // On connecte la ligne du digicode 
byte Colonne_Pins[Colonne] = {5, 4, 3, 2}; // On connecte la colonne du digicode

//On initialise la librairie avec nos paramètres ( la taille de la matrice et symboles)
Keypad mon_keypad = Keypad( makeKeymap(hexaBouton), Ligne_Pins, Colonne_Pins, Ligne, Colonne); 

boolean locked = true;

char secretCode[] = { '1', '2', '3', '4' };

char numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '#', "*"};

int compteur = 0;  // Permet de compter le nombre de touche appuyée

int compteurChangementCode =0;

char code[4]; // Contient les touches tapées par l'utilisateur

// Divers
int compteurBlocage = 0; // Permet de compter les tentatives avant le blocage

int compteurBuzzer = 0; // Permet de stopper le buzzer a un moment donné


void setup() 
{
  Serial.begin(9600);

  // On définit le buzzer en sortie
  pinMode(buzzer, OUTPUT);

  // Initialisation du bus SPI
  SPI.begin(); 

  // Initialisation du module MFRC522 
  rfid.PCD_Init(); 

  // Partie servo
  servo_A.attach(Servo_A);
  servo_B.attach(Servo_B);
  servo_A.write(angle);
  servo_B.write(angle);
}
 
void loop() 
{
  // Initialiser la boucle si aucun badge n'est présent 
  if ( !rfid.PICC_IsNewCardPresent())
    return;

  // Vérifier la présence d'un nouveau badge 
  if ( !rfid.PICC_ReadCardSerial())
    return;

  // Afffichage 
  Serial.println(F("Un badge est détecté"));

  // Enregistrer l’ID du badge (4 octets) 
  for (byte i = 0; i < 4; i++) {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  // Vérification du code 
  CodeVerif = GetAccesState(Code_Acces,nuidPICC); 
  if (CodeVerif != 1)
  {
    Serial.println("Code érroné");
    // Faire clignoter la led deux fois
  }
  else
  {
    Serial.println("Accès au digicode");

    // Faire tourner le servo_A de 180°
    for(angle = 0; angle < 180; angle++)  
    {                                  
      servo_A.write(angle);               
      delay(20);                   
    }

    // Maintenant qu'on a l'accès physique au digicode, il faut s'occuper de ses fonctions du digicode

    while(locked == true){
      //mettre une boucle while
      char keypad_matrix = mon_keypad.getKey();  // Récupère la touche appuyé
      if (keypad_matrix) {                       // Si une touche est appuyée
        Serial.println(keypad_matrix);

        code[compteur] = keypad_matrix;  // Met la valeur dans la liste
        compteur += 1;                   // Incrémente pour que l'on se déplace dans la liste des valeurs

        if (keypad_matrix == 'A') {  // Si on appuie sur A, on réintialise les valeurs
          compteur = 0;
          Serial.println("Rénitialisation des valeurs");
        }

        if (keypad_matrix == 'B') { 
          Serial.println("Coffré déja vérouillé");
        }

        if (keypad_matrix == 'C') {
          Serial.println("Le coffre doit-être dévérouillé pour changer le code");
        }

        if (keypad_matrix == 'D') { // Si on a 4 valeurs, on vérifie si le code est bon
          if (code[0] == secretCode[0] && code[1] == secretCode[1] && code[2] == secretCode[2] && code[3] == secretCode[3]) {  // Si le code est bon
            Serial.println("Dévérouillage du coffre");
            locked = false;
            for (angle = 0; angle < 90; angle++) {
              servo_B.write(angle);
              delay(20);
            }
          }

          if (code[0] != secretCode[0] || code[1] != secretCode[1] || code[2] != secretCode[2] || code[3] != secretCode[3]) {  // Si le code n'est pas bon
            Serial.println("Code éronné");
            compteurBlocage = compteurBlocage + 1;
            if(compteurBlocage > 5){
              Serial.println("Coffre bloqué");
              while(compteurBuzzer < 50){
                tone (buzzer, 600); // allume le buzzer actif arduino
                delay(50);
                tone(buzzer, 900); // allume le buzzer actif arduino
                delay(50);
                noTone(buzzer);  // désactiver le buzzer actif arduino
                compteurBuzzer = compteurBuzzer+1;
              }
              delay(300000); // On attend 300 secondes (5min) pour que le coffre soit réutilisable
            }
          }
        }
      }
    }
    while(locked == false){
      char keypad_matrix = mon_keypad.getKey();  // Récupère la touche appuyé
      if (keypad_matrix) {                       // Si une touche est appuyée

        Serial.println(keypad_matrix);

        if (keypad_matrix == 'A') {  // Si on appuie sur A, on réintialise les valeurs
          Serial.println("Coffre déja dévérouillé");
        }

        if (keypad_matrix == 'B') {  // Si on appuie sur B, on vérouille le coffre
          Serial.println("Verrouillage du coffre");
          compteur = 0;
          for (angle = 90; angle > 0; angle--) {
            servo_B.write(angle);
            delay(20);
          }
          delay(1000);
          for (angle = 180; angle > 0; angle--) {
            servo_A.write(angle);
            delay(20);
          }
          locked = true;
        }

        if (keypad_matrix == 'C') {
          compteurChangementCode = 0;
          Serial.println("Changement du code, entrez 4 chiffres");
          while (compteurChangementCode < 4)
          {
            char keypad_matrix = mon_keypad.getKey();  // Récupère la touche appuyé
            if (keypad_matrix){
              //vérifier si le code contient bien que des nombres et # et *
              Serial.println(keypad_matrix);

              secretCode[compteurChangementCode] = keypad_matrix;  // Met la valeur dans la liste
              compteurChangementCode += 1;}
          }
          Serial.println("Code changé");
        }
          if (keypad_matrix == 'D') {
            Serial.println("Coffre déja dévérouillé");
          }
      }
    }
  }

  // Reinitialisation du  RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}

// Fonction permettant de vérifier si le tag RFID est le bon 
byte GetAccesState(byte *CodeAcces,byte *NewCode) 
{
  byte StateAcces=0; 
  if ((CodeAcces[0]==NewCode[0])&&(CodeAcces[1]==NewCode[1])&&
  (CodeAcces[2]==NewCode[2])&& (CodeAcces[3]==NewCode[3]))
    return StateAcces=1; 
  else
    return StateAcces=0; 
}
