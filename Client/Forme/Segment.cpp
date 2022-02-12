#include "Segment.h"
#include "../Visitor/VisiteurForme.h"

void Segment::accepte(VisiteurForme* visiteur) const { visiteur->visite(this); }