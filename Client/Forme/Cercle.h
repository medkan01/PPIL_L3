#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"

class Cercle : public Forme {
public:
	Vecteur2D r;

	/**
	* Constructeur de la classe Cercle.
	* 
	* @param couleurCercle Couleur du cercle.
	* @param rep Repere / Zone de scene du cercle.
	* @param centreCercle Centre du cercle.
	* @param rayon Rayon du cercle.
	*/
	inline Cercle(const Couleur& couleurCercle, const Repere& rep, const Vecteur2D& centreCercle, const Vecteur2D& rayon);

	/// Destructeur de la classe Cercle.
	virtual ~Cercle() {}

	/**
	* Effectue une translation sur la forme.
	*
	* @param v Vecteur de translation
	*/
	virtual inline const Cercle translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothetie sur la forme. (zoom)
	*
	* @param c Point invariant.
	* @param rh Rapport d'homothetie.
	*/
	virtual inline const Cercle homothetie(const Vecteur2D& c, const double& rh) const;

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString Cercle.
	*/
	virtual inline operator string() const;

	/**
	* Clone une forme.
	*
	* @return Copie de la forme.
	*/
	virtual Forme* clone() const { return new Cercle(*this); }

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const;
};

Cercle::Cercle(const Couleur& couleurCercle, const Repere& rep, const Vecteur2D& centreCercle, const Vecteur2D& rayon) {
	couleur = couleurCercle;
	repere = rep;

	try {
		if (!repere.estDans(centreCercle) || !repere.estDans(rayon))
			throw exception("La forme n'est pas dans le repere / zone de scene.");

		centre = centreCercle;
		r = rayon;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

const Cercle Cercle::translation(const Vecteur2D& v) const {
	Cercle c = *this;
	
	c.centre += v;
	c.r += v;
	
	if (!repere.estDans(c.centre) || !repere.estDans(c.r))
		throw exception("La forme n'est pas dans le repere.");

	return c;
}

const Cercle Cercle::homothetie(const Vecteur2D& c, const double& rh) const {
	Cercle cercle = *this;

	cercle.centre = cercle.centre.homothetie(c, rh);
	cercle.r = cercle.r.homothetie(c, rh);

	if (!repere.estDans(cercle.centre) || !repere.estDans(cercle.r))
		throw exception("La forme n'est pas dans le repere.");

	return cercle;
}

Cercle::operator string() const {
	return "Cercle[ " + (string)couleur + " - centre" + centre + " - rayon" + r + " - Repere[" + (string)repere + "]]";
}

#endif