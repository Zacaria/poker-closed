# Jeu de poker

But
===
Ecrire un jeu de poker où un joueur humain joue contre des adversaires gérés par l'ordinateur.

Règles du jeu
=============

On prendra la version du Poker la plus simple pour les débutants : le poker fermé.
Le jeu se fera avec huit joueurs (dont sept contrôlés par l'ordinateur).


Au départ du jeu, tous les joueurs possèdent le même nombre de jetons (ici on prendra
par exemple 1000 jetons, mais vous pouvez modifier cela à votre convenance).

Le tapis d'un joueur s'alimente par caves, le système de caves permettant d'équilibrer les chances entre les joueurs plus riches et plus pauvres :
- La cave est la valeur exprimée en jetons (typiquement 100 à 200) qu'un joueur peut approvisionner initialement, ou réapprovisionner entre deux distributions. La valeur d'une cave est identique pour tous les joueurs.
- Le tapis est le total des jetons qu'un joueur a devant lui et peut miser. Un joueur peut initialement mettre une cave sur le tapis, ou plus si les joueurs sont d'accord.

En cours de partie, un joueur ne peut jouer qu'avec son tapis (et il est interdit d'emprunter à ses adversaires). Si le montant de celui-ci est insuffisant, il peut rajouter une cave, mais uniquement entre les coups.

Dans le système de « cave libre », la contrainte est plus faible : le nombre de cave d'un réapprovisionnement n'est pas limité, un joueur peut se recaver autant qu'il le veut. Il est possible de supprimer toute contrainte sur la cave, les joueurs étant alors directement limités par leur fortune personnelle.

Donneur 
-------

L'ordinateur fera office de croupier et distribuera les cartes.

Au poker fermé, les cartes ne sont mélangées qu'au début de la partie, ou quand un jeu neuf a été mis en service. Le jeu n'est ensuite jamais rebattu, pour lui permettre de se «faire», mais est uniquement coupé.

La partie se fera « au pot ». Tous ou une partie des joueurs doit mettre une mise forcée sur le tapis, indépendamment de son jeu : c'est l'enjeu initial de la partie.

Dans la partie au pot, la plus fréquente, chaque joueur met au pot une mise fixée à l'avance, identique pour tous. Ce montant, fixé en début de partie, est typiquement de un à trois jetons.

L'ordinateur distribue les cartes une par une, en principe dans le sens des aiguilles d'une montre. Il commence par le joueur "sous la douche". Quand chaque joueur a reçu cinq cartes, tous peuvent les ramasser et en prendre connaissance. Commencent alors les enchères.

Déroulement d'un tour d'enchères
--------------------------------

Le principe des enchères est simple : Pour rester dans le coup, tous les joueurs doivent avoir misé au total la même valeur d'enchère (sauf cas du « tapis », discuté plus loin), mais chacun peut relancer sur les enchères de ses adversaires. Les enchères sont achevées dès que tout le monde a misé la même enchère (personne n'a relancé), ou que tous sauf un se sont couchés.

Chaque joueur doit tenir le compte de ce qu'il a déjà misé, et de ce qu'il lui reste à miser pour atteindre le niveau de l'enchère courante, en fonction de l'historique des enchères. Ces comptes doivent être soigneusement surveillés, notamment lors des sur-enchères, le montant des sommes à ajouter par chaque joueur pour « suivre » peuvent résulter d'un historique très complexe.

Dans les parties au pot, les enchères sont ouvertes par le premier joueur à gauche du donneur. Lors d'un tour d'enchères, dans les parties au pot, chaque joueur encore en jeu peut, à son tour, choisir comme possibilité avant l'ouverture :

*Parole* : dans le cas où aucune enchère n'a encore été faite dans le tour, le joueur peut rester en jeu en donnant la parole au joueur suivant, sans rien miser. NB : avant l'ouverture, le « passe » n'existe pas ; un joueur qui « passe » (par abus de langage) indique en fait qu'il joue « parole ».
*Ouvrir*, s'il est le premier à faire une mise. Il annonce sa mise en disant « j'ouvre de tant », et place la mise au centre du tapis. Cette mise est appelée l'ouverture.


Une fois qu'un joueur a ouvert, les possibilités sont :

