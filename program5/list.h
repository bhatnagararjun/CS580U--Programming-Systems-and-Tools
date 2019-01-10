//
//  list.h
//  pst5
//
//  Created by Mohit Gadi on 11/17/18.
//  Copyright © 2018 Mohit Gadi. All rights reserved.
//

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "data.h"

/*
typedef struct Data{
	int value;
} Data;
*/
typedef struct Node {
    Data data;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct List {
    Node * head, * tail;
    void (*insert)(struct List *, int, Data);
    Data * (*read)(struct List *, int); //a function pointer to a read function
    void (*remove)(struct List *, int); //a function pointer to an delete function
    void (*delete)(struct List *); //a function pointer to a destructor
} List;

List * newList();
void insertList(List * list, int index, Data value);
void removeData(List * list, int index);
Data * readData(List * list, int index);
void deleteList(List * list);

#endif /* list_h */
