#ifndef TESTDEGREE_H
#define TESTDEGREE_H

#include <string>
#include <iostream>
#include "../Utils/Degree.h"
using namespace std;

class TestDegree {
public:
	/**
	* Test la methode toDegree().
	*
	* @return Resultat du test.
	*/
	inline static bool testToRadian();

	/**
	* Affiche le resultat du test.
	*
	* @param test Testarealiser.
	*/
	inline static int resultatTest(const bool& test);

	/// Lance une session de test et affiche les resultats des differents tests.
	inline static void sessionTest();
};

bool TestDegree::testToRadian() {
	Degree theta(45);

	if (theta.toRadian() == M_PI / 4)
		return true;

	return false;
}

int TestDegree::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestDegree::sessionTest() {
	int score = 0;
	const int nbTests = 1;

	cout << endl << "Debut de la session de tests pour la classe Degree.." << endl << "Resultats : ";

	score += resultatTest(testToRadian());

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}

#endif