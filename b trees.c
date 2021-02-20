#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define order 3

struct bnode
{
	int bvalarray[order];
	struct bnode *badd[order+1];
	int count;
	struct bnode *parent;
}*root=NULL;

void deletion(struct bnode*,int);
void insertion(struct bnode*,int);
struct bnode* find_leaf_node(struct bnode*,int);
struct bnode* crt_node(struct bnode*,struct bnode*);
void traversal(struct bnode*);
void sort(struct bnode*,int);
void splitchild(struct bnode*,int);
void deletion_leaf_node(struct bnode*,int,int);
void search(struct bnode*);
struct bnode* find_node(struct bnode*,int);

int main()
{
	int m=0,key=0;
	while(1)
	{
	printf("\n\n\t\t\t Menu\n\n1->Inserion\t2->Traversal\t3->Deletion\t4->search\t5->Exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
	  case 1:if(root == NULL)
	         {
				root= crt_node(root,NULL);
			 }
	         printf("\nEnter the value to insert = ");
			 scanf("%d",&key);
			 struct bnode *lf=find_leaf_node(root,key);
			 insertion(lf,key);
	         break;
	  case 2:traversal(root);
	         break;
	  case 3:printf("\nEnter the key to delete =");
	         scanf("%d",&key);
	         struct bnode *p=find_node(root,key);
	         deletion(p,key);
	         break;
	  case 4:printf("\nEnter the key to search = ");
	         scanf("%d",&key);
	         search(find_node(root,key));
	         break;
	  case 5:return 0;
	         break;
	  default:printf("Invalid Choice");}}
}

struct bnode* find_node(struct bnode *ff,int key)
{
	struct bnode *remp=NULL;
	if(ff != NULL)
	{for(int i=0;i<order-1;i++)
		{if(ff->bvalarray[i] != 0)
			{if(key<ff->bvalarray[i])
			    {remp=ff->badd[i];
					break;}
				else if(key == ff->bvalarray[i])
				{return ff;}
			    else
			    {remp=ff->badd[i+1];}}}
	 return find_node(remp,key);}
   return ff;			
}

void deletion(struct bnode *del,int key)
{
	if(del==NULL)
	{printf("\nElement not found");}
	else
	{if(del->badd[0] == NULL){
		int j;
		for(j=0;j<del->count;j++){
			if(key == del->bvalarray[j]){
			deletion_leaf_node(del,key,j);}}}
	else{
		printf("Not a Leaf Node");}}
}

void deletion_leaf_node(struct bnode* del,int key,int j)
{
	int v = (order-1)/2;
	if(del->count > v){
		del->bvalarray[j] = 0;}	
	else if(del->count == v){
		int k;
		for(int i=0;i<=del->parent->count;i++)
		{if(del == del->parent->badd[i])
			{ k=i;
			  break;}
		}
		if(del->parent->badd[k-1] != NULL && del->parent->badd[k-1]->count > v)
		{   del->bvalarray[j]=del->parent->bvalarray[k-1];
			sort(del,j);
			   for(int i=del->parent->badd[k-1]->count-1;i>=0;i++)
			   {if(del->parent->badd[k-1]->bvalarray[i] != 0)
				{ del->parent->bvalarray[k-1]=del->parent->badd[k-1]->bvalarray[i];
			      del->parent->badd[k-1]->bvalarray[i] = 0;
			      del->parent->badd[k-1]->count-=1;
			      break;}}
		}
		else if(del->parent->badd[k+1] != NULL && del->parent->badd[k+1]->count > v)
		{   del->bvalarray[j]=del->parent->bvalarray[k];
			sort(del,j);
			for(int i=0;i<del->parent->badd[k+1]->count;i++)
			{     if(del->parent->badd[k+1]->bvalarray[i] != 0){ 
			       del->parent->bvalarray[k]=del->parent->badd[k+1]->bvalarray[i];
			       del->parent->badd[k+1]->bvalarray[i]=0;
			       del->parent->badd[k+1]->count-=1;
			      break;}}
	     }
	   else
	   {
		   printf("Nodes contain only minimum keys");}
	}
}
	
struct bnode* crt_node(struct bnode *new,struct bnode *par)
{
	 int i;
	 new = (struct bnode*)malloc(sizeof(struct bnode));
	 for(i=0;i<order;i++)
	 {    new->bvalarray[i] = 0;
		  new->badd[i]=NULL;
	 }
	 new->badd[i]=NULL;
	 new->count=0;
	 new->parent=NULL;
	 new->badd[-1]=NULL;
	 return new;
}

void insertion(struct bnode *lf,int key)
{
		if(lf->count<order-1)
		{    for(int i=0;i<order-1;i++)
			{if(lf->bvalarray[i] == 0){
			 lf->bvalarray[i]=key;
			 lf->count+=1;
			 break;}}}
		else
		{   lf->bvalarray[lf->count]=key;
			sort(lf,lf->count);
			splitchild(lf,lf->count+1);	}
}

void splitchild(struct bnode *lf,int h)
{
   if(h==order)
   {   struct bnode *pare=NULL,*newnode=NULL;
	   int med = h/2;
	  newnode = crt_node(newnode,NULL);
	   if(lf->parent==NULL)
	   { pare = crt_node(pare,NULL);
		 lf->parent=pare;
		  root = pare;}
		newnode->parent=lf->parent;
	   lf->parent->bvalarray[lf->parent->count]=lf->bvalarray[med];
	   sort(lf->parent,lf->parent->count);
	   lf->parent->count+=1;
	   for(int i=0;i<lf->parent->count;i++)
	   {  if(lf->parent->bvalarray[i] == lf->bvalarray[med])
		   {lf->parent->badd[i]=lf;
			 lf->parent->badd[i+1]=newnode;}
	   }
	   for(int j=med+1;j<order;j++)
	   {   newnode->bvalarray[newnode->count]=lf->bvalarray[j];
		   newnode->badd[newnode->count]=lf->badd[j];
		   newnode->count+=1;
		   newnode->badd[newnode->count]=lf->badd[j+1];} 
	   for(int i=med;i<order;i++)
	   {  lf->bvalarray[i]=0;
		   lf->badd[i+1]=NULL;
		   lf->count=med;}
	splitchild(lf->parent,lf->parent->count); 
   } 		
}

struct bnode* find_leaf_node(struct bnode *fnode,int key)
{
	struct bnode *temp = NULL;
	int i;
	if(fnode->badd[0] != NULL)
	{ for(i=0;i<order-1;i++)
	    {if(fnode->bvalarray[i] != 0)
			{if(key<fnode->bvalarray[i])
			    {temp=fnode->badd[i];
					break;}
	            else
				{temp=fnode->badd[i+1];}
			}}
        return find_leaf_node(temp,key);}
    return fnode;
}

void search(struct bnode* kk)
{
	if(kk == NULL){
		printf("\nElement not found");}
	else{
		 printf("\nElement found");}
}

void sort(struct bnode *lf,int i)
{
	  for(int j=0;j<i;j++)
	  {if(lf->bvalarray[i] < lf->bvalarray[j])
		  { lf->badd[i+1]=lf->badd[j+1];
			 int temp = lf->bvalarray[j];
			 lf->bvalarray[j] = lf->bvalarray[i];
			 lf->bvalarray[i] = temp;} }
}

void traversal(struct bnode *kop)
{
	if(kop!=NULL)
	{   
		for(int i=0;i<=kop->count;i++)
	    {traversal(kop->badd[i]);
			if(kop->bvalarray[i] != 0){
				printf("\n%d",kop->bvalarray[i]);}}}				
}
