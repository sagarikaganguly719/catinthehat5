//circular linked list
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *newnode,*start,*temp,*temp1,*new2,*new3;

void create()
{
	start=NULL;
	if(start==NULL)
	{   newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n enter data for the node");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		start=newnode;
		newnode->next=start;
		printf("\n created successfully");
	}
	else
	printf("\n list is not empty");
	}

      void traverse()
{
if(start==NULL)
printf("\n list is empty");
	else
	{
	temp=start;
while(temp->next!=start)
		{ 
		 printf(" %d ",temp->data);
			temp=temp->next;
			}
		printf(" %d -> ",temp->data);
		printf(" NULL ");
		}
		}
		
	void insert_beg()
	{
		if(start!=NULL)
		{  
		new2=(struct node *)malloc(sizeof(struct node));
		
		printf("\n enter data for new node ");
		scanf("%d",&new2->data);
		
		temp=start;
		while(temp->next!=start)
		temp=temp->next;
			
		temp->next=new2;
		new2->next=start;
		start=new2;
		printf("\n inserted successfully");} 
else
printf("\n list is empty");
}
    void insert_end()
	{
		if(start==NULL)
		printf("\n list is empty");
		else{  
new3=(struct node *)malloc(sizeof(struct node));
printf("enter data for new node ");
scanf("%d",&new3->data);
new3->next=NULL;
temp=start;
while(temp->next!=start)
temp=temp->next;
temp->next=new3;
new3->next=start;
printf("\n inserted successfully");
}

}
void del_beg()
{ int num;
if(start==NULL)
printf("\n list is empty");
else
{printf("enter number to be deleted");
	scanf("%d",&num);
	temp=start;
	if(temp->next==start)
	{free(temp);
	start=NULL;
	}
	else
	{temp1=start;
while(temp1->next!=start)
{
	temp1=temp1->next;
	}
	if(temp1->next->data==num)
		{
		start=start->next;
			temp1->next=start;
			temp->next=NULL;
			free(temp);
printf("No. %d is deleted sucessfully.\n",num);
}
	else
printf("Data not found");
}
}
}
void del_end()
{  int num1;
temp=start;
if(temp!=NULL)
{printf("enter data to be deleted");
		scanf("%d",&num1);
		temp1=temp->next;
		while(temp1->next!=start){
			temp=temp1;
			temp1=temp1->next;}
		if(temp->data==num1)
{
temp->next=start;
temp1->next=NULL;
free(temp1);
}
else 
printf("\n data not found");}
else 
printf("\n list is empty");}
main()
	{
		int ch;
		do
		{
		printf("\n 1. Creation");
		printf("\n 2. Traversal");
		printf("\n 3. Insert from beginning");
		printf("\n 4. Insert from the end");
		printf("\n 5. Delete from the beginning");
		printf("\n 6. Delete from the end");
		printf("\n Enter choice");
		scanf("%d",&ch);
		switch(ch)
		{case 1: create();
			break;
		case 2: traverse();
			break;
case 3:  insert_beg();
	traverse();
	 break;
case 4: insert_end();
	traverse();
	break;
 case 5: del_beg();
	 traverse();
	 break;

case 6: del_end();
	traverse();
	 break;
default: printf("\n invalid choice");
	exit(0);}
}while(ch>=1 || ch<=5);
}
7
