#include<stdio.h>
int main()
{  int n;
	FILE*fptr;
	fptr=fopen(F:\C Programs\Dev-Cpp\test.txt","w");
	if(fptr==NULL)
	{
		printf("ERROR!");
        
	}
	printf("enter n");
	scanf("%d",&n);
	fprintf(fptr,"%d",n);
	fclose(fptr);
	
	return 0;
	getch();
}
