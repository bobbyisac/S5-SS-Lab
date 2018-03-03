#include<stdio.h>

int n,i,j,t,k,ts,flag,rem;
float atat,awt;

struct pr
{
    int bt,at,wt,tat,pp,rt;
};

int gantt(struct pr p[n])
{
    printf("\n");
    for(i=0;i<t+2;i++)
    {
        printf("_");
    }
    printf("\n|");
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].bt-2;j++)
        {
            printf(" ");
        }
        printf("P%d|",i);
    }
    printf("\n");
    for(i=0;i<t+2;i++)
    {
        printf("_");
    }
    printf("\n0");
    k=p[0].at;
    for(i=0;i<n;i++)
    {
        if(p[i].at>k)
        {
            k=p[i].at;
        }
        for(j=0;j<p[i].bt;j++)
        {
            printf(" ");
        }
        k=k+p[i].bt;
        printf("%d",k);
    }
    return 0;
}

int print(struct pr p[n])
{
    printf("\nAT\tBT\tPP\tWT\tTAT");
    for(i=0;i<n;i++)
    {
        printf("\n%d",p[i].at);
        printf("\t%d",p[i].bt);
        printf("\t%d",p[i].pp);
        printf("\t%d",p[i].wt);
        printf("\t%d",p[i].tat);
    }
    printf("\nAverage Wait Time (AWT) = %f",awt);
    printf("\nAverage Turnaround Time (ATAT) = %f",atat);
    gantt(p);
    return 0;
}

int calcfcfs(struct pr p[n])
{
    t=p[0].at;
    atat=0;
    awt=0;
    for(i=0;i<n;i++)
    {
        if(p[i].at>t)
        {
            t=p[i].at;
        }
        p[i].wt=t-p[i].at;
        t=t+p[i].bt;
        p[i].tat=t-p[i].at;
        atat=atat+p[i].tat;
        awt=awt+p[i].wt;
    }
    atat=atat/n;
    awt=awt/n;
    return 0;
}

int sortfcfs(struct pr p[n])
{
    struct pr temp;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    calcfcfs(p);
    print(p);
    return 0;
}

int calcsjf(struct pr p[n])
{
    t=0;
    atat=0;
    awt=0;
    for(i=0;i<n;i++)
    {
        p[i].wt=t;
        t=t+p[i].bt;
        p[i].tat=t;
        atat=atat+p[i].tat;
        awt=awt+p[i].wt;
    }
    atat=atat/n;
    awt=awt/n;
    return 0;
}

int sortsjf(struct pr p[n])
{
    struct pr temp;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i-1;j++)
        {
            if(p[j].bt>p[j+1].bt)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    calcsjf(p);
    print(p);
    return 0;
}
int calcps(struct pr p[n])
{
    t=0;
    atat=0;
    awt=0;
    for(i=0;i<n;i++)
    {
        p[i].wt=t;
        t=t+p[i].bt;
        p[i].tat=t;
        atat=atat+p[i].tat;
        awt=awt+p[i].wt;
    }
    atat=atat/n;
    awt=awt/n;
    return 0;
}

int sortps(struct pr p[n])
{
    struct pr temp;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i-1;j++)
        {
            if(p[j].pp<p[j+1].pp)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    calcps(p);
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
        printf("\nEnter Arrival Time for process %d: ",i);
        scanf("%d",&p[i].at);
        printf("\nEnter Burst Time for process %d: ",i);
        scanf("%d",&p[i].bt);
        printf("\nEnter Priority for process %d: ",i);
        scanf("%d",&p[i].pp);
    }
    printf("\n----FCFS----");
    sortfcfs(p);
    printf("\n----SJF----");
    sortsjf(p);
    printf("\n----PRIORITY----");
    sortps(p);
    return 0;
}

int main()
{
    getdata();
    return 0;
}
