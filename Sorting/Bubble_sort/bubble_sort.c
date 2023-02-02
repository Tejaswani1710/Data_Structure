#include<stdio.h>

int Swap(int *a, int*b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}//swap

int Bubble_sort(int a[30], int n)
{
  int i;
  int j;
  int flag=0;  
  for(i=0;i<=n-1;i++)
    {
       for(j=0;j<=n-2-i;j++)
       {
          if(a[j] > a[j+1])
                  Swap(&a[j],&a[j+1]);
          flag=1;
       }
   if(flag==0)
       break;
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
  int n;
  int a[30];
  printf("\n Enter the size of array: ");
  scanf("%d",&n);
  printf("\n Enter %d element of array:  ",n);
  for(i=0;i<=n-1;i++)
    {
       scanf("%d",&a[i]);
    }	  
  printf("\n Your Array before Sorting: ");
  for(i=0;i<=n-1;i++)
    {
       printf(" %d",a[i]);
    }
    Bubble_sort(a,n);
 
return 0;
}//main
