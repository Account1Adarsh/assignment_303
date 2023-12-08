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

int search(int arr[],int n,int k){
    int lo,hi,mid;
    lo=0;
    hi=n-1;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    selection(arr,n);

    int k;
    scanf("%d",&k);

    int indx=search(arr,n,k);
    printf("The searched element index in sorted array is:%d",indx+1);
    return 0;
}