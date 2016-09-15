//binary search tree
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
};
struct node *temp,*parent,*location,*root,*ptr,*ptrsave;
void insert()
{
    int item;
	printf("\n enter the data for the tree node");
	scanf("%d",&item);
    find(item,&parent,&location);
    if(location!=NULL)   //matlab the node already exists
    {
    	printf("\n item already present");
    	return;
	}
	//initialising temp
temp= (struct node *)malloc(sizeof(struct node));
temp->data=item;
temp->lchild=NULL;
temp->rchild=NULL;   //a normal node created.
//now , we have to place the node.
if(parent==NULL)  //if there is no parent,then temp becomes the root
root=temp;
else
{   //if there is a parent, then the node is a lucky guy!
	if(item<parent->data)
  parent->lchild=temp;
  else
  parent->rchild=temp;	
}
}
//now the find function
void find(int item,struct node **par,struct node **loc)
{
	//there are 4 conditions
	if(root==NULL)    //there is no root
	{
		*loc=NULL;
		*par=NULL;
			return;
	}
	if(item==root->data)    //item is at root
	{
		*loc=root;
		*par=NULL;
		return;
	}
	ptr=(struct node *)malloc(sizeof(struct node));
	ptrsave=(struct node *)malloc(sizeof(struct node));
	if(item<root->data)
	ptr=root->lchild;
	else
	ptr=root->rchild;
	ptrsave=root;
	
	
	while(ptr!=NULL)
	{
		if(item==ptr->data)   //item is present at location
		{
			*loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->data)
		ptr=ptr->lchild;
		else
		ptr=ptr->rchild;
	}
	//item is not present...
	*loc=NULL;
	*par=ptrsave;
	
	printf("\n inserted successfully");
}
//recursive traversal
void inorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	inorder(ptr->lchild);
	printf("%d",ptr->data);
	inorder(ptr->rchild);
}
void preorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	printf("%d",ptr->data);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
	if(ptr==NULL)
	return;
	preorder(ptr->lchild);
	preorder(ptr->rchild);
	printf("%d",ptr->data);
}

//non recursive traversal

main()
{
	int ch;
	do
	{
		printf("\n 1.insertion");
		printf("\n 2.inorder traversal");
		printf("\n 3.preorder traversal");
		printf("\n 4.postorder traversal");
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:  insert();
			    break;
			case 2:
				inorder(root);
				break;
		    case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			default: printf("\n invalid choice");
			         exit(0);
	    }
	}while(ch<=4);
}
