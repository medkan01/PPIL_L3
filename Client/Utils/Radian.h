#pragma once
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>

/**
* Un radian est defini par un double.
*/
class Radian {
public:
	double alpha;

	/**
	* Constructeur de la classe Radian qui contruit un Radian alpha.
	*
	* @param alpha valeur de u1 dans le vecteur u(u1, u2).
	*/
	Radian(double alpha) : alpha(alpha) {}

	/// Destructeur de la classe Radian.
	virtual ~Radian() {}

	/**
	* Permet de passer de radianadegree.
	*
	* @return resultat de la conversion.
	*/
	const double toDegree() const { return (alpha * 180) / M_PI; }

	/**
	* Operateur de cast de Radianadouble.
	*
	* @return valeur d'alpha.
	*/
	operator double() const { return alpha; }
};