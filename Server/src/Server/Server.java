package Server;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe serveur qui contient la fonction main.
 * Se charge d'initialiser le serveur Java.
 */
public class Server {
    public static void main(String[] args) {
        try {
            int n = 10;

            // Creation et initialisation du socket
            int port = 44444;
            ServerSocket serveur = new ServerSocket(port);
            while (--n >= 0) {
                // Attente de connexion
                Socket adresseClient = serveur.accept(); // Bloquant
                Interlocuteur interlocuteur = new Interlocuteur(adresseClient);

                // Creation d'un thread pour permettre la connexion de plusieurs client
                // simultanement
                ThreadServeur t = new ThreadServeur(interlocuteur);
                t.start();
            }

            serveur.close();
        } catch (

        Exception e) {
            System.out.println("Erreur: " + e);
        }
    }
}
