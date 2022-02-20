package Forme;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Vecteur2D {
    public double x;
    public double y;

    /**
     * Constructeur de la classe Vecteur2D.
     * 
     * @param x : Abcisse du points.
     * @param y : Ordonnee du points.
     */
    public Vecteur2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Vecteur2D(String str) {
        try {
            Pattern p = Pattern.compile("\\(([+-]?(\\d*[.])?\\d+)\\,\\s*([+-]?(\\d*[.])?\\d+)\\)");
            Matcher m = p.matcher(str);

            m.find();

            String resX = m.group(1);
            String resY = m.group(3);

            this.x = Double.parseDouble(resX);
            this.y = Double.parseDouble(resY);

        } catch (Exception e) {
            System.out.println("Pattern incorrect");
            System.exit(1);
        }
    }

    public static double distance(Vecteur2D u, Vecteur2D v) {
        return Math.abs(Math.sqrt(Math.pow((v.x - u.x), 2) + Math.pow((v.y - u.y), 2)));
    }
}
