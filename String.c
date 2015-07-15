//
//  String.c
//  Database
//
//  Created by framk on 7/10/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#include "String.h"

String* string_create(char* text){
    String* tempstring = malloc(sizeof(String));
    tempstring->text = text;
    tempstring->size = 2;
    return tempstring;
}