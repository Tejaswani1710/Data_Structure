#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
  int size;
  int tos;
  int s[];
  
}sta;//obj........strucutre of stack

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
      printf("\n Pushed element: %c",element);
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

int peek()
{
  int x=-1;
  if(!IsEmpty())
    {
      x=sta.s[sta.tos];
    }
  else
    printf("\n Stack is Empty....(peek)");
}//peek

int pre(char ch)
{
  switch(ch)
    {
       case '*':
       case '/':
             return 3;
       case '+':
       case '-':
             return 2;
       case '(':
       case '[':
       case '{':
             return 1;	     
    }//switch	  
}//pre
int main()
{
 int i;
 int len=0;
 int j=0;
 char ch;
 char p;
 char postfix[30];
 char infix[40];
 printf("\n Enter a string: ");
 gets(infix);
 len = strlen(infix);
 printf("\n Length=%d",len);
 for(i=0;i<len;++i)
    {
       ch=infix[i];
       switch(ch)
       {
          case '(':	
	  case '[':
	  case '{':	
		 push(ch);
	         break;
	  case ')':
	  case ']':
	  case '}':
	        while(1)
	          {
		   // char p;
		    p=pop();
		    if(p=='(' || p=='[' || p=='{')
			  break;
		    postfix[j++]=p;
		  }//while	
	        break;
	  case '*':
          case '+':
          case '-':
          case '/':
                while(!IsEmpty() && pre(peek())>=pre(ch))
	           postfix[j++]=pop();
                push(ch);
                break;
          default:
              postfix[j++]=ch;		
       }//switch      
    }//for	 
  while(!IsEmpty())
     {
        postfix[j++]=pop();
	postfix[j++]='\0';
     }//while
  printf("\n\n  Postfix: ");
  puts(postfix);
  printf("\n");
 return 0; 
}//main	
