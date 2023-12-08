#include<stdio.h>
#include<stdlib.h>

int push(int arr[],int rear,int front,int val,int size,int n){
    if(size==n){
        printf("OVERFLOW!!!\n");
        return rear;
    }
    // int k=(rear-front+n)%n;
    if(front<0){
        arr[0]=val;
        front=0;
        rear=0;
        size++;
        return 0;
    }
    // if(k<n-1){
    //     rear=(rear+1)%n;
    // }
    rear=(rear+1)%n;
    arr[rear]=val;
    size++;
    return rear;
}

int pop(int arr[],int front,int rear,int size,int n){
    
    if(size==0){
        printf("UNDERFLOW!!!\n");
        return front;
    }
    front=(front+1)%n;
    size--;
    return front;
}

void show(int arr[],int front,int rear,int size,int n){
    if(size==0){
        printf("This queue is empty!!!\n");
        return;
    }
    int count=0;
    int i=front;
    while(count<size){
        printf("%d",arr[i]);
        i=(i+1)%n;
        count++;
    }
    printf("\n");
}
int main(){
    int size=0;
    int front=-1,rear=-1,arr[5];
    int n=sizeof(arr)/sizeof(arr[0]);
    int a=1;
    while(a){
        printf("To Push enter 1\n");
        printf("To Pop enter 2\n");
        printf("To Show enter 3\n");
        printf("To exit enter 0\n");
        scanf("%d",&a);
        switch(a){
        case 1:
            {   
                int val;
                printf("Enter the element to be inserted\n");
                scanf("%d",&val);
                rear=push(arr,rear,front,val,size,n);
                break;
            }
        case 2:
            {
                front=pop(arr,front,rear,size,n);
                break;
            }
        case 3:{
                show(arr,front,rear,size,n);
                break;
            }

        }
    }
    return 0;
}