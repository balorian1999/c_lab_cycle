#include<stdio.h>
#include<malloc.h>
void Insertion();
void Deletion();
void Traverse();
void search();
struct node
{
 int data;
 struct node *pre;
 struct node *suc;
}*stnode=NULL;
struct node *pulp=NULL;
int o=0;
int main()
{
	int m;
	while(1)
	{
	printf("\n\n\t\t\tDoubley Linked List Menu\n\n1->Insertion\t2->Deletion\t3->Traverse\t4->search\t5->exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
		case 1:Insertion();
		       break;
		 case 2:Deletion();
		       break;
		 case 3:Traverse();
		       break;
		 case 4:search();
		       break;
		 case 5:return 0;
		       break;
		 default:printf("Invalid Choice");
	} }}

void Insertion()
{
 struct node *fnode;
 if(stnode==NULL)
 {
  stnode=(struct node*)malloc(sizeof(struct node));
  printf("\n\tEnter the data=");
  scanf("%d",&stnode->data);
  stnode->pre=NULL;
  stnode->suc=NULL;
  pulp=stnode;
  o++;
 }
 else
 {
  fnode=(struct node*)malloc(sizeof(struct node));
  printf("\n\tEnter the data=");
  scanf("%d",&fnode->data);
  fnode->suc=NULL;
  fnode->pre=stnode;
  stnode->suc=fnode;
  stnode=fnode;
  o++;
 }
}
void Deletion()
{
 struct node *cur;
 int k;
 (o>2)?printf("\n1->delatbeg\t2->delatend\t3->delatpos"):printf("\n1->delatbeg\t2->delatend");
 printf("\n\tEnter choice for deletion\n");
 scanf("%d",&k);
 if(pulp == NULL || stnode == NULL)
 {
	 printf("\n!Element cannot be Deleted! List is empty!");
 }
 else
 {
	 if(k == 1)
	 {
		 printf("\nElement Deleted = %d",pulp->data);
		 if(o == 1)
		 {
		 pulp = NULL;
	     }
	     else
	     {
		 pulp = pulp->suc;
		 pulp->pre = NULL;
	     }
	     o--;
	 }
	 if(k==2)
	 {
		  printf("\nElement Deleted = %d",pulp->data);
		 if(o == 1)
		 {
		 stnode = NULL;
	     }
	     else
	     {
		 stnode = pulp->pre;
		 stnode->suc = NULL;
	     }
	     o--;
	 }
	 if(k==3 && o>2)
	 {
		 int pos;
		 cur = pulp;
		 printf("\nEnter the position = ");
		 scanf("%d",&pos);
		 for(int i=2;i<=pos;i++)
		 {
			 cur=cur->suc;
		 }
		 printf("\nElement Deleted = %d",cur->data);
		 cur->pre->suc = cur->suc;
		 cur->suc->pre = cur->pre;
		 o--;
	 }
}
}	
void Traverse()
{
	if(stnode == NULL)
	{
		printf("\n!List is empty");
	}
	else
	{	
	struct node *cur = pulp;
	while(cur!=NULL)
	{
		printf("\n%d",cur->data);
		cur=cur->suc;
	}
    }
} 		 
void search()
{
	if(stnode == NULL)
	{
		printf("\n!List is empty");
	}
	else
	{
		int item,k=1,pos=0;
	 printf("\nEnter the element to find = ");
	 scanf("%d",&item); 		
	struct node *cur = pulp;
	while(cur!=NULL)
	{
		if(item == cur->data)
		{
			printf("\nElement found at position = %d",k);
			pos=1;
		}
		k++;
		cur=cur->suc;
	}
	(pos!=1)?printf("\nElement not found"):printf("\t");
    }
} 			 
		 
	  
