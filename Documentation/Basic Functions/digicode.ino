#include <Keypad.h>

const byte Ligne = 4; //quatre ligne sur le digicode
const byte Colonne = 4; //quatre colonne sur le digicode
//On définit maintenant les symboles correspondant à chaque bouton
char hexaBouton[Ligne][Colonne] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte Ligne_Pins[Ligne] = {9, 8, 7, 6}; // On connecte la ligne du digicode 
byte Colonne_Pins[Colonne] = {5, 4, 3, 2}; // On connecte la colonne du digicode

//On initialise la librairie avec nos paramètres ( la taille de la matrice et symboles)
Keypad mon_keypad = Keypad( makeKeymap(hexaBouton), Ligne_Pins, Colonne_Pins, Ligne, Colonne); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
// On demande à la librairie le chiffre tapé.
  char keypad_matrix = mon_keypad.getKey();
  
  if (keypad_matrix){
    Serial.println(keypad_matrix);
  }
}