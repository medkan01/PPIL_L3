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

	/**
	* Ajoute une fonctionnalite a un groupe de forme.
	*
	* @param gf Groupe de formes concerne.
	*/
	virtual void visite(const GroupeFormes* gf) const;
};

void DessinerFormeJava::visite(const Segment* s) const {

	string type = "segment/";
	string couleur = s->couleur + "/";
	string repere = (string)s->repere + "/";
	string vecteurs = s->a + ";" + s->b;

	string donnees = type + couleur + repere + vecteurs;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void DessinerFormeJava::visite(const Triangle* t) const {
	string type = "triangle/";
	string couleur = t->couleur + "/";
	string repere = (string)t->repere + "/";
	string vecteurs = t->a + ";" + t->b + ";" + t->c;

	string donnees = type + couleur + repere + vecteurs;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void DessinerFormeJava::visite(const Cercle* c) const {
	string type = "cercle/";
	string couleur = c->couleur + "/";
	string repere = (string)c->repere + "/";
	string point = Vecteur2D(c->centre.x - c->r, c->centre.y + c->r) + "/";
	string rayon = to_string(c->r * 2) + "/";

	string donnees = type + couleur + repere + point + rayon;
	try {
		Client::instance().envoiDonnees(donnees);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

inline void DessinerFormeJava::visite(const GroupeFormes* gf) const {
	VisiteurForme* v;
	v = new DessinerFormeJava;

	try {
		vector<Forme*>::const_iterator it;

		for (it = gf->groupe.begin(); it != gf->groupe.end(); it++)
			(*it)->accepte(v);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

	// virtual void visite(Polygone* p) // TODO

#endif