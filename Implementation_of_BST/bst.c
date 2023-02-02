#include<stdio.h>
#include<stdlib.h>



struct node
{
  int data;
  struct node *rchild;
  struct node *lchild;
};
struct node *bst;

void Insert(int element)
{
  struct node *temp;
  struct node *curr;
  temp=(struct node *)malloc(sizeof(struct node *));
  
  temp->data=element;
  temp->lchild = temp->rchild = NULL;
  
  if(bst==NULL)
        bst=temp;
  else
        curr=bst;
 while(1)
    {
      if(element < curr->data)
            if(curr->lchild!=NULL)
	         curr=curr->lchild;
	   else
	       {	   
	         curr->lchild=temp;
                 break;		
               }
      else//ele>curr->lchild
        {
  	   if(curr->rchild!=NULL)
			curr=curr->rchild;
	   else
		   curr->rchild=temp;
		   break;
        }
    }  
}//insert element

int Find_max(struct node *curr)
{
  int x=-1;
  if(curr!=NULL)
    {
                while(curr->rchild!=NULL)
                        curr = curr->rchild;
                x=curr->data;
        }
return x;
}//max

int Find_min(struct node *curr)
{
  int x=-1;
  if(curr!=NULL)
     {
        while(curr->lchild!=NULL)
		curr = curr->lchild;
	x=curr->data;
     }	  
  return x;
}//min

struct node * Delete(struct node *curr,int element)
{
  if(curr!=NULL)
    {
	   if(element < curr->data)
			curr->lchild = Delete(curr->lchild,element);
	   else if(element > curr->data)
			curr->rchild = Delete(curr->rchild,element);
	   else if(curr->lchild!=NULL && curr->rchild!=NULL)
		{
		   curr->data = Find_max(curr->lchild);
		   curr->lchild = Delete(curr->lchild,curr->data);
	        }
   	   else
	        {
	           struct node *temp;
                   temp=(struct node *)malloc(sizeof(struct node *));
		   temp = curr;
	      	   if(curr->rchild == NULL)
			 curr = curr->lchild;
		   else
		         curr = curr->rchild;
	           free(temp);
	        }
     }
 return curr;
}//del

void Inorder(struct node *curr)
{
  if(curr!=NULL)
     {
        Inorder(curr->lchild);
	printf(" %d",curr->data);
	Inorder(curr->rchild);
     }
 	  
}//inorder

void Preorder(struct node *curr)
{
  if(curr!=NULL)
    {
		printf(" %d",curr->data);
		Preorder(curr->lchild);
		Preorder(curr->rchild);
	}
}//preorder

void Postorder(struct node *curr)
{
  if(curr!=NULL)
    {
        Postorder(curr->lchild);
        Postorder(curr->rchild);
        printf(" %d",curr->data);
   	}
}//postorder


int No_of_leafNodes(struct node *curr)
{
  if(curr == NULL)
		return 0;
  if(curr->lchild == NULL && curr->rchild == NULL)
        return 1;
 return(No_of_leafNodes(curr->lchild) + No_of_leafNodes(curr->rchild));
}//leaf nodes

int No_of_Non_LeafNodes(struct node *curr)
{
  if(curr == NULL)
		return 0;
  if(curr->lchild == NULL && curr->rchild == NULL)
		return 0;
  return(No_of_Non_LeafNodes(curr->lchild) + No_of_Non_LeafNodes(curr->rchild));
}//non leaf nodes

int Max(int a,int b)
{
	if(a<b)
			return b;
return a;	
}//max

int Height(struct node *curr)
{
  if(curr == NULL)
		return -1;
  if(curr->lchild == NULL && curr->rchild == NULL)
		return 0;
 return(Max(Height(curr->lchild),Height(curr->rchild))+1);
}//height

int main()
{
bst = NULL;
int x;
int del;
struct node *y;
int ch;
int ele;
while(1)
  {
 	 printf("\n\n 1.Insert an element \n 2.Delete an element \n 3.Inorder \n 4.Preorder \n 5.Postorder \n 6.No. of Leaf Nodes \n 7.No. of Non Leaf Nodes \n 8.Height \n 9.Quit");
        printf("\n Your choice: ");
	scanf("%d",&ch);
	switch(ch)
	   {
	      case 1:
		    printf("\n Enter the element: ");
		    scanf("%d",&ele);
		    Insert(ele);  
		    break;  
	      case 2:
		    printf("\n Enter the element to delete: ");
		    scanf("%d",&del);
                    y=Delete(bst,del);
		  //  printf("\n Element deleted %d.",y->data);
		    break;
	      case 3:
		    printf("\n Inorder: ");
		    Inorder(bst);
	            break;
              case 4:
		    printf("\n Preorder: ");
		    Preorder(bst);
		    
		    break;
              case 5:
		    printf("\n Postorder: ");
		    Postorder(bst);

		    break;
              case 6:
//		    int x;
		    x= No_of_leafNodes(bst);
		    printf("\n No. of Leaf Nodes: %d",x);
		    break;
              case 7:
//		    int x;
		    x=No_of_Non_LeafNodes(bst);
		    printf("\n No of non leaf nodes: %d",x);
		    break;
              case 8:
//		    int x;
		    x=Height(bst);
		    printf("\n Height = %d",x);
		    break;
              case 9:
		    exit(0);
		    break;
	      default:
		   printf("\nINVALID CHOICE!!!");
     		   break;		   
		      
	   }//switch	
  }//while		
}//main
