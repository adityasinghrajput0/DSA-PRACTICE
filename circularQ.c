#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

int isFull() {
    return (front==(rear+1)%MAX);
}

void enqueue(int ele) {
    if (isFull()) {
        printf("Queue is FUll.");
        return;
    }
    if (front==-1) {
        front=0;
    }
    rear=(rear+1)%MAX;
    queue[rear]=ele;
    printf("\nElement inserted at %d : %d\n",rear,ele);
}

void dequeue() {
    if (front==-1) {
        printf("Queue is empty.");
        return;
    }
    else if (front==rear) {
        printf("Element deleted from queue: %d",queue[front]);
        front=rear=-1;
    }
    else {
        printf("\nElement deleted from queue: %d",queue[front]);
        front=(front+1)%MAX;
    }
}

void display() {
    if (front==-1) {
        printf("Queue is empty.");
        return;
    }
    else {
        int i=front;
        printf("\nElements of queue are: ");
        while (1) {
            printf(" %d",queue[i]);
            if (i==rear) break;
            i=(i+1)%MAX;
        }
    }
}

int main() {
    int ch,ele;
    while (1) {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d",&ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
} 