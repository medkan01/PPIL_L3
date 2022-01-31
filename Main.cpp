#pragma once
#include "TestVecteur2D.h"
#include "TestRadian.h"
#include "TestDegree.h"
#include "TestSegment.h"
using namespace std;

int main() {
	TestVecteur2D::sessionTest();
	TestRadian::sessionTest();
	TestDegree::sessionTest();
	TestSegment::sessionTest();

	return 0;
}