#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
	Cette classe repr�sente un vecteur, un point ou une coordonn�es dans un espace en 2 dimensions
*/
class Vecteur2D {
public:
	// Attributs
	int x, y;

	/**
	* Constructeur de la classe Vecteur2D qui contruit un vecteur u(u1, u2).
	*
	* @param x est la valeur de u1 dans le vecteur u(u1, u2).
	* @param y est la valeur de u2 dans le vecteur u(u1, u2).
	*/
	explicit Vecteur2D(int x = 0, int y = 0) : x(x), y(y) {}

	///	Destructeur de la classe Vecteur2D.
	virtual ~Vecteur2D() {}

	/**
	* Addtition de deux vecteurs u et v.
	*
	* @param v le vecteur qui sera additionn� avec le vecteur u courant.
	* @return le vecteur r�sultant de l'addition des vecteurs u et v.
	*/
	const Vecteur2D operator+(const Vecteur2D& v) const;

	/**
	* Op�rateur - unaire. Permet entre autre d'opposer un vecteur.
	*
	* @return l'oppos� du vecteur courant.
	*/
	const Vecteur2D operator-() const;

	/**
	* Soustraction de deux vecteurs u et v.
	*
	* @param v le vecteur qui sera soustrait avec le vecteur u courant.
	* @return le vecteur r�sultant de la soustraction des vecteurs u et v.
	*/
	const Vecteur2D operator-(const Vecteur2D& v) const;

	/**
	* Multiplication de deux vecteurs u et v.
	*
	* @param v le vecteur qui sera multipli� avec le vecteur u courant.
	* @return le vecteur r�sultant de la multiplication des vecteurs u et v.
	*/
	const Vecteur2D operator*(const Vecteur2D& v) const;

	/**
	* Multiplication d'un vecteur par un entier i.
	*
	* @param i l'entier qui sera multipli� avec le vecteur u courant.
	* @return le vecteur r�sultant de la multiplication de l'entier i et du vecteur u courant.
	*/
	const Vecteur2D operator*(const int& i) const;

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
	*
	* @return une chaine de caract�re correspondant au vecteur courant.
	*/
	operator string() const;

};

const Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const {
	return Vecteur2D(x + v.x, y + v.y);
}

const Vecteur2D Vecteur2D::operator-() const {
	return Vecteur2D(-x, -y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D& v) const {
	return Vecteur2D(x - v.x, y - v.y);
}

const Vecteur2D Vecteur2D::operator*(const Vecteur2D& v) const {
	return Vecteur2D(x * v.x, y * v.y);
}

const Vecteur2D Vecteur2D::operator*(const int& i) const {
	return Vecteur2D(x * i, y * i);
}

Vecteur2D::operator string() const {
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

inline ostream& operator<<(ostream& s, const Vecteur2D& v) {
	return s << (string)v;
}