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

bool testRotationDegree() {
	Vecteur2D u(4, 0), w(0,0);
	Degree theta(90);

	u = u.rotation(w, theta);
	if ((int) u.x == 0 && (int) u.y == 4)
		return true;
	
	return false;
}

bool testRotationRadian() {
	Vecteur2D u(4, 0), w(0, 0);
	Radian alpha(M_PI / 2);

	u = u.rotation(w, alpha);

	if ((int) u.x == 0 && (int) u.y == (double) 4)
		return true;

	return false;
}

bool testHomothetie() {
	Vecteur2D u(4, 2), v(0, 0);
	u = u.homothetie(v, 2);

	if ((int) u.x == 8 && (int) u.y == 4)
		return true;

	return false;
}

bool testDeterminant() {
	Vecteur2D u(2, 3), v(4, 5);
	double delta = determinant(u, v);

	if ((int)delta == -2)
		return true;

	return false;
}

int resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void sessionTestVecteur2D() {
	bool test;
	int score = 0;
	const int nbTests = 12;

	cout << "Début de la session de tests.." << endl << "Résultats : ";

	score += resultatTest(testOperatorPlus());
	score += resultatTest(testOperatorMoinsUnaire());
	score += resultatTest(testOperatorMoins());
	score += resultatTest(testOperatorFois());
	score += resultatTest(testOperatorFoisDoubleDroite());
	score += resultatTest(testOperatorFoisDoubleGauche());
	score += resultatTest(testOperatorString());
	score += resultatTest(testDistance());
	score += resultatTest(testRotationDegree());
	score += resultatTest(testRotationRadian());
	score += resultatTest(testHomothetie());
	score += resultatTest(testDeterminant());

	cout << endl << "Fin de la session de tests.." << endl;

	cout << endl << "Score : " << score << "/" << nbTests << endl;
}

int main() {
	sessionTestVecteur2D();

	return 0;
}