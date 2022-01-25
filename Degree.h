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
	* Permet de passer de degrée à radian.
	* 
	* @return const double - résultat de la conversion.
	*/
	const double toRadian() const { return (theta * M_PI) / 180; }

	/**
	* Opérateur de cast de Degree à double.
	*
	* @return double - correspondant à la valeur de theta.
	*/
	operator double() const { return theta; }
};