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
	static void connect(const string& ip = "127.0.0.1", const int& port = 44444);
};

void Client::connect(const string& ip = "127.0.0.1", const int& port = 44444) {
	// Déclaration des variables
	int r;
	WSADATA wsaData;

	int familleAdresse = AF_INET;
	int typeSocket = SOCK_STREAM;
	int protocole = IPPROTO_TCP;
	SOCKET sock;

	SOCKADDR_IN sockaddr;

	sockaddr.sin_family = AF_INET;
	inet_pton(AF_INET, (PCSTR)adresse, &sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(port);

	// Initialisation de Winsock
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw Erreur("WSAStartup");

	sock = socket(familleAdresse, typeSocket, protocole);
	if (sock == SOCKET_ERROR) throw Erreur("Socket error");

	r = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
	if (r == SOCKET_ERROR) throw Erreur("Socket error");

	cout << "Connexion au serveur réussie." << endl;

	string requete;
	cout << "Veuillez saisir un message" << endl;
	cin >> requete;
	if (requete == "") requete = "HelloWorld!";
	requete += " \r\n";
	int l = strlen(requete.c_str());

	r = send(sock, requete.c_str(), l, 0);

	if (r == SOCKET_ERROR) throw Erreur("Socket error");

	cout << "Message envoyé avec succés." << endl;
}



#endif