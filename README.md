# PUSH SWAP

## INPUT/ OUTPUT

```
Reception : une chaîne de caractère («-9 8 25 1») ou
une multitude de chaîne de caractères (argv) (-9 8 25 1)
Rendu : une liste de commande (ex : rra \n pb
\n rb \n...)
```
## PARSING


**1ere étape**
Harmoniser ce qui est reçus

**2ème étape**
Vérifier si les élements recus sont mauvais :
- (caractères invalides)
- (signes - et + (un seul signe autorisé))
- (deux fois le même élements)
- (int min int max (conseil, utilise atoll))

**3ème étape**
Créer un tableau de int

**4eme étape**
Verifier si les nombres reçus sont pas déjà triés

**5eme étape**
Créer un tableaux de int des index triés
ex :
```
- int(0) = -9 
- int(1) = 8 
- int(2) = 25 
- int(3) = 1 
```
```
- int(0) = plus petite valeur donc 0
- int(1) = 2
- int(2) = plus grande valeur donc 3
- int(3) = 1
```
## NOUVELLE NOTION

```
Création de liste chaînée (soit une double liste chaînée
soit une simple
```

1ere étape
Transformer le tableaux de int à index triés en liste
chaînée

2ème étape
Créer des fonctions pour gérer la liste chaînée
ex : dans le cas d’une double liste chaînée faire fonction pour
remonter au début de la liste et une pour aller à la fin de
la liste, faire une fonction pour connaître la taille de ta liste, faire une fonction pour imprimer ta liste (peut servir
juste le temps de coder push swap), et
puis pour plus tard une fonction pour free la liste (que je conseille de faire à la fin)

3ème étape
Créer des fonctions permettant de déplacer les éléments
dans les listes (push, swap, rotate, reverse rotate) : les commandes

## ALGO

```
Explication de l'algo que j'ai fait
```

1ere étape
Faire une fonction qui trie les trois dernier éléments de la
liste chaînée a

2ème étape

Faire en sorte que les fonctions re-
cherches des éléments contenus dans une fenêtre de
valeurs pour les push dans la list b, dès que ta focntion trouve
un élément ne faisant pas parti de cette fenêtre,
rotate la liste a (sa revient à le mettre à la fin de la liste
a). A chaque push dans b, déplaces la fenêtre d’un
cran. Si la fonction croises un éléments plus petits que la valeur
minimum acceptée par la fenêtre, cet element est push en b et
reverse rotate dans b (ce qui permet de la mettre à la fin
de la liste b), avances la fenêtre également d’un cran.
Faire ça jusqu’à ce qu’il ne restes que trois éléments
dans a.

3ème étape
Tris les trois éléments de la liste a avec la fonction que
tu auras fait precedemment.

4eme étape
Pour finir, vides b dans a, en cherchant à chaque fois
dans b le plus grand éléments et en le mettant dans a.
L’enjeux est de réussir à ce que les 3 éléments restant
dans a soit remis à la bonne place au fur et à mesure.
Puis, oublie pas de tout bien free.
