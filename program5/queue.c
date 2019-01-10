#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queuelist * newQueuelist(){
	    Queuelist * s=malloc(sizeof(Queuelist));
		        s->peek=&peekQueuelist;
			    s->enqueue=&enqueueQueuelist;
			        s->dequeue=&dequeueQueuelist;
				    s->clear=&clearQueuelist;
				        s->delete=&deleteQueuelist;
					    return s;
}


void enqueueQueuelist(Queuelist * l, Data d){
	    if(l->data->head==NULL){
		            List * q = newList(d,NULL,NULL);
			            q->head->data=d;
				            q->head=q->tail;
					        }
	        else{
			        Node * p = l->data->head;
				        Node * e = newQueue(d,NULL,NULL);
					        p->prev= e;
						        e->next = p;
							        l->data->head=e;
								    }
}

Data dequeueQueuelist(Queuelist * s){
    Data d=*(s->data->read(s->data,0));
	    s->data->remove(s->data,0);
    return d;
}

Data peekQueuelist(Queuelist * l){
	    if(l->data->head==NULL)
            return (Data) {-1};
	        else{
			        Node * p=l->data->head;
				        return p->data;
					    }
}

void clearQueuelist(Queuelist * s){
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
void deleteQueuelist(Queuelist *s){
    free(s->data);
    free(s);
}



Queuevector * newQueuevector(){
	    Queuevector *v=malloc(sizeof(Queuevector));
    v->data=newVector();
		    v->data->max_size=0;
		        v->data->current_size=0;
			    v->enqueue= &pushQueuevector;
			        v->dequeue=&popQueuevector;
				    v->peek=&peekQueuevector;
				        v->clear=&clearQueuevector;
					    v->delete=&deleteQueuevector;
					        return v;
}

Data popQueuevector(Queuevector * qv){
	    Data d=qv->data[current_size];
	        return removeVector(qv->data,sv->data->current_size)
}
Data peekQueuevector(Queuevector * qv){
	    data d=qv->data[v->current_size-1]
		        return d;
}

void pushQueuevector(Queuevector * v, Data d){
    int full=v->data->current_size;
    return insertVector(v->data,current_size,d);
}

void clearQueuevector(Queuevector *qv){
    while(qv->data->head!=NULL){
        popQueuevector(s);
    }
}

void * deleteQueuevector(Queuevector * qv){
	    free(qv);
}

