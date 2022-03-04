#pragma once
#include <stdio.h>
#include "TCPIP/Client.h"
#include "Visitor/DessinerFormeJava.h"
#include "Forme/Cercle.h"
#include "Forme/Polygone.h"
#include "Tests/SessionTests.h"
using namespace std;

/*
int main() {
	const Couleur noire = Couleur::BLACK;
	const Couleur rouge = Couleur::RED;

	const Repere r(Vecteur2D(-1, -1), Vecteur2D(11, 7));

	Cercle oeil1(noire, r, Vecteur2D(3, 5), 1), oeil2(noire, r, Vecteur2D(7, 5), 1);
	Cercle iris1(noire, r, Vecteur2D(2.5, 5), 0.2), iris2(noire, r, Vecteur2D(6.5, 5), 0.2);
	Triangle nez(rouge, r, Vecteur2D(4.5, 3.5), Vecteur2D(5.5, 3.5), Vecteur2D(5, 4));
	Segment s1(noire, r, Vecteur2D(2, 2.5), Vecteur2D(3, 1.5));
	Segment s2(noire, r, Vecteur2D(3, 1.5), Vecteur2D(4.5, 1));
	Segment s3(noire, r, Vecteur2D(4.5, 1), Vecteur2D(5.5, 1));
	Segment s4(noire, r, Vecteur2D(5.5, 1), Vecteur2D(7, 1.5));
	Segment s5(noire, r, Vecteur2D(7, 1.5), Vecteur2D(8, 2.5));
	Segment s6(noire, r, Vecteur2D(2, 2.5), Vecteur2D(8, 2.5));

	Vecteur2D a(2, 2.5), b(3, 1.5), c(4.5, 1), d(5.5, 1), e(7, 1.5), f(8, 2.5);
	vector<Vecteur2D> lp;
	lp.push_back(a);
	lp.push_back(b);
	lp.push_back(c);
	lp.push_back(d);
	lp.push_back(e);
	lp.push_back(f);

	Polygone sourire(noire, r, lp);

	GroupeFormes yeux = GroupeFormes(Couleur::CYAN);
	yeux.ajouterForme(&oeil1);
	yeux.ajouterForme(&oeil2);
	yeux.ajouterForme(&iris1);
	yeux.ajouterForme(&iris2);

	sourire = sourire.rotation(sourire.centre, Radian(M_PI));

	VisiteurForme* v;
	v = new DessinerFormeJava;

	Client::instance().connexion();

	yeux.accepte(v);
	nez.accepte(v);
	sourire.accepte(v);
	sourire = sourire.homothetie(sourire.centre, 1.1);
	sourire.accepte(v);

	Client::instance().deconnexion();

	return 0;
}
*/

int main() {
	sessionTests();
}