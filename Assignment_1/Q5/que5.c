#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};   //structure
 struct node *list;
 struct node *curr;

void Insert_begin(int element)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data = element;
  temp->next = list;
  list = temp;
}//insert in the beginning

void Insert_elements(int element)
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
}//insert elements

int Delete_element(int element)
{ 
  int x=-1;  
  struct node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if(list!=NULL)//if there r elements in list
   {
     if(list->next == NULL)//if there is only 1 element in list
       {
         temp=list;
      	 list=temp->next;
	 x=temp->data;
	 free(temp);
       }
     else//if element are >1
       {
         curr=list;
	 while(curr->next!=NULL && curr->next->data!=element)//till we found element
		 curr=curr->next;
         if(curr->next == NULL)//last element
		 printf("\n Element not found!!!");
	 else//element found
           {
	     temp = curr->next;
	     x=temp->data;
	     curr->next = temp->next;
	     free(temp);
	   }
       }
   }
  else
     printf("\n List is Empty......(del sp)");
return x;  
}//del element

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
  int num;
  int i;
  int j=1;
  int ele;
  int mele;
  int fele;  
  printf("\n Enter how many elements you want in your list:");
  scanf("%d",&num);
  for(i=0;i<num;++i)
   {
     printf("\n Enter the %d of your list: ",j++);
     scanf("%d",&ele);
     Insert_elements(ele);
   }
  printf("\n Your list:\n ");
  Display();
  printf("\n Enter the element you want to be in the front: ");
  scanf("%d",&mele);
  fele=Delete_element(mele);
  printf("\n%d",fele);
  Insert_begin(fele);
  printf("\n Your stack after changes:\n");
  Display();
 return 0;
}//main	
