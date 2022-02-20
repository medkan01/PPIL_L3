#pragma once
#include "../Forme/Segment.h"

class TestSegment {
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

bool TestSegment::testTranslation() {
	Vecteur2D a(0, 0), b(2, 3), u(4, 3), resA(4, 3), resB(6, 6), resCentre(5, 4.5);
	Segment s(Couleur::BLACK, Repere(), a, b);
	
	s = s.translation(u);

	return (s.a == resA && s.b == resB && s.centre == resCentre);
}

bool TestSegment::testRotationDegree() {
	Vecteur2D a(-4, 0), b(4, 0), resA(4, 0), resB(-4, 0), resCentre(0, 0);
	Segment s(Couleur::BLACK, Repere(), a, b);

	s = s.rotation(s.centre, Degree(180));

	return ((s.a.x >= 3.999 && s.a.x <= 4.0001) && (s.a.y >= -0.0001 && s.a.y <= 0.0001) && (s.b.x >= -4.0001 && s.b.x <= -3.999) && (s.b.y >= -0.0001 && s.b.y <= 0.0001));
}

bool TestSegment::testRotationRadian() {
	Vecteur2D a(-4, 0), b(4, 0), resA(4, 0), resB(-4, 0), resCentre(0, 0);
	Segment s(Couleur::BLACK, Repere(), a, b);

	s = s.rotation(s.centre, Radian(M_PI));

	return ((s.a.x >= 3.999 && s.a.x <= 4.0001) && (s.a.y >= -0.0001 && s.a.y <= 0.0001) && (s.b.x >= -4.0001 && s.b.x <= -3.999) && (s.b.y >= -0.0001 && s.b.y <= 0.0001));
}

bool TestSegment::testHomothetie() {
	Vecteur2D a(-2, 0), b(2, 0), resA(-3, 0), resB(3, 0), resCentre(0, 0);
	Segment s(Couleur::BLACK, Repere(), a, b);

	s = s.homothetie(s.centre, 1.5);

	return (s.a == resA && s.b == resB && s.centre == resCentre);
}

int TestSegment::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestSegment::sessionTest() {
	int score = 0;
	int nbTests = 0;

	cout << endl << "Debut de la session de tests pour la classe Segment.." << endl << "Resultats : ";

	score += resultatTest(testTranslation()); nbTests++;
	score += resultatTest(testRotationDegree()); nbTests++;
	score += resultatTest(testRotationRadian()); nbTests++;
	score += resultatTest(testHomothetie()); nbTests++;

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}