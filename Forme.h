#pragma once
#include <iostream>
#include <string>

#include "Vecteur2D.h"

using namespace std;

class Forme {
	string couleur;
public:
	/**
	* Effectue une translation sur la forme.
	* 
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	virtual void translation(const Vecteur2D& v) const = 0;

	/**
	* Effectue une homothétie sur la forme. (zoom)
	* 
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homothétie.
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
	* Opérateur de cast. Equivalent d'une méthode toString().
	*
	* @return string - vecteur courant.
	*/
	virtual operator string() const = 0;

	/**
	* Récupère la couleur d'une forme.
	*
	* @return string - couleur de la forme.
	*/
	inline string getCouleur() const { return couleur; }

	/**
	* Modifie la couleur d'une forme.
	*
	* @param const string& c - Nouvelle couleur de la forme.
	*/
	inline void setCouleur(const string& c) { couleur = c; }
};