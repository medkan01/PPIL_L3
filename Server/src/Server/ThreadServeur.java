package Server;

public class ThreadServeur extends Thread {
    Interlocuteur i;

    public ThreadServeur(Interlocuteur i) {
        super();
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
