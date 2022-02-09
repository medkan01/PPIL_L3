# PPIL_L3
## Projet de synthèse - L3

Afin de valider la troisième année de Licence Informatique, je dois réaliser un projet de synthèse sur une durée d'environ 4 mois.
Ce projet a pour but de mettre en oeuvre l'ensemble des notions découvertes durant ces trois années universitaires. Les notions concernées comprennent celles vues dans les différents projets / TD / TP de développement et de programmation (les design pattern, les langages, etc). Elles comprennent aussi les notions d'organisations acquises en dehors des cours universitaires et le stage.

Ce projet est initialement prévu pour être réalisé avec deux personnes. Cependant, la quantité de notions que propose ce projet étant assez conséquente, j'ai choisi de réaliser ce projet seul afin de mettre à profit la totalité de mes compétences. 

L'application à créer doit permettre de construire et dessiner des formes et des groupes de formes à l'aide d'une application client/serveur à l'aide de deux technologies: C++ (_pour la partie client_) et Java (_pour la partie serveur_).
Le fait d'utiliser Java ET C++ dans une même application permet de profiter des performances de calcule de C++ et les performances de gestion d'interface graphique de Java.

Le but de ce projet est d'utiliser toutes les compétences acquises durant ces 3 années de Licence Informatique (_dans mon cas, mes 2 ans de DUT Informatique puis ma 3ème années de Licence Informatique_) et notamment les compétences suivantes :
  - Programmtion orientée objet
  - Classes et classes abstraites
  - Design Pattern
  - Réseau (_protocole TCP/IP, avec l'utilisation des sockets_)
  - Système _ou programmation système_ (_multi-threading_) 

### Design Pattern

Durant ces trois années, j'ai pu apprendre plusieurs Design Pattern :
  - MVC
  - Factory
  - *Singleton*
  - *Chain of responsability*
  - *Visitor*
  
Les trois dernier Design Pattern ont été acquis durant le développement de cette application.
  
### Multi-threading
  
Le serveur doit pouvoir être géré en multi-threading. Dans le cadre de ce projet, il est inutile de géré les exclusions mutuelles car aucune données ne sera aménée à être modifiée simultanément sur plusieurs processus.
