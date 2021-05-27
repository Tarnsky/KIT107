/*
 * Implementation for Queue using linked-list
 *	Author: <<YOUR STUDENT IDs AND NAMES HERE>>
 *	Version: May 2021
 *
 *	This file holds the queue ADT.  It comprises
 *	a head-of-queue field (first).
 *
 *	YOU NEED TO MAKE CHANGES TO THIS FILE!
 */


#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"


// types
struct queue_int {
	node first;
};


/*
*	init_queue
*	initialiser function.
*	Pre-condition: none
*	Post-condition: create a new queue variable with a NULL first
*					field and the address of it assigned to the
*					parameter (qp)
*	Informally: creates an empty queue
*/
void init_queue(queue *qp)
{
	trace("queue: Initialiser starts");

	*qp = (queue)malloc(sizeof(struct queue_int));
	(*qp)->first = NULL;

	trace("queue: Initialiser ends");
	//COMPLETE?? Yes!
}


/*
*	is_empty_queue
*	Emptiness test.
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: true is returned if the queue variable is
*					empty, false is returned otherwise
*	Informally: indicate if the queue contains no nodes
*
*	return boolean whether or not the queue is empty
*/
bool is_empty_queue(queue q)
{
	trace("is_empty_queue: is_empty_queue starts and ends");

	return (q->first == NULL);
}


/*
*	front
*	Find value at front of queue.
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: the value at the front of queue is returned
*	Informally: find the value at the front of queue
*
*	return (void *) the value on front of the queue
*/
void *front(queue q)
{
	trace("front: front starts");
	
	if (is_empty_queue(q))
	{
		fprintf(stderr, "front: empty queue.");
		exit(1);
	}
	return get_data_node(q->first);
	
	//COMPLETE?? Mostly, just need to keep the return out of the else's
}


/*
*	rear
*	Remove head of the queue
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: the value at the front of queue is deleted updating
*					the "first" field accordingly
*	Informally: delete the head of the queue
*/
void rear(queue q)
{
	trace("rear: rear starts");

	if (is_empty_queue(q))
	{
		fprintf(stderr, "rear: empty queue.");
		exit(1);
	}
	q->first = get_next_node(q->first);
	
	//COMPLETE?? Mostly!

	trace("rear: rear ends");
}


/*
*	add
*	Add item to back of queue
*	Pre-condition: the queue variable is defined and valid
*	Post-condition: a new node is created containing the parameter
*					value (o) in the data field and NULL in the
*					next field and this is inserted at the rear
*					of the linked list
*
*	Param o value to be added to back of queue
*/
void add(queue q, void *o)
{
	trace("add: add starts");
	
	node current_node;// current node, for storing each queue element
	node next_node; // this is the next node of current node

	init_node(&next_node, o); // the next node is o

	if (is_empty_queue(q))
	{
		q->first = next_node;
		trace("add: empty queue");
	}
	else
	{
		// initial current node is the head of the queue
		current_node = q->first;
		// get the last node
		while (get_next_node(current_node) != NULL)
		{
			current_node = get_next_node(current_node);
		}
		// assign the next node/o as the next node of the last node
		set_next_node(current_node, next_node);
	}
	trace("add: add ends");
}


/*
*	to_string_queue
*	String conversion for queue
*	Pre-condition: none
*	Post-condition: a string variable is returned consisting of the
*				string representation of all items in the queue,
*				from left to right, separated by " " and contained
*				within "<" and ">"
*	Informally: produce a string representation of the queue
*
*	return (char *) printable contents of queue
*/
char *to_string_queue(queue q, char *f)
{
	node c;
	char *fmt = (char *)malloc(10 * sizeof(char));
	char *s=(char *)malloc(100*10*sizeof(char));
	
	if (is_empty_queue(q))
	{
		s = "<>";
	}
	else 
	{
		s[0] = '\0';
		sprintf(fmt, "%%s%s", f);
		c = q->first;
		while (c != NULL)
		{
			sprintf(s, fmt, s,*(int *)(get_data_node(c)));
			if (get_next_node(c) != NULL)
			{
				sprintf(s, "%s, ", s);
			}
			c = get_next_node(c);
		}
	}
	return s;
}
