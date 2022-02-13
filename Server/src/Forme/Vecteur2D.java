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
    public Vecteur2D(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Vecteur2D(String str) {
        try {
            Pattern p = Pattern.compile("\\(([+-]?([0-9]*[.])?[0-9]+)\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\)");
            Matcher m = p.matcher(str);

            m.find();

            this.x = Double.parseDouble(m.group(1));
            this.y = Double.parseDouble(m.group(3));
        } catch (Exception e) {
            System.out.println("Pattern incorrect");
        }

    }

    public static Vecteur2D changementRepere(Vecteur2D v) {
        Vecteur2D n = v;
        // double lambda

        return n;
    }
}
