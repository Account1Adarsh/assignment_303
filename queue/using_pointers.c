#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* head,int val){
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(head==NULL){
        return temp;
    }
    struct node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

struct node* pop(struct node* head){
    if(head==NULL){
        printf("NO elements left to be deleted\n");
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

void show(struct node*head){
    if(head==NULL){
        printf("empty queue\n");
        return;
    }
    struct node*curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main(){
    struct node*head=NULL;
    //struct node*tail=NULL;
    int a=1;
    while(a){
        printf("to push eneter 1\n");
        printf("to pop eneter 2\n");
        printf("to show eneter 3\n");
        printf("to exit eneter 0\n");
        scanf("%d",&a);
        if(a==1){
            int val;
            scanf("%d",&val);
            head=push(head,val);
        }
        else if(a==2){
            head=pop(head);
        }
        else if(a==3){
            show(head);
        }
    }
    return 0;
}