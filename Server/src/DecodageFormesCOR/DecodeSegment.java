package DecodageFormesCOR;

import Forme.Forme;
import Forme.Vecteur2D;

public class DecodeSegment extends DecodeCOR {

    /**
     * Constructeur de la classe DecodeSegment.
     * 
     * @param suivant : Expert suivant.
     */
    public DecodeSegment(DecodeCOR suivant) {
        super(suivant);
    }

    /**
     * Decode la forme entree au format texte, si l'expert en est capable.
     * 
     * @param str : forme au format texte qui doit etre decode.
     * @return Forme decodee.
     */
    public Forme decodeForme1(String str) {
        try {
            String[] newStr = str.split("/"); // newStr[0] = type; newStr[1] = liste des points; newStr[2] = couleur;
            String type = newStr[0];
            String[] listePoints = newStr[1].split(";");
            String couleur = newStr[2];

            if (!type.equals("segment"))
                return null;

            if (listePoints.length != 2)
                return null;

            Vecteur2D[] points = new Vecteur2D[2]; // 2 points pour un segment
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
