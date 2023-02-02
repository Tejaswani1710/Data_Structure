#include<stdio.h>

int a[30];
int n;

int Heapify(int i, int size)
{
  int temp;
  int c;  
  for (temp= a[i]; 2*i+1<size; i=c)
    {
     	  c=2*i+1;
     if(2*i+2<size && a[2*i+2]>a[i])
   	   c++;
     if(a[c]>temp)
 	  a[i]=a[c];
     else
	break;
    }
 a[i]=temp;  
}//heapify

int Swap(int *a, int*b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}//swap


int Heap_Sort()
{
  int i;	
  for(i=n/2 -1;i>=0;i--)
	  Heapify(i,n);
  for(i=n-1;i>=1;i--)
     {
         Swap(&a[0],&a[i]);
	 Heapify(0,i);
     }	  
   printf("\n Your Array after Sorting: ");
          for(i=0;i<=n-1;i++)
            {
               printf(" %d",a[i]);
            }
   printf("\n");
}//sorting	

int main()
{	
  int i;
 
  printf("\n Enter the size of array: ");
  scanf("%d",&n);
  printf("\n Enter %d element of array:  ",n);
  for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
  printf("\n Your Array before Sorting: ");
  for(i=0;i<n;i++)
    {
       printf(" %d",a[i]);
    }
 Heap_Sort();

return 0;
}//main 
