#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int addr;
char label[10];
struct node *next;
};



void addatend(struct node **startptrptr,struct node **endptrptr,int addr,char label[10])//Add at end
{
	struct node *nnodeptr=(struct node *) malloc(sizeof(struct node *));
	nnodeptr->addr=addr;
	strcpy(nnodeptr->label,label);
	nnodeptr->next=NULL;
	if ((*startptrptr)==NULL)
	{
	(*startptrptr)=(*endptrptr)=nnodeptr;
	}
	else
	{
	(*endptrptr)->next=nnodeptr;
	(*endptrptr)=nnodeptr;
	}
}

/*
void delend(struct node **startptrptr)//Deletion from the end
{
    struct node *prev,*rider;
    rider=*startptrptr;
    if ((*startptrptr)==NULL)
        printf("Empty!\n");
    else if((*startptrptr)->next==NULL)
        *startptrptr=NULL;
    else
        {
            while(rider->next!=NULL)// To find 2nd last node
                {
                    prev=rider;
                    rider=rider->next;
                }
            prev->next=NULL;
        }
}
*/
void display(struct node *rider,int key)//Display the List
{
	printf("%d |",key);
	while(rider!=NULL)
	{
	printf("%d - %s -> ",rider->addr,rider->label);
	rider=rider->next;
	}
	printf("\n");
}


void main()
{

	int ch,addr,key,hash,i;
	char label[10];
	printf("Enter the required hash value=");
	scanf("%d",&hash);
	struct node *start[hash],*end[hash];
	for (i = 0; i < hash; i++)
	{
		start[i]=NULL;
		end[i]=NULL;
	}

    for(;;)
    {
        printf("\n1.Insert SYMTAB(ONCE)\n2.Display Hash Table\nEnter choice:");
        scanf("%d",&ch);
        if (ch==1)
        {

		FILE *f1,*f2;
		f1=fopen("symtab.txt","r");
		while(!feof(f1))
		{
		fscanf(f1,"%d %s",&addr,label);
		key=addr%hash;
		addatend(&start[key],&end[key],addr,label);

		}
	}
	else if (ch==2)
	{
		for(i=0;i<hash;i++)
		{
		display(start[i],i);
		}
        }
        else
            exit(0);
    }


}
