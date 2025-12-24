#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;
node root=NULL;

node createNode(int data) {
    node newNode=(node)malloc(sizeof(struct Node));
    newNode->val=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

node insert(node root,int data) {
    if (root==NULL ) return createNode(data);
    else if(data<root->val) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}

void inorder(node root) {
    if (root!=NULL) {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

void preorder(node root) {
    if (root!=NULL) {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root) {
    if (root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
}

node search(node root,int key) {
    if(root==NULL || root->val==key) return root;
    else if (key<root->val) return search(root->left,key);
    else return search(root->right,key);
}

int main() {
    int ch,ele;
    while (1) {
        printf("1.Insert\n");
        printf("2.Inorder\n");
        printf("3.Preorder\n");
        printf("4.Postorder\n");
        printf("5.search\n");
        printf("6.exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d",&ele);
                root=insert(root,ele);
                printf("Element %d inserted\n",ele);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Enter an element to search: ");
                scanf("%d",&ele);
                if(search(root,ele)) {
                    printf("\nElement %d found..",ele);
                }
                else printf ("\nElement Not found..");
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
} 