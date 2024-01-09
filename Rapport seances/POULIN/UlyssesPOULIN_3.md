*******************
# Rapport 
*******************

## Séance du 8 Janvier

## Acquisition de l'Arduino et Améliorations Prévues

Après avoir récupéré un Arduino, plusieurs ajustements et améliorations sont envisagés pour renforcer la sécurité et la fiabilité du système de coffre.

- **Validation simultanée de RFID et du digicode**
  Il est essentiel de garantir que tant le RFID que le digicode doivent être validés pour autoriser l'accès au coffre. En l'absence de cette double validation, il existe un risque potentiel si quelqu'un soulève manuellement le panneau de glissière, ce qui pourrait permettre l'accès au coffre sans la reconnaissance RFID. Il est nécessaire de s'assurer que l'identifiant RFID lu correspond à celui préalablement enregistré dans une variable. Veuillez consulter la section dédiée au code pour plus de détails.

- **Renforcement de la connexion électrique**
  Pour éviter tout débranchement intempestif avant une présentation, il est recommandé de souder les connexions avec des fils AWG32 sur une carte PCB vierge.

- **Utilisation d'un boîtier étanche rechargeable**
  Finalement, un boîtier étanche rechargeable sera utilisé à l'extérieur du coffre. Cette solution résout le problème potentiel de déverrouillage du coffre en cas de batterie déchargée, puisqu'il suffira de le recharger pour le déverrouiller. L'accès au port de charge sera disponible depuis l'extérieur, tout en préservant l'étanchéité du coffre grâce à la protection du panneau arrière de la porte.

## Partie Code

- **Ajustements du code**
  Des modifications mineures du code seront apportées, notamment concernant les angles des servo-moteurs et les test RFID repris du code de Mr. Bermon.

- **Codes hexadécimaux pour les cartes**
  Les codes hexadécimaux des cartes à utiliser sont les suivants :
  - Carte blanche : `12 E5 A2 34`
  - Badge bleu : `E9 D1 77 C1`

