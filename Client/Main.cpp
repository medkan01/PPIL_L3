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
	const Repere r(Vecteur2D(-1, -1), Vecteur2D(11, 7));

	const Cercle oeil1(noire, r, Vecteur2D(3, 5), 1), oeil2(noire, r, Vecteur2D(7, 5), 1);
	const Cercle iris1(noire, r, Vecteur2D(2.5, 5), 0.2), iris2(noire, r, Vecteur2D(6.5, 5), 0.2);
	const Triangle nez(noire, r, Vecteur2D(4.5, 3.5), Vecteur2D(5.5, 3.5), Vecteur2D(5, 4));
	const Segment s1(noire, r, Vecteur2D(2,2.5), Vecteur2D(3,1.5));
	const Segment s2(noire, r, Vecteur2D(3,1.5), Vecteur2D(4.5,1));
	const Segment s3(noire, r, Vecteur2D(4.5,1), Vecteur2D(5.5,1));
	const Segment s4(noire, r, Vecteur2D(5.5,1), Vecteur2D(7,1.5));
	const Segment s5(noire, r, Vecteur2D(7,1.5), Vecteur2D(8,2.5));
	const Segment s6(noire, r, Vecteur2D(2, 2.5), Vecteur2D(8, 2.5));
	const Cercle visage(noire, r, Vecteur2D(5, 5), 4);
	


	VisiteurForme* v;
	v = new DessinerFormeJava;

	Client::instance().connexion();
	// for (int i = 0; i < 11; i++) {
	// 	Segment(noire, r, Vecteur2D(i, 0), Vecteur2D(i, 7)).accepte(v);
	// 	for (int j = 0; j < 7; j++) {
	// 		Segment(noire, r, Vecteur2D(0, j), Vecteur2D(11, j)).accepte(v);
	// 	}
	// }

	oeil1.accepte(v);
	oeil2.accepte(v);
	iris1.accepte(v);
	iris2.accepte(v);
	nez.accepte(v);
	s1.accepte(v);
	s2.accepte(v);
	s3.accepte(v);
	s4.accepte(v);
	s5.accepte(v);
	s6.accepte(v);
	visage.accepte(v);

	Client::instance().deconnexion();

	return 0;
}