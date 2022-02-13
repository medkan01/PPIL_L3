package DessinerFormesCOR;

import Dessin.Dessin;
import Forme.Vecteur2D;

public class DessinerSegment extends DessinerCOR {

    public DessinerSegment(DessinerCOR suivant) {
        super(suivant);
    }

    protected boolean dessinerForme1(String requete, Dessin d) {
        // On separe les informations.
        String[] newStr = requete.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;
        String type = newStr[0];
        String[] listePoints = newStr[1].split(";");
        // String couleur = newStr[2];

        // On verifie si c'est un segment.
        if (!type.equals("segment"))
            return false;

        // On verifie qu'il y a le bon nombre de points pour faire un segment.
        if (listePoints.length != 2)
            return false;

        // On reparti les points.
        Vecteur2D[] points = new Vecteur2D[2]; // 2 points pour un segment
        int i = 0;

        for (String s : listePoints) {
            points[i] = new Vecteur2D(s);
            i++;
        }

        // Tout est bon pour dessiner le segment, alors on le dessine

        try {
            d.graphics.drawLine((int) points[0].x, (int) points[0].y, (int) points[1].x, (int) points[1].y);
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
