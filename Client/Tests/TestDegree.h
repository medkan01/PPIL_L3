#pragma once
#include <string>
#include <iostream>
#include "../Utils/Degree.h"
using namespace std;

class TestDegree {
public:
	/**
	* Test la m�thode toDegree().
	*
	* @return const double - R�sultat du test.
	*/
	inline static bool testToRadian();

	/**
	* Affiche le r�sultat du test.
	*
	* @param const bool& test - Test � r�aliser.
	*/
	inline static int resultatTest(const bool&);

	/// Lance une session de test et affiche les r�sultats des diff�rents tests.
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

	cout << endl << "D�but de la session de tests pour la classe Degree.." << endl << "R�sultats : ";

	score += resultatTest(testToRadian());

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}