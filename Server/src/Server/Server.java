package Server;

import java.net.ServerSocket;
import java.net.Socket;

import Dessin.Dessin;
import Forme.Vecteur2D;

/**
 * Classe serveur qui contient la fonction main.
 * Se charge d'initialiser le serveur Java.
 */
public class Server {
    public static void main(String[] args) {
        try {
            int n = 10;

            // Creation d'une fenetre de dessin
            Dessin d = new Dessin("Serveur de dessin", new Vecteur2D(0, 0), 1100, 700);

            // Creation et initialisation du socket
            int port = 44444;
            ServerSocket serveur = new ServerSocket(port);
            while (--n >= 0) {
                // Attente de connexion
                Socket adresseClient = serveur.accept(); // Bloquant
                Interlocuteur interlocuteur = new Interlocuteur(adresseClient, d);

                // Creation d'un thread pour permettre la connexion de plusieurs client
                // simultanement
                ThreadServeur run = new ThreadServeur(interlocuteur);
                Thread t = new Thread(run);
                t.start();
            }

            serveur.close();
        } catch (

        Exception e) {
            System.out.println("Erreur: " + e);
        }
    }
}
