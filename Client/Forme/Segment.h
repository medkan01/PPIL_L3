#ifndef SEGMENT_H
#define SEGMENT_H

#include "Forme.h"
using namespace std;

/// Classe Segment, definie par un point A et B.
class Segment : public Forme {
public:
	Vecteur2D a, b;

	/**
	* Constructeur de la classe Segment.
	* 
	* @param c Couleur de la forme.
	* @param rep Repere de la forme.
	* @param vecA point a du segment.
	* @param vecB point b du segment.
	*/
	Segment(const Couleur& c = Couleur::BLACK, const Repere& rep = Repere(), const Vecteur2D& vecA = Vecteur2D(0, 0), const Vecteur2D& vecB = Vecteur2D(0, 0)) {
		couleur = c;
		Vecteur2D vecCentre = Vecteur2D((vecA.x + vecB.x) / 2, ((vecA.y + vecB.y) / 2));
		repere = rep;

		try {
			if (!rep.estDans(vecCentre) || !rep.estDans(vecA) || !rep.estDans(vecB))
				throw exception("La forme n'est pas dans le repere.");
			centre = vecCentre;
			a = vecA;
			b = vecB;
		}
		catch (exception e) {
			cout << endl << endl << e.what() << endl << endl;
		}
	}

	/// Destructeur de la classe segment
	virtual ~Segment() {}

	/**
	* Effectue une translation sur la forme.
	*
	* @param v Vecteur de translation
	*/
	virtual inline Segment translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothetie sur la forme. (zoom)
	*
	* @param pi Point invariant.
	* @param rh Rapport d'homothetie.
	*/
	virtual inline Segment homothetie(const Vecteur2D& pi, const double& rh) const;

	/**
	* Effectue une rotation sur la forme. A noter que dans la quasi-totalite du temps la rotation 
	* sera effectuee par rapport au centre de la forme.
	*
	* @param pi Point invariant. (centre de rotation)
	* @param alpha Angle de rotation. (en radian)
	*/
	virtual inline Segment rotation(const Vecteur2D& pi, const Radian& alpha) const;

	/**
	* Effectue une rotation sur la forme. A noter que dans la quasi-totalite du temps la rotation 
	* sera effectuee par rapport au centre de la forme.
	*
	* @param pi Point invariant. (centre de rotation)
	* @param theta Angle de rotation. (en radian)
	*/
	virtual inline Segment rotation(const Vecteur2D& pi, const Degree& theta) const;

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString vecteur courant.
	*/
	virtual inline operator string() const;

	/**
	* Clone une forme.
	*
	* @return Copie de la forme.
	*/
	virtual Forme* clone() const { return new Segment(*this); }

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const;
};

inline ostream& operator<<(ostream& os, const Segment& s) {
	return os << (string)s;
}

Segment Segment::translation(const Vecteur2D& v) const {
	return Segment(couleur, repere, a + v, b + v);
}

Segment Segment::homothetie(const Vecteur2D& pi, const double& rh) const {
	return Segment(couleur, repere, a.homothetie(pi, rh), b.homothetie(pi, rh));
}

Segment Segment::rotation(const Vecteur2D& pi, const Degree& angle) const {
	return Segment(couleur, repere, a.rotation(pi, angle), b.rotation(pi, angle));
}

Segment Segment::rotation(const Vecteur2D& pi, const Radian& angle) const {
	return Segment(couleur, repere, a.rotation(pi, angle), b.rotation(pi, angle));
}

Segment::operator string() const {
	return "segment/" + (string)a + "/" + (string)b + "/" + (string)couleur;
}

#endif