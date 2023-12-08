#include<stdio.h>
#include<stdlib.h>

int push(int arr[],int tail,int val){
    if(tail==99){
        printf("OVERFLOW CONDITION!!!\n");
        return tail;
    }
    arr[tail+1]=val;
    tail++;
    return tail;
}

int pop(int arr[],int tail){
    if(tail<0){
        printf("UNDERFLOW!\n");
        tail=-1;
        return tail;
    }
    else{
        tail--;
        return tail;
    }
}

void show(int arr[],int tail){
    for(int i=0;i<=tail;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

// int top(int arr[],int tail){
//     return arr[tail];
// }

int main(){
    int arr[100];
    int tail=-1;
    int a=1;
    while(a){
        printf("To push an element in stck enter 1: \n");
        printf("To pop an element from stack enter 2: \n");
        printf("To print the elements in stck enter 3: \n");
        printf("To show top of stack enter 4: \n");
        printf("To exit giving instruction enter 0: \n");
        scanf("%d ",&a);
        if(a==1){
            int val;
            printf("Enter the element you want to push \n");
            scanf("%d",&val);
            tail=push(arr,tail,val);
        }
        else if(a==2){
            tail=pop(arr,tail);
        }
        else if(a==3){
            show(arr,tail);
        }
        else if(a==4){
            printf("Top of stack is: %d\n", arr[tail]);
        }
    }
    return 0;
}