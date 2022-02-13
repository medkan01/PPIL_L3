package Forme;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.naming.ldap.ManageReferralControl;

public class Vecteur2D {
    public int x;
    public int y;

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
            Pattern p = Pattern.compile("\\(([+-]?(\\d*[.])?\\d+)\\,\\s*([+-]?(\\d*[.])?\\d+)\\)");
            Matcher m = p.matcher(str);

            m.find();

            String resX = m.group(1);
            String resY = m.group(3);

            double doubleX = Double.parseDouble(resX);
            double doubleY = Double.parseDouble(resY);

            this.x = (int) doubleX;
            this.y = (int) doubleY;

        } catch (Exception e) {
            System.out.println("Pattern incorrect");
            System.exit(1);
        }

    }

    public static Vecteur2D changementRepere(Vecteur2D v) {
        Vecteur2D n = v;
        // double lambda

        return n;
    }

    public static void main(String[] args) {
        Pattern p = Pattern.compile("\\(([+-]?([0-9]*[.])?[0-9]+)\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\)");
        Matcher m1 = p.matcher("(10,10)");
        Matcher m2 = p.matcher("(12.210, 85)");
        Matcher m3 = p.matcher("(45,87.2)");
        Matcher m4 = p.matcher("(85,59)");

        System.out.println(m1.find());
        System.out.println(m2.find());
        System.out.println(m3.find());
        System.out.println(m4.find());

        System.out.println(m1.group(1) + ", " + m1.group(3));
        System.out.println(m2.group(1) + ", " + m2.group(3));
        System.out.println(m3.group(1) + ", " + m3.group(3));
        System.out.println(m4.group(1) + ", " + m4.group(3));

        Vecteur2D v = new Vecteur2D("(10,5)");

        System.out.println(v.x + ", " + v.y);

    }
}
