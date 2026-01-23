#include <stdio.h>
#include <stdlib.h>


void push (int ele, int sn,int top[], int stack[], int next[], int* free) {
    if (*free==-1) {
        printf("\nStack Overflow");
        return;
    }
    int i=*free;
    *free=next[i];
    stack[i]=ele;
    next[i]=top[sn];
    top[sn]=i;
    printf("\n%d pushed on top of stack %d",ele,sn);
}

int pop(int sn, int top[], int stack[], int next[], int* free) {
    if (top[sn]==-1) {
        printf("\nStack Underflow");
        return -1;
    }
    int i=top[sn];
    top[sn]=next[i];
    next[i]=*free;
    *free=i;
    return stack[i];
}

void display(int sn,int top[], int stack[], int next[]) {
    if (top[sn]==-1) {
        printf("\nStack is Empty.");
        return;
    }
    int i=top[sn];
    printf("\nStack %d elements are: ",sn);
    while (i!=-1) {
        printf("  %d",stack[i]);
        i=next[i];
    }
}

int main() {
    int max;
    int k;
    int free=0;
    printf("\nEnter the no. of stacks: ");
    scanf("%d",&k);
    printf ("\nEnter the size of Stack: ");
    scanf("%d",&max);
    int stack[max];
    int top[k];
    int next[max];
    
    for (int i=0; i<k; i++) top[i]=-1;
    for (int i=0; i<max; i++) {
        if (i==max-1) {
            next[i]=-1;
            break;
        }
        next[i]=i+1;
    }
    push(10, 0, top, stack, next, &free);
    push(20, 0, top, stack, next, &free);
    push(30, 1, top, stack, next, &free);

    display(0, top, stack, next);
    display(1, top, stack, next);

    printf("\nPopped from stack 0: %d", pop(0, top, stack, next, &free));

    display(0, top, stack, next);

    return 0;
}