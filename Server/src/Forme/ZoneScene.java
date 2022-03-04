package Forme;

public class ZoneScene {
    public Vecteur2D p1;
    public Vecteur2D p2;

    /**
     * Constructeur de la classe ZoneScene.
     * 
     * @param p1 : Point p1 de la zone de scene.
     * @param p2 : Point p2 de la zone de scene.
     */
    public ZoneScene(Vecteur2D p1, Vecteur2D p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    /**
     * Constructeur par recopie de la classe ZoneScene.
     * 
     * @param zone : Zone a copier.
     */
    public ZoneScene(ZoneScene zone) {
        this.p1 = zone.p1;
        this.p2 = zone.p2;
    }
}
