#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "vector.h"

typedef struct Queuelist{
	    List * data;
	        Data (*peek)(struct Queuelist *);
		    Data (*dequeue)(struct Queuelist *);
		        void (*enqueue)(struct Queuelist *, Data);
			    void (*clear)(struct Queuelist *);
			        void (*delete)(struct Queuelist * s);
} Queuelist;

Queuelist * newQueuelist();
void enqueueQueuelist(struct Queuelist *, Data);
Data dequeueQueuelist(struct Queuelist *);
Data peekQueuelist(struct Queuelist *);
void clearQueuelist(struct Queuelist *);
void deleteQueuelist(struct Queuelist *);

typedef struct Queuevector{
	    List * data;
	        Data (*peek)(struct Queuevector *);
		    Data (*dequeue)(struct Queuevector *);
		        void (*enqueue)(struct Queuevector *, Data);
			    void (*clear)(struct Queuevector *);
			        void (*delete)(struct Queuevector *);
} Queuevector;

Queuevector * newQueuevector();
void pushQueuevector(struct Queuevector *, Data);
Data popQueuevector(struct Queuevector *);
Data peekQueuevector(struct Queuevector *);
void clearQueuevector(struct Queuevector *);
void deleteQueuevector(struct Queuevector *);

#endif
