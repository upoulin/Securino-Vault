*******************
# Rapport 
*******************

## Séance du 16 Février

### Code

Au cours de cette séance, j'ai finalisé la partie code en implémentant les LEDs, qui respectent plusieurs états :
  
| État LED           | Signification                      |
|--------------------|-----------------------------------|
| Rouge              | Coffre verrouillé                  |
| Rouge clignotant   | Trop de tentatives                 |
| Vert               | Coffre déverrouillé                |
| Vert clignotant    | Coffre en cours de déverrouillage  |
| Rouge et vert      | Changement du code                 |

Au final, je prévois de maintenir l'utilisation de la fonction `delay` car je ne trouve pas d'alternatives à ma portée, et le coffre fonctionne correctement avec cette fonction. Je propose donc de conserver son utilisation.

### Branchements finaux

J'ai testé le système avec la carte PCB que David a soudée la semaine dernière, et le système est fonctionnel. Il a également été testé avec une alimentation sur batterie, ce qui confirme son bon fonctionnement. Il ne me reste plus qu'à fixer tous les branchements à la porte, et ma partie sera terminée.
