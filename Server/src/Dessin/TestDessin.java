package Dessin;

public class TestDessin {
    public static void main(String[] args) {
        try {
            Dessin d = new Dessin("Test de la fenetre de dessin", 0, 0, 800, 600);
            d.graphics.drawLine(100, 300, 600, 500);
            d.graphics.drawLine(600, 500, 700, 300);
            d.graphics.drawLine(700, 300, 100, 300);
        } catch (Exception e) {
            System.out.println("Erreur: " + e);
        }

    }
}
