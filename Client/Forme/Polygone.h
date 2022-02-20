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

	/**
	* Retourne l'abcisse du centre.
	*
	* @return abcisse du centre du polygone.
	*/
	inline const double abcisseCentre() const;

	/**
	* Retourne l'ordonnee du centre.
	*
	* @return ordonnee du centre du polygone.
	*/
	inline const double ordonneeCentre() const;
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

	/**
	* Determine l'aire du polygone.
	*
	* @return aire du Polygone.
	*/
	inline const double aire() const;

	/**
	* Effectue une translation sur la forme.
	*
	* @param v Vecteur de translation
	*/
	inline virtual const Polygone translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothetie sur la forme. (zoom)
	* Calcule d'une homothetie :
	* OM' = k(OM OC) + OC
	* M' = k * (M C) + C
	*
	* @param C Point invariant.
	* @param k Rapport d'homothetie.
	*/
	inline virtual const Polygone homothetie(const Vecteur2D& C, const double& k) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param R Point invariant. (centre de rotation)
	* @param theta Angle de rotation. (en degree)
	*/
	inline virtual const Polygone rotation(const Vecteur2D& R, const Degree& theta) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param R Point invariant. (centre de rotation)
	* @param alpha Angle de rotation. (en radian)
	*/
	inline virtual const Polygone rotation(const Vecteur2D& R, const Radian& alpha) const;

	friend ostream& operator<<(ostream& os, const Polygone& t);
};

inline ostream& operator<<(ostream& os, const Polygone& t) {
	return os << (string)t;
}

#endif