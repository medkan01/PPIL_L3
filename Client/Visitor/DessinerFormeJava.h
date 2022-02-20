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
	* Formate les donnees du segment de facon a ce qu'elles soient envoyes au serveur Java.
	* C'est ensuite le serveur java qui va dessiner le segment.
	*
	* @param s : Segment concerne.
	*/
	virtual void visite(const Segment* s) const;

	/**
	* Formate les donnees du triangle de facon a ce qu'elles soient envoyes au serveur Java.
	* C'est ensuite le serveur java qui va dessiner le triangle.
	*
	* @param t : Triangle concerne.
	*/
	virtual void visite(const Triangle* t) const;

	/**
	* Formate les donnees du cercle de facon a ce qu'elles soient envoyes au serveur Java.
	* C'est ensuite le serveur java qui va dessiner le cercle.
	*
	* @param t : Cercle concerne.
	*/
	virtual void visite(const Cercle* c) const;

	/**
	 * Dessine un polygone.
	 * 
	 * @param p : Polygone concerne.
	 */
	// virtual void visite(const Polygone* p) const;
};

void DessinerFormeJava::visite(const Segment* s) const {
	string donnees =  "segment/" + s->a + ";" + s->b + "/" + (string)s->couleur + "/" + (string)s->repere;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void DessinerFormeJava::visite(const Triangle* t) const {
	string type = "triangle/";
	string vecteurs = t->a + ";" + t->b + ";" + t->c + "/";
	string couleur = t->couleur;
	string repere = "/" + (string)t->repere;
	string donnees = type + vecteurs + couleur + repere;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void DessinerFormeJava::visite(const Cercle* c) const {
	string type = "cercle/";
	string point = Vecteur2D(c->centre.x - c->r, c->centre.y + c->r) + "/";
	string rayon = to_string(c->r * 2) + "/";
	string couleur = c->couleur;
	string repere = "/" + (string)c->repere;
	string donnees = type + point + rayon + couleur + repere;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

	// virtual void visite(Polygone* p) // TODO

#endif