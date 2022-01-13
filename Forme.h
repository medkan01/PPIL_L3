#pragma once
#include <iostream>
#include <string>

#include "Vecteur2D.h"
#include "Couleur.h"

using namespace std;

/**
* Repr�sente une forme quelconque.
* 
* D�finie par une couleur et un point d'origine.
*/
class Forme {
	Couleur couleur;
	Vecteur2D origine;
public:
	/**
	* Constructeur de la classe Forme.
	* 
	* @param const string& couleur - Couleur de la forme.
	* @param const Vectuer2D& origine - Origine de la forme.
	*/
	Forme(const Couleur& couleur, const Vecteur2D& origine) : 
		couleur(couleur), origine(origine) {}

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
	* R�cup�re la couleur de la forme.
	*
	* @return string - couleur de la forme.
	*/
	const Couleur getCouleur() const { return couleur; }

	/**
	* Modifie la couleur de la forme.
	*
	* @param const string& c - nouvelle couleur de la forme.
	*/
	void setCouleur(const string& c) { couleur = c; }

	/**
	* R�cup�re l'origine de la forme.
	* 
	* @return const Vecteur2D - origine de la forme.
	*/
	const Vecteur2D getOrigine() const { return origine; }

	/**
	* Modifie l'origine de la forme.
	* 
	* @param const Vecteur2D& u - nouvelle origine de la forme.
	*/
	void setOrigine(const Vecteur2D& u) { origine = u; }

	/**
	* Op�rateur = qui remplace la forme courante par la forme entr�e en param�tre.
	*
	* @param const Forme* forme - Nouvelle forme.
	* @return Forme* - Forme remplac�e.
	*/
	virtual const Forme* operator =(const Forme* forme) const = 0;

	/**
	* Clone une forme.
	* 
	* @return Forme* - Copie de la forme.
	*/
	virtual Forme* clone() const = 0;
};