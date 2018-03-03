#include<stdio.h>
#include<stdlib.h>

int ar[6]={14,35,67,115,98,127}, head, c, i, st, l=0, u=199, j, temp;

int fcfs()
{
	st=0;
	for(i=0;i<6;i++)
	{	
		st=st+abs(head-ar[i]);
		head=ar[i];
	}
	printf("\nAverage Seek Time=%d\n",st/6);
	return 0;
}

int scan()
{
	st=0;
	for(i=0;i<6;i++)
	{	
		for(j=0;j<(5-i);j++)
		{	
			if(ar[j]>ar[j+1])
			{	
				temp=ar[j+1];
				ar[j+1]=ar[j];
				ar[j]=temp;
			}
		}
	}
	for(i=0;i<6;i++)
	{	
		if(head<ar[i])
			break;
	}
	int k=i-1;
	while(i<6)
	{	
		st=st+abs(head-ar[i]);
		head=ar[i];
		i++;
	}
	st=st+abs(head-u);
	head=u;
	while(k>=0)
	{	
		st=st+abs(head-ar[k]);
		head=ar[k];
		k--;
	}
	st=st+abs(head-l);
	head=l;
	printf("\nAverage Seek Time=%d\n",st/6);	
	return 0;
}

int cscan()
{
	st=0;
	for(i=0;i<6;i++)
	{	
		for(j=0;j<(5-i);j++)
		{	
			if(ar[j]>ar[j+1])
			{	
				temp=ar[j+1];
				ar[j+1]=ar[j];
				ar[j]=temp;
			}
		}
	}
	for(i=0;i<6;i++)
	{	
		if(head<ar[i])
			break;
	}
	int k=i-1;
	while(i<6)
	{	
		st=st+abs(head-ar[i]);
		head=ar[i];
		i++;
	}
	st=st+abs(head-u)+(u-l);
	head=l;
	for(i=0;i<=k;i++)
	{	
		st=st+abs(head-ar[k]);
		head=ar[k];
	}
	printf("\nAverage Seek Time=%d\n",st/6);
	return 0;
}
		
int main()
{	
	printf("\nEnter the Head position : ");
	scanf("%d",&head);
	printf("\n-----MAIN MENU-----\n1.FCFS\n2.SCAN\n3.C-SCAN\nEnter your choice : ");
	scanf("%d",&c);
	if(c==1)
		fcfs();
	else if(c==2)
		scan();
	else if(c==3)
		cscan();
	return 0;	
}
