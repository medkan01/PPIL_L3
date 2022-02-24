package DessinerFormesCOR;

import Dessin.Dessin;
import Forme.Repere;
import Forme.Vecteur2D;
import Forme.ZoneScene;

import java.awt.Color;

public class DessinerCercle extends DessinerCOR {

    public DessinerCercle(DessinerCOR suivant) {
        super(suivant);
    }

    protected boolean dessinerForme1(String requete, Dessin d) {
        // On separe les informations.
        String[] newStr = requete.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;

        // On recupere le type de la forme.
        String type = newStr[0];

        // On verifie si c'est un cercle.
        if (!type.equals("cercle"))
            return false;

        // On recupere la couleur de la forme.
        String[] couleur = newStr[1].split("-");
        Color c = new Color(Integer.parseInt(couleur[0]), Integer.parseInt(couleur[1]), Integer.parseInt(couleur[2]));

        // On recupere le repere de la forme.
        String[] rep = newStr[2].split(";");
        Vecteur2D p1 = new Vecteur2D(rep[0]);
        Vecteur2D p2 = new Vecteur2D(rep[1]);

        ZoneScene zoneRecue = new ZoneScene(p1, p2);

        Repere r = new Repere(zoneRecue, d.zone);

        // On recupere ensuite les donnees du cercle, a savoir :
        // Le points haut gauche du cercle
        // Le diametre du cercle
        String pointCercle = newStr[3];
        double rayonMonde = Double.parseDouble(newStr[4]);

        Vecteur2D point = r.transforme(new Vecteur2D(pointCercle));

        int rayon = (int) ((d.zone.p2.x * rayonMonde) / p2.x);

        // Tout est bon pour dessiner le cercle, alors on le dessine
        try {
            d.graphics.setColor(c);
            d.graphics.drawOval((int) point.x, (int) point.y, rayon, rayon);
        } catch (Exception e) {
            return false;
        }

        return true;
    }

}
