package DessinerFormesCOR;

import Dessin.Dessin;

public class DessinerForme {

    /**
     * Expert qui dessine une forme.
     * 
     * @param requete : Forme a decoder.
     * @param d       : Dessin sur lequel la forme a decoder doit etre dessinee.
     * @return Resultat du decodage.
     */
    public static boolean dessine(String s, Dessin dessin) {
        DessinerCOR d;

        d = new DessinerSegment(null);
        d = new DessinerTriangle(d);
        d = new DessinerCercle(d);
        d = new DessinerPolygone(d);

        return d.dessinerForme(s, dessin);
    }
}
