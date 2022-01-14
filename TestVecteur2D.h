#pragma once
#include "Vecteur2D.h"
using namespace std;

/**
* Test de l'op�rateur +.
* 
* @return bool - R�sultat du test.
*/
bool testOperatorPlus();

/**
* Test de l'op�rateur - unaire.
*
* @return bool - R�sultat du test.
*/
bool testOperatorMoinsUnaire();

/**
* Test de l'op�rateur -.
*
* @return bool - R�sultat du test.
*/
bool testOperatorMoins();

/**
* Test de l'op�rateur *.
*
* @return bool - R�sultat du test.
*/
bool testOperatorFois();

/**
* Test de l'op�rateur * avec un double en tant qu'op�rande droite.
*
* @return bool - R�sultat du test.
*/
bool testOperatorFoisDoubleDroite();

/**
* Test de l'op�rateur * avec un double en tant qu'op�rande gauche.
*
* @return bool - R�sultat du test.
*/
bool testOperatorFoisDoubleGauche();

/**
* Test de l'op�rateur string (cast).
*
* @return bool - R�sultat du test.
*/
bool testOperatorString();

/**
* Test de la m�thode distance.
*
* @return bool - R�sultat du test.
*/
bool testDistance();

/**
* Test de la m�thode rotation.
*
* @return bool - R�sultat du test.
*/
bool testRotation();

/**
* Test de la m�thode homothetie.
*
* @return bool - R�sultat du test.
*/
bool testHomothetie();

/**
* Test de la fonction amie determinant.
*
* @return bool - R�sultat du test.
*/
bool testDeterminant();

/**
* Test de la m�thode clone.
*
* @return bool - R�sultat du test.
*/
bool testClone();

/**
* Affiche le r�sultat du test.
* 
* @param const bool& test - Test � r�aliser.
*/
void resultatTest(const bool& test);

/// Lance une session de test pour la classe Vecteur2D et affiche les r�sultats des diff�rents tests.
void sessionTestVecteur2D();