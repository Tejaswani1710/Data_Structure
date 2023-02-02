#include<stdio.h>

int Insertion_sort(int a[30],int n)
{
  int i;
  int j;
  int temp;
  for(i=1;i<=n-1;i++)
     {
        j=i-1;
	temp=a[i];
	while(j>=0 && a[j]>temp)
	    {
	      a[j+1] = a[j];
	      j--;
	    }	
	a[j+1]=temp;
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
  int j;
  int n;
  int a[30];
  printf("\n Enter the size of array: ");
  scanf("%d",&n);
  printf("\n Enter the elements of array: ");
  for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);   
     }	  
  printf("\n Your Array before Sorting: ");
  for(i=0;i<=n-1;i++)
    {
       printf(" %d",a[i]);
    }
  Insertion_sort(a,n);
return 0;
}//main	
