#pragma once
#include "Forme.h"
using namespace std;

/// Classe Segment, définie par un point A et B.
class Segment : public Forme {
public:
	Vecteur2D a, b;

	/**
	* Constructeur de la classe Segment.
	* 
	* @param const Couleur& couleur - Couleur de la forme
	* @param const Vecteur2D& a - point a du segment
	* @param const Vecteur2D& b - point b du segment
	*/
	Segment(const Couleur& couleur = Couleur("Noire"), const Vecteur2D & a = Vecteur2D(0, 0) , const Vecteur2D & b = Vecteur2D(0, 0)) : Forme(couleur, Vecteur2D((a.x + b.x) / 2, (a.y + b.y) / 2)), a(a), b(b) {}

	/**
	* Effectue une translation sur la forme.
	*
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	virtual inline Segment translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothétie sur la forme. (zoom)
	*
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homothétie.
	*/
	virtual inline Segment homothetie(const Vecteur2D& pi, const double& rh) const;

	/**
	* Effectue une rotation sur la forme. A noter que dans la quasi-totalité du temps la rotation 
	* sera effectuée par rapport au centre de la forme.
	*
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const Radian& alpha - Angle de rotation. (en radian)
	*/
	virtual inline Segment rotation(const Vecteur2D& pi, const Radian& alpha) const;

	/**
	* Effectue une rotation sur la forme. A noter que dans la quasi-totalité du temps la rotation 
	* sera effectuée par rapport au centre de la forme.
	*
	* @param const Vecteur2D& pi - Point invariant. (centre de rotation)
	* @param const Degree& theta - Angle de rotation. (en radian)
	*/
	virtual inline Segment rotation(const Vecteur2D& pi, const Degree& theta) const;

	/**
	* Opérateur de cast. Equivalent d'une méthode toString().
	*
	* @return string - vecteur courant.
	*/
	virtual inline operator string() const;

	/**
	* Clone une forme.
	*
	* @return Forme* - Copie de la forme.
	*/
	virtual Forme* clone() const { return new Segment(*this); }
};

inline ostream& operator<<(ostream& os, const Segment& s) {
	return os << (string)s;
}

Segment Segment::translation(const Vecteur2D& v) const {
	return Segment(couleur, a + v, b + v);
}

Segment Segment::homothetie(const Vecteur2D& pi, const double& rh) const {
	return Segment(couleur, a.homothetie(pi, rh), b.homothetie(pi, rh));
}

Segment Segment::rotation(const Vecteur2D& pi, const Degree& angle) const {
	return Segment(couleur, a.rotation(pi, angle), b.rotation(pi, angle));
}

Segment Segment::rotation(const Vecteur2D& pi, const Radian& angle) const {
	return Segment(couleur, a.rotation(pi, angle), b.rotation(pi, angle));
}

Segment::operator string() const {
	return "segment/" + (string)a + "/" + (string)b + "/" + (string)couleur;
}