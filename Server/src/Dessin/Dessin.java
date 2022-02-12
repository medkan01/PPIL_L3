package Dessin;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.Dimension;

public class Dessin extends Frame {
    public Graphics graphics;

    /**
     * Constructeur de la classe Dessin.
     * 
     * @param titre   : Titre de la fenetre.
     * @param ox      : Abcisse pour le bord gauche de la fenetre. (pixel)
     * @param oy      : Ordonnee pour le bord superieur de la fenetre. (pixel)
     * @param largeur : Largeur de la fenetre. (pixel)
     * @param hauteur : Hauteur de la fenetre. (pixel)
     */
    public Dessin(String titre, int ox, int oy, int largeur, int hauteur) throws Exception {
        super(titre);
        // Parametrage de la fenetre - Dimensions et position
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
        Thread.sleep(50); // 50ms mini pour que le buffer soit operationnel.
        this.graphics = this.getBufferStrategy().getDrawGraphics();
    }
}