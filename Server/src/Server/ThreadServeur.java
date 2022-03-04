package Server;

public class ThreadServeur implements Runnable {
    Interlocuteur i;

    /**
     * Constructeur de la classe ThreadServeur.
     * 
     * @param i : Interlocuteur a envoyer dans un nouveau thread.
     */
    public ThreadServeur(Interlocuteur i) {
        this.i = i;
    }

    /**
     * Methode run de l'interface Runnable.
     */
    public void run() {
        try {
            this.i.start();
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
