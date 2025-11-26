#include <iostream>
#define MAX 5
using namespace std;

struct Node {
public:
    int data;
    Node* next;
    Node (int val) {
        data=val;
        next=NULL;
    }
};

Node* head=NULL;
int top=0;

Node* push(Node* newNode) {
    if (top>=MAX) {
        cout<<"Stack Overflow";
        return head;
    }
    if (head==NULL){
        head=newNode;
        top++;
        cout<<newNode->data<<" pushed";
        return head;
    }
    Node* temp=head;
    newNode->next=temp;
    head=newNode;
    cout<<newNode->data<<" pushed";
    top++;
    return head;
}

Node* pop() {
    if (head==NULL) {
        cout<<"Stack Underflow";
        return NULL;
    }
    cout<<head->data<<" popped";
    Node* temp=head;
    head=head->next;
    top--;
    delete temp;
    return head;
}

void display() {
    if (head==NULL) {
        cout<<"Stack is empty";
        return;
    }
    Node* temp=head;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    int ch,ele;
    while (1) {
        cout<<endl;
        cout<<"---Stack Menu---\n";
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>ch;
        switch(ch) {
            case 1: {
                cout<<"Enter an element to push: ";
                cin>>ele;
                Node* tempNode=new Node(ele);
                push(tempNode);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }    
            case 4:{
                exit(0);
            }
        }
    }
}