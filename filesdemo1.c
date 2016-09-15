//file program
//Read name and marks of n number of students from user and 
//store them in a file
#include<stdio.h>
int main()
{  int n;
	FILE *fptr;
	fptr=fopen("C:\\test.txt","w");
	if(fptr==NULL)
	{
		printf("ERROR!");
		System.exit(0);
	}
	printf("enter n");
	scanf("%d",&n);
	fprintf(fptr,"%d",n);
	fclose(fptr);
	
	return 0;
}
