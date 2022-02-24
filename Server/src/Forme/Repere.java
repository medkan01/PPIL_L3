package Forme;

public class Repere {
    public double lambda;
    public int e1, e2;
    public Vecteur2D omega;

    public Repere(ZoneScene z1, ZoneScene z2) {
        Vecteur2D p1, p2, q1, q2;
        double x1, x2, y1, y2, x1p, x2p, y1p, y2p;

        p1 = z1.p1;
        p2 = z1.p2;
        q1 = z2.p1;
        q2 = z2.p2;

        x1 = p1.x;
        x2 = p2.x;
        y1 = p1.y;
        y2 = p2.y;

        x1p = q1.x;
        x2p = q2.x;
        y1p = q1.y;
        y2p = q2.y;

        Vecteur2D C = new Vecteur2D((x1 + x2) / 2, (y1 + y2) / 2);
        Vecteur2D Cp = new Vecteur2D((x1p + x2p) / 2, (y1p + y2p) / 2);

        double lambda = Math.min((Math.abs(x2p - x1p)) / (Math.abs(x2 - x1)),
                (Math.abs(y2p - y1p)) / (Math.abs(y2 - y1)));

        int e1, e2;

        if ((x2 - x1 >= 0) == (x2p - x1p >= 0))
            e1 = 1;
        else
            e1 = -1;

        if ((y2 - y1 >= 0) == (y2p - y1p >= 0))
            e2 = 1;
        else
            e2 = -1;

        Vecteur2D LYc = new Vecteur2D(lambda * e1 * C.x, lambda * e2 * C.y);

        Vecteur2D omega = new Vecteur2D(Cp.x - LYc.x, Cp.y - LYc.y);

        this.lambda = lambda;
        this.e1 = e1;
        this.e2 = e2;
        this.omega = omega;
    }

    public Vecteur2D transforme(Vecteur2D u) {
        double xp = this.lambda * this.e1 * u.x + this.omega.x;
        double yp = this.lambda * this.e2 * u.y + this.omega.y;

        Vecteur2D v = new Vecteur2D(xp, yp);

        return v;
    }

    public Vecteur2D transformeInverse(Vecteur2D u) {
        double xp = (u.x - this.omega.x) / (this.lambda * e1);
        double yp = (u.y - this.omega.y) / (this.lambda * e2);

        Vecteur2D v = new Vecteur2D(xp, yp);

        return v;
    }
}
