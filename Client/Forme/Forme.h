#ifndef FORME_H
#define FORME_H

#include "../Utils/Couleur.h"
#include "Vecteur2D.h"
#include "Repere.h"

using namespace std;

class VisiteurForme;

/**
* Represente une forme quelconque.
* 
* Definie par une couleur et un point d'origine.
*/
class Forme {
protected:
	bool dansGroupe;
public:
	Couleur couleur;
	Vecteur2D centre;
	Repere repere;

	/**
	* Constructeur de la classe Forme.
	* 
	* @param couleur Couleur de la forme.
	* @param origine Origine de la forme.
	*/
	Forme(const Couleur& couleur, const Vecteur2D& c, const Repere& rep) : 
		dansGroupe(false),
		couleur(couleur) {
		if (!rep.estDans(centre))
			throw exception("La forme n'est pas dans le repere.");
		centre = c;
		repere = rep;

	}

	/// Constructeur par defaut de la classe Forme.
	Forme() : dansGroupe(false), couleur(Couleur::BLACK), centre(Vecteur2D(0, 0)) {}

	/// Destructeur de la classe forme
	virtual ~Forme() {}

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString vecteur courant.
	*/
	virtual operator string() const = 0;

	/**
	* Clone une forme.
	* 
	* @return Copie de la forme.
	*/
	virtual Forme* clone() const = 0;

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const = 0;

	friend class GroupeFormes;
};

#endif 