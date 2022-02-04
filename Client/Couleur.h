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
	* @param const string& couleur - couleur correspondante.
	*/
	inline Couleur(const string& couleur = "blanc") : 
		couleur(couleur) {}

	/**
	* to_string d'une couleur.
	* 
	* @return string - Couleur.
	*/
	virtual operator string() const { return "[Couleur: " + couleur + "]"; }

};