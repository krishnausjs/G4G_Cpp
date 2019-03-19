#include <stdio.h>

struct node 
{
    int data;
    struct node *next;
};

void push(struct node** head_ref, int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display_linked_list(struct node *head)
{
    int i = 0;
    while(head != NULL)
    {
        printf(" %d - 0x%x \n",head->data, head->next);
        head = head->next;
    }
    printf("\n");
}


void deleteNodeWithoutHead(struct node* pos) 
{ 
	if (pos == NULL) // If linked list is empty 
    {
		return; 
    }
	else
   { 
		struct node* temp = pos->next; 
        printf("Took backup of  0x%x node , data %d\n",temp,temp->data);
		// Copy data of the next node to current node 
		//pos->data = pos->next->data; 
        pos->data = temp->data;
        pos->next = temp->next;

		// Perform conventional deletion 
		//pos->next = pos->next->next; 
        printf("Freeing 0x%x node\n",temp);
		free(temp); 
	} 
	return 0; 
} 

int main(int argc, char **argv)
{
    struct node *head = NULL;
    int n,i;
    int node_data;
    
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    printf("Enter the nodes\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&node_data);
        push(&head,node_data);
    }
    printf("Nodes in linked list are \n");
    display_linked_list(head);
    
    printf("Deleting node %d at 0x%x \n",head->next->next->next->data,head->next->next->next);
    deleteNodeWithoutHead(head->next->next->next);
    display_linked_list(head);
    
	return 0;
}
