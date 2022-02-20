#ifndef GROUPEFORMES_H
#define GROUPEFORMES_H

#include <vector>

#include "Forme.h"

using namespace std;

class GroupeFormes {
public:
	Couleur couleur;
	vector<Forme*> groupe;

	/**
	* Constructeur de la classe GroupeFormes.
	* 
	* @param couleur Couleur des formes de ce groupe.
	*/
	GroupeFormes(const Couleur& couleur) : couleur(couleur) {}

	/**
	* Constructeur par recopie de la classe GroupeFormes.
	* Les formes ne seront pas copiees car elles ne peuvent appartenir qu'a un seul groupe.
	* 
	* @param gf Groupe de forme a copier.
	*/
	GroupeFormes(const GroupeFormes& gf);

	/// Destructeur de classe GroupeFormes.
	virtual ~GroupeFormes();

	/**
	* Methode permettant l'ajout de forme dans le groupe.
	* 
	* @param forme Forme a ajouter au groupe.
	*/
	void ajouterForme(Forme* forme);

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const;
};

#endif