#pragma once
#include <string>

#include "Forme.h"
using namespace std;

/**
* Repr�sente un triangle d�fini par une couleur, un vecteur d'origine a et deux autres vecteurs b et c.
* Par exemple, dans le triangle ABC, A est l'origine. Entre autre, le triangle sera donc d�fini par AB et AC.
*/
class Triangle : public Forme {
	Vecteur2D AB, AC;
public:
	/**
	* Constructeur de la classe Triangle qui construit un triangle ABC d'une couleur donn�e.
	* 
	* @param const Couleur& couleur - couleur du triangle.
	* @param const Vecteur2D& origine - origine du triangle abc.
	* @param const Vecteur2D& AB - vecteur AB du triangle ABC.
	* @param const Vecteur2D& AC - vecteur AC du triangle ABC.
	*/
	Triangle(const Couleur& couleur, const Vecteur2D& origine, const Vecteur2D& AB, const Vecteur2D& AC) :
		Forme(couleur, origine), AB(AB), AC(AC) {}

	/**
	* D�termine l'aire du triangle.
	*
	* @return const double - aire du triangle.
	*/
	const double aire() const { return determinant(AB, AC) * 0.5; }

	/**
	* Effectue une translation sur la forme.
	*
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	inline virtual const Forme* translation(const Vecteur2D& v) const;

	/**
	* Effectue une homoth�tie sur la forme. (zoom)
	* Calcule d'une homothetie : 
	* OM' = k(OM - OC) + OC
	* M' = rh * (M - C) + C
	*
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homoth�tie.
	*/
	inline virtual const Forme* homothetie(const Vecteur2D& C, const double& k) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const double& angle - Angle de rotation. (en radian)
	*/
	inline virtual const Forme* rotation(const Vecteur2D& pi, const double& angle) const;

	/**
	* Clone un triangle.
	* 
	* @return Forme* - Copie du triangle
	*/
	inline virtual Forme* clone() const;

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
	*
	* @return string - vecteur courant.
	*/
	inline virtual operator string() const;
};

const Forme* Triangle::translation(const Vecteur2D& v) const {
	
}

const Forme* Triangle::homothetie(const Vecteur2D& C, const double& k) const {
	
}

const Forme* Triangle::rotation(const Vecteur2D& v, const double& angle) const {

}

Triangle::operator string() const {
	return "[Triangle: A(" + to_string(getOrigine().x) + ", " + to_string(getOrigine().y) + ") - B" + (string) AB + " - C" + (string) AC + " - " + (string) getCouleur() + "]";
}

Forme* Triangle::clone() const {
	return new Triangle(*this);
}