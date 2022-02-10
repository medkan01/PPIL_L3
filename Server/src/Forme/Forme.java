package Forme;

public class Forme {
    String type;
    Vecteur2D[] points;
    String couleur;

    /**
     * Constructeur de la classe Forme.
     * 
     * @param typ : type de la forme
     * @param pts : liste des points de la forme
     * @param clr : couleur de la forme
     */
    public Forme(String typ, Vecteur2D[] pts, String clr) {
        this.type = typ;
        this.points = pts;
        this.couleur = clr;
    }

    /**
     * Methode toString permettant de mettre un forme au format texte.
     * 
     * @return Forme au format texte.
     */
    public String toString() {
        String res;
        res = this.type + "\n";
        for (Vecteur2D s : this.points) {
            res += "Point: (" + s.x + ", " + s.y + ")\n";
        }
        res += "Couleur: " + this.couleur + "\n";

        return res;
    }
}
