#ifndef VISITEURFORME_H
#define VISITEURFORME_H

#include "../Forme/Segment.h"
#include "../Forme/Triangle.h"
#include "../Forme/Cercle.h"
#include "../Forme/GroupeFormes.h"
#include "../Forme/Polygone.h"

/**
 * Class utilisant le designe pattern visitor et qui va permettre d'ajouter des fonctionnalit√©
 * si elles ont ete oublie.
 */
class VisiteurForme {
public:

	/**
	 * Ajoute une fonctionnalite a un segment.
	 * 
	 * @param s : Segment concerne.
	 */
	virtual void visite(const Segment* s) const = 0;

	/**
	 * Ajoute une fonctionnalite a un triangle.
	 * 
	 * @param t : Triangle concerne.
	 */
	virtual void visite(const Triangle* t) const = 0;

	/**
	 * Ajoute une fonctionnalite a un cerlce.
	 * 
	 * @param c : Cercle concerne.
	 */
	virtual void visite(const Cercle* c) const = 0;

	/**
	* Ajoute une fonctionnalite a un groupe de forme.
	* 
	* @param gf Groupe de formes concerne.
	*/
	virtual void visite(const GroupeFormes* gf) const = 0;

	/**
	 * Ajoute une fonctionnalite a un polygone.
	 * 
	 * @param p : Polygone concerne.
	 */
	virtual void visite(const Polygone* p) const = 0;
};

#endif