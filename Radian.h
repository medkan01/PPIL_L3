#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES
#include <math.h>

/**
* Un radian est d�fini par un double.
*/
class Radian {
public:
	double alpha;

	/**
	* Constructeur de la classe Radian qui contruit un Radian alpha.
	*
	* @param const double& x - valeur de u1 dans le vecteur u(u1, u2).
	*/
	Radian(double alpha) : alpha(alpha) {}

	/// Destructeur de la classe Radian.
	virtual ~Radian() {}

	/**
	* Permet de passer de radian � degr�e.
	*
	* @return const double - r�sultat de la conversion.
	*/
	const double toDegree() const { return (alpha * 180) / M_PI; }

	/**
	* Op�rateur de cast de Radian � double.
	*
	* @return double - correspondant � la valeur d'alpha.
	*/
	operator double() const { return alpha; }
};