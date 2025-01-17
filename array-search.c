#include<stdio.h>



void lsearch(int *a,int n){
    
int i,f=0,num;
printf("enter element to search:\n");
scanf("%d",&num);

for(i=0;i<n;i++){
    if(a[i]==num){
        f=1;
        break;
    }
}

if(f==1)
printf("element %d found at position %d\n",num,i+1);
else
printf("element not found\n");
}

void bsearch(int *a,int n){
int mid,num,i,j,temp;
int pos=-1,ub=n-1,lb=0;

//bubble sort
for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
printf("the sorted aaray\n");
for(i=0;i<n;i++){
    printf("%d \t",a[i]);
}

printf("enter element to search:\n");
scanf("%d",&num);


    while(lb<=ub){
        mid=(ub+lb)/2;
        if(num==a[mid]){
            pos=mid;
            break;
        }
        else if(num>a[mid]){
            lb=mid+1;
        }
        else{
            ub=mid-1;
        }
    }
    if(pos==-1){
        printf("item not found\n");
    }
    else{
        printf("element %d found at position %d\n",num,pos+1);
    }
    
}







void main()
{
int a[30],i,n,ch;
printf("enter limit of aay:\n");
scanf("%d",&n);
printf("enter aay elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);	
}

printf("\n");
do
{
printf("\n1.using linear search\n2.using binary search\n3.exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:lsearch(a,n);
break;
case 2:bsearch(a,n);
break;
case 3:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=3);
}
