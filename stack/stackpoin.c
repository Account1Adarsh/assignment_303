#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(struct node* top,int val){
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=top;
    return temp;
}

struct node* pop(struct node* top){
    if(top==NULL){
        printf("UNDERFLOW!!!\n");
        return top;
    }
    struct node* temp=top;
    top=top->next;
    free(temp);
    return top;
}

void show(struct node* top){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node*curr=top;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
int main(){
    struct node*top=NULL;
    int a=1;
    while(a){
        printf("To push an element in stck enter 1: \n");
        printf("To pop an element from stack enter 2: \n");
        printf("To print the elements in stck enter 3: \n");
        printf("To show top of stack enter 4: \n");
        printf("To exit giving instruction enter 0: \n");
        scanf("%d ",&a);
        if(a==1){
            printf("Enter the element you want to push \n");
            int val;
            scanf("%d",&val);
            top=push(top,val);
        }
        else if(a==2){
            top=pop(top);
        }
        else if(a==3){
            show(top);
        }
        else if(a==4){
            printf("Top of stack is: %d\n", top->data);
        }
    }
    
    return 0;
}