/*
[Q3.] Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers
      (Array Implementation of Stack with maximum size MAX)
      a. Push an Element on to Stack
      b. Pop an Element from Stack
      c. Demonstrate how Stack can be used to check Palindrome
      d. Demonstrate Overflow and Underflow situations on Stack
      e. Display the status of Stack
      f. Exit
      Support the program with appropriate functions for each of the above operation.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5

int s[MAX],top=-1,item;
int IsFull( )
{
    if(top>=MAX-1)
        return 1;
    return 0;
}
int IsEmpty( )
{
    if(top==-1)
        return 1;
    return 0;
}
void push(int item)
{
    top++;
    s[top]=item;
}
void pop( )
{
    item=s[top];
    top--;
}
void display( )
{
    int i;
    printf("\n the elements of the stack are");
    for(i=top; i>=0; i--)
        printf("\n %d",s[i]);
}
void check_pal( )
{
    int num, temp, digit, revnum=0,k=0;
    while(top!=-1)
        pop( );
    printf("\nenter the number\n");
    scanf("%d",&num);
    temp=num;
    top=-1;
    while(temp!=0)
    {
        digit=temp%10;
        push(digit);
        temp=temp/10;
    }
    while(top!=-1)
    {
        pop( );
        revnum=item*pow(10,k)+revnum;
        k=k+1;
    }
    printf("\nReverse of %d is %d\n",num,revnum);
    if(num == revnum)
        printf("The %d is Palindrome\n", num);
    else
        printf("The %d is not a Palindrome\n", num);
}
int main( )
{
    int ch;
    do
    {
        printf("\n1. Push \n2. Pop \n3. Display\n4. Check Palindrome\n5. Exit\n");
        printf("\n Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter the element to be inserted:");
                   scanf("%d",&item);
                   if(IsFull( ))
                   printf("Stack Overflow\n");
                   else
                   push(item);
                   break;
                   case 2: if(IsEmpty( ))
                   printf("Stack Underflow\n");
                   else
               {
                   pop( );
                   printf("The item deleted is %d\n",item);
               }
                   break;
                   case 3: if(IsEmpty( ))
                   printf("Stack is Empty\n");
                   else
                   display( );
                   break;
                   case 4: check_pal( );
                   break;
                   case 5: exit(0);
                   default:printf("Invalid choice: \n");
               }
               }while(ch!=5);
                   return 0;
               }


