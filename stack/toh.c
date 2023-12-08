#include<stdio.h>
#include<stdlib.h>

void TOH(int n,char A,char C,char B){
    if(n==1){
        printf("MOVE 1 DISC FROM %c TO %c ",A,C);
    }
    TOH(n-1,A,B,C);
    printf("MOVE %d DISC FROM %c TO %c ",n,A,C);
    TOH(n-1,B,C,A);
}

int main(){
    printf("Enter the number of disc in rod A: ");
    int n;
    scanf("%d",&n);
    TOH(n,'A','C','B');
    return 0;
}