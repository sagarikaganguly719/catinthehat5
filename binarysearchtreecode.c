//binary search tree  and avl check...
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *lchild,*rchild;	
};
struct node *temp,*root,*parent,*location,*ptr,*ptrsave;
int count=0,count1=0;
void insert()
{
	int item;
	printf("\n enter the data for the tree node");
	scanf("%d",&item);
	find(item,&parent,&location);
	if(location!=NULL)
	{
	printf("\n item already present");
	return;
    }
temp= (struct node *)malloc(sizeof(struct node));
temp->data=item;
temp->lchild=NULL;
temp->rchild=NULL;
//now since the node is ready, you can insert the node anywhere.
//first,check for the parent...if parent is null,add the node as a root.
if(parent==NULL)
root=temp;
else
{   if(item<parent->data)
parent->lchild=temp;
else
parent->rchild=temp;	
}
}  //insert function gets over.
void find(int item,struct node **par,struct node **loc)
{
	//1st condition-> when tree is empty
	if(root==NULL)
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	//2nd condition-> when item is at root,less than root,or greater than root
	if(item==root->data)
	{
		*loc=root;
		*par=NULL;
		return;
	}
	
	//initialising prt and ptrsave
	ptr=(struct node *)malloc(sizeof(struct node));
	ptrsave=(struct node *)malloc(sizeof(struct node));
	
	if(item<root->data)
	ptr=root->lchild;
	else
	ptr=root->rchild;
	ptrsave=root;
	
    //3rd condition-> when item is present at location
    while(ptr!=NULL)
    {
    	if(item==ptr->data)
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
	//4th condition->when item is not present,hence,parent=ptrsave
	*loc=NULL;
	*par=ptrsave;
	printf("\n inserted successfully");
}

void countNodes(struct node *ptr)
{
    if(ptr== NULL)
    return;
    else
    {
       count++;
       countNodes(ptr->lchild);
       countNodes(ptr->rchild);
}
}

size_t height(struct node *root)
{
    size_t i, front, rear, ht;
    struct node *c, *queue[100];

    ht = front = rear = 0;

    if(root) queue[rear++] = root;

    for(;;){
        if(rear == front) return ht;
        else ++ht;

        for(i = rear - front; i; --i){
            c = queue[front++];
            if(c->lchild) queue[rear++] = c->lchild;
            if(c->rchild) queue[rear++] = c->rchild;
        }
    }

    return 0;
}

struct node *checkavl() /* return NULL; if AVL */
{
    size_t top;
    struct node *c, *prev, *stack[100];

    if(!root) return NULL;

    top = 0;
    stack[top++] = root;
    prev = NULL;

    while(top){
        c = stack[top - 1];

        if(!prev || prev->lchild == c || prev->rchild == c){
                 if(c->lchild) stack[top++] = c->lchild;
            else if(c->rchild) stack[top++] = c->rchild;
        }

        else if(c->lchild == prev){
            if(c->rchild) stack[top++] = c->rchild;
        }

        else{
            if(1 < (height(c->lchild) > height(c->rchild) ?
                height(c->lchild) - height(c->rchild) :
                height(c->rchild) - height(c->lchild) )
            ) return c;

            --top;
        }

        prev = c;
    }

    return NULL;
}


main()
{  int ch;
	do{
	
	printf("\n MENU");
	printf("\n 1.Insertion");
	printf("\n 2.Deletion");
	printf("\n 3. Count Nodes");
	printf("\n 4. Traversal");
	printf("\n 5.AVL check");
    printf("\n enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1: insert();
    	break;
    	case 3: countNodes(root);
    	printf("nodes:%d",count);
    	break;
    case 5:
    	if(!checkavl()) printf("Tree is AVL");
    	else printf("Tree is not AVL");
    	break;
    	default: printf("\n invalid choice");
    	exit(0);
	}
}while(ch>=1 || ch<=5);
}
