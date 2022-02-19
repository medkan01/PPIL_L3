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
	
	

	const Couleur noire("Noire");
	const Couleur blanche("Blanche");
	const Repere r(Vecteur2D(0, 0), Vecteur2D(11, 7));

	const Cercle oeil1(noire, r, Vecteur2D(3, 5), Vecteur2D(4, 5)), oeil2(noire, r, Vecteur2D(7, 5), Vecteur2D(8, 5));
	const Triangle nez(noire, r, Vecteur2D(5, 4), Vecteur2D(5, 3), Vecteur2D(4.5, 3.5));


	VisiteurForme* v;
	v = new DessinerFormeJava;

	Client::instance().connexion();

	oeil1.accepte(v);
	oeil2.accepte(v);
	nez.accepte(v);

	Client::instance().deconnexion();

	return 0;
}