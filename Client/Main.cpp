#pragma once
#include "TestVecteur2D.h"
#include "TestRadian.h"
#include "TestDegree.h"
#include "TestSegment.h"
#include "TestTriangle.h"
#include "Client.h"
using namespace std;

int main() {
	Vecteur2D a(0, 0), b(3, 3), c(6, 0);
	Couleur noire("Noire");

	Triangle t(noire, a, b, c);

	Client::envoieDonnee("127.0.0.1", 44444, t);
	return 0;
}