#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

Vector * newVector(){
    Vector *v= malloc(sizeof(Vector));
    v->data=NULL;
    v->max_size=0;
    v->current_size=0;
    v->insert= insertVector;
    v->remove=removeVector;
    v->delete=deleteVector;
    v->read=readVector;
    return v;
}

void insertVector(Vector * v,int location,Data d){
    if(location>=v->max_size){
	v->current_size=v->max_size=location;
        v->max_size=(v->max_size*2)+1;
	//int * new_flag=malloc(sizeof(int)*v->max_size);
	Data * new = malloc(sizeof(Data)*v-> max_size);
        for(int i=0;i<v->max_size;i++){
		new[i].value=-1;
	}
	memcpy(new,v->data,sizeof(Data)*v->current_size);
	//memcpy(new_flag,v->flag,sizeof(Data)*v->current_size);
        free(v->data);
	//free(v->flag);
        v->data=NULL;
        v->data=new;
	//v->flag=NULL;
	//v->flag=new_flag;
	//free(new);
	//free(new_flag);
	//new_flag=NULL;
        new=NULL;
    }
    if(location==v->current_size){
        v->current_size=location+1;
    }
    //v->flag[location]=1;
    v->data[location]=d;
}
void removeVector(Vector * v,int location){
    if(v->current_size ==0){
	    return;
    }
    for(int i=0;i<v->max_size-1;i++){
        if(i >= location){
            v->data[i]=v->data[i+1];
	//    v->flag[i]=v->flag[i+1];
        }
    }
    //int * new_flag=malloc(sizeof(int)*v->max_size);
    v->max_size=v->max_size-1;
    Data *new=malloc(sizeof(Data)* v->max_size);
   //memset(new,-1,sizeof(new));
   for(int i=0;i<v->max_size-2;i++){
	   new[i].value=-1;
   }
   v->current_size=v->current_size-1;
    memcpy(new,v->data,sizeof(Data)*v->current_size);
   // memcpy(new_flag,v->flag,sizeof(int)*v->current_size);
    free(v-> data);
    v->data=NULL;
    v->data=new;
    //free(v->flag);
    //v->flag=NULL;
    //v->flag=new_flag;
    //free(new);
    new =NULL;
    //free(new_flag);
    //new_flag=NULL;
}
Data * readVector(Vector *v,int location){
    if(location > v->current_size){
	return NULL;
    }
    else{
	   return &(v->data[location]);

    }
}

void * deleteVector(Vector *v){
    free(v->data);
    //free(v);
}
