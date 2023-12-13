#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root,int x){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;

    struct node* curr=root;
    struct node* parent=NULL;
    while(curr!=NULL){
        parent=curr;
        if(curr->key<x){
            curr=curr->right;
        }
        else if(curr->key>x){
            curr=curr->left;
        }
        else return root;
    }
    if(parent==NULL){
        return NULL;
    }
    else if(parent->key<x){
        parent->right=temp;
        return root;
    }
    else{
        parent->left=temp;
        return root;
    }
}

struct node* getsucc(struct node* root){
    struct node*curr=root->right;
    while(curr->left!=NULL) curr=curr->left;
    return curr;
}

struct node* delete(struct node* root,int x){
    if(root==NULL){
        return NULL;
    }
    else if(root->key<x){
        root->right=delete(root->right,x);
    }
    else if(root->key>x){
        root->left=delete(root->left,x);
    }
    else{

        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right=NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node* temp=getsucc(root);
            root->key=temp->key;
            root->right=delete(root->right,root->key);
        }
    }
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}
int main(){
    return 0;
}