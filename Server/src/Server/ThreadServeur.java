package Server;

public class ThreadServeur implements Runnable {
    Interlocuteur i;

    public ThreadServeur(Interlocuteur i) {
        this.i = i;
    }

    public void run() {
        try {
            this.i.start();
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
