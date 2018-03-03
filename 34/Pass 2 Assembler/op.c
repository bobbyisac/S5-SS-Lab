#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    FILE *f1,*f2;
    char m1[20],la[20],op[20];
    f1=fopen("source.txt","r");
    f2=fopen("optab.txt","w");
    fscanf(f1,"%s%s%s",la,m1,op);
    while(!feof(f1))
    {
	fscanf(f1,"%s%s%s",la,m1,op);
	if( (strcmp(m1,"RESW")!=0) && (strcmp(m1,"BYTE")!=0) && (strcmp(m1,"RESB")!=0) && (strcmp(m1,"WORD")!=0) &&  (strcmp(m1,"END")!=0) && (strcmp(m1,"START")!=0) )
	{
		fprintf(f2,"%s\n",m1);
	}
	
    }
    fclose(f1);
    fclose(f2);
}
