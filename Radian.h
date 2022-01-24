#include <iostream>
using namespace std;

/**
* Un radian est défini par un double.
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
	* Fonction renvoyant une approximation de la valeur de pi.
	* 
	* @return double - approximation de pi.
	*/
	friend const double pi();
};

const double pi() {
	double pi = 0;
	for (int i = 1; i < 10000000; i += 2) {
		if (i % 4 == 1)
			pi += 1.0 / i;
		else if (i % 4 == 3)
			pi -= 1.0 / i;
	}
	return (double)4 * pi;
}