#include<stdio.h>

int i,j,k,iflag=1;
int alloc[5][3]={0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};
int max[5][3]={7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
int need[5][3];
int avl[3],maxres[3]={10,5,7};
int count[3]={0,0,0};
int flag[5]={1,1,1,1,1};

int print()
{
	printf("\nPID\tALLOC\tMAX\tNEED\tAVL");
	printf("\n--------------------------------------");
	printf("\n\tA B C\tA B C\tA B C\tA B C");
	printf("\n--------------------------------------");
	for(i=0;i<5;i++)
	{
		printf("\nP%d\t",i);
		for(j=0;j<3;j++)
		{
			printf("%d ",alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<3;j++)
		{
			printf("%d ",max[i][j]);
		}
		printf("\t");
		for(j=0;j<3;j++)
		{
			printf("%d ",need[i][j]);
		}
	}
	printf("\t");	
	for(j=0;j<3;j++)
	{
		printf("%d ",avl[j]);
	}
	printf("\n");
	return 0;
}

int calcneed()
{	
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	return 0;
}

int calcavl()
{
	for(j=0;j<3;j++)
	{
		for(i=0;i<5;i++)
		{
			count[j]=count[j]+alloc[i][j];
		}
	}
	for(j=0;j<3;j++)
	{
		avl[j]=maxres[j]-count[j];
	}
	return 0;
}

int safe()
{
	printf("\nSAFE SEQUENCE\n-------------\n");
	for(i=0;iflag==1;i++)
	{
		iflag=0;
		for(j=0;j<3;j++)
		{
			if(need[i][j]>avl[j])
			{
				flag[i]=1;
				break;
			}
			else
				flag[i]=0;
		}
		if(flag[i]==0)
		{
			for(j=0;j<3;j++)
			{
				avl[j]=avl[j]+alloc[i][j];
			}
			printf("P%d ",i);
		}
		if(i==4)
		{
			i=-1;
		}
		for(k=0;k<5;k++)
		{
			if(flag[k]==1)
			{				
				iflag=1;
				break;
			}
			
		}
		
	}
	printf("\n");
	return 0;
}

int main()
{
	calcneed();
	calcavl();
	print();
	safe();
	return 0;	
}
