//
//  IRCClient.c
//  Database
//
//  Created by framk on 7/15/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#include "IRCClient.h"


bool IRCClient_Connect(IRCClient* client, char* host, int port)
{
    return IRCSocket_Connect(&client->_socket, host, port);
}

bool IRCClient_InitSocket(IRCClient* client)
{
    return IRCSocket_Init(&client->_socket);
}

bool IRCClient_Login(IRCClient* client, char* nick, char* user)
{
    client->_nick = nick;
    client->_user = user;
    return true;
}