#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *newnode,*start,*temp,*temp1,*new2,*new3,*new4;
void create()
{
	start=NULL;
	if(start==NULL)
	{   newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n enter data for the node");
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;
		start=newnode;
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
		while(temp->next!=NULL)
		{  printf(" %d ",temp->data);
			temp=temp->next;
		}
		printf(" %d -> ",temp->data);
		printf(" NULL ");
			
		}
	}
	void insert_beg()
	{
		if(start==NULL)
		printf("\n list is empty");
		else
		{
			new2=(struct node *)malloc(sizeof(struct node));
			printf("\n enter data for new node");
			scanf("%d",&new2->data);
			new2->prev=NULL;
			new2->next=NULL;
			new2->next=start;
			start->prev=new2;
			start=new2;
			
			printf("\n inserted successfully");
			}
	}
	void insert_end()
	{
		if(start==NULL)
		printf("\n list is empty");
		else
		{    new3=(struct node *)malloc(sizeof(struct node));
		printf("\n enter data for node");
		scanf("%d",&new3->data);
		  new3->prev=NULL;
		  new3->next=NULL;
			temp=start;
			while(temp->next!=NULL)
			temp=temp->next;
				temp->next=new3;
				new3->prev=temp;
				printf("\n inserted successfully");
		}
	}
	void insert_mid()
	{   int num;
		if(start==NULL)
		printf("\n list is empty");
		else
		{
			new4=(struct node *)malloc(sizeof(struct node));
			printf("\n enter data for the node");
			scanf("%d",&new4->data);
			new4->prev=NULL;
			new4->next=NULL;
			printf("\n enter node after which node has to be added");
			scanf("%d",&num);
			temp=start;
			temp1=temp->next;
			while(temp1->data==num)
			   {
				 temp1=temp1->next;
			    temp=temp->next;
			}
				temp->next=new4;
				new4->prev=temp;
				new4->next=temp1;
				temp1->prev=new4;				
			printf("\n inserted successfully");
		}
	}
	
	void del_beg()
	{
		if(start==NULL)
		printf("\n list is empty");
		else
		{
			temp=start;
			start=start->next;
			temp->next=NULL;
			start->prev=NULL;
			free(temp);
		}
	}
	
	void del_end()
	{
		if(start==NULL)
		printf("\n list is empty");
		else
		{
			temp=start;
			temp1=temp->next;
			while(temp1->next!=NULL)
			{ temp=temp1;
			temp1=temp1->next;
		}
		temp->next=NULL;
		temp1->prev=NULL;
		free(temp1);
	}
}
 
    void del_mid()
    {   int num1;
    	if(start==NULL)
    	printf("\n list is empty");
    	else
    	{
    		printf("\n enter the node to be deleted");
    		scanf("%d",&num1);
    		temp=start;
    		temp1=start;
    		while(temp->next!=NULL)
    		{
    			if(temp->data==num1)
    			{
    				temp1->next=temp->next;
    				temp->next->prev=temp1;
    				free(temp);
				}
				else
				{
					temp1=temp;
					temp=temp->next;
				}
			}
		}
	}
main()
	{
		int ch;
		do
		{
		printf("\n 1. Creation");
		printf("\n 2. Traversal");
		printf("\n 3. Insert from beginning");
		printf("\n 4. Insert from the end");
		printf("\n 5. Insert at intermediate position");
		printf("\n 6. Delete from beginning");
		printf("\n 7. Delete from end");
		printf("\n 8. Delete from intermediate position");
		printf("\n Enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
			break;
			case 2: traverse();
			break;
			case 3: insert_beg();
			traverse();
			break;
			case 4: insert_end();
			traverse();
			break;
 			case 5: insert_mid();
 			traverse();
 			break;
 			case 6: del_beg();
 			traverse();
 			break;
 			case 7: del_end();
 			traverse();
 			break;
 			case 8: del_mid();
 			traverse();
 			break;
			default: printf("\n invalid choice");
			exit(0);
			
		}
	}while(ch>=1 || ch<=8);
}

