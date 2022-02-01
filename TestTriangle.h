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

	cout << endl << t << endl;

	t = t.translation(Vecteur2D(2, 2));

	cout << endl << t << endl;

	return t.centre == Vecteur2D(5, 3);
}

bool TestTriangle::testRotationDegree() {
	return false;
}

bool TestTriangle::testRotationRadian() {
	return false;
}

bool TestTriangle::testHomothetie() {
	return false;
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