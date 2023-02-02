#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};   //structure
 struct node *list;
 struct node *curr;

int Push(int element)
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
}//push

int Pop()
{
  int x=-1;
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if(list!=NULL)//if there r elements in list
   {
    if(list->next == NULL)//if there is only 1 element in list
      {
         temp=list;
	 x=temp->data;
	 list=NULL;
	 free(temp);
      }	    
    else //if the elements are >1 in the list
      {
        curr=list;
	while(curr->next->next!=NULL)//till last element
		curr = curr->next;
	temp=curr->next;
	x=temp->data;
	curr->next=NULL;
	free(temp);
      }
   } 	  
  else
   printf("\n List is empty.....(del end)");
 return x;   
}//pop

int peek()
{
  if(list == NULL)
	  printf("\n Stack is Empty");
  else
     {
       curr=list;
       while(curr->next!=NULL)
         {
	    curr=curr->next;
	 }	       
       printf("\n Top of stack is: %d",curr->data);
     }	  
}//peek

void Print_ele(struct node *curr)
{
  if(curr == NULL)
          return;
  Print_ele(curr->next);
  printf("%d\n",curr->data);
}//print

void Display()
{
 if(list!=NULL)
  	 Print_ele(list);
  else
      printf("\n List is empty.....(travel back)");	  	  
}//display

int main()
{
  int num;
  int ele;
  int pele;
  int dele;
  int ch;
  int i;
  int j=1;
  while(1)
     {	  
	printf("\n ************************** ");     
        printf("\n 1.Create a stack \n 2.Push an element into stack \n 3.Pop an element from stack \n 4.Peek into the stack \n 5.Display your stack \n 6.Quit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
	switch(ch)
	   {
	     case 1://create
		   printf("\n Enter how many elements you want in your list:");
                   scanf("%d",&num);
                   for(i=0;i<num;++i)
                      {
                        printf("\n Enter the %d of your list: ",j++);
                        scanf("%d",&ele);
                        Push(ele);
		      }	
		   printf("\n Your stack:\n ");
		   Display();
		   break;
             case 2://push
                   printf("\n Enter the element to be pushed: ");
		   scanf("%d",&pele);
		   Push(pele);
		   printf("\n Stack after pushing an element:\n");
		   Display();
		   break;
	     case 3://pop
		   printf("\n Element popped: %d",Pop());
                   printf("\n Stack after popping an element:\n");
		   Display();
		   break;
	     case 4://peek
		   peek();
		   break;
	     case 5://display
		   printf("\n Your stack:\n");
		   Display();
		   break;
	     case 6://exit
		   exit(0);
		   break;
	     default: 
                    printf("\n INVALID CHOICE!!!");
 		    break;		    
	   }//switch	
     }//while
}//main
