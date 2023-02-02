#include<stdio.h>

int Swap(int *a, int*b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}//swap

int Quick_Sort(int a[30], int low, int high)
{
  int i;
  int j;  
  int pivot;
  pivot = a[low];
  i=low+1;
  j=high;
  if(low<high)
     {
         while(1)
	   {
	     while(a[j]>pivot)
		     j--;
	     while(i<=high && a[i]<pivot)
		     i++;
	     if(i<j)
		  Swap(&a[i],&a[j]);
             else
	         break;	     
	   }//while
        Swap(&a[low],&a[j]);
        Quick_Sort(a,low,j-1);
	Quick_Sort(a,j+1,high);	
     }
  
  	  
  printf("\n Your Array after Sorting: ");
  for(i=0;i<=high;i++)
    {
       printf(" %d",a[i]);
    }
  
}//sorting

int main()
{
  int n;
  int a[30];
  int i;
  printf("\n Enter the size of array: ");
  scanf("%d",&n);
  printf("\n Enter %d element of array:  ",n);
  for(i=0;i<=n-1;i++)
    {
       scanf(" %d",&a[i]);
    }	  
  printf("\n Your Array before Sorting: ");
  for(i=0;i<n;i++)
    {
       printf(" %d",a[i]);
    }
   Quick_Sort(a,0,n-1);
   return 0;
}//main	
