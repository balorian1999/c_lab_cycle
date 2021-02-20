#include<stdio.h>
int main()
{
  int m,n;
  printf("Enter the size of first array = ");
  scanf("%d",&m);
  int a[m];
  printf("Enter array elements:\n");
  for(int i=0;i<m;i++)
  {
	  scanf("%d",&a[i]);
	  for(int j=0;j<i;j++)
	  {
		  if(a[i]>a[j])
		  {
			  int temp = a[j];
			  a[j] = a[i];
			  a[i] = temp;
		 }
	   }
  }
  printf("Enter the size of second array = ");
  scanf("%d",&n);
  int b[n];
  printf("Enter array elements:\n");
  for(int i=0;i<n;i++)
  {
	  scanf("%d",&b[i]);
	   for(int j=0;j<i;j++)
	  {
		  if(b[i]>b[j])
		  {
			  int temp = b[j];
			  b[j] = b[i];
			  b[i] = temp;
		 }
	   }
  }
  int c[m+n];
  int j=0;
  for(int i=0;i<m+n;i++)
  {
	  if(i>m-1)
	  {
		  c[i]=b[j];
		  j++;
	  }
	  else
	  {
		  c[i]=a[i];
	   }
   }
   printf("\nMerged Array");
   {
	   for(int i=0;i<m+n;i++)
	   {
		   printf("\n%d",c[i]);
		}
	}
 return 0;
}
  
  
