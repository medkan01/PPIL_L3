package DessinerFormesCOR;

import Dessin.Dessin;

public abstract class DessinerCOR extends Dessiner {
    DessinerCOR suivant;

    /**
     * Constructeur de la classe DessinerCOR.
     * 
     * @param suivant
     */
    public DessinerCOR(DessinerCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * 
     * 
     * @param requete
     * @param d
     * @return
     */
    abstract protected boolean dessinerForme1(String requete, Dessin d);

    public boolean dessinerForme(String requete, Dessin d) {
        boolean resultat = this.dessinerForme1(requete, d);

        if (resultat == true)
            return true;

        if (this.suivant != null)
            return this.suivant.dessinerForme(requete, d);

        return false;
    }

}
