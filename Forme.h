#pragma once
#include <iostream>
#include <string>

#include "Vecteur2D.h"
#include "Couleur.h"

using namespace std;

class Forme {
	Couleur couleur;
public:
	/**
	* Constructeur de la classe Forme.
	* 
	* @param const string& couleur - Couleur de la forme.
	*/
	Forme(const Couleur& couleur) : couleur(couleur) {}

	/**
	* Effectue une translation sur la forme.
	* 
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	virtual void translation(const Vecteur2D& v) const = 0;

	/**
	* Effectue une homoth�tie sur la forme. (zoom)
	* 
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homoth�tie.
	*/
	virtual void homothetie(const Vecteur2D& pi, const double& rh) const = 0;

	/**
	* Effectue une rotation sur la forme.
	* 
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const double& angle - Angle de rotation. (en radian)
	*/
	virtual void rotation(const Vecteur2D& pi, const double& angle) const = 0;

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
	*
	* @return string - vecteur courant.
	*/
	virtual operator string() const = 0;

	/**
	* R�cup�re la couleur d'une forme.
	*
	* @return string - couleur de la forme.
	*/
	const Couleur getCouleur() const { return couleur; }

	/**
	* Modifie la couleur d'une forme.
	*
	* @param const string& c - Nouvelle couleur de la forme.
	*/
	void setCouleur(const string& c) { couleur = c; }

	/**
	* Op�rateur = qui remplace la forme courante par la forme entr�e en param�tre.
	*
	* @param const Forme* forme - Nouvelle forme.
	* @return Forme* - Forme remplac�e.
	*/
	virtual const Forme* operator =(const Forme* forme) const = 0;
};