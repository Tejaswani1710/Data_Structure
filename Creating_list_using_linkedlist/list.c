#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};   //structure
 struct node *list;
 struct node *curr;

void Insert_elements(int ele)
{ 
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
	
  if(list==NULL)
   {	
     temp->data = ele;
     temp->next = NULL;
     list = temp;
   }
  else
   {
     curr=list;
      while(curr->next!=NULL)
	      curr = curr->next;
      temp->data = ele;
      temp->next = NULL;
      curr->next = temp;
   }	  
}//insert elements 

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

int main()
{
 int i;
 int j=1;
 int num;
 int ele;
 printf("\n Enter how many elements you want in your list:");
 scanf("%d",&num);
 for(i=0;i<num;++i)
   {
     printf("\n Enter the %d of your list: ",j++);
     scanf("%d",&ele);
     Insert_elements(ele);
   }	 
 printf("\n Your list: ");
 Display();
 return 0;
}
