#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	FILE *f1,*f2,*f3,*f4;
	int lc,sa,l,op1,o,len,opcode=10;
	char m1[20],la[20],op[20],otp[20],ad[20],addr[20],op2[20],z[20];
	// generating optab
	f1=fopen("source.txt","r");
	f2=fopen("optab.txt","w");
	fscanf(f1,"%s%s%s",la,m1,op);
	while(!feof(f1))
	{		
		if( (strcmp(m1,"RESW")!=0) && (strcmp(m1,"BYTE")!=0) && (strcmp(m1,"RESB")!=0) && (strcmp(m1,"WORD")!=0) &&  (strcmp(m1,"END")!=0) && (strcmp(m1,"START")!=0) )
		{
			fprintf(f2,"%s\t%d\n",m1,(opcode++));
		}
		fscanf(f1,"%s%s%s",la,m1,op);
	
    	}
    	fclose(f1);
    	fclose(f2);
    	// generating symtab
    	f1=fopen("source.txt","r");
    	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","w");
	f4=fopen("inter.txt","w");
	fscanf(f1,"%s%s%d",la,m1,&op1);
	if(strcmp(m1,"START")==0)
	{
        	sa=op1;
        	lc=sa;
        	fprintf(f4,"-\t%s\t%s\t%d\n",la,m1,op1);
    	}
    	else
    	{
        	lc=0;
    	}
    	fscanf(f1,"%s%s",la,m1);
    	while(!feof(f1))
    	{
        	fscanf(f1,"%s",op);
        	fprintf(f4,"%d\t%s\t%s\t%s\n",lc,la,m1,op);
        	if(strcmp(la,"-")!=0)
        	{
            	fprintf(f3,"%d\t%s\n",lc,la);
        	}
        	fscanf(f2,"%s%d",otp,&o);
        	while(!feof(f2))
        	{
            		if(strcmp(m1,otp)==0)
            		{
                		lc=lc+3;
                		break;
            		}
            		fscanf(f2,"%s%d",otp,&o);
        	}
		if(strcmp(m1,"WORD")==0)
		{
			lc=lc+3;
		}
		else if(strcmp(m1,"RESW")==0)
		{
			op1=atoi(op);
			lc=lc+(3*op1);
		}
		else if(strcmp(m1,"BYTE")==0)
		{
			len=strlen(op)-3;
			lc=lc+len;
		}
		else if(strcmp(m1,"RESB")==0)
		{
			op1=atoi(op);
			lc=lc+op1;
		}
		fscanf(f1,"%s%s",la,m1);
	}
	if(strcmp(m1,"END")==0)
	{
        	printf("\nProgram Length=%d\n",lc-sa);
    	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	// pass 2 - generating opcode
	f1=fopen("inter.txt","r");
	f2=fopen("objectcode.txt","w");
	
	
	
	while(!feof(f1))
	{
		fscanf(f1,"%s%s%s%s",z,la,m1,op);
	
		f3=fopen("optab.txt","r");
		
		fscanf(f3,"%s%s",otp,op2);
		
		while(!feof(f3))
		{
			
			if(strcmp(m1,otp)==0)
			{
			
				f4=fopen("symtab.txt","r");
				fscanf(f4,"%s%s",addr,ad);
				while(!feof(f4))
				{
					
					if(strcmp(op,ad)==0)
					{
			
						strcat(op2,addr);
						fprintf(f2,"%s\t%s\t%s\t%s\n",z,m1,op,op2);
					}
					fscanf(f4,"%s%s",addr,ad);
				}
				fclose(f4);
			}
			fscanf(f3,"%s%s",otp,op2);
			
		}
		fclose(f3);
		
		
	}

	fclose(f1);
	fclose(f2);
	// generating text records file
	f1=fopen("objectcode.txt","r");
	f2=fopen("text","w");
	fprintf(f2,"%d\n",sa);
	fprintf(f2,"%d",lc);
	fclose(f1);
	fclose(f2);
	
}
