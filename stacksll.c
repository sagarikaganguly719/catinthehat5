//stack implementation through linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *newnode,*start,*temp,*new1,*new2,*temp1;
	int pos,pos1;
void create()
{
	start=NULL;
	if(start==NULL)
	{    newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n enter a number to be stored in the node");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		start=newnode;
	}
	else
	printf("\n list is not empty");
	
}
void traverse()
{ temp=start;
	if(temp==NULL)
	printf("\n list is empty");
	else
	{   printf("\n start ");
		while(temp!=NULL)
     {
     	printf(" %d ",temp->data);
     	temp=temp->next;
	 }
	 printf(" null");
}
}

void push()
{    if(start==NULL)
    printf("\n list is empty ");
    else
    { new2=(struct node *)malloc(sizeof(struct node));
    	printf("\n enter a number to the node");
    	scanf("%d",&new2->data);
    	new2->next=NULL;
    	temp=start;
    	while(temp->next!=NULL)
    	temp=temp->next;
    	temp->next=new2;
    		printf("\n inserted from the end successfully");
	}
}

void pop()
{
    if(start==NULL)
    printf("\n list is empty");
    else
    {
    	temp=start;
    	temp1=temp->next;
    	while(temp1->next!=NULL)
    	{
    		temp=temp1;
    		temp1=temp1->next;
    	}
    	temp->next=NULL;
    	printf("\n %d has been deleted",temp1->data);
    	temp1->next=NULL;
    	free(temp1);
    }
}
main()
	{
		int ch;
		do
		{
			printf("\n menu:");
		printf("\n 1. Creation");
		printf("\n 2. Traversal");
		printf("\n 3. Push");
		printf("\n 4. Pop");
		printf("\n Enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
			break;
			case 2: traverse();
			 break;
			 case 3: push();
			 traverse();
			 break;
			 case 4: pop();
			 traverse();
			 break;
			default: printf("\n invalid choice");
			exit(0);
			
		}
	}while(ch>=1);
	getch();
}
