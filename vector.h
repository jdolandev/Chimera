//
//  vector.h
//  Database
//
//  Created by framk on 7/9/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#ifndef __Database__vector__
#define __Database__vector__

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_CAPACITY 0xff

typedef struct {
    int size;
    int capacity;
    int *data;		//Generic data
} Vector;

void vector_init(Vector *vector);
void vector_append(Vector *vector, int value);
int vector_get(Vector *vector, int index);
void vector_set(Vector *vector, int index, int value);
void vector_realloc(Vector *vector);
void vector_free(Vector *vector);

#endif /* defined(__Database__vector__) */
