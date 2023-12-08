#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    printf("Enter the number for factorial: ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,fact(n));
    return 0;
}