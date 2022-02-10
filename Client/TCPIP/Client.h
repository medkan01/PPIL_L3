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
	// Attributs
	SOCKADDR_IN sockaddr;
	SOCKET sock;
	WSADATA wsaData;
	static Client s_client;

	/// Constructeur de la classe Client. Mis en prive pour l'utilisation du pattern singleton.
	inline Client();

	/// Destructeur de la classe singleton.
	inline ~Client();

	/// Constructeur par recopie supprime pour eviter de pouvoir creer des copies de l'instance singleton.
	Client(const Client&) = delete;

public:
	/**
	* Getter de l'attribut sockaddr.
	* 
	* @return SOCKADDR_IN - sockaddr
	*/
	SOCKADDR_IN getSockadrr() const { return sockaddr; }

	/**
	* Getter de l'attribut sock.
	*
	* @return SOCKET - sock
	*/
	SOCKET getSocket() const { return sock; }

	/**
	* Getter de l'attribut sockaddr.
	*
	* @return WSADATA - wsaData
	*/
	WSADATA getWsaData() const { return wsaData; }

	/**
	* Permet de récupérer l'instance de client, geree avec le design pattern singleton.
	* 
	* @return Client& - instance de client
	*/
	static Client& instance() { return s_client; }

	/// Permet de connecter le socket au serveur local 127.0.0.1
	inline void connection() const;

	/**
	* Envoie du texte au serveur.
	* 
	* @param const string& data - message a envoyer
	*/
	inline void envoiDonnees(const string& data) const;
};

Client::Client() {
	// Declaration des constantes
	const char* ip = "127.0.0.1";
	const int port = 44444;
	const int familleAdresse = AF_INET;
	const int typeSocket = SOCK_STREAM;
	const int protocole = IPPROTO_TCP;

	// Variable de resultat des actions vers le serveur
	int r;

	sockaddr.sin_family = AF_INET;
	inet_pton(AF_INET, (PCSTR)ip, &sockaddr.sin_addr.s_addr);
	sockaddr.sin_port = htons(port);

	// Initialisation de Winsock.
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw exception("WSAStartup");

	sock = socket(familleAdresse, typeSocket, protocole);
	if (sock == SOCKET_ERROR) throw exception("Socket error");
}

Client::~Client() {
	if (sock != NULL)
		closesocket(sock);

	WSACleanup();
}

void Client::connection() const {
	try {
		int r;
		r = connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR) throw exception("Socket error");
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

inline void Client::envoiDonnees(const string& data) const {
	try {
		string d = data + "\r\n";
		const char* buf = d.c_str();
		const int bufsize = d.length();
		if (send(sock, buf, bufsize, 0) == SOCKET_ERROR) throw exception("Socket error");
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

}
#endif