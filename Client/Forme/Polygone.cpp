#include "Polygone.h"
#include "../Visitor/VisiteurForme.h"

void Polygone::ajouterPoint(const Vecteur2D& p) {
	points.push_back(p);
	points = tri_fusion(points);
	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
}

Polygone::Polygone(const Couleur& c, const Repere& r, const vector<Vecteur2D>& listePoints) {
	couleur = c;
	repere = r;

	vector<Vecteur2D>::const_iterator it;
	for (it = listePoints.begin(); it != listePoints.end(); it++)
		ajouterPoint(*it);

	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
}

Polygone::Polygone(const Polygone& p) {
	couleur = p.couleur;
	repere = p.repere;

	vector<Vecteur2D>::const_iterator it;
	for (it = p.points.begin(); it != p.points.end(); it++)
		ajouterPoint(*it);

	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
}

Polygone::Polygone() {
	couleur = Couleur::BLACK;
	repere = Repere();

	Vecteur2D a(0, 0), b(5, 0), c(5, 5), d(0, 5);

	ajouterPoint(a);
	ajouterPoint(b);
	ajouterPoint(c);
	ajouterPoint(d);

	centre = Vecteur2D(abcisseCentre(), ordonneeCentre());
}

Polygone::~Polygone() {
	points.clear();
}

void Polygone::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }

Polygone::operator string() const {
	return "Polygone[ " + (string)couleur + " - Repere[" + (string)repere + "]]";
}

const double Polygone::abcisseCentre() const {
	double x = 0, aireT = aire();
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++) {
		x += (points[i].x + points[(i + 1) % points.size()].x) * determinant(points[i], points[(i + 1) % points.size()]);
	}

	x = x / (6 * aireT);

	return x;
}

const double Polygone::ordonneeCentre() const {
	double y = 0, aireT = aire();
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++) {
		y += (points[i].y + points[(i + 1) % points.size()].y) * (determinant(points[i], points[(i + 1) % points.size()]));
	}

	y = y / (6 * aireT);

	return y;
}

const double Polygone::aire() const {
	double aire = 0;
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++)
		aire += determinant(points[i], points[(i + 1) % points.size()]);

	aire = aire / 2;

	return aire;
}

const Polygone Polygone::translation(const Vecteur2D& v) const {
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++)
		points[i] = points[i] + v;

	return Polygone(couleur, repere, points);
}

const Polygone Polygone::homothetie(const Vecteur2D& C, const double& k) const {
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++)
		points[i] = points[i].homothetie(C, k);

	return Polygone(couleur, repere, points);
}

const Polygone Polygone::rotation(const Vecteur2D& R, const Degree& theta) const {
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++)
		points[i] = points[i].rotation(R, theta);

	return Polygone(couleur, repere, points);
}

const Polygone Polygone::rotation(const Vecteur2D& R, const Radian& alpha) const {
	vector<Vecteur2D> points = getPoints();

	for (int i = 0; i < points.size(); i++)
		points[i] = points[i].rotation(R, alpha);

	return Polygone(couleur, repere, points);
}