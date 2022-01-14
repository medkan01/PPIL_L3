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

	return false;
}

bool testOperatorFoisDoubleDroite() {

	return false;
}

bool testOperatorFoisDoubleGauche() {

	return false;
}

bool testOperatorString() {

	return false;
}

bool testDistance() {

	return false;
}

bool testRotation() {

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

	cout << endl;
}

int main() {
	sessionTestVecteur2D();
	return 0;
}