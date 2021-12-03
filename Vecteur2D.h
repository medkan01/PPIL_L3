#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
	Cette classe représente un vecteur, un point ou une coordonnées dans un espace en 2 dimensions
*/
class Vecteur2D {
public:
	// Attributs
	int x, y;

	// Constructeurs et destructeur
	/**
	* Constructeur de la classe Vecteur2D qui contruit un vecteur u(u1, u2).
	* 
	* @param x est la valeur de u1 dans le vecteur u(u1, u2)
	* @param y est la valeur de u2 dans le vecteur u(u1, u2)
	*/
	explicit Vecteur2D(int x = 0, int y = 0) : x(x), y(y) {}

	///	Destructeur de la classe Vecteur2D.
	virtual ~Vecteur2D() {}
	
	/**
	* Addtition de deux vecteurs u et v.
	* 
	* @param v le vecteur qui sera additionné avec le vecteur u actuel.
	* @return le vecteur résultant de l'addition des vecteurs u et v
	*/
	const Vecteur2D operator+(const Vecteur2D& v) const;

	/**
	* Soustraction de deux vecteurs u et v.
	*
	* @param v le vecteur qui sera soustrait avec le vecteur u actuel.
	* @return le vecteur résultant de l'addition des vecteurs u et v
	*/
	const Vecteur2D operator-() const;
	const Vecteur2D operator-(const Vecteur2D& v) const;
	operator string() const;

};

const Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const {

}

inline ostream& operator<<(ostream& s, const Vecteur2D& v) {
	return s << (string) v;
}