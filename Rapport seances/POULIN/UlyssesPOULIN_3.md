J'ai récuperé un arduino

RFID et digicode doivent tout les deux etres validés sinon ca veut dire que si qqun leve la glissiere panneau a la main alors on pourrait acceder au coffre sans le rfid
Identifiant lu est le meme que celui mis en variable
Voir partie code

souder avec fil awg32 sur un pcb pour éviter les débranchements de derniere minute avant la presentation

Ajouter et commander regulateur 5V et battery 3.7V (en mettre 2) et en commander avec protections pour éviter la chauffe (coffre en bois)

Au final on va utiliser un boitier eachtne chargeable. Il sera a l'exterieur du coffre ce qui nous enleve le problematique de déverouiller le coffre quand celui ci a plus de batterie car il suffira juste de le charger pour le dévérouiller. L'accès au port de charge se fera depuis l'exterieur. Le coffre sera toujours "étanche" car il aura quand meme la protection du panneau arriere de la porte

Partie code :
Quelques petites modifications du code comme par exemple les angles des servo-moteurs et test RFID avec code de Mr Berlin
Le code hexa de la carte blanche est 12 E5 A2 34
Le code hexa du badge bleu est E9 D1 77 C1 
