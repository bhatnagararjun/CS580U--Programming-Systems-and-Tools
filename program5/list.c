//
//  list.c
//  pst5
//
//  Created by Mohit Gadi on 11/17/18.
//  Copyright © 2018 Mohit Gadi. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List * newList(){
    List * l = malloc(sizeof(List));
    l->head = l->tail= NULL;
    l->insert=insertList;
    l->read=readData;
    l->remove=removeData;
    l->delete=deleteList;
    return l;
}

Node * newNode(Data d, Node  *n, Node *p){
    n =malloc(sizeof(Node));
    n->data =d;
    n->next=n;
    n->prev=p;
    return n;
}

void insertList(List *list, int index, Data data){
    Node *n = newNode(data, NULL, NULL); 
    n->next = n->prev=NULL;
    Node *p = list->head;
    if(p == NULL)
    {
        list->head = list->tail = n;
        return;
    }
    int i;
   for(i=0;i<index;i++){
	    if(p->next == NULL){
		break;
	    }
        p = p->next;
   }
    if(p->next == NULL)
    {
        n->prev = p;
        p->next=n;
        list->tail = n;
    }
    else
    {
        n->prev = p;
        n->next = p->next;
        p->next->prev = n;
        p->next = n;
    }
        
}

void removeData(List *l, int index){
    Node *p = l->head;
    if(index ==0)
    {
        if(p->next == NULL)
        {
            l->head=l->tail = NULL;
        }
        else
        {
            l->head = p->next;
            l->head->prev = NULL;
        }
        free(p);
        return;
    }
    int i;
    for (i = 0; i < index; i++) {
        if(p->next == NULL)
            break;
        p = p->next;
    }
    if(index == i)
    {
        if(p->next == NULL)
        {
            p->prev->next = NULL;
            l->tail = p->prev;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        free(p);
    }
}


Data * readData(List * list, int index){
    int i=0;
    Node * p=list->head;
    while(p->next!=NULL){
        if(i==index){
		return &(p->data);
        }
        p=p->next;
    	i++;
    }
    return NULL;
}

void deleteList(List *l){
    l->head=l->tail=NULL;
    l=NULL;
    //free(l);
}
