package Forme;

import DecodageFormesCOR.DecodeurForme;

public class TestDecode {
    public static void main(String[] args) {
        String segment = "segment/10/10/50/50/Noire";
        String triangle = "triangle/10/10/50/50/20/20/Rouge";
        String cercle = "cercle/50/30/70/50/Rouge";

        Forme f1 = DecodeurForme.decode(segment);
        System.out.println("Forme f1 :");
        System.out.println(f1.toString());

        Forme f2 = DecodeurForme.decode(cercle);
        System.out.println("Forme f2 :");
        System.out.println(f2.toString());

        Forme f3 = DecodeurForme.decode(triangle);
        System.out.println("Forme f3 :");
        System.out.println(f3.toString());

    }
}
