#include<stdio.h>
#include<stdlib.h>

int push(int arr[],int val,int tail){
    if(tail==99){
        return tail;
    }
    tail++;
    arr[tail]=val;
    return tail;
}
int pop(int arr[],int tail){
    if(tail<0) {
        printf("UNDERFLOW!!1\n");
        return tail;
    }
    for(int i=0;i<tail;i++){
        arr[i]=arr[i+1];
    }
    tail--;
    return tail;
}

void show(int arr[],int tail){
    for(int i=0;i<=tail;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[100];
    int tail=-1;
    int a=1;
    while(a){
        printf("To push an element in queue enter 1: \n");
        printf("To pop an element from queue enter 2: \n");
        printf("To print the elements of queue enter 3: \n");
        printf("To exit giving instruction enter 0: \n");
        scanf("%d",&a);
        if(a==1){
            printf("Enter the element you want to push \n");
            int val;
            scanf("%d",&val);
            tail=push(arr,val,tail);
        }
        else if(a==2){
            tail=pop(arr,tail);
        }
        else if(a==3){
            show(arr,tail);
        }
    }
    
    return 0;
}