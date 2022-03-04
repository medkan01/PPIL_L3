package DessinerFormesCOR;

import Dessin.Dessin;

public abstract class Dessiner {
    /***
     * Methode initiale et necessaire pour le Design Pattern Chaine de
     * Responsabilite
     * 
     * @param requete : Forme a decoder.
     * @param d       : Dessin sur lequel il faut dessiner la forme.
     * @return boolean exprimant si la forme a pu etre decodee ou non.
     */
    protected abstract boolean dessinerForme(String requete, Dessin d);
}
