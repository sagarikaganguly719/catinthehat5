#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};

	struct node *newnode,*start,*temp,*new1,*new2,*new3,*temp1;
	int pos,pos1;
	
	void create()
	{//creating
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
//traversing
void traverse()
{

	temp=start;
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
	void insert_beg()
	{ //insertion from the beginning
	 if(start==NULL)
	 printf("\n list is empty");
	 else
	 {new1=(struct node *)malloc(sizeof(struct node));
	 	printf("\n enter a number to the node");
	 	scanf("%d",&new1->data);
	 	new1->next=NULL;
	 	new1->next=start;
	 	start=new1;
	 	printf("\n inserted from beginning successfully");
		}	
	}

    void insert_end()
	{//insertion from the end 
    if(start==NULL)
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


void insert_med()
{	//insertion from an intermediate position
	if(start==NULL)
	printf("list is empty");
	else
	{new3=(struct node *)malloc(sizeof(struct node));
       printf("\n enter a number to the node");
       scanf("%d",&new3->data);
       new3->next=NULL;
       printf("enter the element node after which the new node will be inserted");
       scanf("%d",&pos);
       temp=start;	
       while(temp->data!=pos)
       {
       	temp=temp->next;
       	temp1=temp->next;
       	}
       	temp->next=new3;
       	new3->next=temp1;
       	printf("\n the element has been inserted from the mid successfully");
       	}
       }
    
       void del_beg()
	   {	//deletion from the beginning
       	if(start==NULL)
       	printf("\n list is empty");
       	else
       	{temp=start;
       start=temp->next;
       temp->next=NULL;
       free(temp);
       printf("\n deleted successfully");
	   }
	   }

  void del_end()
  {  //deletion from the end
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

void del_med()
{ //deletion from an intermediate position
    temp=start;
    if(temp==NULL)
    printf("\n list is empty");
    else
    {
    	printf("\n enter the node which is going to be deleted");
    	scanf("%d",&pos1);
    	temp1=temp->next;
    	while(temp1->data!=pos1)
    	{
    		temp=temp1;
    		temp1=temp1->next;
    	}
    	temp->next=temp1->next;
    	temp1->next=NULL;
    	free(temp1);
    	printf("\n deleted successfully");
    	}
    }

	main()
{ int ch;
do{
	printf("\n 1.create");
	printf("\n 2.display");
	printf("\n 3.insert from beg");
	printf("\n 4.insert from end");
    printf("\n 5.insert from middle");
	printf("\n 6.delete from beg");
	printf("\n 7.delete from end");
	printf("\n 8.delete from middle");
	printf("\n enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create();
			break;
		case 2:
			traverse();
			break;
		case 3:
			insert_beg();
			traverse();
			break;
		case 4:
			insert_end();
			traverse();
			break;
		case 5:
			insert_med();
			traverse();
			break;
		case 6:
			del_beg();
			traverse();
			break;
		case 7:
			del_end();
			traverse();
			break;
		case 8:
			del_med();
			traverse();
			break;
		default:printf("\n invalid choice");
			exit(0);
			
		
			
	}
}while(ch<=8);
}
