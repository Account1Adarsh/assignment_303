#include<stdio.h>
#include<stdlib.h>

int add(int arr[],int pos,int tail,int val){
        if(pos<0||pos>tail+1){
            printf("Cannot add the element at given position in list\n");
            return tail;
        }
        if(tail==99){
            printf("Array is full\n");
            return tail;
        }
        for(int i=tail+1;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        return tail+1;
}

int delete(int arr[],int tail,int pos){
    if(pos<0||pos>tail||tail<0){
        printf("Cannot delete the element \n");
        return tail;
    }
    for(int i=pos;i<tail;i++){
        arr[i]=arr[i+1];
    }
    tail--;
    return tail;
}

void show(int arr[],int tail){
    for(int i=0;i<=tail;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[100];
    int tail=-1;
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
            tail=add(arr,pos,tail,val);
        }
        if(a==2){
            int pos;
            printf("Enter position at which you want element to be deleted \n");
            scanf("%d",&pos);
            tail=delete(arr,tail,pos);
        }
        if(a==3){
            show(arr,tail);
        }
    }
    return 0;
}