package Forme;

public class Forme {
    String type;
    String[] points;
    String couleur;

    public Forme(String typ, String[] pts, String clr) {
        this.type = typ;
        this.points = pts;
        this.couleur = clr;
    }

    public String toString() {
        String res;
        res = this.type + "\n";
        int i = 0;
        for (String s : this.points) {
            if (i == 1) {
                res += s + ")\n";
                i = 0;
            } else {
                res += "Point: (" + s + ",";
                i++;
            }
        }
        res += "Couleur: " + this.couleur + "\n";

        return res;
    }
}
