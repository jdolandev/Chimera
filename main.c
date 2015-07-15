//
//  main.c
//  Database
//
//  Created by framk on 7/9/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#include <sys/socket.h>
#include <dirent.h>
#include "vector.h"
#include "IRCClient.h"

int main() {
    IRCClient* clientTest;
    IRCClient_InitSocket(clientTest);
    IRCClient_Connect(clientTest, "irc.freenode.net", 6667);
    IRCClient_Login(clientTest, "framk", "framk");
    return 0;
}
