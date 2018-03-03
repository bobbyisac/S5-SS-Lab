#include<stdio.h>
#define BUFFERSIZE 5

int mutex=1, empty=BUFFERSIZE, full=0, x=0, ch=0;

int signal(int s)
{
	return(++s);
}

int wait(int s)
{
	return(--s);
}

int isfull()
{
	if(full==BUFFERSIZE)
		return 1;		
	else
		return 0;
}

int isempty()
{
	if(empty==BUFFERSIZE)
		return 1;
	else
		return 0;
}

int producer()
{
	if(isfull())
	{
		printf("Buffer is FULL!!!");
	}
	else
	{
		mutex=wait(mutex);
		full=signal(full);
		empty=wait(empty);
		x++;
		printf("\nItem produced : %d",x);
		mutex=signal(mutex);
	}
	return 0;
}

int consumer()
{
	if(isempty())
	{
		printf("Buffer is EMPTY!!!");
	}
	else
	{
		mutex=wait(mutex);
		empty=signal(empty);
		full=wait(full);
		printf("\nItem consumed : %d",x);
		x--;
		mutex=signal(mutex);
	}
	return 0;
}

int main()
{	
	while(ch!=3)
	{
		printf("\n\nMENU\n----\n1.Produce\n2.Consume\n3.Exit");
		printf("\nEnter Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				producer();
				break;
			case 2:
				consumer();
				break;
			default:
				ch=3;
		}
	}
	return 0;
}
