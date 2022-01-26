#pragma once
#include "Couleur.h"
#include "Vecteur2D.h"
using namespace std;

/**
* Représente une forme quelconque.
* 
* Définie par une couleur et un point d'origine.
*/
class Forme {
public:
	Couleur couleur;
	Vecteur2D centre;

	/**
	* Constructeur de la classe Forme.
	* 
	* @param const string& couleur - Couleur de la forme.
	* @param const Vectuer2D& origine - Origine de la forme.
	*/
	Forme(const Couleur& couleur, const Vecteur2D& centre) : 
		couleur(couleur), centre(centre) {}

	/**
	* Opérateur de cast. Equivalent d'une méthode toString().
	*
	* @return string - vecteur courant.
	*/
	virtual operator string() const = 0;

	/**
	* Clone une forme.
	* 
	* @return Forme* - Copie de la forme.
	*/
	virtual Forme* clone() const = 0;
};