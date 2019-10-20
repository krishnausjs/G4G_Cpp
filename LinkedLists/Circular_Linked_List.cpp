#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//This is a program to implement Circular Queue using Linked lists
struct node
{
	int data;
	struct node *next;
};


struct Queue
{
	struct node *front,*rear;
};

void enQueue(Queue *q, int data)
{
	//Create a node first
	struct node *temp = new node;
	
	//Fill the data
	temp->data = data;

	//Note enQueue in circular queue is done through rear pointer.
	//Case 1 : Check if queue is empty. If empty, current node becomes the first node
	if(q->front == NULL)
	{
		//Looks queue is empty as q->front pointing to NULL
		//Make temp node as first node
		q->front = temp;
	}
	else
	{
		//We have more than one element in queue.
		//q->rear points to last and q->rear->next to front.
		//Modify q->rear->next to point to new node.
		q->rear->next = temp;
	}

	//Update the rear pointer to point the new node temp.
	q->rear =  temp;

	//Finally fix the broken circular link
    q->rear->next = q->front;
}

int deQueue(Queue *q)
{
	int value;

	//First check if queue is empty.
	if(q->front == NULL)
	{
		cout << "Queue is empty\n";
		return 0; // INIT_MIN;
	}	
	else
	{
		//Note dequeue operation is done through front pointer
		//First check if the node we are going to delete is the last node
		if(q->front == q->rear)
		{
			// if its last node. Take the value
			value = q->front->data;
			free(q->front);			
			q->front = NULL;
			q->rear = NULL;
		}
		else
		{
			//If there are more than one nodes and we want to dequeue one,
			// We need to use q->front pointer 
			value = q->front->data;
			
			struct node *temp = q->front;
			q->front = q->front->next;
			q->rear->next = q->front;
			free(temp);
		}
	}
	return value;
}

void displayQueue(Queue *q)
{
	struct node *temp = q->front;

	while(temp->next != q->front)
	{
		cout << endl << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Queue *q = new Queue;
		
	enQueue(q, 20);
	enQueue(q, 21);
	enQueue(q, 22);
	enQueue(q, 23);
	enQueue(q, 24);
	enQueue(q, 25);
	enQueue(q, 26);

	displayQueue(q);

	cout << "Value of deQueue " << deQueue(q) << endl;
	cout << "Value of deQueue " << deQueue(q) << endl;
	cout << "Value of deQueue " << deQueue(q) << endl;

	displayQueue(q);
	return 0;
}
