#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"
#include "list.h"

int top;
Stacklist * newStacklist(){
    Stacklist * s=malloc(sizeof(Stacklist));
    s->data=newList();
    s->peek=peekstacklist;
    s->pop=popstacklist;
    s->push=pushstacklist;
    s->clear=clearstacklist;
    s->delete=deletestacklist;
    return s;
}

Data peekstacklist(Stacklist * s){
    List * l=s->data;
    Node * l1 =s->data->head;
    printf("%d, %d,%d",l==NULL,l1==NULL,s==NULL);
    int index=1;
    if(l->head==NULL){
    	    Data d;
    	    d.value=-1;
    	    return d;
     }
    while(l1->next!=NULL){
        l1=l1->next;
        index++;
    }
    return *(s->data->read(s->data,index-1));
}

Data popstacklist(Stacklist * s){
    Node * l=s->data->head;
    List * l1=s->data;
    int index=0;
    if(l1->head==NULL){
	    Data d;
	    d.value=-1;
	    return d;
    }
    while(l->next!=NULL){
        l=l->next;
        index++;
    }
    Data d=*(s->data->read(s->data,index));
    s->data->remove(s->data,index);
    return d;

}

void pushstacklist(Stacklist * s,Data d){
    if(l->head==NULL){
        List * q = newQueue(d,NULL,NULL);
        q->d=d;
        q->head=q->tail;
    }
    else{
        Node * p = l->head;
        Node * e = newQueue(d,NULL,NULL);
        p->prev= e;
        e->next = p;
        l->head=e;
    }
}

void deletestacklist(Stacklist * s){
	free(s->data);
	free(s);
}
void clearstacklist(Stacklist * s){
    Node * l=s->data->head;
    int index=0;
    while(l!=NULL){
        l=l->next;
        index++;
    }
    while(index!=-1){
        popstacklist(s);
        index--;
    }
}
Stackvector * newStackvector(){
    Stackvector * s=malloc(sizeof(Stackvector));
    s->data=newVector();
    s->peek=peekStackvector;
    s->pop=popStackvector;
    s->push=pushStackvector;
    s->clear=clearStackvector;
    s->delete=deletestackvector;
    top=0;
    return s;
}
void pushStackvector(struct Stackvector * s, Data d){
   // int top=s->data->current_size;
    if(top==-1){
	    top=0;
    }
    s->data->insert(s->data,top,d);
    top++;
    //printf("top %d \n",top);
    //printf("%d \n",d.value);
}
Data popStackvector(struct Stackvector * s){
    //int top=s->data->current_size;
    //top--;
    Data d;
    //printf("top  now%d",top);
    if(top==-1){
	    top=0;
	    return (Data){-1};
    }
  //  printf("Here now %d",top);
  top--;
    d=*(s->data->read(s->data,top));
    //printf("%d data \n",d.value);
    s->data->remove(s->data,top);
//    top--;
    return d;
}
Data peekStackvector(struct Stackvector * s){
   // int top=s->data->current_size;
   // top--;
    Data d= *(s->data->read(s->data,top));
    return d;
}
void deletestackvector(Stackvector * s){
	free(s->data);
	free(s);
}
void clearStackvector(struct Stackvector * s){
   // int top=s->data->current_size;
   // top--;
    while(top!=-1){
        top--;
        popStackvector(s);
    }
}




