#pragma once
#include <string>
#include <iostream>
#include "Degree.h"
using namespace std;

class TestDegree {
public:
	/**
	* Test la méthode toDegree().
	*
	* @return const double - Résultat du test.
	*/
	inline static bool testToRadian();

	/**
	* Affiche le résultat du test.
	*
	* @param const bool& test - Test à réaliser.
	*/
	inline static int resultatTest(const bool&);

	/// Lance une session de test et affiche les résultats des différents tests.
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

	cout << endl << "Début de la session de tests pour la classe Degree.." << endl << "Résultats : ";

	score += resultatTest(testToRadian());

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}