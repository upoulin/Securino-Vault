# Séance 3 :  8 Janvier 2024

### Objectifs de cette séance:
- Présenter la maquette du système aux professeurs
- Demander le matériel nécessaire et disponible

### Présentation de la maquette et du système :
Les professeurs semblent l'avoir validée. Le principal était d'avoir un avis sur le système de coulisse avec le servo moteur, et celui-ci est favorable.

### Demande du matériel, et autres questions :
#### Remplacement de la breadboard par une carte PCB à souder :
Pour des raisons de dimensions mais aussi d'arrangement et de fiabilisation des connexions, il nous a été conseillé par un des professeurs d'utiliser une **carte PCB** semblable à une breadboard, que nous pourrons découper en fonction de la taille souhaitée. Nous pourrons y souder les cables au lieu de juste les brancher, afin d'éviter de potentielles mauvaises connexions et ainsi fiabliser le circuit de l'Arduino. De plus, il nous suffira de percer dedans pour la fixer par la suite avec des vis, au lieu de devoir fabriquer un support spécial pour la breadboard.

#### Demande du moyen alimentation éléctrique le plus optimal :
Ayant prévu, sur la maquette, une assez grande place pour un coupleur 4,5V, un des professeur nous a dit que cette tension serait à la limite du suffisant pour alimenter correctement l'Arduino et ses composants. Il nous a d'abord conseillé d'utiliser 2 batteries de 3,7V chacune à mettre en série (2 x 3,7V = 7,4V) pour ensuite ramener cette tension sur un régulateur 5V, déja en stock et ainsi la transmettre à l'Arduino sans danger. Dans ce cas il aurait fallu commander 2 de ces batteries (18650 Li-Ion : 3,7 V / 4200mAh) ainsi qu'un coupleur mais nous avons quand-même demander à d'autres professeurs, pour voir ce qu'il y avait en stock. Après recherche dans les stock, les professeurs nous ont donné 2 de ces même batteries, ainsi qu'un coupleur/chargeur, se branchant directement sur l'Arduino, ne nécessitant pas d'un régulateur 5V. Ce coupleur/chargeur est un peu plus gros que l'espace prévu initalement et nécessitera donc d'élargir un peu plus le panneau avant.

(photo)

#### Demande concernant les épaisseurs de planches de bois disponibles :
Un des professeur nous a répondu que les épaissseurs de planches disponibles étaient 3mm , 5mm et 10mm, ce qui est plus petit, (et mieux) que ce que j'avais prévu a savoir 20mm d'épaisseur. Les plus petites vis disponibles pour l'instant, sont des vis de taille 3mm x 6mm (diamètre x longueur) qui me permettront normalement de fixer les composants depuis l'intérieur. Si il n'y a pas de plus petites vis, il faudra coller ensemble 2 plaques de 3 et 5mm (8mm d'épaisseur totale) pour que les vis ne traversent pas. 6mm étant trop juste comme épaisseur et 10mm étant trop grand, c'est pour l'instant la solution la plus optimale.
