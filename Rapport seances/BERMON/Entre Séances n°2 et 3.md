## Travail Personnel entre les séances n°2 et 3 : 19 Décembre 2023 - 7 Janvier 2024

### Récupération d'un module "Heltec LoRa 32" pour communication I2C :
#### Rappel du rapport précédent : 
- Constat d'un nombre de pins insuffisant sur la carte Arduino UNO pour pouvoir réaliser tous les branchements prévus.
- Pas de module I2C à la fin de la séance n°2, impossible de continuer ma réflexion sur le projet en dehors des séances.

Ayant prévu de continuer à travailler pendant les vacances, j'ai donc contacté un des professeurs pour pouvoir récupérer un module avant les vacances, chose faite trois jours plus tard. 

### Prise en main du module "Heltec LoRa 32" :
Recherche sur Internet du fonctionnement et de la programmation du module. Après plusieurs heures de recherche, je décide d'abandonner le module car je ne comprends pas comment adapter celui-ci à mon système, et décide de trouver une autre solution pour libérer des pins sur la carte Arduino.

### Suppression de LEDS sur le coffre :
Recontage du nombre de pins utilisables, et du nombre de pins à utiliser. Je me suis rendu compte que finalement il ne nous manquait que 2 pins sur la carte pour pouvoir brancher les composants comme prévus. Ayant abandonné le module I2C, nous avons décidé de supprimer 2 des 3 LEDS prévues au départ (ainsi que 2 résistances par conséquent). Nous n'en garderons qu'une pour tout de même répondre au besoin du [Cahier des Charges](../Documentation/CahierDesCharges.md), à savoir : "Indication lumineuse et sonore lors des controles".

### Changement du sens d'ouverture de la porte :
D'après de nombreuses photos sur Internet, beaucoup de coffres semblent avoir une porte s'ouvrant à gauche avec une charnière à droite. Même si cela ne semble pas être un standard, nous avons décidé de changer le sens d'ouverture, initialement prévu vers la gauche, pour une ouverture vers la droite. Le schéma donné précédemment n'est donc plus valide, ou du moins, il doit être retourné.
