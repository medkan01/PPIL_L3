package DecodageFormesCOR;

import Forme.Forme;

public class DecodeurForme {

    /**
     * Lance l'algorithme de decodage de la forme à l'aide du design pattern Chain
     * of Responsability.
     * 
     * @param s : forme au format texte qui doit etre decodee.
     * @return Forme decodee.
     */
    public static Forme decode(String s) {
        DecodeCOR d;

        d = new DecodeSegment(null);
        d = new DecodeCercle(d);
        d = new DecodeTriangle(d);

        return d.decodeForme(s);
    }
}
