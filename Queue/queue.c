#include<stdio.h>
struct queue
{
  int size;
  int front;
  int rear;
  int q[];
}que;//obj

int Underflow()
{
  if(que.front == -1 && que.rear == -1)
    {
      return -1;
    }
  return 0;
}//underflow

int Overflow()
{
  if(que.rear == que.size-1)
    {
       return 1;
    }
  return 0;
}//overflow

void Display()
{
  int i;
  if(!Underflow())
    {
       for(i=que.front;i<=que.rear;i++)
         {
	    printf("\n #%d",que.q[i]);
         }
    } 
  else
    printf("\n Queue is empty.....");
}//display

void Enqueue(int ele)
{
  if(!Overflow())
    {
      if(que.front == -1 && que.rear == -1)
        {
	  que.front++;
        }
     que.rear++;
     que.q[que.rear]=ele;
    }
  else
    printf("\n Queue is full.....");
}//in

int Dequeue()
{
  int x=-1;
  if(!Underflow())
    {
      x=que.q[que.front];
      if(que.front == que.rear)
         { que.front=-1;
		que.rear=-1;}
      else
         que.front++;
    }
  else
     printf("\n Queue is Empty.... ");
  return x;
}//out

int main()
{
  que.front=-1;
  que.rear=-1;
  printf("\n Enter the Size of Queue: ");
  scanf("%d",&que.size);
  printf("\n Enter the elements of Queue: ");
  for(int i=0;i<que.size;++i)
     {
	int j;
        scanf("%d",&j);
        Enqueue(j);
     }
  printf("\n Elements of queue:");
  Display();
  printf("\n Dequeue of elemnts: ");
  for(int i=0;i<que.size;++i)
     {
        printf("\n@ %d",Dequeue());
     }
 Display();
  return 0;
}//main
