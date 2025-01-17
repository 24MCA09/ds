#include<stdio.h>
int size=5;
int top=-1;

void push(int *stack){
int num;
if(top==size-1){
    printf("stack overflow");
}
else{
    printf("enter number :");
    scanf("%d",&num);
    top=top+1;
    stack[top]=num;
    printf("%d pushed to stack",num);
}
printf("\n");
}

void pop(int *stack){

if(top<0){
    printf("stack underflow");
}
else{
    top=top-1;
    printf("value poped");
}
printf("\n");

}

void display(int *stack){
    int i;
if(top<0){
    printf("stack empty\n");
}
else{
    printf("stack elements");
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
printf("\n");

}

void main(){
int stack[5],ch;
do{
printf("Stack Operations\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:push(stack);
break;
case 2:pop(stack);
break;
case 3:display(stack);
break;
case 4:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=4);
}






