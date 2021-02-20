#include<stdio.h>
#include<stdlib.h>
#define size 10 
int queue[size];
int FRONT = -1;
int REAR = -1;
int b=0;
void Insertion();
void Deletion();
void search(int,int,int);
void display(int,int);
int main()
{
	int m;
	int item;
	while(1)
	{
	printf("\n\n\t\t\tQueue Menu\n\n1->Insertion\t2->Deletion\t3->Display\t4->search\t5->exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
		case 1:Insertion();
		       break;
		case 2:Deletion();
		       break;
		 case 3:display(REAR,FRONT);
		       break;
		case 4: printf("\nEnter the element to search = ");
               scanf("%d",&item);
               b=0;
               search(REAR,FRONT,item);
		       break;
		case 5:return 0;
		      break;
		 default:printf("Invalid Choice");
	} }}
	    
void Insertion()
{
	int value=0;
	printf("\n\tEnter the value = ");
    scanf("%d",&value);
	if((REAR == size-1 && FRONT == 0) ||(REAR == FRONT-1))
	{
		printf("\n!Queue overflow!");
	}
	else
    { 
	 if(REAR== size-1 && FRONT != 0 )
	 {
	 REAR = 0;
	 queue[REAR]=value;
     }
	else if(FRONT == -1)
	{
	 REAR=FRONT=0;
	 queue[REAR]=value;
	}
	else
	{
    REAR = REAR + 1;
    queue[REAR]=value;
    }
	printf("\n!Element inserted");
   }}
   
void Deletion()
{
	if(FRONT == -1)
	{
		printf("\n!Queue underflow!");
	}
	else
	{
		if(FRONT == size)
	    {
		 FRONT = 0;
	     }
	     printf("\nElement Deleted = %d",queue[FRONT]);
	     FRONT = FRONT +1;
	     if(FRONT == REAR)
	     {
	      FRONT = REAR =-1;
 }}}
 
void display(int s,int h)
{
  if(FRONT == -1)
	{
		printf("\n!Queue underflow!");
    }
    else
   { 
     if(s>h)
	 { 
	 for(int i = h; i<=s ; i++)
	 {
			printf("\n%d",queue[i]);
	}
    }
    else
    {
		display(REAR,0);
		display(size-1,FRONT);
	}
   }
}
	
void search(int x,int y,int ite)
{
  if(x>y)
  {
  for(int i = y; i<=x ; i++)
  {
   if(ite == queue[i] && y!=-1 && x!=-1)
  {
	printf("\nitem found at position = %d",i+1);
    b++;
   }
   }
	if(b==0)
	{
	    printf("\nElement not Found");
     }
    }
    else
    { 
     search(REAR,0,ite);
     search(size-1,FRONT,ite);
     }
 }
  	
