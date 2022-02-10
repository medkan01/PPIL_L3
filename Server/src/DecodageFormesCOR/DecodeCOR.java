package DecodageFormesCOR;

import Forme.Forme;

public abstract class DecodeCOR extends Decode {
    DecodeCOR suivant; // Expert suivant.

    /**
     * Constructeur de la classe DecodeCOR.
     * 
     * @param suivant : Expert suivant.
     */
    public DecodeCOR(DecodeCOR suivant) {
        this.suivant = suivant;
    }

    /**
     * Decode la forme entree au format texte, si l'expert en est capable.
     * 
     * @param str : forme au format texte qui doit etre decode.
     * @return Forme decodee.
     */
    abstract protected Forme decodeForme1(String str);

    public Forme decodeForme(String str) {
        Forme f = this.decodeForme1(str);

        if (f != null)
            return f;

        if (this.suivant != null)
            return this.suivant.decodeForme(str);

        return null;
    }
}
