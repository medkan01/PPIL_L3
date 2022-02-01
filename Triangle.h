#pragma once
#include "Forme.h"
using namespace std;

/**
* Représente un triangle défini par une couleur, un vecteur d'origine a et deux autres vecteurs b et c.
* Par exemple, dans le triangle ABC, A est l'origine. Entre autre, le triangle sera donc défini par AB et AC.
*/
class Triangle : public Forme {
	Vecteur2D a, b, c;
	/**
	* Retourne l'abcisse du centre.
	* 
	* @return const double - abcisse du centre du triangle.
	*/
	const double abcisseCentre() const;

	/**
	* Retourne l'ordonnée du centre.
	* 
	* @return const double - ordonnée du centre du triangle.
	*/
	const double ordonneeCentre() const;
public:
	/**
	* Constructeur de la classe Triangle qui construit un triangle ABC d'une couleur donnée.
	* 
	* @param const Couleur& couleur - couleur du triangle.
	* @param const Vecteur2D& a - origine du triangle abc.
	* @param const Vecteur2D& b - vecteur AB du triangle ABC.
	* @param const Vecteur2D& c - vecteur AC du triangle ABC.
	*/
	inline Triangle(const Couleur& couleur, const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c);

	/**
	* Détermine l'aire du triangle.
	*
	* @return const double - aire du triangle.
	*/
	inline const double aire() const;

	/**
	* Effectue une translation sur la forme.
	*
	* @param const Vecteur2D& v - Vecteur de translation
	*/
	inline virtual const Triangle translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothétie sur la forme. (zoom)
	* Calcule d'une homothetie : 
	* OM' = k(OM - OC) + OC
	* M' = k * (M - C) + C
	*
	* @param const Vecteur2d& - Point invariant.
	* @param const double& - Rapport d'homothétie.
	*/
	inline virtual const Triangle homothetie(const Vecteur2D& C, const double& k) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param const Vecteur2D& R - Point invariant. (centre de rotation)
	* @param const Degree& theta - Angle de rotation. (en degrée)
	*/
	inline virtual const Triangle rotation(const Vecteur2D& R, const Degree& theta) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param const Vecteur2D& R - Point invariant. (centre de rotation)
	* @param const Radian& alpha - Angle de rotation. (en radian)
	*/
	inline virtual const Triangle rotation(const Vecteur2D& R, const Radian& alpha) const;

	/**
	* Clone un triangle.
	* 
	* @return Forme* - Copie du triangle
	*/
	inline virtual Forme* clone() const;

	/**
	* Opérateur de cast. Equivalent d'une méthode toString().
	*
	* @return string - vecteur courant.
	*/
	inline virtual operator string() const;
};

const double Triangle::abcisseCentre() const {
	double x = 0;
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		x += (points[i].x + points[(i + 1) % 3].x) * (determinant(points[i], points[(i + 1) % 3]));
	}

	return x / (6 * aire());
}

const double Triangle::ordonneeCentre() const {
	double y = 0;
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		y += (points[i].y + points[(i + 1) % 3].y) * (determinant(points[i], points[(i + 1) % 3]));
	}

	return y / (6 * aire());
}

Triangle::Triangle(const Couleur& couleurTriangle, const Vecteur2D& pa, const Vecteur2D& pb, const Vecteur2D& pc) {
	a = pa;
	b = pb;
	c = pc;
	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
	couleur = couleurTriangle;
}


const double Triangle::aire() const {
	double aire = 0;
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		aire += determinant(points[i], points[(i + 1) % 3]);
	}

	return aire / 2;
}

const Triangle Triangle::translation(const Vecteur2D& v) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa + v;
	pb = pb + v;
	pc = pc + v;

	cout << pa << endl;
	cout << pb << endl;
	cout << pc << endl;

	Triangle t(couleur, pa, pb, pc);

	cout << t.centre << endl;

	return t;
}

const Triangle Triangle::homothetie(const Vecteur2D& C, const double& k) const {
	Vecteur2D pa = a, pb = b, pc = c;
	
	pa = pa.homothetie(C, k);
	pb = pb.homothetie(C, k);
	pc = pb.homothetie(C, k);

	return Triangle(couleur, pa, pb, pc);
}

const Triangle Triangle::rotation(const Vecteur2D& R, const Degree& theta) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa.rotation(R, theta);
	pb = pb.rotation(R, theta);
	pc = pb.rotation(R, theta);

	return Triangle(couleur, pa, pb, pc);
}

const Triangle Triangle::rotation(const Vecteur2D& R, const Radian& alpha) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa.rotation(R, alpha);
	pb = pb.rotation(R, alpha);
	pc = pb.rotation(R, alpha);

	return Triangle(couleur, pa, pb, pc);
}

Triangle::operator string() const {
	return "[Triangle: A" + (string)a + " - B" + (string) b + " - C" + (string) c + " - " + (string) couleur + "]";
}

Forme* Triangle::clone() const {
	return new Triangle(*this);
}

inline ostream& operator<<(ostream& os, const Triangle& t) {
	return os << (string)t;
}