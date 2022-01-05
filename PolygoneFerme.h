#pragma once
#include <string>
#include "Forme.h"
using namespace std;

class PolygoneFerme : public Forme {
public:
	/**
	* Constructeur de la classe PolygoneFerme.
	* 
	* @param const string& couleur - Couleur du polygone.
	*/
	PolygoneFerme(const string& couleur) : Forme(couleur) {}
};