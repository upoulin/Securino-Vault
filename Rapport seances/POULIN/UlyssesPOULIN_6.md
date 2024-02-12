*******************
# Rapport 
*******************

## Séance du 9 Février

### Code

Au cours de cette séance, j'ai consacré une grande partie de mon temps à la programmation, en m'efforçant d'implémenter toutes les fonctions nécessaires avec l'ensemble des composants, notamment l'ajout du buzzer et la gestion du nombre maximal de tentatives. J'ai cherché à optimiser considérablement le code, en repartant quasiment de zéro. Pour ce faire, j'ai créé un nouveau fichier .ino et j'ai tiré profit de différents codes que j'avais élaborés auparavant.

À certains moments, j'ai dû modifier les configurations d'I/O en raison de difficultés de compréhension de certains modules, ce qui a entraîné, par exemple, le passage du digicode sur les pins 14 et 15.

J'ai également réussi à mettre en œuvre les servo-moteurs, dont :
- le servo A, celui de la porte qui coulisse vers le haut (rotation de 180°)
- le servo B, le verrou de la porte (rotation de 90°)

Des compteurs ont été ajoutés pour une meilleure organisation du code, permettant de bloquer le coffre après un certain nombre de tentatives infructueuses ou de couper le buzzer.

Il me reste à implémenter les LED et à tester l'ensemble avec une alimentation sur batterie. Pour la prochaine séance, je prévois de me documenter davantage sur les optimisations possibles, en évitant notamment l'utilisation de la fonction "delay", jugée trop simpliste et peu efficace.
