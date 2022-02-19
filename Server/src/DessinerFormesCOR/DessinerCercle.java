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

        String[] listePoints = newStr[1].split(";");
        // String couleur = newStr[2];
        String[] rep = newStr[3].split(";");
        Vecteur2D p1 = new Vecteur2D(rep[0]);
        Vecteur2D p2 = new Vecteur2D(rep[1]);

        ZoneScene zoneRecue = new ZoneScene(p1, p2);

        Repere r = new Repere(zoneRecue, d.zone);

        // On verifie qu'il y a le bon nombre de points pour faire un cercle.
        if (listePoints.length != 2)
            return false;

        // On reparti les points.
        Vecteur2D[] points = new Vecteur2D[2]; // 2 points pour un cercle
        int i = 0;

        for (String s : listePoints) {
            points[i] = r.transforme(new Vecteur2D(s));
            i++;
        }

        // Tout est bon pour dessiner le cercle, alors on le dessine

        try {
            d.graphics.drawOval((int) points[0].x, (int) points[0].y, (int) Vecteur2D.distance(points[0], points[1]),
                    (int) Vecteur2D.distance(points[0], points[1]));
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
