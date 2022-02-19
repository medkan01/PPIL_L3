package Dessin;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import Forme.Vecteur2D;
import java.awt.Dimension;

public class Dessin extends Frame {
    public Graphics graphics;
    public ZoneScene zone;

    /**
     * Constructeur de la classe Dessin.
     * 
     * @param titre   : Titre de la fenetre.
     * @param posFen  : Position de la fenetre. (pixel)
     * @param largeur : Largeur de la fenetre. (pixel)
     * @param hauteur : Hauteur de la fenetre. (pixel)
     */
    public Dessin(String titre, Vecteur2D posFen, int largeur, int hauteur) throws Exception {
        super(titre);
        // Parametrage de la fenetre - Dimensions et position
        int ox, oy;
        ox = (int) posFen.x;
        oy = (int) posFen.y;

        Toolkit tk = Toolkit.getDefaultToolkit();
        int larE, hauE; // Largeur et hauteur de l'ecran
        Dimension dimension = tk.getScreenSize();
        larE = (int) dimension.getWidth();
        hauE = (int) dimension.getHeight();

        int bordGauche, bordSuperieur, l, h;

        bordGauche = Math.max(0, ox);
        bordSuperieur = Math.max(0, oy);
        l = Math.min(largeur, larE - bordGauche);
        h = Math.min(hauteur, hauE - bordSuperieur);

        this.setBounds(bordGauche, bordSuperieur, l, h);
        this.setVisible(true);

        // Active rendering - Initialisation
        this.setIgnoreRepaint(true);

        int nbBuffers = 1;
        this.createBufferStrategy(nbBuffers);
        Thread.sleep(100); // 50ms mini pour que le buffer soit operationnel.
        this.graphics = this.getBufferStrategy().getDrawGraphics();

        Vecteur2D p1 = new Vecteur2D(0, hauteur);
        Vecteur2D p2 = new Vecteur2D(largeur, 0);

        this.zone = new ZoneScene(p1, p2);
    }
}

// package Dessin;

// import java.awt.Frame;
// import java.awt.Graphics;
// import java.awt.Toolkit;
// // import java.awt.image.BufferStrategy;
// import Forme.Vecteur2D;
// import java.awt.Dimension;

// public class Dessin extends Frame {
// public Graphics graphics;
// public ZoneScene zone;

// /**
// * Constructeur de la classe Dessin.
// *
// * @param titre : Titre de la fenetre.
// * @param posFen : Position de la fenetre. (pixel)
// * @param largeur : Largeur de la fenetre. (pixel)
// * @param hauteur : Hauteur de la fenetre. (pixel)
// */
// public Dessin(String titre, Vecteur2D posFen, int largeur, int hauteur)
// throws Exception {
// super(titre);
// // Parametrage de la fenetre - Dimensions et position
// Toolkit tk = Toolkit.getDefaultToolkit();
// int largeurEcran, hauteurEcran; // Largeur et hauteur de l'ecran
// Dimension dimension = tk.getScreenSize();
// largeurEcran = (int) dimension.getWidth();
// hauteurEcran = (int) dimension.getHeight();

// int bordGauche, bordSuperieur, l, h;

// bordGauche = Math.max(0, (int) posFen.x);
// bordSuperieur = Math.max(0, (int) posFen.y);
// l = Math.min(largeur, largeurEcran - bordGauche);
// h = Math.min(hauteur, hauteurEcran - bordSuperieur);

// this.setBounds(bordGauche, bordSuperieur, l, h);
// this.setVisible(true);

// // Active rendering - Initialisation
// this.setIgnoreRepaint(true);

// int nbBuffers = 2;
// this.createBufferStrategy(nbBuffers);
// Thread.sleep(100); // 50ms mini pour que le buffer soit operationnel.
// this.graphics = this.getBufferStrategy().getDrawGraphics();

// Vecteur2D p1 = new Vecteur2D(0, hauteur);
// Vecteur2D p2 = new Vecteur2D(largeur, 0);

// this.zone = new ZoneScene(p1, p2);
// }

// // public static void main(String[] args) {
// // try {
// // Frame f = new Frame("Frame en Active Rendering");
// // f.setBounds(30, 60, 400, 400);

// // f.setVisible(true);
// // f.setIgnoreRepaint(true);
// // int nBuffers = 2;
// // f.createBufferStrategy(nBuffers);
// // Thread.sleep(150);

// // BufferStrategy strat = f.getBufferStrategy();
// // Graphics g = strat.getDrawGraphics();

// // g.drawLine(30, 30, 100, 100);
// // g.drawLine(30, 100, 100, 30);

// // strat.show();
// // g.dispose();

// // } catch (Exception e) {
// // System.out.println(e);
// // }
// // }
// }