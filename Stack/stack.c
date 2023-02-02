#include<stdio.h>
#include<stdlib.h>
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

int length()
{
   return sta.tos+1;
}//length

void display()
{
 int i=0;
 if(!IsEmpty())
   {
     for(;i<sta.tos;i++)
       {
	 printf("\n Element @ %d is %d",i,sta.s[i]);
       }
   }
 else
   printf("\nStack is Empty... (Display)");
}//display

void push(int element)
{
  if(!IsFull())
    {
      sta.tos++;
      sta.s[sta.tos]=element;
      printf("\n Pushed element: %d",sta.s[sta.tos]);
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
  sta.size;
  sta.tos=-1;
  printf("\n Enter the number of elelments: ");
  scanf("%d",&sta.size);
  sta.s[sta.size];
  printf("Enter the %d elements of Array: ",sta.size);
  int i;
  for(i=0;i<sta.size;i++)
    {
       int j;
       scanf("%d",&j);
       push(j);
    }
  printf("\n Top element is %d.",peek());
  printf("\n Stack size is %d.",length());
  for(i=0;i<sta.size;i++)
     {
         printf("\n Popped element is %d.",pop());
     }
}//main
