#include<stdio.h>
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

int main()
{
  int len;
  int flag;
  int i;
  char ch;
  char infix[30];
  printf("\n Enter a string: ");
  gets(infix);
  printf("\n Your String: ");
  puts(infix);
  len = strlen(infix);
  printf("\n Length of your string: %d",len);
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
	         if(!IsEmpty())
	           { 
	             char p;
		     p=peek();
		     if((ch==')' && p=='(')||(ch==']' && p=='[')||(ch=='}' && p=='{'))
	                  p=pop();
	           }//if	     
	        else
	           flag=1;
	     break;
	      default:;
	   }//switch  
     }//for	  
       if(i==len && IsEmpty())
            printf("\n Balanced....\n");
       else
	    printf("\n Unbalanced....\n");       
}	
