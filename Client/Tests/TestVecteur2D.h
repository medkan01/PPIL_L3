#pragma once
#include "../Forme/Vecteur2D.h"
using namespace std;

class TestVecteur2D {
public:
	/**
	* Test de l'operateur +.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorPlus();

	/**
	* Test de l'operateur - unaire.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorMoinsUnaire();

	/**
	* Test de l'operateur -.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorMoins();

	/**
	* Test de l'operateur *.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorFois();

	/**
	* Test de l'operateur * avec un double en tant qu'operande droite.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorFoisDoubleDroite();

	/**
	* Test de l'operateur * avec un double en tant qu'operande gauche.
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorFoisDoubleGauche();

	/**
	* Test de l'operateur string (cast).
	*
	* @return Resultat du test.
	*/
	inline static bool testOperatorString();

	/**
	* Test de la methode distance.
	*
	* @return Resultat du test.
	*/
	inline static bool testDistance();

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
	* Test de la fonction amie determinant.
	*
	* @return Resultat du test.
	*/
	inline static bool testDeterminant();

	/**
	* Affiche le resultat du test.
	*
	* @param test Testarealiser.
	*/
	inline static int resultatTest(const bool& test);

	/// Lance une session de test pour la classe Vecteur2D et affiche les resultats des differents tests.
	inline static void sessionTest();

};

bool TestVecteur2D::testOperatorPlus() {
	Vecteur2D u(1, 3), v(3, 2), w = u + v;

	return (w.x == 4 && w.y == 5);
}

bool TestVecteur2D::testOperatorMoinsUnaire() {
	Vecteur2D u(1, 3), v = -u;

	return (v.x == -1 && v.y == -3);
}

bool TestVecteur2D::testOperatorMoins() {
	Vecteur2D u(1, 3), v(3, 2), w = u - v;

	return (w.x == -2 && w.y == 1);
}

bool TestVecteur2D::testOperatorFois() {
	Vecteur2D u(1, 3), v(3, 2);
	double ps = u * v;

	return (ps == 9);
}

bool TestVecteur2D::testOperatorFoisDoubleDroite() {
	Vecteur2D u(1, 3), v = 3 * u;

	return (v.x == 3 && v.y == 9);
}

bool TestVecteur2D::testOperatorFoisDoubleGauche() {
	Vecteur2D u(1, 3), v = u * 3;

	return (v.x == 3 && v.y == 9);
}

bool TestVecteur2D::testOperatorString() {
	Vecteur2D u(1, 3);

	return ((string)u == "(1.000000, 3.000000)");
}

bool TestVecteur2D::testDistance() {
	Vecteur2D u(1, 3), v(3, 3);

	return (u.distance(v) == 2);
}

bool TestVecteur2D::testRotationDegree() {
	Vecteur2D u(4, 0), w(0, 0);
	Degree theta(90);

	u = u.rotation(w, theta);

	return ((u.y >= 3.9999 && u.y <= 4.0001) && (u.x >= -0.0001 && u.x <= 0.0001));
}

bool TestVecteur2D::testRotationRadian() {
	Vecteur2D u(4, 0), w(0, 0);
	Radian alpha(M_PI / 2);

	u = u.rotation(w, alpha);

	return ((u.y >= 3.9999 && u.y <= 4.0001) && (u.x >= -0.0001 && u.x <= 0.0001));
}

bool TestVecteur2D::testHomothetie() {
	Vecteur2D u(4, 2), v(0, 0);
	u = u.homothetie(v, 2);

	return (u.x == 8 && u.y == 4);
}

bool TestVecteur2D::testDeterminant() {
	Vecteur2D u(2, 3), v(4, 5);
	double delta = determinant(u, v);

	return (delta == -2);
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

	cout << endl << "Debut de la session de tests pour la classe Vecteur2D.." << endl << "Resultats : ";

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