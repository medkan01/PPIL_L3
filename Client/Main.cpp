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
using namespace std;

int main() {
	Vecteur2D a(50, 50), b(500, 200), c(200, 450);
	Vecteur2D d(50, 150), e(700, 400);
	Couleur noire("Noire");
	Couleur blanche("Blanche");
	Repere r(Vecteur2D(0,0), Vecteur2D(720, 480));

	Triangle t(noire, r, a, b, c);
	Segment s(blanche, r, d, e);
	
	VisiteurForme* v;
	v = new DessinerFormeJava;

	Client::instance().connexion();

	t.accepte(v);
	s.accepte(v);

	Client::instance().deconnexion();

	return 0;
}