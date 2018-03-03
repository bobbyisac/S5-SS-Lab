#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
	FILE *f1,*f2,*f3;
	char rec[100],lens[3],sas[7],vals[7];
	int i,j,k,sa,len;
	f1=fopen("obj.txt","r");
	f2=fopen("output.txt","w");
	fscanf(f1,"%s",rec);
	while(!feof(f1))
	{
		printf("%s\n",rec);
		if(rec[0]=='T')
		{
			lens[0]=rec[9];
			lens[1]=rec[10];
			len=atoi(lens);//Lenght of record
			len=len/3;
			for(i=2,j=0;i<=7;i++,j++)			
				sas[j]=rec[i];
			sa=atoi(sas);//Starting Address of record
			i=0;
			j=12;
			while(i<len)
			{
				for(k=0;k<6;k++,j++)
					vals[k]=rec[j];
				fprintf(f2,"%d\t%s\n",sa+(i*3),vals);
				j++;
				i++;
			}
			
		}
		fscanf(f1,"%s",rec);
	}
	fclose(f1);
	fclose(f2);
}

