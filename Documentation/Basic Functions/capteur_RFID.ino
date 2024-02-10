#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 9
#define RST_PIN 10

byte Count_acces=0; 
byte CodeVerif=0; 
byte Code_Acces[4]={0x12, 0xE5, 0xA2, 0x34}; //Celui de la carte blanche (pour le badge bleu c'est E9 D1 77 C1)

MFRC522 rfid(SS_PIN, RST_PIN); // Instance de la classe

byte nuidPICC[4];

void setup() 
{ 
  // Init RS232
  Serial.begin(9600);

  // Init SPI bus
  SPI.begin(); 

  // Init MFRC522 
  rfid.PCD_Init(); 
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
  {Serial.println("Code érroné");}
  else
  {Serial.println("Accès au digicode");}


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
