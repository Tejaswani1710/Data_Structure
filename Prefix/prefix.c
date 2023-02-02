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
       case ')':
       case ']':
       case '}':
             return 1;	     
    }//switch	  
}//pre

int reverse_string(char prefix[30],int n, int size)
{
 char temp;
 temp=prefix[n];
 prefix[n]=prefix[size - n];
 prefix[size-n]=temp;
 if(n==size/2)
       return prefix ;
 return reverse_string(prefix,++n,size);
}

int main()
{
 int i;
 int len=0;
 char j=0;
 char ch;
 char p;
 char prefix[30];
 char infix[30];
 printf("\n Enter a string: ");
 gets(infix);
 len = strlen(infix);
 printf("\n Length=%d",len);
 for(i=len-1;i>=0;--i)
    {
       ch=infix[i];
       switch(ch)
       {
          case ')':	
	  case ']':
	  case '}':	
		 push(ch);
	         break;
	  case '(':
	  case '[':
	  case '{':
	        while(1)
	          {
	//	    char p;
		    p=pop();
		    if(p==')' || p==']' || p=='}')
			  break;
		    prefix[j++]=p;
		  }//while	
	        break;
	  case '*':
          case '+':
          case '-':
          case '/':
                while(!IsEmpty() && pre(peek())>=pre(ch))
	           prefix[j++]=pop();
                push(ch);
                break;
          default:
              prefix[j++]=ch;		
       }//switch      
    }//for	 
  while(!IsEmpty())
     {
        prefix[i++]=pop();
	prefix[j++]='\0';
     }//while
//  prefix[j++]='\0';  
  len=strlen(prefix);
  reverse_string(prefix,0,len-1);
  printf("\n\n Prefix: ");
  puts(prefix);
  //printf("\n");
  return 0; 
}//main	
