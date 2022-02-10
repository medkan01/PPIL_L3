package DecodageFormesCOR;

import Forme.Forme;
import Forme.Vecteur2D;

public class DecodeTriangle extends DecodeCOR {

    /**
     * Constructeur de la classe DecodeTriangle.
     * 
     * @param suivant : Expert suivant.
     */
    public DecodeTriangle(DecodeCOR suivant) {
        super(suivant);
    }

    /**
     * Decode la forme entree au format texte, si l'expert en est capable.
     * 
     * @param str : forme au format texte qui doit etre decode.
     * @return Forme decodee.
     */
    protected Forme decodeForme1(String str) {
        try {
            String[] newStr = str.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;
            String type = newStr[0];
            String[] listePoints = newStr[1].split(";");
            String couleur = newStr[2];

            if (!type.equals("triangle"))
                return null;

            if (listePoints.length != 3)
                return null;

            Vecteur2D[] points = new Vecteur2D[3]; // 2 points pour un segment
            int i = 0;

            for (String s : listePoints) {
                points[i] = new Vecteur2D(s);
                i++;
            }

            return new Forme(type, points, couleur);
        } catch (Exception e) {
            return null;
        }
    }
}