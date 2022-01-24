#pragma once
#include "Vecteur2D.h"
using namespace std;

bool testOperatorPlus() {
	Vecteur2D u(1, 3), v(3, 2), w = u +v;

	if (w.x == 4 && w.y == 5)
		return true;

	return false;
}

bool testOperatorMoinsUnaire() {
	Vecteur2D u(1, 3), v = -u;
	if (v.x == -1 && v.y == -3)
		return true;

	return false;
}

bool testOperatorMoins() {
	Vecteur2D u(1, 3), v(3, 2), w = u - v;

	if (w.x == -2 && w.y == 1)
		return true;

	return false;
}

bool testOperatorFois() {
	Vecteur2D u(1, 3), v(3, 2);
	double ps = u * v;

	if (ps == 9)
		return true;

	return false;
}

bool testOperatorFoisDoubleDroite() {
	Vecteur2D u(1, 3), v = 3*u;

	if (v.x == 3 && v.y == 9)
		return true;

	return false;
}

bool testOperatorFoisDoubleGauche() {
	Vecteur2D u(1, 3), v = u * 3;

	if (v.x == 3 && v.y == 9)
		return true;

	return false;
}

bool testOperatorString() {
	Vecteur2D u(1, 3);

	if ((string)u == "(1.000000, 3.000000)")
		return true;

	return false;
}

bool testDistance() {
	Vecteur2D u(1, 3), v(3, 3);

	if (u.distance(v) == 2)
		return true;

	return false;
}

bool testRotation() {
	Vecteur2D u(4, 0), v(0, 0);
	
	
	return false;
}

bool testHomothetie() {

	return false;
}

bool testDeterminant() {

	return false;
}

bool testClone() {

	return false;
}

void resultatTest(const bool& test) {
	if (test)
		cout << ".";
	else
		cout << "x";
}

void sessionTestVecteur2D() {
	cout << "Lancement des tests.." << endl << "Résultats : ";

	resultatTest(testOperatorPlus());
	resultatTest(testOperatorMoinsUnaire());
	resultatTest(testOperatorMoins());
	resultatTest(testOperatorFois());
	resultatTest(testOperatorFoisDoubleDroite());
	resultatTest(testOperatorFoisDoubleGauche());
	resultatTest(testOperatorString());
	resultatTest(testDistance());
	resultatTest(testRotation());
	resultatTest(testHomothetie());
	resultatTest(testDeterminant());
	resultatTest(testClone());

	cout << endl;
}

/*
int main() {
	sessionTestVecteur2D();
	return 0;
}
*/