## Travail Personnel entre les séances n°2 et 3 : 19 Décembre 2023 - 7 Janvier 2024

### Récupération d'un module "Heltec LoRa 32" pour communication I2C :
#### Rappel du rapport précédent : 
- Constat d'un nombre de pins insuffisant sur la carte Arduino UNO pour pouvoir réaliser tous les branchements prévus.
- Pas de module I2C à la fin de la séance n°2, impossible de continuer ma réflexion sur le projet en dehors des séances.

Ayant prévu de continuer à travailler pendant les vacances, j'ai donc contacté un des professeurs pour pouvoir récupérer un module avant les vacances, chose faite trois jours plus tard. 

### Prise en main du module "Heltec LoRa 32" :
Recherche sur Internet du fonctionnement et de la programmation du module. Après plusieurs heures de recherche, je décide d'abandonner le module car je ne comprends pas comment adapter celui-ci à mon système, et décide de trouver une autre solution pour libérer des pins sur la carte Arduino.

### Suppression de LEDS sur le coffre :
Recontage du nombre de pins utilisables, et du nombre de pins à utilisé. Je me suis rendu compte que finalement il ne me manquait que 2 pins sur la carte pour pouvoir brancher les composants comme prévus. Ayant abandonné le module I2C, je décide que l'on supprimera 2 des 3 LEDS prévus au départ. Nous en gardons une pour répondre au cahier des charges, à savoir
