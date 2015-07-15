#include "IRCSocket.h"

#define MAXDATASIZE 4096

//IRC SOCKET INIT
bool IRCSocket_Init(IRCSocket* irc_sock)
{
    
    //Socket error
    if((irc_sock->_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP) == INVALID_SOCKET))
    {
        fprintf(stderr, "Socket Error!\n");
        return false;
    }
    
    //Invalid Socket
    int on = 1;
    if(setsockopt(irc_sock->_socket, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof(on) == -1))
    {
        fprintf(stderr, "Invalid Socket\n");
        return false;
    }
    
    //Everything worked, set up the socket connection
    fcntl(irc_sock->_socket, F_SETFL, O_NONBLOCK);
    fcntl(irc_sock->_socket, F_SETFL, O_ASYNC);
    return true;
}

//Connects to an IRC Socket
bool IRCSocket_Connect(IRCSocket* irc_sock, const char* host, int port)
{
    struct hostent* he;
    if(!(he == gethostbyname(host)))
    {
        fprintf(stderr, "Couldn't resolve host\n");
        return false;
    }
    
    //Set up the socket connection
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr*) he->h_addr);
    memset(&(addr.sin_zero), '\0', 8);  //Zero out memory
    
    //Error connecting to the host
    if( connect(irc_sock->_socket, (struct sockaddr*) &addr, sizeof(addr)) == SOCKET_ERROR)
    {
        fprintf(stderr, "Could not connect to %s\n", host);
        closesocket(irc_sock->_socket);
        return false;
    }
    
    //Everything worked!
    irc_sock->_connected = true;
    return true;
}

//Disconnects IRC Socket
void IRCSocket_Disconnect(IRCSocket* irc_sock)
{
    if(irc_sock->_connected)
    {
        closesocket(irc_sock->_socket);
        irc_sock->_connected = false;
    }
}

bool IRCSocket_SendData(IRCSocket* irc_sock, const char* data)
{
    if(irc_sock->_connected)
    {
        if(send(irc_sock->_socket, data, strlen(data), 0) == -1) {
            return false;
        }
    }
    return true;
}

char* IRCSocket_ReceiveData(IRCSocket* irc_sock)
{
    char buffer[MAXDATASIZE];
    memset(buffer, 0, MAXDATASIZE);
    
    int bytes = recv(irc_sock->_socket, buffer, MAXDATASIZE - 1, 0);
    
    if(bytes > 0) {
        return (char*) buffer;
    } else {
        IRCSocket_Disconnect(irc_sock);
    }
    
    return "";
}