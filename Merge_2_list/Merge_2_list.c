#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};   //structure
 struct node *list;
 struct node *curr;
 struct node *list1;
 struct node *list2;


 void Insert(struct node *list,int element)
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
  return list;
}//insert 

void Display()
{
  struct node *curr;
  curr=list;
  while(curr!=NULL)
     {
       printf(" %d",curr->data);
       curr=curr->next;
     }
}//display

int Merge(struct node *list3, struct node *list2, struct node list1)
{
  struct node *c1, *c2;	
  c1=list1;
  c2=list2;
  while(c1!=NULL && c2!=NULL)
      {
         if(c1->data < c2->data)
   	    {
	       list3 = Insert(list, c1->data);
	       c1=c1->next;
	    }		 
      else if(c2->data<c1->data)
        {
          list3=Insert(list3,c2->data);
           c2=c2->next;
        }
      else
        {
          list3=Insert(list3,c1->data);
            c1=c1->next;
            c2=c2->next;
        }
     }
         while(c1!=NULL)
          {
             list3=Insert(list3,c1->data);
              c1=c1->next;

          }
            while(c2!=NULL)
          {
             list3=Insert(list3,c2->data);
              c2=c2->next;

          }
        
  return list3;
}//merge

int main()
{
  int ele;
  int ch;
  while(1)
    {
       printf("\n 1.Enter the element of list 1 \n 2.Enter the elements of list 2 \n 3.Merge the lists \n 4.Display \n 5.Exit");
       scanf("%d",&ch);
       switch(ch)
	     {
	       case 1:
				 printf("\n Enter the element for list 1: ");
				 scanf("%d",&ele);
				 Insert(list1,ele);
		         break;
	       case 2:
		         break;
	       case 3:
		         break;
	       case 4:
		         break;
	       case 5:
		         break;
	       default:
		          printf("\n INVALID CHOICE!!!");
		          break;	   
	     }//switch
    }//while
}//main	
