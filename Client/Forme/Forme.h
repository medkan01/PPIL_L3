#pragma once
#include "../Utils/Couleur.h"
#include "Vecteur2D.h"
using namespace std;

/**
* Represente une forme quelconque.
* 
* Definie par une couleur et un point d'origine.
*/
class Forme {
public:
	Couleur couleur;
	Vecteur2D centre;

	/**
	* Constructeur de la classe Forme.
	* 
	* @param couleur Couleur de la forme.
	* @param origine Origine de la forme.
	*/
	Forme(const Couleur& couleur, const Vecteur2D& centre) : 
		couleur(couleur), centre(centre) {}

	/// Constructeur par defaut de la classe Forme.
	Forme() : couleur(Couleur("Noire")), centre(Vecteur2D(0, 0)) {}

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
};