#ifndef VECTEUR2D_H
#define VECTEUR2D_H
#include <string>
#include <iostream>
#include <vector>
#include "../Utils/Radian.h"
#include "../Utils/Degree.h"
using namespace std;

/**
 * Represente un point dans l'espace (sous forme de vecteur)
 */
class Vecteur2D {
public:
	// Attributs
	double x, y;

	/**
	* Constructeur de la classe Vecteur2D qui contruit un vecteur u(u1, u2).
	*
	* @param x valeur de u1 dans le vecteur u(u1, u2).
	* @param y valeur de u2 dans le vecteur u(u1, u2).
	*/
	explicit Vecteur2D(const double& x = 0, const double& y = 0) : 
		x(x), y(y) {}

	///	Destructeur de la classe Vecteur2D.
	virtual ~Vecteur2D() {}

	/**
	* Addtition de deux vecteurs u et v.
	*
	* @param v vecteur qui sera additionne avec le vecteur u courant.
	* @return vecteur resultant de l'addition des vecteurs u et v.
	*/
	inline const Vecteur2D operator+(const Vecteur2D& v) const;

	/**
	* Operateur - unaire. Permet entre autre d'opposer un vecteur.
	*
	* @return oppose du vecteur courant.
	*/
	inline const Vecteur2D operator-() const;

	/**
	* Soustraction de deux vecteurs u et v.
	*
	* @param v vecteur qui sera soustrait avec le vecteur u courant.
	* @return le vecteur resultant de la soustraction des vecteurs u et v.
	*/
	inline const Vecteur2D operator-(const Vecteur2D& v) const;

	/**
	* Produit scalaire de deux vecteurs u et v.
	*
	* @param v vecteur qui resultera du produit scalaire avec le vecteur courant.
	* @return produit scalaire de u . v.
	*/
	inline const double operator*(const Vecteur2D& v) const;

	/**
	* Multiplication d'un vecteur par un entier i.
	*
	* @param i entier qui sera multiplie avec le vecteur u courant.
	* @return vecteur resultant de la multiplication de l'entier i et du vecteur u courant.
	*/
	inline const Vecteur2D operator*(const double& i) const;

	/**
	* Addtition de deux vecteurs u et v greceal'operateur +=.
	*
	* @param v vecteur qui sera additionne avec le vecteur u courant.
	* @return vecteur resultant de l'addition des vecteurs u et v.
	*/
	inline const Vecteur2D operator+=(const Vecteur2D& v);

	/**
	* Operateur de cast. Equivalent d'une methode toString().
	*
	* @return toString correspondant au vecteur courant.
	*/
	inline operator string() const;

	/**
	* Distance entre le vecteur u courant et un vecteur v.
	* 
	* @param v le second vecteur permettant de calculer la distance.
	* @return distance entre un vecteur v et le vecteur u courant.
	*/
	inline const double distance(const Vecteur2D& v) const;

	/**
	* Effectue une rotation vectorielleapartir d'un point de rotation R, du point concerne et d'un angle phi.
	* 
	* @param R Centre de rotation.
	* @param phi Angle de rotation en radian.
	* @return Vecteur apres rotation.
	*/
	inline virtual const Vecteur2D rotation(const Vecteur2D& R, const Radian& phi) const;

	/**
	* Effectue une rotation vectorielleapartir d'un point de rotation R, du point concerne et d'un angle phi.
	*
	* @param R Centre de rotation.
	* @param phi Angle de rotation en degree.
	* @return Vecteur apres rotation.
	*/
	inline virtual const Vecteur2D rotation(const Vecteur2D& R, const Degree& phi) const;

	/**
	* Effectue une homothetie vectorielleapartir d'un point invariant, du point concerne et d'un rapport a.
	*
	* @param C Point invariant.
	* @param a Rapport d'homothetie.
	* @return Vecteur apres homothetie.
	*/
	inline virtual const Vecteur2D homothetie(const Vecteur2D& C, const double& a) const;

	/**
	* Determinant d'un couple de vecteur.
	*
	* @param u vecteur u.
	* @param v vecteur v.
	* @return valeur du determinant du couple de vecteurs u et v.
	*/
	friend const double determinant(const Vecteur2D& u, const Vecteur2D& v);

	/**
	* Clone un vecteur.
	* 
	* @return Copie du vecteur.
	*/
	virtual Vecteur2D* clone() const { return new Vecteur2D(*this); }

