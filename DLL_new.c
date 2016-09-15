#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 

typedef struct Node
{
     struct Node *prev;
     int info;
     struct Node *next;
}node;

node *start=NULL, *temp2, *temp4;

void insert_begning(int value)
{
     node *ptr,*new;
     new=malloc(sizeof(node));
     new->info=value;
     new->next=NULL;
     new->prev=NULL;
    
     if(start==NULL)
     {
         start=new;
     }
     else
     {
         new->next=start;
         start->prev=new;
         start=new;
    
     }
}

void insert_end(int value)
{
     node *ptr,*new;
     new=malloc(sizeof(node));
     new->info=value;
     new->next=NULL;
     new->prev=NULL;
    
     if(start==NULL)
     {
         start=new;
     }
     else
     {
         ptr=start;
         while(ptr->next!=NULL)
		 {
		 	ptr=ptr->next;
		 }
		 ptr->next=new;
		 new->prev=ptr;
	}
	//ptr=ptr->next;
}   

int insert_after(int value, int loc)
{
 node *ptr,*new,*tmp;
     new=malloc(sizeof(node));
     new->info=value;
     new->next=NULL;
     new->prev=NULL;
    
     if(start==NULL)
     {
         start=new;
     }
	 else
	    {
	    	ptr=start;
	    	while(ptr!=NULL&& ptr->info!=loc)
	    	{
	    		ptr=ptr->next;
	    	}
	    	if(ptr==NULL)
			{
				printf("%d is not present in list",loc);
		    }
		    else
		    {
		    	tmp=ptr->next;
		    	ptr->next=new;
		    	new->prev=ptr;
		    	tmp->prev=new;
		    	new->next=tmp;
		    }
	    }
} 


void deletebeg()
{
	node *ptr;
	if (start==NULL)
	{
		printf("list os empty");
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			start=start->next;
			start=NULL;
			free(ptr);
		}
	   else
    	{
		ptr=start;
		start=start->next;
		start->prev=NULL;
		free(ptr);

       }	
    }
}  
void delete_from_end()
{
    node *ptr,*tmp;
    ptr=start;
	if (start==NULL)
	{
		printf("list is empty");
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			ptr=NULL;
			free(ptr);
		}
	
      	else
      	{
			while(ptr->next!=NULL)
		    {
				tmp=ptr;
				ptr=ptr->next;
		    }
			tmp->next=NULL;
			free(ptr);
    	}
    }
} 

void delete_from_middle(int value)
{
    node *r,*tmp,*q;
    q=start;
    r=start;
    if (start==NULL)
	{
		printf("list is empty");
	}
    if(start->info==value)
    {
     	q=start;
	 	start=start->next;
	 	start->prev=NULL;
	 	free(q);	
    }
    
    while(q->next!=NULL)
    {
    	if(q->info == value)
    	{
    		//tmp=q->next;
    		r -> next = q -> next;
    		q -> next -> prev = r;
    		free(q);
    	}
    	else
    	{
    		r = q;
    		q = q -> next;
    	}
    	
    }
    printf("data deleted from list is %d\n",value);

}

void display()
{
     node *temp,*ptr;
    ptr=start;
     if(start==NULL)
      {
         printf("List is Empty");
      }
     while(ptr!=NULL)
     {
          printf("-> %d ",ptr->info);
          ptr=ptr->next;
     }
} 

/* To sort the linked list */
void sort()
{
    int i, j, x;
 
    temp2 = start;
    temp4 = start;
 
    if (temp2 == NULL)
    {
        printf("\n List empty to sort");
        return;
    }
 
    for (temp2 = start; temp2 != NULL; temp2 = temp2->next)
    {
        for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
        {
            if (temp2->info > temp4->info)
            {
                x = temp2->info;
                temp2->info = temp4->info;
                temp4->info = x;
            }
        }
    }
    //display();
}


int main()
{
    int value, i, loc;
   // head=NULL;
    printf("Select the choice of operation on link list");
    printf("\n1.) insert at begning\n2.) insert at end\n3.) insert at middle");
    printf("\n4.) delete from end\n5.) delete middle\n6.) display list\n7.)exit\n8. sort");
    while(1)
    {
          printf("\n\nenter the choice of operation you want to do ");
          scanf("%d",&i);
          switch(i)
          {
                case 1:
                
                 printf("enter the value you want to insert in node ");
                 scanf("%d",&value);
                 insert_begning(value);
                 display();
                 break;
                
                 case 2:
                 
                 printf("enter the value you want to insert in node at last ");
                 scanf("%d",&value);
                 insert_end(value);
                 display();
                 break;
                
                 case 3:
                 
                 printf("after which data you want to insert data ");
                 scanf("%d",&loc);
                 printf("enter the data you want to insert in list ");
                 scanf("%d",&value);
                 insert_after(value,loc);
                 display();
                 break;
                 
                 case 4:
                 
                 delete_from_end();
                 display();
                 break;
                 
                 case 5:
                 
                 printf("enter the value you want to delete");
                 scanf("%d",&value);
                 delete_from_middle(value);
                 display();
                 break;
                 
                 case 6 :
                 
                 display();
                 break;
                 
                 case 7 :
                 
                      exit(0);
                      break;
                 case 8:
                 sort();
                 //deletebeg();
                 display();
                 break;
                 
                 
          }
    }
   // printf("\n\n%d",last->data);
   // display();
    getch();
}
