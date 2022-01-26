#pragma once
#include "Couleur.h"
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

	/**
	* Effectue une translation sur la forme.
	* 
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	virtual const Forme* translation(const Vecteur2D& v) const = 0;

	/**
	* Effectue une homoth�tie sur la forme. (zoom)
	* 
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homoth�tie.
	*/
	virtual const Forme* homothetie(const Vecteur2D& pi, const double& rh) const = 0;

	/**
	* Effectue une rotation sur la forme.
	* 
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const double& angle - Angle de rotation. (en radian)
	*/
	virtual const Forme* rotation(const Vecteur2D& pi, const double& angle) const = 0;

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
	*
	* @return string - vecteur courant.
	*/
	virtual operator string() const = 0;

	/**
	* R�cup�re l'origine de la forme.
	* 
	* @return const Vecteur2D - origine de la forme.
	*/
	const Vecteur2D getOrigine() const { return centre; }

	/**
	* Modifie l'origine de la forme.
	* 
	* @param const Vecteur2D& u - nouvelle origine de la forme.
	*/
	void setOrigine(const Vecteur2D& u) { centre = u; }

	/**
	* Clone une forme.
	* 
	* @return Forme* - Copie de la forme.
	*/
	virtual Forme* clone() const = 0;
};