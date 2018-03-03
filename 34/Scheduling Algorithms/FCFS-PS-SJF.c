#include<stdio.h>

struct p
{
	int bt,at,tat,wt,pp;
};

float awt,atat;
int n,i,j,t;

void calcfcfs(struct p pr[])
{
	t=pr[0].at;
	atat=0;
	awt=0;
	for(i=0;i<n;i++)
	{
		if(t<pr[i].at)
		{
			t=pr[i].at;
		}
		pr[i].wt=t-pr[i].at;
		t=t+pr[i].bt;
		pr[i].tat=pr[i].wt+pr[i].bt;
		//pr[i].tat=t-pr[i].at;
		atat=atat+pr[i].tat;
		awt=awt+pr[i].wt;
	}
	atat=atat/n;
	awt=awt/n;
}

void calcsjf(struct p pr[])
{
	t=0;
	atat=0;
	awt=0;
	for(i=0;i<n;i++)
	{
		pr[i].wt=t;
		t=t+pr[i].bt;
		pr[i].tat=pr[i].wt+pr[i].bt;
		atat=atat+pr[i].tat;
		awt=awt+pr[i].wt;
	}
	atat=atat/n;
	awt=awt/n;
}

void calcps(struct p pr[])
{
	t=0;
	atat=0;
	awt=0;
	for(i=0;i<n;i++)
	{
		pr[i].wt=t;
		t=t+pr[i].bt;
		pr[i].tat=pr[i].wt+pr[i].bt;
		atat=atat+pr[i].tat;
		awt=awt+pr[i].wt;
	}
	atat=atat/n;
	awt=awt/n;
}

void print(struct p pr[])
{
	printf("\nAT\tBT\tPP\tWT\tTAT");
	for(i=0;i<n;i++)
	{
		printf("\n%d",pr[i].at);
		printf("\t%d",pr[i].bt);
		printf("\t%d",pr[i].pp);
		printf("\t%d",pr[i].wt);
		printf("\t%d",pr[i].tat);	
	}
	printf("\nAverage waiting time = %f",awt);
	printf("\nAverage turn around time = %f",atat);
}

void gantt(struct p pr[])
{
	printf("\n");
	for(i=0;i<t+1;i++)
	{
		printf("_");	
	}
	printf("\n|");
	for(i=0;i<n;i++)
	{
		for(j=0;j<(pr[i].bt-2);j++)
		{
			printf(" ");
		}
	
		printf("%d|",i);
	}
	printf("\n");
	for(i=0;i<t+1;i++)
	{
		printf("_");	
	}
	printf("\n0");
	int count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(pr[i].bt-1);j++)
		{
			printf(" ");
		}
		count=count+j+1;
		printf("%d",count);
	}	
}

void sortfcfs(struct p pr[])
{
	struct p temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(pr[j].at>pr[j+1].at)
			{
				temp=pr[j+1];
				pr[j+1]=pr[j];
				pr[j]=temp;
			}
		}
	}
	calcfcfs(pr);
	print(pr);
	gantt(pr);
}

void sortsjf(struct p pr[])
{
	struct p temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(pr[j].bt>pr[j+1].bt)
			{
				temp=pr[j+1];
				pr[j+1]=pr[j];
				pr[j]=temp;
			}
		}
	}
	calcsjf(pr);
	print(pr);
	gantt(pr);
}

void sortps(struct p pr[])
{
	struct p temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(pr[j].pp<pr[j+1].pp)
			{
				temp=pr[j+1];
				pr[j+1]=pr[j];
				pr[j]=temp;
			}
		}
	}
	calcps(pr);
	print(pr);
	gantt(pr);
}


void getdata()
{
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct p pr[n];

	for(i=0;i<n;i++)
	{
		printf("\nEnter Arrival Time for process %d: ",i+1);
		scanf("%d",&pr[i].at);
		printf("\nEnter Burst Time for process %d: ",i+1);
		scanf("%d",&pr[i].bt);
		printf("\nEnter Process Priority for process %d: ",i+1);
		scanf("%d",&pr[i].pp);
	}
	printf("\n--------------FCFS--------------");	
	sortfcfs(pr);
	printf("\n--------------SJF--------------");
	sortsjf(pr);
	printf("\n--------------PS--------------");
	sortps(pr);
}

int main()
{
	
	getdata();

	printf("\n");
	return 0;

}
