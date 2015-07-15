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
#include "String.h"

int main() {
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir("./");
    if(dp != NULL) {
        while(ep == readdir(dp))
            puts(ep->d_name);
        (void) closedir(dp);
    } else {
        perror("Couldn't open directory");
    }
    return 0;
}
