#include<stdio.h>
#define n 60
int bst[n];
void Insertion(int,int);
void Traverse(int);
void Deletion(int,int);
void Search(int,int);
int inordsuc(int);
int keypos(int,int);
int main()
{
	int m=0,key=0;
	for(int j=1;j<=n;j++)
	{
		bst[j]=-1;
	}
	while(1)
	{
	printf("\n\n\t\t\t Menu\n\n1->Inserion\t2->Traverse\t3->Deletion\t4->Search\t5->Exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
	  case 1:printf("\nEnter the key = ");
	         scanf("%d",&key);
	         Insertion(key,1);
	         break;
	  case 2:Traverse(1);
	         break;
	  case 3:printf("\nEnter the key to delete = ");
	         scanf("%d",&key);
	         Deletion(key,1);
	         break;
	  case 4:printf("\nEnter the key to search = ");
	         scanf("%d",&key);
	         Search(key,1);
	         break;	
	  case 5:return 0;
	         break;
	  default:printf("Invalid Choice");
	}
   }
}
void Insertion(int key,int i)
{
	if(bst[i]==-1)
	{
		bst[i]=key;
		printf("\n Insertion Successfull");
	}
	else if(key<bst[i])
	{
		Insertion(key,2*i);
	}
	else
	{
		Insertion(key,(2*i)+1);
	}
}
void Traverse(int l)
{
	if(bst[l]!=-1 && l<=n)
	{
		Traverse(2*l);
		printf("\n\t%d",bst[l]);
		Traverse((2*l)+1);
	}
}
int inordsuc(int c)
{
	while(bst[c] && bst[2*c] != -1)
	{
		c=2*c;
		if(c>n)
		{
			c=c/2;
			break;
		}
	}
	return c;
}
int keypos(int key,int i)
{
	while(bst[i]!=key && i<=n)
	{
	 	
    if(key<bst[i])
	{
		i=2*i;
	}
	else
	{
		i=(2*i)+1;
     }
    }
    return i;
}
void Deletion(int key,int i)
{
	int p=keypos(key,i);
	if(bst[p]==-1 || p>n)
	{
		printf("\nTree Empty/Out of Size OR Element Not Found");
	}
	else
	{
		while(bst[p] != -1 && p <= n)
		{
		if(bst[2*p]==-1)
		{
			bst[p]=((2*p)+1<=n)?bst[(2*p)+1]:-1;
			p=(2*p)+1;	
		}
		else if(bst[(2*p)+1]==-1)
		{
			bst[p]=(2*p<=n)?bst[2*p]:-1;
			p=2*p;
		}
		else
		{
			int c=inordsuc((2*p)+1);
			bst[p]=(c<=n)?bst[c]:-1;
			p=c;
		 }
		}
		printf("\nElement Deleted = %d",key);
	}
}
void Search(int key,int i)
{
	int k = keypos(key,i);
	if(bst[k]==-1 || k>n)
	{
		printf("\nElement Not found");
	}
	else
	{
		printf("\nElement found" );
	}
}
			

	
		
	
	
