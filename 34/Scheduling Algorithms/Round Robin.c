#include<stdio.h>

struct p
{
	int bt,at,tat,wt,rt,b;
};

float awt,atat;
int n,i,j,t,flag,slice,tbt;

void print(struct p pr[])
{
	printf("\nBT\tWT\tTAT");
	for(i=0;i<n;i++)
	{
		//printf("\n%d",pr[i].at);
		printf("\n%d",pr[i].bt);
		//printf("\t%d",pr[i].pp);
		printf("\t%d",pr[i].wt);
		printf("\t%d",pr[i].tat);	
	}
	printf("\nAverage waiting time = %f",awt);
	printf("\nAverage turn around time = %f",atat);
}

void gantt(struct p pr[])
{
	printf("\n");
	for(i=0;i<tbt;i++)
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
	for(i=0;i<tbt;i++)
	{
		printf("_");	
	}
	printf("\n0");	
}

void rr(struct p pr[])
{
 tbt=0;
 for(i=0;i<n;i++)
 {
  tbt=tbt+pr[i].bt;
  pr[i].b=pr[i].bt;
  pr[i].wt=0;
 }
 t=0;
 i=0;
 //flag=1;
 slice=3;
 while(tbt>0)
 {
  flag=0;
  if(pr[i].b>0)
  {
   flag=1;
   if(pr[i].wt==0)
   {
    pr[i].wt=t;
   }
   if(pr[i].b>=slice)
   {
    pr[i].b=pr[i].b-slice;
    t=t+slice;
    tbt=tbt-slice;
   }
   else
   {
    t=t+pr[i].b;
    tbt=tbt-pr[i].b;
    pr[i].b=0;
   }
  
   pr[i].tat=t;
   printf("\n%d\t%d",pr[i].wt,pr[i].tat);
   awt=awt+pr[i].at;
   atat=atat+pr[i].tat;
  }
  if(i==(n-1))
  {
   i=0;
  }
  else
  {
   i++;
  }
  //if(flag==1)
  //{
   //awt=awt+pr[i].at;
   //atat=atat+pr[i].tat;
  //}
 }
 awt=awt/n;
 atat=atat/n;
 print(pr);
 //gantt(pr);
}

void getdata()
{
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct p pr[n];

	for(i=0;i<n;i++)
	{
		//printf("\nEnter Arrival Time for process %d: ",i+1);
		//scanf("%d",&pr[i].at);
		printf("\nEnter Burst Time for process %d: ",i+1);
		scanf("%d",&pr[i].bt);
		//printf("\nEnter Process Priority for process %d: ",i+1);
		//scanf("%d",&pr[i].pp);
	}
	//printf("\n--------------FCFS--------------");	
	//sortfcfs(pr);
	//printf("\n--------------SJF--------------");
	//sortsjf(pr);
	//printf("\n--------------PS--------------");
	//sortps(pr);
	rr(pr);
}

int main()
{
	
	getdata();

	printf("\n");
	return 0;

}
