# Séance 2 :  18 Décembre 2023

Objectifs de cette séance: 
- Continuer la réflexion sur l'architecture et le fonctionnement du coffre.
- Faire les dimensions et les premiers dessins des pièces nécessaires à la création et à son fonctionnement.

Architechture et Fonctionnement du coffre :
Orientation du coffre :
Lorsque nous avons choisi de fabriquer notre coffre fort, une des spécificités qui nous tenait à coeur, était le fait qu'après avoir validé la carte RFID, le clavier à code, initialement caché, soit dévoilé par une sorte de panneau coulissant (controlé par un servo-moteur), disparaissant dans la porte du coffre. On pensait que cela rajouterait un coté futuriste qui nous plaisait. Or, lors du premier dessin du coffre, nous étions parti sur le fait que celui-ci serait horizontal, et le "panneau" coulissant, se déplacerait horizontalement. Mais au vu de la contraite évidente de place et la compléxité de l'élaboration d'un système de coulisse dans les deux sens, nous avons décidé de partir sur un modèle vertical, ou le "panneau" irait de bas en haut puis de haut en bas. De plus nous n'avions pas réellement spécifié la disposition du coffre fort dans le cahier des charges, donc nous nous permettons de le faire vertical.

Disposition des éléments :
Le fait d'avoir changé l'orientation du coffre, va nous permettre aussi d'optmiser la disposition des divers composants. Ces derniers pourront normalement tous être incorporés dans la porte et ainsi éviter les fils apparents, ou autres potentiels problèmes liés à la dispertion des composants. Cela facilite la conception et fait que l'on développe principalement une porte / trappe sécurisée, vissée simplement sur un coffre. Notons aussi que ce choix permet de sécuriser la batterie à l'intérieur de la porte, et qu'elle puisse être changée facilement, uniquement quand le coffre est dévérouillé.

Mesure du niveau de batterie :
Nous ne nous étions pas vraiment penchés sur la question avant, mais il est nécessaire que nous puissions mesurer le niveau de batterie pour éviter tout blocage du coffre (cf : Cahier des Charges). En regardant sur internet, nous avons vu qu'il était possible du mesurer la tensions à l'aide de 2 résistances en formant un pont diviseur de tension. Selon les spécificités de la batterie, il faudra choisir les résistances, R1 et R2 telles que la tension mesurée analogiquement sur R1 ne dépasse pas 5 volts pour éviter de brûler une deuxième carte Arduino ;) 

Utilisation d'une "Breadboard" :
Au vu du nombre de composants utilisés, il nous sera necéssaire d'utiliser une breadboard pour notamment les résistances nécessaires aux LEDS et à a mesure de la batterie. Il nous faudra donc agir en fonction pour l'agencement des composants dans la porte.

Manque de pins de la carte Arduino :
Durant la séance nous nous sommes rendus compte que les pins disponibles viendront à manquer si l'on veut connecter l'entierté des composants à une seule carte. Nous pensions d'abord opter pour une carte Arduino MEGA plutôt que UNO, celle-ci disposant de plus de pins, mais cela nous a été refusé par un des professeurs. Une nouvelle mission s'est alors ajouté à ma séance, ce qui m'a fait prendre du retard. Je devais désormais trouver un moyen d'optimiser le nombre de pins utilisés, nottament par le clavier à code, et le lecteur RFID, afin de libérer 2 pins. Le professeur m'a ensuite dit que dans le "pire des cas", il serait possible de passer par un module I2C, ce qui nous permettrait de sauvgarder 3 pins sur la carte. Or jusqu'à la fin de la séance j'ai cherché sur Internet comment faire sans, et finalement je n'ai pas demandé le module, ce qui fait que je ne peux pas travailler complètement l'agencement du de la porte et des pièces à l'intérieur. 



Dimensions et les premiers dessins :
Dimensions de la porte (avant ajout de la breadboard, donc celles-ci sont éronnées) :
Hauteur : ~ 24 cm. Largeur de la carte arduino ( ~ 5,5 cm ) + 2 fois la hauteur du clavier (Clavier + Panneau) (2 x 8cm ) + espaces supplémentaires.
Largeur : ~ 12 cm. Longueur de la carte Arduino ( ~ 8 cm ) + espaces supplémentaires.
Epaisseur : ~ 5 cm. Epaisseur du servo-moteur ( ~ 3 cm ) + espaces supplémentaires.
 




- Dimensions porte
- Calcul servo axe et dessin voir cahier
- Dimensions de porte
- I2C
