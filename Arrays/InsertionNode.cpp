#include <iostream>
using namespace std;

struct Node {
    public:
        int data;
        Node* next;
    public:
        Node (int data) {
            this->data=data;
            this->next=NULL;
        }
};

Node* insertHead(Node* head) {
    Node* temp=new Node(20);
    temp->next=head;
    return temp;
}

Node* insertTail(Node* head,Node* newNode) {
    Node* temp=head;
    while (temp->next != NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}

Node* insertK(Node* head, Node* newNode,int k) {
    if (newNode==NULL) return;
    if (head==nullptr) return newNode;
    Node* temp=head;
    Node* prev=NULL;
    int cnt=0;
    while (temp != NULL) {
        cnt++;
        if (cnt==k) {
            prev->next=newNode;
            newNode->next=temp;
        }
        prev=temp;
        temp->next=temp;
    }
}