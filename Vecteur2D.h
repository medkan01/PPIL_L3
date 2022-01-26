#pragma once
#include <string>
#include <iostream>
#include "Radian.h"
#include "Degree.h"
using namespace std;

/**
	Repr�sente un vecteur, un point ou une coordonn�es dans un espace en 2 dimensions
*/
class Vecteur2D {
public:
	// Attributs
	double x, y;

	/**
	* Constructeur de la classe Vecteur2D qui contruit un vecteur u(u1, u2).
	*
	* @param const double& x - valeur de u1 dans le vecteur u(u1, u2).
	* @param const double& y - valeur de u2 dans le vecteur u(u1, u2).
	*/
	explicit Vecteur2D(const double& x = 0, const double& y = 0) : 
		x(x), y(y) {}

	///	Destructeur de la classe Vecteur2D.
	virtual ~Vecteur2D() {}

	/**
	* Addtition de deux vecteurs u et v.
	*
	* @param const Vecteur2D& v - vecteur qui sera additionn� avec le vecteur u courant.
	* @return const Vecteur2D - vecteur r�sultant de l'addition des vecteurs u et v.
	*/
	inline const Vecteur2D operator+(const Vecteur2D& v) const;

	/**
	* Op�rateur - unaire. Permet entre autre d'opposer un vecteur.
	*
	* @return const Vecteur2D - oppos� du vecteur courant.
	*/
	inline const Vecteur2D operator-() const;

	/**
	* Soustraction de deux vecteurs u et v.
	*
	* @param const Vecteur2D& v - vecteur qui sera soustrait avec le vecteur u courant.
	* @return - le vecteur r�sultant de la soustraction des vecteurs u et v.
	*/
	inline const Vecteur2D operator-(const Vecteur2D& v) const;

	/**
	* Produit scalaire de deux vecteurs u et v.
	*
	* @param const Vecteur2D& v - vecteur qui r�sultera du produit scalaire avec le vecteur courant.
	* @return - produit scalaire de u . v.
	*/
	inline const double operator*(const Vecteur2D& v) const;

	/**
	* Multiplication d'un vecteur par un entier i.
	*
	* @param const double& i - entier qui sera multipli� avec le vecteur u courant.
	* @return const Vecteur2D - vecteur r�sultant de la multiplication de l'entier i et du vecteur u courant.
	*/
	inline const Vecteur2D operator*(const double& i) const;

	/**
	* Addtition de deux vecteurs u et v gr�ce � l'op�rateur +=.
	*
	* @param const Vecteur2D& v - vecteur qui sera additionn� avec le vecteur u courant.
	* @return const Vecteur2D - vecteur r�sultant de l'addition des vecteurs u et v.
	*/
	inline const Vecteur2D operator+=(const Vecteur2D& v);

	/**
	* Op�rateur de cast. Equivalent d'une m�thode toString().
	*
	* @return string - correspondant au vecteur courant.
	*/
	inline operator string() const;

	/**
	* Distance entre le vecteur u courant et un vecteur v.
	* 
	* @param const Vecteur2D v - le second vecteur permettant de calculer la distance.
	* @return const double - correspondant � la distance entre un vecteur v et le vecteur u courant.
	*/
	inline const double distance(const Vecteur2D& v) const;

	/**
	* Effectue une rotation vectorielle � partir d'un point de rotation R, du point concern� et d'un angle phi.
	* 
	* @param const Vecteur2D& R - Centre de rotation.
	* @param const Radian& phi - Angle de rotation en radian.
	* @return const Vecteur2D - Point apr�s rotation.
	*/
	inline virtual const Vecteur2D rotation(const Vecteur2D& R, const Radian& phi) const;

	/**
	* Effectue une rotation vectorielle � partir d'un point de rotation R, du point concern� et d'un angle phi.
	*
	* @param const Vecteur2D& R - Centre de rotation.
	* @param const Degree& phi - Angle de rotation en degr�e.
	* @return const Vecteur2D - Point apr�s rotation.
	*/
	inline virtual const Vecteur2D rotation(const Vecteur2D& R, const Degree& phi) const;

	/**
	* Effectue une homothetie vectorielle � partir d'un point invariant, du point concern� et d'un rapport a.
	*
	* @param const Vecteur2D& C - Point invariant.
	* @param const double& a - Rapport d'homothetie.
	* @return const Vecteur2D - Point apr�s homothetie.
	*/
	inline virtual const Vecteur2D homothetie(const Vecteur2D& C, const double& a) const;

	/**
	* D�terminant d'un couple de vecteur.
	*
	* @param const Vecteur2D& u - vecteur u.
	* @param cosnt Vecteur2D& v - vecteur v.
	* @return const double - valeur du d�terminant du couple de vecteurs u et v.
	*/
	friend const double determinant(const Vecteur2D& u, const Vecteur2D& v);

	/**
	* Clone un vecteur.
	* 
	* @return Vecteur2D* - Copie du vecteur.
	*/
	virtual Vecteur2D* clone() const { return new Vecteur2D(*this); }

	/**
	* Multiplication d'un vecteur par un entier i.
	*
	* @param const double& i - entier qui sera multipli� avec le vecteur u courant.
	* @param const Vecteur2D& v - Vecteur qui va �tre multipli�.
	* @return const Vecteur2D - vecteur r�sultant de la multiplication de l'entier i et du vecteur u courant.
	*/
	friend const Vecteur2D operator *(const double& i, const Vecteur2D& v);
};

const Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const {
	return Vecteur2D(x + v.x, y + v.y);
}

const Vecteur2D Vecteur2D::operator-() const {
	return Vecteur2D(-x, -y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D& v) const {
	return Vecteur2D(x + (- v.x), y + (- v.y));
}

const double Vecteur2D::operator*(const Vecteur2D& v) const {
	return x * v.x + y * v.y;
}

const Vecteur2D Vecteur2D::operator*(const double& i) const {
	return Vecteur2D(x * i, y * i);
}

Vecteur2D::operator string() const {
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

const double Vecteur2D::distance(const Vecteur2D& v) const {
	return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
}

inline ostream& operator<<(ostream& os, const Vecteur2D& v) {
	return os << (string)v;
}

const Vecteur2D Vecteur2D::rotation(const Vecteur2D& R, const Radian& phi) const {
	Vecteur2D v = *this;
	v.x = x * cos(phi) - y * sin(phi);
	v.y = x * sin(phi) + y * cos(phi);

	return v;
}

const Vecteur2D Vecteur2D::rotation(const Vecteur2D& R, const Degree& phi) const {
	Vecteur2D v = *this;
	v.x = x * cos(phi.toRadian()) - y * sin(phi.toRadian());
	v.y = x * sin(phi.toRadian()) + y * cos(phi.toRadian());

	return v;
}

const Vecteur2D Vecteur2D::homothetie(const Vecteur2D& C, const double& a) const {
	Vecteur2D v = *this;
	v.x = a * (x - C.x) + C.x;
	v.y = a * (y - C.y) + C.y;

	return v;
}

const double determinant(const Vecteur2D& u, const Vecteur2D& v) {
	return (u.x * v.y) - (u.y * v.x);
}

const Vecteur2D operator *(const double& k, const Vecteur2D& v) {
	Vecteur2D t = v;
	t.x = t.x * k;
	t.y = t.y * k;

	return t;
}

const Vecteur2D Vecteur2D::operator+=(const Vecteur2D& v) {
	*this = *this + v;
	return *this;
}