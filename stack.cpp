#include <stdio.h>
#include <stdlib.h>

int *stack;
int top=-1;
int size=2;

void resize() {
    stack=(int*)realloc(stack,2*size*sizeof(stack));
}

void push(int ele) {
    stack[++top]=ele;
    printf("%d pushed on top of stack",ele);
}

void pop() {
    if (top==-1) {
        printf("Stack Underflow");
        return;
    }
    printf("%d popped out of stack",stack[top--]);
}

void display() {
    if (top==-1) {
        printf("Stack is empty.");
        return;
    }
    printf("Stack Elements: ");
    for (int i=top; i>=0; i--) {
        printf("  %d",stack[i]);
    }
}

int main() {
    int ch,ele;
    stack=(int*)malloc(size*sizeof(stack));
    while (1) {
        printf("\n===STACK MENU===");
        printf("\n1.Push an element");
        printf("\n2.Pop an element");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                if (top==size-1) {
                    resize();
                    printf("Size of stack has been increases");
                    size*=2;
                    break;
                }
                printf("\nEnter an element to push: ");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program..");
                exit(0);
        }
    }
    return 0;
}
