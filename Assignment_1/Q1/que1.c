#include<stdio.h>
int Sum(int a[50][50], int m, int n)
{
int i;
int j;
int sum=0;
for(i=0;i<m;++i)
   {
      for(j=0;j<n;++j)
      {
          if(i>j)
           {
              sum+=a[i][j];
           }
      }
   }
 return sum;
}//func
int main()
{
 int i;
 int j;
 int m;
 int n;
 int sum=0;
 int a[50][50];
 printf("\n Enter the number of rows: ");
 scanf("%d",&m);
 printf("\n Enter the number of columns: ");
 scanf("%d",&n);
 printf("\n Enter the %d elements of matrix: ",(m*n));
 for(i=0;i<m;++i)
   {
     for(j=0;j<n;++j)
       {
          scanf(" %d",&a[i][j]);
       }
   }	 
 printf("\n Your matrix:\n");
 for(i=0;i<m;++i)
   {
      for(j=0;j<n;++j)
      {
         printf(" %d ",a[i][j]);
      }      
    printf("\n");  
   }	 
 printf("\n Elements below main diagonal are: ");
 for(i=0;i<m;++i)
   {
      for(j=0;j<n;++j)
      {
          if(i>j)
	   {	  
	      printf("%d ",a[i][j]);
	   }   
      }      
   }
 sum=Sum(a,m,n);
 printf("\n Sum of elements below  main diagonal is: %d",sum); 
	 
 //printf("%d\n",Sum(a,m,n));
 return 0;
}// main	
