#pragma once
#include <stdio.h>
#include "Tests/TestVecteur2D.h"
#include "Tests/TestRepere.h"
#include "Tests/TestRadian.h"
#include "Tests/TestDegree.h"
#include "Tests/TestSegment.h"
#include "Tests/TestTriangle.h"
#include "TCPIP/Client.h"
#include "Visitor/DessinerFormeJava.h"
#include "Forme/Cercle.h"
using namespace std;

int main() {
	const Vecteur2D a(4, 7), b(6, 7), c(5,7);
	const Vecteur2D d(4.5, 6), e(4.5, 2);
	const Vecteur2D f(6.5, 6), g(6.5, 2);
	const Vecteur2D h(5, 2), i(6, 2);

	const Couleur noire("Noire");
	const Couleur blanche("Blanche");
	const Repere r(Vecteur2D(0, 0), Vecteur2D(11, 7));

	const Cercle c1(noire, r, a, c), c2(noire, r, b, c), c3(noire, r, h, i);
	const Segment s1(noire, r, d, e), s2(noire, r, f, g);

	VisiteurForme* v;
	v = new DessinerFormeJava;

	Client::instance().connexion();

	c1.accepte(v);
	c2.accepte(v);
	c3.accepte(v);

	s1.accepte(v);
	s2.accepte(v);

	Client::instance().deconnexion();

	return 0;
}