#include<stdio.h>
#include<stdlib.h>
#define size 10
int stack[size];
int TOS = -1;
void PUSH();
void POP();
void Display();
void search();
int main()
{
	int m;
	while(1)
	{
	printf("\n\n\t\t\tStack Menu\n\n1->Insertion\t2->Deletion\t3->Search\t4->Display\t5->exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
		case 1:PUSH();
		       break;
		case 2:POP();
		       break;
		 case 3:search();
		       break;
		case 4:Display();
		      break;
		case 5:return 0;
		     break;
		 default:printf("Invalid Choice");
	}
   }
}
void PUSH()
{
	if(TOS == size-1)
	{
		printf("\n!Stack Overflow!");
	}
	else
	{
		TOS++;
		printf("\n\tEnter the value=");
		scanf("%d",&stack[TOS]);
		printf("\n!Inserted");
	}
}
void POP()
{
	if(TOS == -1)
	{
		printf("\n!Stack Underflow!");
	}
	else
	{
		printf("\nElement Deleted = %d",stack[TOS]);
		TOS--;
	}
}
void Display()
{
	if(TOS == -1)
	{
		printf("\n!Stack Underflow!");
	}
	else
	{
		for(int i=0;i<=TOS;i++)
		{
			printf("\n%d",stack[i]);
		}
	}
}
void search()
{
	if(TOS == -1)
	{
		printf("\n!Stack Underflow!");
	}
    else
    {
		int item;
		char t;
		printf("\nEnter the element to find = ");
		scanf("%d",&item);
		for(int i=0;i<=TOS;i++)
		{
			if(item == stack[i])
			{
				printf("\nElement found at position = %d",i+1);
				 t = 'n';
				 break ;
			}
		}
		(t!= 'n')? printf("\nElement not Found"):printf("\t");
	}
}
		
