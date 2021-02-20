#include<stdio.h>
char Bs2[9]="";
char Bs1[9]="";
char UN[9]="",IN[9]="",DI[9]="";
void bitStringCreation(int[],int[],int[],int,int,int);
void Union(int);
void Intersection(int);
void Difference(int);
int main()
{
   int m,i=0,si=0,sj=0;
   int U[]={1,2,3,4,5,8,9,10}; 
   int S1[]={5,10,8,9,2};
   int S2[]={1,2,5};
   i=sizeof(U)/4; 
   si=sizeof(S1)/4;
   sj=sizeof(S2)/4;  
   bitStringCreation(U,S1,S2,i,si,sj);
   while(1)
	{
	printf("\n\n\t\t\t Menu\n\n1->Union\t2->Intersection\t\t3->Difference\t\t4->Exit");
	printf("\n\n\tEnter the choice = ");
	scanf("%d",&m);
	switch(m)
	{
	  case 1:Union(i);
	         break;
	  case 2:Intersection(i);
	         break;
	  case 3:Difference(i);
	         break;
	  case 4:return 0;
	         break;	
	}
   }
 }
 void bitStringCreation(int U[],int S1[],int S2[],int k,int si,int sj)
 {
	 int ii=0,i=0,j=0;
	 for(i=0;i<k;i++)
	 {
		 for(int j=0;j<si;j++)
		  { 
			 if(U[i]==S1[j])
			 {
				   ii=1;
				   break;
			 }
			 else
			 {
				ii=0;
			 }
		  }
		Bs1[i]=(ii==1)?'1':'0';
	 }
	  Bs1[i]='\0';
	  ii=0;
	 for(j=0;j<k;j++)
	 {
		 for(int i=0;i<sj;i++)
		 {
			if(U[j]==S2[i])
			{
				ii=1;
			    break;
			}
			else
			{
				ii=0;
			}
		}
		Bs2[j]=(ii==1)?'1':'0'; 
	  }	
	  Bs2[j]='\0'; 
     printf("Bit String of Set1= %s",Bs1);
     printf("\n\nBit String of Set2= %s",Bs2);  
 } 
 
void Union(int k)
{
	int i;
	for(i=0;i<k;i++)
	{
	 UN[i]=((Bs1[i]-'0')|(Bs2[i]-'0'))+'0';
    }
     UN[i]='\0';
	printf("\nUNION Bit String = %s",UN);

}
void Intersection(int k)
{
	int i;
	for(i=0;i<k;i++)
	{
	 IN[i]=((Bs1[i]-'0')&(Bs2[i]-'0'))+'0';
    }
     IN[i]='\0';
	printf("\nINTERSECTION Bit String = %s",IN);
}
void Difference(int k)
{
	int ch,j;
	char Comp[9]="";
	printf("\n\t1)Set1-Set2\t\t2)Set2-Set1\n\n\tEnter the Choice =");
	scanf("%d",&ch);
	if(ch==2)
	{
		for(int i=0;i<k;i++)
		{
			Comp[i]=(Bs1[i]=='1')?'0':'1';
		}
	for(j=0;j<k;j++)
	{
	 DI[j]=((Bs2[j]-'0')&(Comp[j]-'0'))+'0';
    }
     DI[j]='\0';
	}
	else
	{
	for(int i=0;i<k;i++)
		{
			Comp[i]=(Bs2[i]=='1')?'0':'1';
		}
		
	for(j=0;j<k;j++)
	{
	 DI[j]=((Bs1[j]-'0')&(Comp[j]-'0'))+'0';
    }
     DI[j]='\0';
   }
   	printf("\nDIFFERENCE BIT STRING= %s",DI);
}
		
