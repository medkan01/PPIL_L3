#include "Triangle.h"
#include "../Visitor/VisiteurForme.h"

void Triangle::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }