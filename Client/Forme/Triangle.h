#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Forme.h"
using namespace std;

/**
* Represente un triangle defini par une couleur, un vecteur d'origine a et deux autres vecteurs b et c.
* Par exemple, dans le triangle ABC, A est l'origine. Entre autre, le triangle sera donc defini par AB et AC.
*/
class Triangle : public Forme {
	/**
	* Retourne l'abcisse du centre.
	* 
	* @return abcisse du centre du triangle.
	*/
	inline const double abcisseCentre() const;

	/**
	* Retourne l'ordonnee du centre.
	* 
	* @return ordonnee du centre du triangle.
	*/
	inline const double ordonneeCentre() const;
public:
	Vecteur2D a, b, c;
	/**
	* Constructeur de la classe Triangle qui construit un triangle ABC d'une couleur donnee.
	* 
	* @param couleurTriangle Couleur du triangle.
	* @param rep Repere de la forme.
	* @param pa Origine du triangle ABC.
	* @param pb Point B du triangle ABC.
	* @param pc Point C du triangle ABC.
	*/
	inline Triangle(const Couleur& couleurTriangle, const Repere& rep, const Vecteur2D& pa, const Vecteur2D& pb, const Vecteur2D& pc);

	/// Destructeur de la classe triangle
	virtual ~Triangle() {}

	/**
	* Determine l'aire du triangle.
	*
	* @return aire du triangle.
	*/
	inline const double aire() const;

	/**
	* Effectue une translation sur la forme.
	*
	* @param v Vecteur de translation
	*/
	inline virtual const Triangle translation(const Vecteur2D& v) const;

	/**
	* Effectue une homothetie sur la forme. (zoom)
	* Calcule d'une homothetie : 
	* OM' = k(OM OC) + OC
	* M' = k * (M C) + C
	*
	* @param C Point invariant.
	* @param k Rapport d'homothetie.
	*/
	inline virtual const Triangle homothetie(const Vecteur2D& C, const double& k) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param R Point invariant. (centre de rotation)
	* @param theta Angle de rotation. (en degree)
	*/
	inline virtual const Triangle rotation(const Vecteur2D& R, const Degree& theta) const;

	/**
	* Effectue une rotation sur la forme.
	*
	* @param R Point invariant. (centre de rotation)
	* @param alpha Angle de rotation. (en radian)
	*/
	inline virtual const Triangle rotation(const Vecteur2D& R, const Radian& alpha) const;

	/**
	* Clone un triangle.
	* 
	* @return Copie du triangle
	*/
	inline virtual Forme* clone() const;

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString du vecteur courant.
	*/
	inline virtual operator string() const;

	/**
	* Methode visitor pour ajouter des fonctionnalites oublies.
	*/
	virtual void accepte(VisiteurForme* visiteur) const;
};

const double Triangle::abcisseCentre() const {
	double x = 0, aireT = aire();;
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		x += (points[i].x + points[(i + 1) % 3].x) * determinant(points[i], points[(i + 1) % 3]);
	}

	x = x / (6 * aireT);

	return x;
}

const double Triangle::ordonneeCentre() const {
	double y = 0, aireT = aire();
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		y += (points[i].y + points[(i + 1) % 3].y) * (determinant(points[i], points[(i + 1) % 3]));
	}

	y = y / (6 * aireT);

	return y;
}

Triangle::Triangle(const Couleur& couleurTriangle, const Repere& rep, const Vecteur2D& pa, const Vecteur2D& pb, const Vecteur2D& pc) {
	a = pa;
	b = pb;
	c = pc;
	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
	couleur = couleurTriangle;
	repere = rep;
}


const double Triangle::aire() const {
	double aire = 0;
	Vecteur2D points[3] = { a, b, c };

	for (int i = 0; i < 3; i++) {
		aire += determinant(points[i], points[(i + 1) % 3]);
	}

	aire = aire / 2;

	return aire;
}

const Triangle Triangle::translation(const Vecteur2D& v) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa + v;
	pb = pb + v;
	pc = pc + v;

	return Triangle(couleur, repere, pa, pb, pc);
}

const Triangle Triangle::homothetie(const Vecteur2D& C, const double& k) const {
	Vecteur2D pa = a, pb = b, pc = c;
	
	pa = pa.homothetie(C, k);
	pb = pb.homothetie(C, k);
	pc = pc.homothetie(C, k);

	return Triangle(couleur, repere, pa, pb, pc);
}

const Triangle Triangle::rotation(const Vecteur2D& R, const Degree& theta) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa.rotation(R, theta);
	pb = pb.rotation(R, theta);
	pc = pc.rotation(R, theta);

	return Triangle(couleur, repere, pa, pb, pc);
}

const Triangle Triangle::rotation(const Vecteur2D& R, const Radian& alpha) const {
	Vecteur2D pa = a, pb = b, pc = c;

	pa = pa.rotation(R, alpha);
	pb = pb.rotation(R, alpha);
	pc = pc.rotation(R, alpha);

	return Triangle(couleur, repere, pa, pb, pc);
}

Triangle::operator string() const {
	return "triangle/" + (string)a + "/" + (string) b + "/" + (string) c + "/" + (string) couleur;
}

Forme* Triangle::clone() const {
	return new Triangle(*this);
}

inline ostream& operator<<(ostream& os, const Triangle& t) {
	return os << (string)t;
}

#endif