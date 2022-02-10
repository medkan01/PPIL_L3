#pragma once
#include <string>
#include <iostream>
#include "../Utils/Radian.h"
using namespace std;

class TestRadian {
public:
	/**
	* Test la methode toDegree().
	*
	* @return Resultat du test.
	*/
	inline static bool testToDegree();

	/**
	* Affiche le resultat du test.
	*
	* @param test Testarealiser.
	*/
	inline static int resultatTest(const bool& test);

	/// Lance une session de test et affiche les resultats des differents tests.
	inline static void sessionTest();
};

bool TestRadian::testToDegree() {
	Radian alpha(M_PI / 4);

	if (alpha.toDegree() == 45)
		return true;

	return false;
}

int TestRadian::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestRadian::sessionTest() {
	int score = 0;
	const int nbTests = 1;

	cout << endl << "Debut de la session de tests pour la classe Radian.." << endl << "Resultats : ";

	score += resultatTest(testToDegree());

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}