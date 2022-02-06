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
            int port = 44444;
            ServerSocket serveur = new ServerSocket(port);
            System.out.println("Démarrage du serveur...");

            while(true){
                System.out.println("En attente de connexion...");
                Socket adresseClient = serveur.accept();
                System.out.println("Connexion en cours...");
                System.out.println("Client connecté: " + adresseClient);
                Interlocuteur interlocuteur = new Interlocuteur(adresseClient);
                interlocuteur.start();
            }
        } catch (Exception e) {
            System.out.println("Erreur: " + e.getMessage());
        }
    }
}
