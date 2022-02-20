#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>

using namespace std;

#include "Forme.h"

/**
* Classe polygone.
* Permet de creer un polygone avec une liste de points.
*/
class Polygone : public Forme {
	vector<Vecteur2D> points;

public:
	/**
	* Constructeur de la classe Polygone.
	* 
	*/
	Polygone(const Couleur& c, const Repere& r, const vector<Vecteur2D>& listePoints);

	/**
	* Constructeur par recopie de la classe Polygone.
	*
	*/
	Polygone(const Polygone& p);

	/**
	* Constructeur par defaut de la classe Polygone.
	*
	*/
	Polygone();

	/// Destructeur de la classe Polygone.
	virtual ~Polygone();

	/**
	* Permet d'ajouter un point a la liste de points du polygone.
	*
	* @param p Point a ajouter a la liste.
	*/
	void ajouterPoint(const Vecteur2D& p);

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const;

	/**
	* Permet de recuperer les points du polygone.
	* 
	* @return Liste des points.
	*/
	const vector<Vecteur2D> getPoints() const { return points; }

	/**
	* Clone une forme.
	*
	* @return Copie de la forme.
	*/
	virtual Forme* clone() const { return new Polygone(*this); }

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString vecteur courant.
	*/
	virtual operator string() const;
};

#endif