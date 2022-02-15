#ifndef REPERE_H
#define REPERE_H

#include "Vecteur2D.h"

class Repere {
public:
	Vecteur2D p1, p2;

	/**
	* Constructeur de la classe Repere.
	* 
	* @param a Premier point de la diagonale du repere.
	* @param b Deuxieme point de la diagonale du repere.
	*/
	Repere(const Vecteur2D& a, const Vecteur2D& b) { 
		p1 = a;
		p2 = b;
	}

	/**
	* Constructeur par defaut de la classe Repere.
	*/
	Repere() { p1 = Vecteur2D(-20, -20); p2 = Vecteur2D(20, 20); }

	/// Destructeur de la classe Repere.
	virtual ~Repere() {}

	/**
	* Permet de recuperer un string du repere.
	* 
	* @return String representant le repere.
	*/
	operator string() const { return p1 + ";" + p2; }

	/**
	* Permet de savoir si le vecteur v est inclu dans le repere.
	* 
	* @param v Vecteur a tester.
	* @return True si la vecteur est dans le repere. False sinon.
	*/
	inline bool estDans(const Vecteur2D& v) const;
};

bool Repere::estDans(const Vecteur2D& v) const {
	return v.x >= p1.x && v.y >= p1.y && v.x <= p2.x && v.y <= p2.y;
}

#endif