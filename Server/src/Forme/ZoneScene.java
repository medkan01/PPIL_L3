package Forme;

public class ZoneScene {
    public Vecteur2D p1;
    public Vecteur2D p2;

    public ZoneScene(Vecteur2D p1, Vecteur2D p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public ZoneScene(ZoneScene zone) {
        this.p1 = zone.p1;
        this.p2 = zone.p2;
    }
}
