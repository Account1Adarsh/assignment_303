#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int size(struct node* head){
    int count=1;
    if(head==NULL){
        return 0;
    }
    struct node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
        count++;
    }
    return count;
}
struct node* insert(struct node* head,int pos ,int val){
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        exit(1);
    }
    temp->data=val;
    temp->next=NULL;


    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    int n=size(head);
    //pos=pos%n;
    pos = (pos % n + n) % n;//handles negative pos as well
    //pos=(pos-pos/n)%n;
    struct node* curr=head;
    if(pos==0){//insert at the beginning
        temp->next=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        return temp;
    }
    else{
      for(int i=1;i<pos;i++){
        curr=curr->next;
      }
      temp->next=curr->next;
      curr->next=temp;
      return head;
    }
}

struct node* delete(struct node* head,int pos){
    int n=size(head);
    //pos=(pos-pos/n)%n;
    pos = (pos % n + n) % n;//handles negative pos as well
    struct node* temp=NULL;
    struct node*curr=head;
    if(pos==0){
        while(curr->next->next!=head){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=curr->next->next;
        free(temp);
        return head;
    }
    else if(pos==1){
        temp=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=head->next;
        head=head->next;
        free(temp);
        return head;
    }
    else {
        for(int i=1;i<pos;i++){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=temp->next;
        free(temp);
        return head;
    }
}
void print(struct node* head){
    struct node* curr=head;
    printf("->%d ",curr->data);
    while(curr->next!=head){
        printf("->%d ",curr->next->data);
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
            head=insert(head,pos,val);
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