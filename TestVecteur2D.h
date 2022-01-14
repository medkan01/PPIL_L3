#pragma once
#include "Vecteur2D.h"
using namespace std;

/**
* Test de l'opérateur +.
* 
* @return bool - Résultat du test.
*/
bool testOperatorPlus();

/**
* Test de l'opérateur - unaire.
*
* @return bool - Résultat du test.
*/
bool testOperatorMoinsUnaire();

/**
* Test de l'opérateur -.
*
* @return bool - Résultat du test.
*/
bool testOperatorMoins();

/**
* Test de l'opérateur *.
*
* @return bool - Résultat du test.
*/
bool testOperatorFois();

/**
* Test de l'opérateur * avec un double en tant qu'opérande droite.
*
* @return bool - Résultat du test.
*/
bool testOperatorFoisDoubleDroite();

/**
* Test de l'opérateur * avec un double en tant qu'opérande gauche.
*
* @return bool - Résultat du test.
*/
bool testOperatorFoisDoubleGauche();

/**
* Test de l'opérateur string (cast).
*
* @return bool - Résultat du test.
*/
bool testOperatorString();

/**
* Test de la méthode distance.
*
* @return bool - Résultat du test.
*/
bool testDistance();

/**
* Test de la méthode rotation.
*
* @return bool - Résultat du test.
*/
bool testRotation();

/**
* Test de la méthode homothetie.
*
* @return bool - Résultat du test.
*/
bool testHomothetie();

/**
* Test de la fonction amie determinant.
*
* @return bool - Résultat du test.
*/
bool testDeterminant();

/**
* Test de la méthode clone.
*
* @return bool - Résultat du test.
*/
bool testClone();

/**
* Affiche le résultat du test.
* 
* @param const bool& test - Test à réaliser.
*/
void resultatTest(const bool& test);

/// Lance une session de test pour la classe Vecteur2D et affiche les résultats des différents tests.
void sessionTestVecteur2D();