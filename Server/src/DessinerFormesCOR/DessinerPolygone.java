package DessinerFormesCOR;

import Dessin.Dessin;
import Dessin.ZoneScene;
import Forme.Repere;
import Forme.Vecteur2D;
import java.awt.Color;

public class DessinerPolygone extends DessinerCOR {
    public DessinerPolygone(DessinerCOR suivant) {
        super(suivant);
    }

    protected boolean dessinerForme1(String requete, Dessin d) {
        // On separe les informations.
        String[] newStr = requete.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;

        // On recupere le type de la forme.
        String type = newStr[0];

        // On verifie si c'est un segment.
        if (!type.equals("polygone"))
            return false;

        // On recupere la couleur
        String[] couleur = newStr[1].split("-");
        Color c = new Color(Integer.parseInt(couleur[0]), Integer.parseInt(couleur[1]), Integer.parseInt(couleur[2]));

        // On recupere ensuite la repere dans lequel se trouve la forme.
        String[] rep = newStr[2].split(";");
        Vecteur2D p1 = new Vecteur2D(rep[0]);
        Vecteur2D p2 = new Vecteur2D(rep[1]);

        ZoneScene zoneRecue = new ZoneScene(p1, p2);

        Repere r = new Repere(zoneRecue, d.zone);

        // On recupere ensuite la liste des points.
        String[] listePoints = newStr[3].split(";");

        // On reparti les points.
        Vecteur2D[] points = new Vecteur2D[listePoints.length]; // 2 points pour un segment
        int i = 0;

        for (String s : listePoints) {
            points[i] = r.transforme(new Vecteur2D(s));
            i++;
        }

        // Tout est bon pour dessiner le segment, alors on le dessine
        try {
            d.graphics.setColor(c);
            for (int j = 0; j < i; j++)
                d.graphics.drawLine((int) points[j].x, (int) points[j].y, (int) points[(j + 1) % i].x,
                        (int) points[(j + 1) % i].y);
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
