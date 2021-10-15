//Input:
//Line 1: n : the number of processes (1 <= n <=100000) & q : time quantum (1 <= q <=1000)
//Line 2~n+1 : The name of the individual process (1 <= length <= 10) & time : need to complete (1 <= time <= 50000) 
//(The total time is less than 1,000,000)
//Output
//Line n: Complete the job of processes in oreder & elapsed time

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Len_Of_Name 11
#define LEN 100000

struct Qnode{
    char name[Len_Of_Name];
    int t;
    struct Qnode* next;
};
typedef struct Qnode Qnode;

typedef struct{
    Qnode *front, *rear;
}Queue;

Qnode* newNode(char name[], int t)
{
    Qnode* temp = (Qnode*)malloc(sizeof(Qnode));
    strncpy(temp->name , name, Len_Of_Name);
    temp->t = t;
    temp->next = NULL;
    return temp;
}

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;

}

int isFull(const Queue* q){
    int size = 0;
    Qnode* tmp;
    for(tmp = q->front; tmp!=NULL;){
        size++;
        if(size == LEN){
            free(tmp);
            return 1;
        }
        tmp = tmp->next;
    }
    free(tmp);
    return 0;
}

void enqueue(Queue* q, char name[],int t){
    Qnode* temp = newNode(name , t);
    if(!q->rear){
        q->front = q->rear = temp;
    }
    else{
        if(isFull(q))
            printf("overflow");
        else{
            q->rear->next = temp;
            q->rear = temp;
        }
    }
}

Qnode dequeue(Queue* q){
    Qnode tmp; 
    if(!q->front){
        tmp = (Qnode){
            .t=-1,
            .next=NULL
        };
        return tmp;

    }
    else{
        strncpy(tmp.name,q->front->name,Len_Of_Name);
        tmp.t = q->front->t;
        q->front = q->front->next;
        
        if(q->front == NULL)
            q->rear = NULL;
        return tmp;
    }

}

int min(int a, int b){
    return a < b ? a:b;
}

int main(){
    int elaps = 0, c;
    int i,q;
    Queue* queue = createQueue();
    int n;
    scanf("%d %d", &n, &q);
    char* name = (char*)malloc(sizeof(char)*11);
    int t;
    for(i =0; i<n;i++){
        scanf("%s", name);
        scanf("%d", &t);
        enqueue(queue,name,t);
    }
    while(queue->front != NULL){
        Qnode node = dequeue(queue);
        c = min(node.t,q);
        node.t -= c;
        elaps += c;
        if(node.t > 0){
            enqueue(queue,node.name,node.t);
        }
        else{
            printf("%s %d\n", node.name, elaps);
        }
    }
    
    return EXIT_SUCCESS;
}