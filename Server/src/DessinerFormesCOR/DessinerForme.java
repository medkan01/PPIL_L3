package DessinerFormesCOR;

import Dessin.Dessin;

public class DessinerForme {

    public static boolean dessine(String s, Dessin dessin) {
        DessinerCOR d;

        d = new DessinerSegment(null);
        d = new DessinerTriangle(d);

        return d.dessinerForme(s, dessin);
    }
}
