#include "GroupeFormes.h"
#include "../Visitor/VisiteurForme.h"

GroupeFormes::GroupeFormes(const GroupeFormes& gf) {
	couleur = gf.couleur;
}

GroupeFormes::~GroupeFormes() {
	vector<Forme*>::iterator it;
	for (it = groupe.begin(); it != groupe.end(); it++) {
		delete(*it);
	}

	groupe.clear();
}

void GroupeFormes::ajouterForme(Forme* forme) {
	// On verifie si la forme n'appartient pas deja a un groupe.
	if (forme->dansGroupe)
		cout << "La forme est deja dans un groupe." << endl;
	else {
		// On change certains attributs de la forme.
		forme->couleur = couleur;
		forme->dansGroupe = true;

		// On ajoute la forme au groupe.
		groupe.push_back(forme->clone());
	}
}

void GroupeFormes::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }