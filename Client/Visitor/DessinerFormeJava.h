#ifndef DESSINERFORMEJAVA_H
#define DESSINERFORMEJAVA_H

#include "VisiteurForme.h"
#include "../TCPIP/Client.h"

/**
* Cette classe permet d'envoyer les donnees d'une forme au serveur java si celui-ci est
* disponible.
*/
class DessinerFormeJava : public VisiteurForme {
public:

    /**
	 * Dessine un segment.
	 * 
	 * @param s : Segment concerne.
	 */
	virtual void visite(const Segment* s) const;

	/**
	 * Dessine un triangle.
	 * 
	 * @param t : Triangle concerne.
	 */
	virtual void visite(const Triangle* t) const;

	/**
	 * Dessine un cerlce.
	 * 
	 * @param c : Cercle concerne.
	 */
	// virtual void visite(Cercle* c);

	/**
	 * Dessine un polygone.
	 * 
	 * @param p : Polygone concerne.
	 */
	// virtual void visite(Polygone* p);
};

    /**
	 * Formate les donnees du segment de facon a ce qu'elles soient envoyes au serveur Java.
	 * C'est ensuite le serveur java qui va dessiner le segment.
	 * 
	 * @param s : Segment concerne.
	 */
	void DessinerFormeJava::visite(const Segment* s) const {
		string donnees =  "segment/" + s->a + ";" + s->b + "/" + (string)s->couleur;
		try {
			Client::instance().envoiDonnees(donnees);
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	}

	/**
	 * Formate les donnees du triangle de facon a ce qu'elles soient envoyes au serveur Java.
	 * C'est ensuite le serveur java qui va dessiner le triangle.
	 * 
	 * @param t : Triangle concerne.
	 */
	void DessinerFormeJava::visite(const Triangle* t) const {
		string type = "triangle/";
		string vecteurs = t->a + ";" + t->b + ";" + t->c + "/";
		string couleur = t->couleur;
		string donnees = type + vecteurs + couleur;
		try {
			Client::instance().envoiDonnees(donnees);
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	}

	// virtual void visite(Cercle* c) // TODO

	// virtual void visite(Polygone* p) // TODO

#endif