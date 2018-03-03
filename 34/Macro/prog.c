#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *f1,*f2,*f3,*f4;
	int count=1;
	char ad[20],la[20],m1[20],op1[20],op2[20],otp[20],mname[10],sa[10],arg[10];
	f1=fopen("code.txt","r");
	f2=fopen("DEFTAB1.txt","w");
	f3=fopen("NAMTAB1.txt","w");
	while(!feof(f1))//NAMTAB AND DEFTAB Creation
	{
		//printf("Start");
		fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
		//printf("%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
		if((strcmp(m1,"MACRO")==0))
		{
			strcpy(mname,la);
			strcpy(sa,ad);
			
			while(strcmp(m1,"MEND")!=0)
			{
				if(strcmp(op1,"&A")==0)
					strcpy(op1,"X?1");
				else if(strcmp(op1,"&B")==0)
					strcpy(op1,"X?2");
				if(strcmp(op2,"&A")==0)
					strcpy(op2,"X?1");
				else if(strcmp(op2,"&B")==0)
					strcpy(op2,"X?2");
				printf("%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
				fprintf(f2,"%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
				fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
			}
			fprintf(f2,"%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
			fprintf(f3,"%s\t%s\t%s",mname,sa,ad);
		}
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	//ARGTAB Creation
	f1=fopen("code.txt","r");
	f2=fopen("ARGTAB1.txt","w");
	while(!feof(f1))
	{	
		fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
		if((strcmp(m1,"M1")==0))
		{
			fprintf(f2,"%d\t%s\n",count++,op1);
			fprintf(f2,"%d\t%s\n",count++,op2);
		}
	}
	fclose(f1);
	fclose(f2);
	//Expansion
	f1=fopen("code.txt","r");
	f2=fopen("ARGTAB1.txt","r");
	f3=fopen("EXPAND.txt","w");
	f4=fopen("DEFTAB1.txt","r");
	fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
	while(!feof(f1))
	{	
		
		if((strcmp(m1,"MACRO")==0))
		{
			while((strcmp(m1,"MEND")!=0))
				fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
			fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);		
		}
		if(strcmp(m1,"M1")==0)//Macro Expansion
		{
			while((strcmp(m1,"MEND")!=0))
			{
				if(strcmp(op1,"X?1")==0)
					strcpy(op1,"A1");
				else if(strcmp(op1,"X?2")==0)
					strcpy(op1,"A1");
				if(strcmp(op2,"X?1")==0)
					strcpy(op2,"B1");
				else if(strcmp(op2,"X?2")==0)
					strcpy(op2,"B1");
				fprintf(f3,"%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
				fscanf(f4,"%s%s%s%s%s",ad,la,m1,op1,op2);	
			}
		}
		//printf("%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
		fprintf(f3,"%s\t%s\t%s\t%s\t%s\n",ad,la,m1,op1,op2);
		fscanf(f1,"%s%s%s%s%s",ad,la,m1,op1,op2);
		
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);


}

