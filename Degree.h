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
	* @param const double& x - valeur de u1 dans le vecteur u(u1, u2).
	*/
	Degree(double theta) : theta(theta) {}

	/// Destructeur de la classe Radian.
	virtual ~Degree() {}

	/**
	* Permet de passer de degr�e � radian.
	* 
	* @return const double - r�sultat de la conversion.
	*/
	const double toRadian() const { return (theta * M_PI) / 180; }

	/**
	* Op�rateur de cast de Degree � double.
	*
	* @return double - correspondant � la valeur de theta.
	*/
	operator double() const { return theta; }
};