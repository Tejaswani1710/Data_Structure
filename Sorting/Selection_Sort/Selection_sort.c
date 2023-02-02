#include<stdio.h>

void Swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}//swap	

int main()
{
  int n;
  int i;
  int j;
  int loc;
  int ss[30];
  printf("\n Enter the size of array: ");
  scanf("%d",&n);
  printf("\n Enter %d the elements of array: ",n);
  for(i=0;i<n;i++)
     {
        scanf("%d",&ss[i]);
     }
     printf("\nThe Array is:");	 
      for(i=0;i<n;i++)
     {
        printf(" %d",ss[i]);
     }
     
  for(i=0;i<n;i++)
     {
        loc=i;
	for(j=i+1;j<n;j++)
           {
	       if(ss[j] < ss[loc])
		       loc=j;
	   }		
	if(loc!=i)
		Swap(&ss[i],&ss[loc]);
     }	  
  printf("\n After Sorting: ");
   for(i=0;i<n;i++)
     {
        printf(" %d",ss[i]);
     }
return 0;
}//main
