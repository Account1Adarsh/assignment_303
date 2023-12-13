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
        
        if(parent==NULL) return temp;
        
        else if(parent->key<x){
            parent->right=temp;
        }
        else {
            parent->left=temp;
        }
        return root;

}

int getsuccesor(struct node* root,int x){
    struct node* curr=root->right;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr->key;
}

struct node* delete(struct node* root,int x){
        if(root==NULL) return NULL;

        else if(root->key>x){
            root->left=delete(root->left,x);
        }

        else if(root->key<x){
            root->right=delete(root->right,x);
        }

        else{
            
            if(root->left==NULL){
                struct node* temp=root->right;
                free(root);
                return temp;
            }

            else if(root->right==NULL){
                struct node* temp=root->left;
                free(root);
                return temp;
            }

            else{
                root->key=getsuccesor(root,x);
                root->right=delete(root->right,root->key);
                return root;
            }
        }
}

void inordershow(struct node* root){
    if(root==NULL) return;
    inordershow(root->left);
    printf("%d ",root->key);
    inordershow(root->right);
    //printf("\n");
}


int main(){
    struct node* root=NULL;
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,45);
    inordershow(root);
    printf("\n");
    root=delete(root,10);
    inordershow(root);
    printf("\n");
    root=insert(root,15);
    root=insert(root,60);
    inordershow(root);
    printf("\n");
    root=delete(root,45);
    inordershow(root);
    printf("\n");
    return 0;
}