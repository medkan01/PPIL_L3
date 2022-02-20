#pragma once
#include <string>
#include <iostream>
using namespace std;

class Couleur {
	int r, g, b;

public:
	/**
	* Constructeur de la classe Couleur.
	* Creer une couleur au format RGB.
	* Par defaut, la couleur creer est noire.
	* 
	* @param red Intensite du rouge.
	* @param green Intensite du vert.
	* @param blue Intensite du bleu.
	*/
	inline Couleur(const int& red = 0, const int& green = 0, const int& blue = 0);

	/// Destructeur de la classe Couleur.
	virtual ~Couleur() {}

	/// Operateur de conversion string.
	inline operator string() const;

	/**
	* Operateur de concatenation de string
	* 
	* @param s String a concatener.
	* @return Concatenation de la couleur avec le string s.
	*/
	inline const string operator +(const string& s) const;

	/**
	* Operateur de concatenation de string
	*
	* @param s String a concatener.
	* @param couleur Couleur a concatener
	* @return Concatenation de la couleur couleur avec le string s.
	*/
	friend const string operator +(const string& s, const Couleur& couleur);

	static const Couleur BLACK;
	static const Couleur BLUE;
	static const Couleur RED;
	static const Couleur GREEN;
	static const Couleur YELLOW;
	static const Couleur CYAN;
};

Couleur::Couleur(const int& red, const int& green, const int& blue) {
	r = red;
	g = green;
	b = blue;

	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;

	if (r < 0) r = 0;
	if (g < 0) g = 0;
	if (b < 0) b = 0;
}

inline Couleur::operator string() const {
	return to_string(r) + "-" + to_string(g) + "-" + to_string(b);
}

const string Couleur::operator +(const string& s) const {
	return (string)(*this) + s;
}

inline const string operator+(const string& s, const Couleur& couleur) {
	return s + (string) couleur;
}