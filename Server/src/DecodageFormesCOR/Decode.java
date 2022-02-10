package DecodageFormesCOR;

import Forme.Forme;

public abstract class Decode {

    /**
     * Lance l'algorithme de decodage de la forme à l'aide du design pattern Chain
     * of Responsability.
     * 
     * @param s : forme au format texte qui doit etre decodee.
     * @return Forme decodee.
     */
    protected abstract Forme decodeForme(String s);
}
