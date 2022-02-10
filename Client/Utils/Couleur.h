#pragma once
#include <string>
#include <iostream>
using namespace std;

class Couleur {
public:
	string couleur;
	/**
	* Constructeur de la classe Couleur.
	* 
	* @param couleur couleur correspondante.
	*/
	inline Couleur(const string& couleur = "blanc") : 
		couleur(couleur) {}

	/// Destructeur de la classe couleur
	virtual ~Couleur() {}

	/**
	* to_string d'une couleur.
	* 
	* @return Couleur.
	*/
	virtual operator string() const { return couleur; }

};