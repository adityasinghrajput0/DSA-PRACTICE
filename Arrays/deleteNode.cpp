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

Node* removeK(int k,Node* head) {
    if (head==NULL) return NULL;
    if (k==1) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    int cnt=0;
    while (temp != NULL) {
        cnt++;
        if (cnt==k) {
            prev->next=prev->next->next;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}