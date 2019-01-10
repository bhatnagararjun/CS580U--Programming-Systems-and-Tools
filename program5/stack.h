
#ifndef STACK_H
#define STACK_H
#include "list.h"
#include "vector.h"


typedef struct Stacklist{
    List * data;
    Data (*peek)(struct Stacklist *);
    Data (*pop)(struct Stacklist *);
    void (*push)(struct Stacklist *, Data);
    void (*clear)(struct Stacklist *);
    void (*delete)(struct Stacklist *);
} Stacklist;

void * pop(struct Stacklist * l);
Stacklist * newStacklist();
void pushstacklist(struct Stacklist *, Data);
Data peekstacklist(Stacklist * s);
Data popstacklist(Stacklist * s);
void clearstacklist(Stacklist * s);
void deletestacklist(Stacklist * s);

typedef struct Stackvector{
    Vector * data;
    Data (*peek)(struct Stackvector *);
    Data (*pop)(struct Stackvector *);
    void (*push)(struct Stackvector *, Data);
    void (*clear)(struct Stackvector *);
    void (*delete)(struct Stackvector *);
} Stackvector;

Stackvector * newStackvector();
void pushStackvector(struct Stackvector *, Data);
Data popStackvector(struct Stackvector *);
Data peekStackvector(struct Stackvector *);
void clearStackvector(struct Stackvector *);
void deletestackvector(struct Stackvector *);

#endif
