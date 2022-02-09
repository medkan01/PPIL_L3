#pragma once
#include <stdio.h>
#include "TestVecteur2D.h"
#include "TestRadian.h"
#include "TestDegree.h"
#include "TestSegment.h"
#include "TestTriangle.h"
#include "Client.h"
using namespace std;

int main() {
	/*
	Vecteur2D a(0, 0), b(3, 3), c(6, 0);
	Vecteur2D d(2, 5), e(8, 9);
	Couleur noire("Noire");
	Couleur blanche("Blanche");

	Triangle t(noire, a, b, c);
	Segment s(blanche, d, e);

	Client::envoieDonnee("127.0.0.1", 44444, t);
	Client::envoieDonnee("127.0.0.1", 44444, s);
	*/
	WSADATA wsaData;
	SOCKET sock;
	Client::connection("127.0.0.1", 44444, &wsaData, &sock);
	int r;

	char recvbuf[512];
	int recvbuflen = 512;

	// Envoie de donnees au serveur
	if ((r = send(sock, "HelloWorld!\r\n", 13, 0)) == SOCKET_ERROR)
		throw exception("Socket Error.");
	
	if((r = recv(sock, recvbuf, recvbuflen, 0)) == SOCKET_ERROR)
		throw exception("Socket Error.");

	cout << recvbuf << endl;

	closesocket(sock);
	WSACleanup();

	return 0;
}