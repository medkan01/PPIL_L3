package DessinerFormesCOR;

import Dessin.Dessin;
import Dessin.ZoneScene;
import Forme.Repere;
import Forme.Vecteur2D;

public class DessinerCercle extends DessinerCOR {

    public DessinerCercle(DessinerCOR suivant) {
        super(suivant);
    }

    protected boolean dessinerForme1(String requete, Dessin d) {
        // On separe les informations.
        String[] newStr = requete.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;
        String type = newStr[0];

        // On verifie si c'est un cercle.
        if (!type.equals("cercle"))
            return false;

        String pointCercle = newStr[1];

        double rayonMonde = Double.parseDouble(newStr[2]);

        String[] rep = newStr[4].split(";");
        Vecteur2D p1 = new Vecteur2D(rep[0]);
        Vecteur2D p2 = new Vecteur2D(rep[1]);

        ZoneScene zoneRecue = new ZoneScene(p1, p2);

        Repere r = new Repere(zoneRecue, d.zone);

        Vecteur2D point = r.transforme(new Vecteur2D(pointCercle));

        int rayon = (int) ((d.zone.p2.x * rayonMonde) / p2.x);

        // Tout est bon pour dessiner le cercle, alors on le dessine
        try {
            d.graphics.drawOval((int) point.x, (int) point.y, rayon, rayon);
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
