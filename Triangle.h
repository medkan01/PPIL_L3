#pragma once
#include <string>

#include "Forme.h"
using namespace std;

/**
* Repr�sente un triangle.
* D�finie par trois vecteurs a, b et c correspondant � un triangle ABC.
*/
class Triangle : public Forme {
	Vecteur2D a, b, c;
};