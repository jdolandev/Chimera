//
//  vector.c
//  Database
//
//  Created by framk on 7/9/15.
//  Copyright (c) 2015 Chimera. All rights reserved.
//

#include "vector.h"

//Constructor
void vector_init( Vector *vector ) {
    vector->size = 0;
    vector->capacity = VECTOR_CAPACITY;
    vector->data = malloc(sizeof(int) * vector->capacity);
}

//Appends a value to the list of vectors
void vector_append( Vector* vector, int value ) {
    if( vector->size >= vector->capacity ) {
        vector_realloc(vector);
    }
    vector->data[vector->size++] = value;
}

//
int vector_get( Vector* vector, int index ) {
    //If they're trying to retrieve from an impossible location
    if ( index >= vector->size || index < 0) {
        fprintf(stderr, "Instance at %d doesn't exist\n", index);
        exit(1);
    }
    return vector->data[index];
}

//Doubles the capacity of the vector
void vector_realloc(Vector *vector) {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
}

//Sets a value at a certain index to whatever you want
void vector_set(Vector *vector, int index, int value) {
    vector->data[index] = value;
}

//Destructor
void vector_free(Vector *vector) {
    free(vector->data);			//Free all elements of the vector
}