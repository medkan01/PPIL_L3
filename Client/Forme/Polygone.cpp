#include "Polygone.h"
#include "../Visitor/VisiteurForme.h"

void Polygone::ajouterPoint(const Vecteur2D& p) {
	points.push_back(p);
	points = tri_fusion(points);
}

Polygone::Polygone(const Couleur& c, const Repere& r, const vector<Vecteur2D>& listePoints) {
	couleur = c;
	repere = r;

	vector<Vecteur2D>::const_iterator it;
	for (it = listePoints.begin(); it != listePoints.end(); it++)
		ajouterPoint(Vecteur2D(*it));
}

Polygone::Polygone(const Polygone& p) {
	couleur = p.couleur;
	repere = p.repere;

	vector<Vecteur2D>::const_iterator it;
	for (it = p.points.begin(); it != p.points.end(); it++)
		ajouterPoint(Vecteur2D(*it));
}

Polygone::Polygone() {
	couleur = Couleur::BLACK;
	repere = Repere();

	Vecteur2D a(0, 0), b(5, 0), c(5, 5), d(0, 5);

	ajouterPoint(a);
	ajouterPoint(b);
	ajouterPoint(c);
	ajouterPoint(d);
}

Polygone::~Polygone() {
	points.clear();
}

void Polygone::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }

Polygone::operator string() const {
	return "Polygone[ " + (string)couleur + " - Repere[" + (string)repere + "]]";
}
