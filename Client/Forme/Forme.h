#pragma once
#include "../Utils/Couleur.h"
#include "Vecteur2D.h"
using namespace std;

/**
* Repr�sente une forme quelconque.
* 
* D�finie par une couleur et un point d'origine.
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

	/// Constructeur par d�faut de la classe Forme.
	Forme() : couleur(Couleur("Noire")), centre(Vecteur2D(0, 0)) {}

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
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