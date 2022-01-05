#pragma once
#include <string>

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

};