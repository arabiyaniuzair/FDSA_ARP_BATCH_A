#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* createTree(){
    int x;
    cin>>x;

    if(x==-1)
        return NULL;

    Node* root=new Node(x);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cin>>x;
        if(x!=-1){
            temp->left=new Node(x);
            q.push(temp->left);
        }

        cin>>x;
        if(x!=-1){
            temp->right=new Node(x);
            q.push(temp->right);
        }
    }

    return root;
}

void inorder(Node* root){
    if(root ==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left!=NULL)
            q.push(temp->left);

        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main(){
    cout<<"Enter tree nodes in level order (-1 for no node): ";

    Node* root=createTree();

    cout<<"Inorder: ";
    inorder(root);

    cout<<"\nPreorder: ";
    preorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    cout<<"\nLevel Order: ";
    levelorder(root);

    return 0;
}
