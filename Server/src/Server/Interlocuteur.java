package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Classe qui va gérer les communications entre le serveur et les clients.
 */
public class Interlocuteur {
    BufferedReader fluxEntrant;
	PrintStream fluxSortant;

    /**
     * Constructeur de la classe Interlocuteur.
     * 
     * @param Socket socket - socket permettant la connexion entre un client et le serveur.
     * @throws Exception
     */
    public Interlocuteur(Socket socket) throws Exception {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
    }

    /**
     * Procédure étant le comportement du serveur lorsque qu'il reçoit un message.
     */
    public void start() {
        try {
            while(!Thread.interrupted()) {
                String requete = this.fluxEntrant.readLine();
                System.out.println("Message reçu: " + requete + "\n");
                this.fluxSortant.println("1");
            }
        } catch (Exception e) {
            System.out.println("Erreur: " + e.getMessage());
        }
    }
}
