#pragma once
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>

class Degree {
public:
	double theta;

	/**
	* Constructeur de la classe Radian qui contruit un Radian alpha.
	*
	* @param theta - valeur de u1 dans le vecteur u(u1, u2).
	*/
	Degree(double theta) : theta(theta) {}

	/// Destructeur de la classe Radian.
	virtual ~Degree() {}

	/**
	* Permet de passer de degree a radian.
	* 
	* @return resultat de la conversion.
	*/
	const double toRadian() const { return (theta * M_PI) / 180; }

	/**
	* Operateur de cast de Degreeadouble.
	*
	* @return valeur de theta.
	*/
	operator double() const { return theta; }
};