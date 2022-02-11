#ifndef VISITEURFORME_H
#define VISITEURFORME_H

#include "../Forme/Segment.h"
#include "../Forme/Triangle.h"
// #include "../Forme/Cercle.h"
// #include "../Forme/Polygone.h"

/**
 * Class utilisant le designe pattern visitor et qui va permettre d'ajouter des fonctionnalité
 * si elles ont ete oublie.
 */
class VisiteurForme {
public:

	/**
	 * Ajoute une fonctionnalite a un segment.
	 * 
	 * @param s : Segment concerne.
	 */
	virtual void visite(Segment* s) = 0;

	/**
	 * Ajoute une fonctionnalite a un triangle.
	 * 
	 * @param t : Triangle concerne.
	 */
	virtual void visite(Triangle* t) = 0;

	/**
	 * Ajoute une fonctionnalite a un cerlce.
	 * 
	 * @param c : Cercle concerne.
	 */
	// virtual void visite(Cercle* c) = 0;

	/**
	 * Ajoute une fonctionnalite a un polygone.
	 * 
	 * @param p : Polygone concerne.
	 */
	// virtual void visite(Polygone* p) = 0;
};

#endif