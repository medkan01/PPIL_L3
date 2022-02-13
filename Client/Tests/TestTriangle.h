#pragma once
#include "../Forme/Triangle.h"

class TestTriangle {
public:
	/**
	* Test de la methode translation.
	*
	* @return Resultat du test.
	*/
	inline static bool testTranslation();

	/**
	* Test de la methode rotation avec les degrees.
	*
	* @return Resultat du test.
	*/
	inline static bool testRotationDegree();

	/**
	* Test de la methode rotation avec les radians.
	*
	* @return Resultat du test.
	*/
	inline static bool testRotationRadian();

	/**
	* Test de la methode homothetie.
	*
	* @return Resultat du test.
	*/
	inline static bool testHomothetie();

	/**
	* Affiche le resultat du test.
	*
	* @param test Testarealiser.
	*/
	inline static int resultatTest(const bool&);

	/// Lance une session de test pour la classe Vecteur2D et affiche les resultats des differents tests.
	inline static void sessionTest();
};

bool TestTriangle::testTranslation() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0);
	Triangle t(Couleur("Noire"), Repere(), a, b, c);

	t = t.translation(Vecteur2D(3, 2));

	return t.centre == Vecteur2D(6, 3);
}

bool TestTriangle::testRotationDegree() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(2,4), resB(5,1), resC(2, -2);
	Triangle t(Couleur("Noire"), Repere(), a, b, c);

	t = t.rotation(t.centre, Degree(-90));

	return t.a == resA && t.b == resB && t.c == resC;
}

bool TestTriangle::testRotationRadian() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(2, 4), resB(5, 1), resC(2, -2);
	Triangle t(Couleur("Noire"), Repere(), a, b, c);

	t = t.rotation(t.centre, Radian(-M_PI / 2));

	return t.a == resA && t.b == resB && t.c == resC;
}

bool TestTriangle::testHomothetie() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0), resA(1.5, 0.5), resB(3, 2), resC(4.5, 0.5);
	Triangle t(Couleur("Noire"), Repere(), a, b, c);

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

	cout << endl << "Debut de la session de tests pour la classe Triangle.." << endl << "Resultats : ";

	score += resultatTest(testTranslation()); nbTests++;
	score += resultatTest(testRotationDegree()); nbTests++;
	score += resultatTest(testRotationRadian()); nbTests++;
	score += resultatTest(testHomothetie()); nbTests++;

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}