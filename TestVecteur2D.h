#pragma once
#include "Vecteur2D.h"
using namespace std;

class TestVecteur2D {
public:
	/**
	* Test de l'opérateur +.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorPlus();

	/**
	* Test de l'opérateur - unaire.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorMoinsUnaire();

	/**
	* Test de l'opérateur -.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorMoins();

	/**
	* Test de l'opérateur *.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorFois();

	/**
	* Test de l'opérateur * avec un double en tant qu'opérande droite.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorFoisDoubleDroite();

	/**
	* Test de l'opérateur * avec un double en tant qu'opérande gauche.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorFoisDoubleGauche();

	/**
	* Test de l'opérateur string (cast).
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testOperatorString();

	/**
	* Test de la méthode distance.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testDistance();

	/**
	* Test de la méthode rotation avec les degrées.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testRotationDegree();

	/**
	* Test de la méthode rotation avec les radians.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testRotationRadian();

	/**
	* Test de la méthode homothetie.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testHomothetie();

	/**
	* Test de la fonction amie determinant.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testDeterminant();

	/**
	* Affiche le résultat du test.
	*
	* @param const bool& test - Test à réaliser.
	*/
	inline static int resultatTest(const bool&);

	/// Lance une session de test pour la classe Vecteur2D et affiche les résultats des différents tests.
	inline static void sessionTest();

};

bool TestVecteur2D::testOperatorPlus() {
	Vecteur2D u(1, 3), v(3, 2), w = u + v;

	if (w.x == 4 && w.y == 5)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorMoinsUnaire() {
	Vecteur2D u(1, 3), v = -u;
	if (v.x == -1 && v.y == -3)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorMoins() {
	Vecteur2D u(1, 3), v(3, 2), w = u - v;

	if (w.x == -2 && w.y == 1)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorFois() {
	Vecteur2D u(1, 3), v(3, 2);
	double ps = u * v;

	if (ps == 9)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorFoisDoubleDroite() {
	Vecteur2D u(1, 3), v = 3 * u;

	if (v.x == 3 && v.y == 9)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorFoisDoubleGauche() {
	Vecteur2D u(1, 3), v = u * 3;

	if (v.x == 3 && v.y == 9)
		return true;

	return false;
}

bool TestVecteur2D::testOperatorString() {
	Vecteur2D u(1, 3);

	if ((string)u == "(1.000000, 3.000000)")
		return true;

	return false;
}

bool TestVecteur2D::testDistance() {
	Vecteur2D u(1, 3), v(3, 3);

	if (u.distance(v) == 2)
		return true;

	return false;
}

bool TestVecteur2D::testRotationDegree() {
	Vecteur2D u(4, 0), w(0, 0);
	Degree theta(90);

	u = u.rotation(w, theta);
	if ((int)u.x == 0 && (int)u.y == 4)
		return true;

	return false;
}

bool TestVecteur2D::testRotationRadian() {
	Vecteur2D u(4, 0), w(0, 0);
	Radian alpha(M_PI / 2);

	u = u.rotation(w, alpha);

	if ((int)u.x == 0 && (int)u.y == (double)4)
		return true;

	return false;
}

bool TestVecteur2D::testHomothetie() {
	Vecteur2D u(4, 2), v(0, 0);
	u = u.homothetie(v, 2);

	if ((int)u.x == 8 && (int)u.y == 4)
		return true;

	return false;
}

bool TestVecteur2D::testDeterminant() {
	Vecteur2D u(2, 3), v(4, 5);
	double delta = determinant(u, v);

	if ((int)delta == -2)
		return true;

	return false;
}

int TestVecteur2D::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestVecteur2D::sessionTest() {
	int score = 0;
	int nbTests = 0;

	cout << endl << "Début de la session de tests pour la classe Vecteur2D.." << endl << "Résultats : ";

	score += resultatTest(testOperatorPlus()); nbTests++;
	score += resultatTest(testOperatorMoinsUnaire()); nbTests++;
	score += resultatTest(testOperatorMoins()); nbTests++;
	score += resultatTest(testOperatorFois()); nbTests++;
	score += resultatTest(testOperatorFoisDoubleDroite()); nbTests++;
	score += resultatTest(testOperatorFoisDoubleGauche()); nbTests++;
	score += resultatTest(testOperatorString()); nbTests++;
	score += resultatTest(testDistance()); nbTests++;
	score += resultatTest(testRotationDegree()); nbTests++;
	score += resultatTest(testRotationRadian()); nbTests++;
	score += resultatTest(testHomothetie()); nbTests++;
	score += resultatTest(testDeterminant()); nbTests++;

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}