	/**
	* Multiplication d'un vecteur par un entier i.
	*
	* @param i entier qui sera multiplie avec le vecteur u courant.
	* @param v Vecteur qui va etre multiplie.
	* @return vecteur resultant de la multiplication de l'entier i et du vecteur u courant.
	*/
	friend const Vecteur2D operator *(const double& i, const Vecteur2D& v);

	/**
	* Operateur qui verifie si un vecteur v est egal au vecteur courant.
	* 
	* @param v Vecteur qui sera compare au vecteur courant.
	* @return Resultat de la comparaison.
	*/
	inline const bool operator==(const Vecteur2D v) const;

	/**
	* Operateur de concatenation de string.
	* 
	* @param s String qui va etre concatene au vecteur. (au format string)
	* @return Resultat de la concatenation.
	*/
	inline const string operator+(const string& s) const;

	/**
	* Operateur de concatenation de string.
	*
	* @param s String qui va etre concatene au vecteur. (au format string)
	* @param u Vecteur qui va ?tre concatene au string.
	* @return Resultat de la concatenation.
	*/
	friend const string operator+(const string& s, const Vecteur2D& u);

	/**
	* Operateur de comparaison de deux vecteurs pour savoir si le vecteur 
	* v est inferieur ou egal au vecteur courant.
	* 
	* @param v Vecteur a comparer avec le vecteur courant.
	* @return True si v est inferieur ou egal au vecteur courant. False sinon.
	*/
	inline bool operator >=(const Vecteur2D& v) const;

	/**
	* Operateur de comparaison de deux vecteurs pour savoir si le vecteur
	* v est superieur ou egal au vecteur courant.
	*
	* @param v Vecteur a comparer avec le vecteur courant.
	* @return True si v est superieur ou egal au vecteur courant. False sinon.
	*/
	inline bool operator <=(const Vecteur2D& v) const;

	/**
	* Operateur de comparaison de deux vecteurs pour savoir si le vecteur
	* v est strictement inferieur au vecteur courant.
	*
	* @param v Vecteur a comparer avec le vecteur courant.
	* @return True si v est strictement inferieur au vecteur courant. False sinon.
	*/
	inline bool operator >(const Vecteur2D& v) const;

	/**
	* Operateur de comparaison de deux vecteurs pour savoir si le vecteur
	* v est strictement superieur au vecteur courant.
	*
	* @param v Vecteur a comparer avec le vecteur courant.
	* @return True si v est strictement superieur au vecteur courant. False sinon.
	*/
	inline bool operator <(const Vecteur2D& v) const;

	/**
	* Creer un vecteur qui est le resulat d'une translation du vecteur courant par le double d.
	* La translation s'effectue champ ? champ.
	* 
	* @param d Double qui va servir a la translation.
	* @return Vecteur resultant de la translation.
	*/
	inline const Vecteur2D operator+(const double& d) const;

	/**
	* Creer un vecteur qui est le resulat d'une translation du vecteur courant par le double d.
	* La translation s'effectue champ ? champ.
	*
	* @param d Double qui va servir a la translation.
	* @param u Vecteur qui va subir la translation.
	* @return Vecteur resultant de la translation.
	*/
	friend const Vecteur2D operator+(const double& d, const Vecteur2D& u);

	/**
	* Creer un vecteur qui est le resulat d'une translation du vecteur courant par le double d.
	* La translation s'effectue champ ? champ.
	*
	* @param d Double qui va servir a la translation.
	* @return Vecteur resultant de la translation.
	*/
	inline const Vecteur2D operator+=(const double& d) const;

	/**
	* Fonction de tri par fusion.
	* 
	* @param T Tableau de Vecteur2D a trier.
	*/
	friend vector<Vecteur2D> tri_fusion(vector<Vecteur2D> T);

	/**
	* Fonction qui fusionne deux tableau tries T1 et T2.
	* 
	* @param T1 Premier tableau trie.
	* @param T2 Deuxieme tableau trie.
	* @return Tableau trie qui contient les elements de T1 et T2.
	*/
	friend vector<Vecteur2D> fusion(vector<Vecteur2D> T1, vector<Vecteur2D> T2);
};

const bool Vecteur2D::operator==(const Vecteur2D v) const {
	return x >= v.x - 0.00001 && x <= v.x + 0.00001 && y >= v.y - 0.00001 && y <= v.y + 0.00001;
}

const Vecteur2D Vecteur2D::operator+(const Vecteur2D& v) const {
	return Vecteur2D(x + v.x, y + v.y);
}

