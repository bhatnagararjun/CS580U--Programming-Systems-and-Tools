#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"

/*typedef struct Data{
    int value;
} Data;
*/
typedef struct Vector{
    Data * data;
    int max_size;
    int current_size;
    void (*insert)(struct Vector *,int,Data);
    Data *(*read)(struct Vector *,int);
    void (*remove)(struct Vector *,int);
    void *(*delete)(struct Vector *);
} Vector;

Vector * newVector();
void insertVector(Vector *,int ,Data);
void removeVector(Vector *,int);
Data * readVector(Vector *,int);
void * deleteVector(Vector *);


#endif
