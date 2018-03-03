#include<stdio.h>

int n,i,j,t,k,ts,flag,rem;
float atat,awt;

struct pr
{
    int bt,at,wt,tat,pp,rt;
};

int print(struct pr p[n])
{
    printf("\nBTtWT\tTAT");
    for(i=0;i<n;i++)
    {
        printf("\n%d",p[i].bt);
        printf("\t%d",p[i].wt);
        printf("\t%d",p[i].tat);
    }
    printf("\nAverage Wait Time (AWT) = %f",awt);
    printf("\nAverage Turnaround Time (ATAT) = %f",atat);
    return 0;
}

int rr(struct pr p[n])
{
    atat=0;
    awt=0;
    ts=2;
    flag=0;
    for (i=0;i<n;i++)
	{
		p[i].rt=p[i].bt;
	}
    rem=n;
    for(t=0,i=0;rem!=0;)
    {
        if(p[i].rt<=ts && p[i].rt>0)
        {
            t=t+p[i].rt;
            p[i].rt=0;
            flag=1;
        }
        else if(p[i].rt>0)
        {
            p[i].rt=p[i].rt-ts;
            t=t+ts;
        }
        if(p[i].rt==0 && flag==1)
        {
            rem--;
            p[i].tat=t;
            p[i].wt=t-p[i].bt;
            awt=awt+p[i].wt;
            atat=atat+p[i].tat;
            flag=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }
    awt=awt/n;
    atat=atat/n;
    print(p);
    return 0;
}

int getdata()
{
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct pr p[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time for process %d: ",i);
        scanf("%d",&p[i].bt);
    }
    printf("\n----ROUND ROBIN----");
    rr(p);
    return 0;
}

int main()
{
    getdata();
    return 0;
}