*Se coucher ou passer* (en anglais, fold) : le joueur laisse ses cartes au milieu de la table (non visible) et ne joue plus jusqu'à la donne suivante. NB : il n'est possible de se coucher qu'après l'ouverture. Après l'ouverture, un joueur ne peut que miser à hauteur de l'enchère, ou se coucher ; un joueur qui dit parole (par abus de langage) indique en fait qu'il se couche.
*Suivre ou voir* (call ou see) : le joueur complète sa mise avec ses jetons, de manière à mettre dans le pot (au total) une somme égale à la dernière enchère. Le joueur dira plutôt « suivre » au premier tour d'enchères, et « pour voir » au second. NB : Si son tapis est inférieur à la somme nécessaire pour atteindre la dernière enchère, il peut rester en jeu à condition de miser la totalité des jetons qui lui restent : on dit alors qu'il fait tapis (voir plus loin).
*Relancer* (raise) : le joueur en position de « suivre » peut augmenter les enchères, et miser dans le pot (au total de ce qu'il mise) une somme supérieure à la dernière enchère. Une relance après une première relance est une sur-relance. Il n'est pas possible de relancer sur le montant de sa propre enchère : si tous les joueurs dans le coup ont suivi, le tour d'enchère est fini.
*Tapis* (All-in) : le joueur qui n'a plus assez de jetons pour suivre mise la totalité de ce qui lui reste. Cela lui permet de participer à l'enchère en cours sans avoir à miser plus loin, quelles que soient les relances, comme s'il décidait de « suivre » à chaque fois. S'il perd, il est éliminé et perd son tapis. S'il gagne, il ne remporte les mises des autres joueurs qu'à hauteur de son tapis, le reste des enchères étant remporté par le joueur ayant la deuxième meilleure main (et ainsi de suite, en cas de « tapis » multiples). Un joueur peut également faire tapis lors d'une relance ou une sur-relance.

Le tour d'enchère est terminé lorsque tous les joueurs ont soit misé la même somme, soit se sont retirés du coup.

Note :
------
 en principe, on ne joue qu'avec ce qui se trouve sur la table. Il n'est pas possible d'acheter des jetons supplémentaires au cours d'une enchère.

Cartes
------

On demande à chaque joueur encore dans le coup (en commençant par celui sous la douche) le nombre de cartes qu'il désire échanger. Chaque joueur annonce à tour de rôle le nombre de cartes qu'il écarte, en les rejetant (face sur la table), avant d'en recevoir autant de nouvelles. Le donneur rassemble toutes les cartes écartées.

Un joueur qui n'échange aucune carte annonce « servi », sinon « une carte », ou « deux cartes », parfois « trois cartes ».

Deuxième tour d'enchères
-------------------------

Le deuxième tour se déroule suivant les mêmes règles que le premier, seuls pouvant enchérir les joueurs qui sont restés dans le coup au premier tour.

Fin du coup
-----------

La partie se termine lorsque :

- il ne reste plus qu'un joueur en jeu. Il remporte alors le pot sans même avoir à montrer son jeu ;
- il n'y a plus de tour de mise. On passe alors à l'abattage (showdown), phase où les mains des joueurs encore en lice sont comparées pour déterminer le détenteur de la meilleure. En cas d'égalité, le pot est partagé équitablement entre les gagnants.

S'il y a abattage de jeu, tous les joueurs encore en compétition montrent l'intégralité de leur jeu à tous les joueurs de la table. 


Les mains au poker
------------------

Pour les mains au poker, voir l'article de wikipedia :

https://fr.wikipedia.org/wiki/Main_au_poker

Stratégies possibles pour l'ordinateur
======================================

- *Le bluffeur* : quelque soit sa main, il enchirera avec une grosse surenchère ou suivra le cas échéant, mais ne se couchera jamais
- *Le peureux* : Ne commence à ne pas se coucher qu'avec une double paire, et ne fait
pas de grosses surenchères si il n'a pas la quinte royale !
- *L'autiste'* : Décide selon une probabilité (que vous pouvez choisir en fonction de son jeu)
si il suit, surenchère ou se couche, mais il ne vas pas tenir compte de l'annonce des autres
joueurs.

Bien sûr, il pourrait y avoir d'autres stratégies bien plus efficaces que ces dernières, mais
elles demandent une grosse programmation, avec une bonne connaissance de l'I.A.
Mais si vous pensez à d'autres stratégies pour joueur, vous ètes les bienvenus pour les mettre
en oeuvre !

Mise en oeuvre
==============

Pour la mise en oeuvre, avant de vous lancer parfois dans des algorithmes compliqués, assurez
vous qu'il n'existe pas des fonctions de la STL déjà proposées pour ce que vous voulez faire.
Par exemple, pour le mélange des cartes, regardez à tout hasard si il n'existe pas une
fonction shuffle dans la librairie standard C++\ldots

Affichage des cartes
====================

Un exemple d'affichage de toutes les cartes du jeu est donné dans @test_cartes.cpp@.
Les cartes sont définies dans @cartes.hpp@ et utilisent l'UTF8 (pour le graphisme)
et les codes ANSI (pour la couleur) afin d'afficher les cartes.

Pour afficher une carte, il suffira donc d'inclure @cartes.hpp@ et de lancer le code
dans un terminal ANSI supportant l'UTF 8 (les terminaux proposés par Linux ou
MSYS 2 sous Windows font cela très bien).

Si vous rencontrez des difficultés à l'affichage (@test_cartes.cpp@ vous donne n'importe
quoi à l'affichage), essayez de configurer votre terminal en changeant de fonte, et si
cela ne marche pas, remplacer l'affichage des cartes par deux lettres ou chiffre,
la première lettre donnant la valeur de la carte et la seconde lettre sa couleur.

Par exemple, VT pourra signifier Valet de Trèfle, 4D quatre de carreaux (Diamond en anglais), etc.

Nota Bene:
---------
Il se peut que les cartes affichées soient très petites. N'hésitez pas pour essayer d'agrandir
les fontes !