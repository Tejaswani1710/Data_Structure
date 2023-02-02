#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};   //structure
 struct node *list;
 struct node *curr;

 int Enqueue(int element)
{
   struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = element;
  temp->next = NULL;
  if(list == NULL)
    {
       list =temp;
    }	  
  else
    {
      curr=list;
      while(curr->next!=NULL)
	      curr = curr->next;
      curr->next = temp;
    }	  
}//enqueue

int Dequeue()
{
  int x=-1;
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if(list!=NULL)//if there r elements in list
    {
      temp=list;
      x=temp->data;
      list=temp->next;
      free(temp);
    }	  
  else
     printf("\n List is empty....(Del beg)");
  return x;   
}//Dequeue

void Display()
{
  struct node *curr;
  curr=list;
  while(curr!=NULL)
     {
       printf("%d\n",curr->data);
       curr=curr->next;
     }
}//display

int main()
{
 int ch;
 int i;
 int num;
 int j=1;
 int ele; 
 int iele;

 while(1) 
    {
      printf("\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* ");	    
      printf("\n 1.Create a queue \n 2.Enqueue an element in the queue \n 3.Dequeue an element from queue \n 4.Display \n 5.Quit");
      printf("\n Enter your choice: ");
      scanf("%d",&ch);
      printf("\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* ");
      switch(ch)
         {
	    case 1://create
		  printf("\n Enter how many elements you want in your list:");
  		  scanf("%d",&num);
  		  for(i=0;i<num;++i)
   		     {
     			printf("\n Enter the %d of your list: ",j++);
     			scanf("%d",&ele);
     			Enqueue(ele);
   		     }
  		  printf("\n Your queue:\n");
  		  Display();  
		  break;  
            case 2://enqueue
		  printf("\n Enter the element your want to insert in the queue: ");
		  scanf("%d",&iele);
		  Enqueue(iele);
		  printf("\n Your queue after adding an element:\n");
		  Display();
		  break;
	    case 3://Dequeue
                  printf("\n Element Dequeued: %d",Dequeue());
		  printf("\n Your queue after removing an element:\n");
		  Display();
		  break;
	    case 4://display
		  printf("\n Your queue:\n");
		  Display();
		  break;
	    case 5://quit
		  exit(0);
		  break;
	    default:
                   printf("\nINVALID CHOICE!!!");
		   break;		   
	 }//switch   
    }//while	 
}//main	
