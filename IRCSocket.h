#ifndef _IRCSocket_H_
#define _IRCSocket_H_

#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

//OSX
#ifdef __APPLE__

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define closesocket(s) close(s)
#define close(s)
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#endif

typedef struct {
    int _socket;
    bool _connected;
} IRCSocket;


bool IRCSocket_Init(IRCSocket* irc_sock);
bool IRCSocket_Connect(IRCSocket* irc_sock, const char* host, int port);
void IRCSocket_Disconnect(IRCSocket* irc_sock);
bool IRCSocket_Connected(IRCSocket* irc_sock);
bool IRCSocket_SendData(IRCSocket* irc_sock, const char* data);
char* IRCSocket_ReceiveData(IRCSocket* irc_sock);

#endif