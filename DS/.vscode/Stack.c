//Input 
//reverse polish notation
//operand: 2<= the number of operands <= 100
//operator: +, -, * -1e^9<= value <= 1e9 and  1<=the number of operands <= 100
//Output:
//the result of the expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
    
};
typedef struct Node Stack_Node;
typedef Stack_Node* ptr;
ptr top = NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    ptr new_node = (ptr)malloc(sizeof(Stack_Node));   
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}
int pop(){
    if(isEmpty()){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        int tmp = top->data;
        top = top->next;
        return tmp;
    }
}


int main(){

    int a,b;
    char* s = (char*)malloc(sizeof(char));
    while( scanf("%s",&(*s))!=EOF){
        if( *s == '+'){
            a=pop();
            b=pop();
            push(a + b);
        }
        else if( *s == '-'){
            b = pop();
            a = pop();
            push(a - b);

        }
        else if( *s == '*'){
            a = pop();
            b = pop();
            push(a*b);
        }
        else{
            push(atoi(s));
        }
    }
    printf("%d\n", pop());
    free(s);
    return 0;
}