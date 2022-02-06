#ifndef CLIENT_H
#define CLIENT_H

#include <winsock2.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Client {
public:
	static void connection(const char* ip, const int& port);
};

void Client::connection(const char* ip, const int& port) {
	try {
		// Déclaration des variables
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

		// Initialisation de Winsock
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);
		if (r) throw exception("WSAStartup");

		sock = socket(familleAdresse, typeSocket, protocole);
		if (sock == SOCKET_ERROR) throw exception("Socket error");

		r = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR) throw exception("Socket error");

		cout << "Connexion au serveur réussie." << endl;
		string requete;
		while (requete != "stop") {
			cout << "Veuillez saisir un message" << endl;
			getline(cin, requete);
			if (requete == "") requete = "HelloWorld!";
			requete += " \r\n";
			int l = strlen(requete.c_str());

			r = send(sock, requete.c_str(), l, 0);

			if (r == SOCKET_ERROR) throw exception("Socket error");

			cout << "Message envoyé avec succés." << endl;
		}
	}
	catch (exception e) {
		cout << "Erreur: " << e.what() << endl;
	}
	
}

#endif