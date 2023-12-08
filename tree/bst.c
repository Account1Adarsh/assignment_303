#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left_child;
    struct node* right_child;
};

struct node* insert(struct node* root,int x){

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left_child=NULL;
    temp->right_child=NULL;

    if(root==NULL){
        return temp;
    }
    struct node* curr=root;
    while(curr!=NULL){
        if(curr->data==x){
            printf("Invalid input \n");
            return root;
        }
        if(x<curr->data){
            if(curr->left_child==NULL){
                curr->left_child=temp;
                return root;
            }
            curr=curr->left_child;
        }
        else{
            if(curr->right_child==NULL){
                curr->right_child=temp;
                return root;
            }
            curr=curr->right_child;
        }
    }
}
struct node* search(struct node* root,int k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        return root;
    }
    else if(k<root->data){
        return search(root->left_child,k);
    }
    else{
        return search(root->right_child,k);
    }
}
struct node* largest(struct node* root){
    struct node* temp=root;
    while(temp->right_child!=NULL){
        temp=temp->right_child;
    }
    return temp;
}

struct node* delete_node(struct node* tree,int x){
    struct node* root=tree;
        if(root==NULL){
            return tree;
        }
        else if(x<root->data){
            return delete_node(root->left_child,x);
        }
        else if(x>root->data){
           return delete_node(root->right_child,x);
        }
        else if(root->left_child && root->right_child){
            struct node* temp= largest(root->left_child);
            root->data=temp->data;
            return delete_node(root->left_child,temp->data);
        }
        else{
            struct node* temp=root;
            if(root->left_child==NULL && root->right_child==NULL){
                root=NULL;
            }
            else if(root->left_child!=NULL){
                root=root->left_child;
            }
            else root=root->right_child;

            free(temp);
            return tree;
        }

        return tree;
}



void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left_child);
    printf("%d ",root->data);
    inorder(root->right_child);
    
}

int main(){
    struct node* root=NULL;
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,45);
    inorder(root);
    printf("\n");
    root=delete_node(root,10);
    inorder(root);
    printf("\n");
    root=insert(root,15);
    root=insert(root,60);
    inorder(root);
    printf("\n");
    root=delete_node(root,45);
    inorder(root);
    printf("\n");
    return 0;
}