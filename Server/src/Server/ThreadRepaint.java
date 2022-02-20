package Server;

import Dessin.Dessin;

public class ThreadRepaint implements Runnable {
    Dessin d;

    public ThreadRepaint(Dessin d) {
        this.d = d;
    }

    public void run() {
        while (!Thread.interrupted())
            d.repaint();
    }
}
