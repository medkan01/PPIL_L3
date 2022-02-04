#pragma once
#include "Triangle.h"

class TestTriangle {
public:
	/**
	* Test de la méthode translation.
	*
	* @return bool - Résultat du test.
	*/
	inline static bool testTranslation();

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
	* Affiche le résultat du test.
	*
	* @param const bool& test - Test à réaliser.
	*/
	inline static int resultatTest(const bool&);

	/// Lance une session de test pour la classe Vecteur2D et affiche les résultats des différents tests.
	inline static void sessionTest();
};

bool TestTriangle::testTranslation() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0);
	Triangle t(Couleur("Noire"), a, b, c);

	t = t.translation(Vecteur2D(3, 2));

	return t.centre == Vecteur2D(6, 3);
}

bool TestTriangle::testRotationDegree() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(2,4), resB(5,1), resC(2, -2);
	Triangle t(Couleur("Noire"), a, b, c);

	t = t.rotation(t.centre, Degree(-90));

	return t.a == resA && t.b == resB && t.c == resC;
}

bool TestTriangle::testRotationRadian() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(2, 4), resB(5, 1), resC(2, -2);
	Triangle t(Couleur("Noire"), a, b, c);

	t = t.rotation(t.centre, Radian(-M_PI / 2));

	return t.a == resA && t.b == resB && t.c == resC;
}

bool TestTriangle::testHomothetie() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(1.5, 0.5), resB(3, 2), resC(4.5, 0.5);
	Triangle t(Couleur("Noire"), a, b, c);

	t = t.homothetie(t.centre, 0.5);

	return t.a == resA && t.b == resB && t.c == resC;
}

int TestTriangle::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestTriangle::sessionTest() {
	int score = 0;
	int nbTests = 0;

	cout << endl << "Début de la session de tests pour la classe Triangle.." << endl << "Résultats : ";

	score += resultatTest(testTranslation()); nbTests++;
	score += resultatTest(testRotationDegree()); nbTests++;
	score += resultatTest(testRotationRadian()); nbTests++;
	score += resultatTest(testHomothetie()); nbTests++;

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}