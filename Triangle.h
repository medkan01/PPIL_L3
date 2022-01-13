#pragma once
#include <string>

#include "Forme.h"
using namespace std;

/**
* Représente un triangle défini par une couleur, un vecteur d'origine a et deux autres vecteurs b et c.
* Par exemple, dans le triangle ABC, A est l'origine. Entre autre, le triangle sera donc défini par AB et AC.
*/
class Triangle : public Forme {
	Vecteur2D AB, AC;
public:
	/**
	* Constructeur de la classe Triangle qui construit un triangle ABC d'une couleur donnée.
	* 
	* @param const Couleur& couleur - couleur du triangle.
	* @param const Vecteur2D& origine - origine du triangle abc.
	* @param const Vecteur2D& AB - vecteur AB du triangle ABC.
	* @param const Vecteur2D& AC - vecteur AC du triangle ABC.
	*/
	Triangle(const Couleur& couleur, const Vecteur2D& origine, const Vecteur2D& AB, const Vecteur2D& AC) :
		Forme(couleur, origine), AB(AB), AC(AC) {}

	/**
	* Détermine l'aire du triangle.
	*
	* @return const double - aire du triangle.
	*/
	const double aire() const { return determinant(AB, AC) * 0.5; }

	/**
	* Effectue une translation sur la forme.
	*
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	inline virtual void translation(const Vecteur2D& v);

	/**
	* Effectue une homothétie sur la forme. (zoom)
	* Calcule d'une homothetie : 
	* OM' = k(OM - OC) + OC
	* M' = rh * (M - C) + C
	*
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homothétie.
	*/
	inline virtual void homothetie(const Vecteur2D& C, const double& rh);

	/**
	* Effectue une rotation sur la forme.
	*
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const double& angle - Angle de rotation. (en radian)
	*/
	virtual void rotation(const Vecteur2D& pi, const double& angle);
};

void Triangle::translation(const Vecteur2D& v) {
	setOrigine(getOrigine() + v);
	AB = AB + v;
	AC = AC + v;
}

const Triangle Triangle::homothetie(const Vecteur2D& pi, const double& rh) {
	
}