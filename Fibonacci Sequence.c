
#include<stdio.h>
#include<stdlib.h>

void main(){
    int i,n,n1=0,n2=1;
    n=n1+n2;
    printf("Fibonacci Sequence :%d,\t%d,\t",n1,n2);
    for(i=3;i<=10;i++){
       printf("%d,\t",n);
       n1=n2;
       n2=n;
       n=n1+n2;
       
    }
}
