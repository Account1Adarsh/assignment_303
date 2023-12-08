#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* insertpos(struct node* head,int pos,int val){
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node*));
    if(temp==NULL){
        exit(1);
    }
    temp->data=val;
    temp->next=NULL;

    if(head==NULL){
        return temp;
    }
    struct node* curr=head;
    if(pos==1){
        temp->next=head;
        return temp;
    }
    for(int i=0;i<pos-2 && curr!=NULL;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        printf("position enetered is longer than length of list\n");
        return head;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
struct node* delete(struct node* head,int pos){
    if(head==NULL){
        return head;
    }
    struct node*curr=head;
    struct node* temp=NULL;
    if(pos==1){
        temp=head->next;
        free(head);
        return temp;
    }
    for(int i=1;i<pos-1 && curr!=NULL;i++){
        curr=curr->next;
    }
    if(curr!=NULL){
        temp=curr->next;
        curr->next=temp->next;
        free(temp);
        return head;
    }
    else{
        printf("position enetered is longer than length of list\n");
        return head;
    }
}

void print(struct node* head){
    struct node*curr=head;
    while(curr!=NULL){
        printf("->%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    int a=1;
    while(a){
        printf("To add element at any position eneter:1\n");
        printf("To delete element at any position eneter:2\n");
        printf("To print element of list enetr:3\n");
        printf("To exit from loop of entering value enter: 0\n");
        scanf("%d",&a);

        if(a==1){
            int pos,val;
            printf("Enter position at which you want element to be added \n");
            scanf("%d",&pos);
            printf("Enter element which you want element to be added \n");
            scanf("%d",&val);
            head=insertpos(head,pos,val);
        }
        if(a==2){
            int pos;
            printf("Enter position at which you want element to be deleted \n");
            scanf("%d",&pos);
            head=delete(head,pos);
        }
        if(a==3){
            print(head);
        }
    }
    return 0;
}