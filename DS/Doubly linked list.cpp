/*
* Input
* n : int 
* command : char[] insertion | delete
* value : int 
* Output
* print the doubly linked list
*/
#include<iostream> 
using namespace std;

typedef struct Node node;
struct Node{
	int value;
	node *next, *prev;
};

node *CreateNode(int value)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

//delete the first node with a particular value
void deleteNode(node **head_ref, int value)
{
	node *tmp = *head_ref;
	//the target node in the front
	if(tmp->value == value) {
		*head_ref = tmp->next;
		(*head_ref)->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		return;
	} else {
		while(tmp->value != value && tmp != NULL) {
			tmp = tmp->next;
			// the target node in the middle
			if(tmp->value == value && tmp->next != NULL) {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				tmp->next = tmp->prev = NULL;
				free(tmp);
				return;
			}
			// the target node in the last
			if(tmp->value == value && tmp->next == NULL) {
				tmp->prev->next = NULL;
				tmp->prev = NULL;
				free(tmp);
				return; 
			}
		}
	}
}

// insert a node after a first node
void insert(node **head_ref, int value)
{
	//no node
	if(!(*head_ref)) {
		printf("Creat the first Node\n");
		*head_ref = CreateNode(value);
		return;
	}
	node* new_node = CreateNode(value);
	// only one node
	if((*head_ref)->next == NULL && (*head_ref)->prev == NULL) {
		(*head_ref)->next = new_node;
		new_node->prev = *head_ref;
	// more than one node
	} else {
		new_node->next = (*head_ref)->next;
		(*head_ref)->next = (*head_ref)->next->prev = new_node;		
		new_node->prev = *head_ref;
	}
}


//print the linked list
void printList(node *node)
{
	while(node != NULL) {
		printf("%d", node->value);
		node = node->next;
		if(node)
			printf("->");
	}
	printf("\n");
}

int main()
{
	ios_base::sync_with_stdio(false);
	int value, n, i;
	int size = 0;
	char command[20];
	node *head = NULL;
	cin >> n;
	cout << endl;
	for(i = 0; i < n; i++) {
		scanf("%s%d", command, &value);
		if(command[0] == 'i') {
			insert(&head,value);
			size++;
		} else {
			deleteNode(&head,value);
			size --;
		}
	}
	printList(head);
	return 0;
}