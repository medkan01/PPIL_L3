#pragma once
#include "TestVecteur2D.h"
#include "TestRadian.h"
#include "TestDegree.h"
#include "TestSegment.h"
#include "TestTriangle.h"
#include "Client.h"
using namespace std;

int main() {
	Client::connection("127.0.0.1", 44444);

	return 0;
}