const Vecteur2D Vecteur2D::operator-() const {
	return Vecteur2D(-x, -y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D& v) const {
	return Vecteur2D(x + (- v.x), y + (- v.y));
}

const double Vecteur2D::operator*(const Vecteur2D& v) const {
	return x * v.x + y * v.y;
}

const Vecteur2D Vecteur2D::operator*(const double& i) const {
	return Vecteur2D(x * i, y * i);
}

Vecteur2D::operator string() const {
	return "(" + to_string(x) + "," + to_string(y) + ")";
}

const double Vecteur2D::distance(const Vecteur2D& v) const {
	return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
}

inline ostream& operator<<(ostream& os, const Vecteur2D& v) {
	return os << (string)v;
}

const Vecteur2D Vecteur2D::rotation(const Vecteur2D& R, const Radian& alpha) const {
	Vecteur2D v = *this;
	v.x = R.x + ((x - R.x) * cos(alpha) - (y - R.y) * sin(alpha));
	v.y = R.y + ((x - R.x) * sin(alpha) + (y - R.y) * cos(alpha));

	return v;
}

const Vecteur2D Vecteur2D::rotation(const Vecteur2D& R, const Degree& theta) const {
	Vecteur2D v = *this;

	v.x = R.x + ((x - R.x) * cos(theta.toRadian()) - (y - R.y) * sin(theta.toRadian()));
	v.y = R.y + ((x - R.x) * sin(theta.toRadian()) + (y - R.y) * cos(theta.toRadian()));

	return v;
}

const Vecteur2D Vecteur2D::homothetie(const Vecteur2D& C, const double& a) const {
	Vecteur2D v = *this;
	v.x = a * (x - C.x) + C.x;
	v.y = a * (y - C.y) + C.y;

	return v;
}

inline const double determinant(const Vecteur2D& u, const Vecteur2D& v) {
	return (u.x * v.y) - (u.y * v.x);
}

inline const Vecteur2D operator *(const double& k, const Vecteur2D& v) {
	Vecteur2D t = v;
	t.x = t.x * k;
	t.y = t.y * k;

	return t;
}

const Vecteur2D Vecteur2D::operator+=(const Vecteur2D& v) {
	*this = *this + v;
	return *this;
}

const string Vecteur2D::operator+(const string& s) const {
	return (string)(*this) + s;
}

inline const string operator+(const string& s, const Vecteur2D& u){
	return s + (string)u;
}

inline const Vecteur2D operator+(const double& d, const Vecteur2D& u) {
	Vecteur2D res;
	res.x = u.x + d;
	res.y = u.y + d;

	return res;
}

bool Vecteur2D::operator >=(const Vecteur2D& v) const {
	return (x > v.x) || (x == v.x && y >= v.y);
}

bool Vecteur2D::operator <=(const Vecteur2D& v) const {
	return (x < v.x) || (x == v.x && y <= v.y);
}

bool Vecteur2D::operator >(const Vecteur2D& v) const {
	return  (x > v.x) || (x == v.x && y > v.y);
}

bool Vecteur2D::operator <(const Vecteur2D& v) const {
	return (x < v.x) || (x == v.x && y < v.y);
}

const Vecteur2D Vecteur2D::operator+(const double& d) const {
	Vecteur2D res;
	res.x = x + d;
	res.y = y + d;

	return res;
}

inline const Vecteur2D Vecteur2D::operator+=(const double& d) const {
	return (* this) + d;
}

inline vector<Vecteur2D> tri_fusion(const vector<Vecteur2D> T) {
	if (T.size() <= 1)
		return T;
	else {
		vector<Vecteur2D> t1(T.begin(), T.begin() + T.size() / 2);
		vector<Vecteur2D> t2(T.begin() + T.size() / 2, T.end());;
		return fusion(tri_fusion(t1), tri_fusion(t2));
	}
}

inline vector<Vecteur2D> fusion(const vector<Vecteur2D> T1, const vector<Vecteur2D> T2) {
	if (T1.empty())
		return T2;
	if (T2.empty())
		return T1;
	if (T1[0] <= T2[0]) {
		vector<Vecteur2D> t1SansPremier(T1.begin() + 1, T1.end());
		vector<Vecteur2D> t = fusion(t1SansPremier, T2);
		t.insert(t.begin(), T1.front());
		return t;
	}
	else {
		vector<Vecteur2D> t2SansPremier(T2.begin() + 1, T2.end());
		vector<Vecteur2D> t = fusion(T1, t2SansPremier);
		t.insert(t.begin(), T2.front());
		return t;
	}
		
}

#endif