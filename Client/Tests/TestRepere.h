#pragma once
#include <string>
#include <iostream>
#include "../Forme/Repere.h"
using namespace std;

class TestRepere {
public:
	/**
	* Test l'operateur string.
	*
	* @return Resultat du test.
	*/
	inline static bool testString();

	/**
	* Test la methode estDans().
	*
	* @return Resultat du test.
	*/
	inline static bool testEstDans();

	/**
	* Affiche le resultat du test.
	*
	* @param test Testarealiser.
	*/
	inline static int resultatTest(const bool& test);

	/// Lance une session de test et affiche les resultats des differents tests.
	inline static void sessionTest();
};

bool TestRepere::testString() {
	Repere r;

	return (string)r == "(-20.000000,-20.000000);(20.000000,20.000000)";
}

bool TestRepere::testEstDans() {
	Vecteur2D u(12, 15), v(10, 56);
	Repere r;

	return r.estDans(u) && !r.estDans(v);
}

int TestRepere::resultatTest(const bool& test) {
	if (test) {
		cout << ".";
		return 1;
	}

	cout << "x";
	return 0;
}

void TestRepere::sessionTest() {
	int score = 0;
	int nbTests = 0;

	cout << endl << "Debut de la session de tests pour la classe Repere.." << endl << "Resultats : ";

	score += resultatTest(testString()); nbTests++;
	score += resultatTest(testEstDans()); nbTests++;

	cout << endl << "Fin de la session de tests.." << endl;

	cout << "Score : " << score << "/" << nbTests << endl << endl;
}