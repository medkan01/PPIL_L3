package Dessin;

public class TestDessin {
    public static void main(String[] args) {
        try {
            Dessin d = new Dessin("Test de la fenetre de dessin", 0, 0, 1280, 1080);

        } catch (Exception e) {
            System.out.println("Erreur: " + e);
        }

    }
}
