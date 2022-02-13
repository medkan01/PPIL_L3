#include "Cercle.h"
#include "../Visitor/VisiteurForme.h"

void Cercle::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }