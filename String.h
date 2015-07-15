//
//  String.h
//  Database
//
//  Created by framk on 7/10/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#ifndef __Database__String__
#define __Database__String__
#include <sys/types.h>

typedef struct {
    char* text;
    uint32_t size;
} String;

#endif /* defined(__Database__String__) */
