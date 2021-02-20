#include<stdio.h>
int rank[11];
int parent[11];
void createDisjointSet(int);
void Union(int,int);
int find(int);
int main()
{
	createDisjointSet(10);
	Union(1,3);
	Union(3,7);
	Union(2,4);
	Union(1,4);
	
	(find(1)==find(7))?printf("\n\nElements are in the same set"):printf("\n\nNot in the same set");
	(find(1)==find(2))?printf("\n\nElements are in the same set"):printf("\n\nNot in the same set");
	(find(7)==find(4))?printf("\n\nElements are in the same set"):printf("\n\nNot in the same set");
	
	return 0;
}
void createDisjointSet(int k)
{
	for(int i=1;i<=k;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}
int find(int x)
{
	if(parent[x]!=x)
	{
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
	
void Union(int a,int b)
{
	int d = find(a);
	int c = find(b);
	if(d==c && c!=-1)
	{
		return;
	}
	if(rank[a]>rank[b])
	{
		parent[b]=a;
		
	}
	else if(rank[b]>rank[a])
	{
		parent[a]=b;
	
	}
	else
	{
		parent[b]=a;
		rank[a]+=rank[a]+1;
	}				
}
