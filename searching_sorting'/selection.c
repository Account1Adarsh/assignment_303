#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_indx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_indx]){
                min_indx=j;
            }
        }
        if(min_indx!=i) swap(&arr[i],&arr[min_indx]);
    }
}

void show(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection(arr,n);
    show(arr,n);
    return 0;
}