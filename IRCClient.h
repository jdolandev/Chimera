//
//  IRCClient.h
//  Database
//
//  Created by framk on 7/15/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#ifndef _IRCClient_H_
#define _IRCClient_H_

#include <stdio.h>
#include "vector.h"
#include "IRCSocket.h"

typedef struct {
    char* prefix;
    char* nick;
    char* user;
    char* host;
} IRCCommandPrefix;

void IRCCommandPrefix_Parse(IRCCommandPrefix* irc_cmd, const char* data);

typedef struct {
    char* command;
    IRCCommandPrefix prefix;
    Vector params;
} IRCMessage;


typedef struct {
    char* _nick;
    char* _user;
    bool _debug;
    IRCSocket _socket;
} IRCClient;

bool IRCClient_InitSocket(IRCClient* client);
bool IRCClient_Connect(IRCClient* client, char* host, int port);
void IRCClient_Disconnect(IRCClient* client);
void IRCClient_Parse(IRCClient* client, char* data);
bool IRCClient_Login(IRCClient* client, char* nick, char* user);
void IRCClient_ReceiveData(IRCClient* client);

#endif /* defined(__Database__IRCClient__) */
