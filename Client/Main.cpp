#pragma once
#include "TestVecteur2D.h"
#include "TestRadian.h"
#include "TestDegree.h"
#include "TestSegment.h"
#include "TestTriangle.h"
using namespace std;

int main() {
	TestVecteur2D::sessionTest();
	TestRadian::sessionTest();
	TestDegree::sessionTest();
	TestSegment::sessionTest();
	TestTriangle::sessionTest();

	return 0;
}