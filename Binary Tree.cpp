#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int data){
        this -> data = data;
        this -> right = NULL;
        this -> left = NULL;
    }
};
void printPreorder(struct Node* node){
    if(node == NULL)
        return;
    cout<<node -> data<<" ";
    printPreorder(node -> left);
    printPreorder(node -> right);
}
void printPostorder(struct Node* node){
    if(node == NULL)
        return;
    printPostorder(node -> left);
    printPostorder(node -> right);
    cout<<node -> data<<" ";
}
void printInorder(struct Node* node){
    if(node == NULL)
        return;
    printInorder(node -> left);
    cout<<node -> data<<" ";
    printInorder(node -> right);
}
int main(){
    struct Node* root = new Node(0);
    /*for(int i = 1;i<=50;i++){
        root -> right = new Node(i);
        root -> left = new Node(i);   
    }*/

    root->right = new Node(2);
    root->left  = new Node(3);
    root->right->right = new Node(4);
    root->left->right = new Node(5);

    printPreorder(root);
    cout<<endl;
    printPostorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
}