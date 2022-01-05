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
};