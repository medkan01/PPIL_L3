#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Client {
public:
	static SOCKET envoieDonnee(const char* ip, const int& port, const string& msg = "");
	static void connection(const char* ip, const int& port, WSADATA* wsaData, SOCKET* sock);
};

SOCKET Client::envoieDonnee(const char* ip, const int& port, const string& msg) {
	try {
		// D�claration des variables.
		int r;
		WSADATA wsaData;

		int familleAdresse = AF_INET;
		int typeSocket = SOCK_STREAM;
		int protocole = IPPROTO_TCP;
		SOCKET sock;

		SOCKADDR_IN sockaddr;

		sockaddr.sin_family = AF_INET;
		inet_pton(AF_INET, (PCSTR)ip, &sockaddr.sin_addr.s_addr);
		sockaddr.sin_port = htons(port);

		// Initialisation de Winsock.
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);
		if (r) throw exception("WSAStartup");

		sock = socket(familleAdresse, typeSocket, protocole);
		if (sock == SOCKET_ERROR) throw exception("Socket error");

		r = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR) throw exception("Socket error");
		cout << "Connexion au serveur reussie." << endl;
		
		// Envoie des donn�es.
		string requete = msg == "" ? "ping" : msg;
		requete += "\r\n";
		int l = strlen(requete.c_str());

		r = send(sock, requete.c_str(), l, 0);
		if (r == SOCKET_ERROR) throw exception("Socket error");
		

		cout << "Message envoye avec succes." << endl;
	}
	catch (exception e) {
		cout << "Erreur: " << e.what() << endl;
	}
}


void Client::connection(const char* ip, const int& port, WSADATA* wsaData, SOCKET* sock) {
	// Initialisation de winsock
	if (WSAStartup(MAKEWORD(2, 2), wsaData) != 0)
		throw exception("Initialisation de WSADATA.");

	// Creation du socket
	if ((*sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw exception("Creation du socket.");

	// Parametrage des informations du serveur
	SOCKADDR_IN sockaddr;
	sockaddr.sin_family = AF_INET;
	inet_pton(AF_INET, (PCSTR)ip, &sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(port);

	// Tentative de connexion au serveur
	int r;
	if((r = connect(*sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) == SOCKET_ERROR)
		throw exception("Connexion au serveur.");
}

#endif