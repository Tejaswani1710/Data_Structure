#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
  int size;
  int tos;
  int s[];

}sta;//obj........strucutre of stack

int ctoi(char a)
{
  return (int)a-48;
}//fun ctoi	

int IsEmpty()
{
 if(sta.tos == -1)
   {
     return -1;
   }
 return 0;
}//Empty

int IsFull()
{
 if(sta.tos == sta.size-1)
   {
      return 1;
   }
 return 0;
}//full

void push(int element)
{
  if(!IsFull())
    {
      sta.tos++;
      sta.s[sta.tos]=element;
      printf("\n Pushed element: %d",element);
    }
  else
     printf("\n Stack is full..");
}//push

int pop()
{
  int x=-1;
  if(!IsEmpty())
    {
       x=sta.s[sta.tos];
       sta.tos--;
    }
  else
    printf("\n Stack is Empty....(Pop)");
  return x;
}//pop

int main()
{
 int a;
 int b;
 int c;
 int i; 
 int len=0;
 char ch;
 char postfix[30];
// sta.tos=-1;
 printf("\n Enter the postfix: ");
 gets(postfix);
 len=strlen(postfix);
 for(i=0;i<len;++i)
   {
     ch=postfix[i];
     switch(ch)
     {
       case '+':
	       a=pop();
	       b=pop();
	       push(b+a);
               break;
       case '-':
               a=pop();
               b=pop();
	       push(b-a);
	       break;
       case '*':
	       a=pop();
	       b=pop();
	       push(b*a);
	       break;
       case '/':
               a=pop();
	       b=pop();
	       push(b/a);
               break;
       default:
	       c = ctoi(ch);
               push(c);	       
     }//switch     
   }//for
 printf("\n Result = %d\n",sta.s[1]);
 return 0;
}//main	
