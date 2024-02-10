# Séance 6 : Séance du 9 février 2024

## Objectifs de la Séance :
- Test de coulissage du cache clavier
- Continuer la modélisation et la découpe les planches de bois du coffre.
- Modéliser et imprimer 3D des dernières pièces.
- Terminer soudage carte PCB.

## Coulissage du cache clavier
J'ai effectué un simple test de montée et descente du cache, en le reliant par une ficelle à l'enrouleur et en fixant le support de l'enrouleur au panneau. Le poids du cache lui suffit à lui-même pour redescendre quand le servo tourne à 180° dans le sens anti-horaire ce qui était l'effet recherché. Il a cependant fallu que je ponce un peu le panneau pour que celui puisse glisser correctement contre le clavier.

## Modélisation des planches de bois  :
Lors de la séance précédente, je me suis penché sur le système de vérouillage physique du coffre. Je pensais mettre sur le flanc des planches gauche du coffre, soit une platine à oeil soit un piton à visser / "vis à anneau".
Je n'avais pas trouvé de vis à anneau dans l'atelier il y a deux semaines, donc j'ai fini par m'en procurer une en cherchant dans une boite à outils chez moi. Je vais donc la visser comme prévue, cependant l'anneau devra se loger dans la porte, ce qui implique d'ajouter un trou dans le panneau arrière de la porte.
Je comptais les faire découper aujourd'hui, mais le temps que je devais y passer, a été consacré à d'autres choses. Cela sera fait normalement la semaine prochaine.

## Modélisation et Impression 3D de pièces
Dans la continuité de l'élaboration du système de vérouillage physique, il nous fallait modéliser et imprimer deux pièces qui sont le support pour le servomoteur, et le crochet qui y est attaché :
### Support du servomoteur de verrouillage
 <img align = "right" src="../../Images/Support_sans_L.jpg" alt="coffre Tinkercad" width=20% />
Le support est semblable à celui utilisé pour l'enrouleur, mais cette fois, il retient le servo vissé, non pas verticalement par rapport à la planche, mais plutôt horizontalement. (photo)
### Crochet du servomoteur
Pour faire le système de loquet entre le servo et la vis à anneau, il a fallu que je modélise une pièce en forme de "L" qui fasse office de crochet. Elle se clipse à un des embouts d'origine fourni avec le servomoteur, et après une rotation de 90° de ce dernier, la pièce viendra se loger dans l'anneau de la vis et ainsi maintenir la porte bloquée. La longueur a été choisie de manière à ce que le crochet puisse de mettre dans l'anneau avec la vis complètement rentrée dans le bois. Notez l'ajout d'un congé dans l'angle du "L" pour réduire la contrainte, et ainsi éviter que la pièce ne casse lorsque l'on tire sur la porte fermée. (photo)

## Soudage de la carte PCB
J'ai continué le soudage des fils sur la carte, or cela m'a pris beaucoup (trop) de temps par rapport à ce que j'avais prévu. En plus de mon manque de technique, j'ai commencé avec un fer à souder auquel il manquait un morceau au niveau de la tête, donc il était compliqué de déposer correctement l'étain sur la carte, mais j'ai finalement réussi à faire les soudures avec un autre poste. Nous ferons des tests de continuité la prochaine fois avant d'essayer le circuit avec le programme.
