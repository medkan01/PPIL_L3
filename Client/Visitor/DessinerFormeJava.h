#ifndef DESSINERFORMEJAVA_H
#define DESSINERFORMEJAVA_H

#include "VisiteurForme.h"

class DessinerForme : public VisiteurForme {
public:

    /**
	 * Dessine un segment.
	 * 
	 * @param s : Segment concerne.
	 */
	virtual void visite(Segment* s) = 0;

	/**
	 * Dessine un triangle.
	 * 
	 * @param t : Triangle concerne.
	 */
	virtual void visite(Triangle* t) = 0;

	/**
	 * Dessine un cerlce.
	 * 
	 * @param c : Cercle concerne.
	 */
	// virtual void visite(Cercle* c) = 0;

	/**
	 * Dessine un polygone.
	 * 
	 * @param p : Polygone concerne.
	 */
	// virtual void visite(Polygone* p) = 0;
};

#endif