#pragma once
#include <string>

#include "Forme.h"
using namespace std;

/**
* Représente un triangle.
* Définie par trois vecteurs a, b et c correspondant à un triangle ABC.
*/
class Triangle : public Forme {
	Vecteur2D a, b, c;
};