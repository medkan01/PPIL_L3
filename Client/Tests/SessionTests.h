#ifndef SESSIONTESTS_H
#define SESSIONTESTS_H

#include "TestDegree.h"
#include "TestRadian.h"
#include "TestRepere.h"
#include "TestSegment.h"
#include "TestTriangle.h"
#include "TestVecteur2D.h"

void sessionTests() {
	cout << "Debut de la session de tests." << endl;

	TestDegree::sessionTest();
	TestRadian::sessionTest();
	TestSegment::sessionTest();
	TestTriangle::sessionTest();
	TestRepere::sessionTest();
	TestVecteur2D::sessionTest();

	cout << "Fin de la session de tests." << endl;
}

#endif