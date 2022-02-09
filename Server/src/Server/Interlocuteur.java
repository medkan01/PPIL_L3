package Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;

// import DecodageFormesCOR.DecodeurForme;
// import Forme.Forme;

/**
 * Classe qui va gérer les communications entre le serveur et les clients.
 */
public class Interlocuteur {
    BufferedReader fluxEntrant;
    PrintStream fluxSortant;

    /**
     * Constructeur de la classe Interlocuteur.
     * 
     * @param Socket socket - socket permettant la connexion entre un client et le
     *               serveur.
     * @throws Exception
     */
    public Interlocuteur(Socket socket) throws Exception {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
    }

    /**
     * Procédure étant le comportement du serveur lorsque qu'il reçoit un message.
     */
    public void start() throws Exception {
        try {
            while (!Thread.interrupted()) {
                String requete = this.fluxEntrant.readLine();
                if (requete != null)
                    System.out.println("Message reçu: \n" + requete + "\n");
                String reponse = "Message bien recu.";
                this.fluxSortant.println(reponse);
            }
        } catch (SocketException e) {
            // System.out.println("Connection arrêtée par le client.");
        } catch (Exception e) {
            System.out.println("Erreur: " + e);
        }
    }
}
