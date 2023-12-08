#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int k=i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void show(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
     int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    show(arr,n);
    return 0;
}