//adjacency list - graph
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Edge;
struct Vertex
{
	int data;
	struct Vertex *nextVertex; //next vertex of the linked list of vertices
    struct Edge *firstEdge; //first edge of the adjacency list of the vertex
}*start=NULL;
struct Edge
{
	struct Vertex *destVertex;  //destinaton vertex of the edge
	struct Edge *nextEdge; //next edge of the adjacency list
};
void insertVertex()
{  int u;
	printf("\n Enter a vertex to be inserted :");
	scanf("%d",&u);
	struct Vertex *temp,*ptr;
	temp=(struct Vertex *)malloc(sizeof(struct Vertex));
	temp->data=u;
	temp->nextVertex=NULL;
	temp->firstEdge=NULL;
	if(start==NULL)
	{
		start=temp;
		return;
	}
ptr=start;
  
  while(ptr->nextVertex!=NULL)
     ptr=ptr->nextVertex;
ptr->nextVertex=temp;

printf("\n node has been inserted successfully");
}
struct Vertex *findVertex(int u)
{
	struct Vertex *ptr,*loc;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data==u)
		{
			loc=ptr;
			return loc;
		}
		else
		ptr=ptr->nextVertex;
	}
	loc=NULL;
	return loc;
}

void insertEdge()
{
	int u,v;
	printf("\n Enter an edge to be inserted :");
	scanf("%d%d",&u,&v);
	struct Vertex *locu,*locv;
	struct Edge *ptr,*temp;
	locu=findVertex(u);
	locv=findVertex(v);
	if(locu==NULL)
	{
		printf("\n start vertex not present,insert %d",u);
		return;
	}
	if(locv==NULL)
	{
		printf("\n end vertex not present,insert %d",v);
		return;
	}
	temp=(struct Edge *)malloc(sizeof(struct Edge));
	temp->destVertex=locv;
	temp->nextEdge=NULL;
	
	if(locu->firstEdge==NULL)
	{
		locu->firstEdge=temp;
	}
	ptr=locu->firstEdge;
	while(ptr->nextEdge!=NULL)
	ptr=ptr->nextEdge;
	ptr->nextEdge=temp;
	
	printf("\n edge has been inserted successfully");
}
void deleteEdge()
{
	int u,v;
	printf("\n enter the edge to be deleted :");
	scanf("%d%d",&u,&v);
struct Vertex *locu;
struct Edge *temp,*q;
locu=findVertex(u);

if(locu==NULL)
{
	printf("\n start vertex not present");
    return;
}
if(locu->firstEdge==NULL)
{
	printf("\n Edge not present");
	return;
}
if(locu->firstEdge->destVertex->data == v)
{
	temp=locu->firstEdge;
	locu->firstEdge=locu->firstEdge->nextEdge;
	free(temp);
	return;
}
q=locu->firstEdge;
while(q->nextEdge != NULL)
{
	if(q->nextEdge->destVertex->data == v)
	{
		temp=q->nextEdge;
		q->nextEdge=temp->nextEdge;
		free(temp);
		return;
	}
	q=q->nextEdge;
	}
printf("\n this edge is not present in the graph");
}
void deleteIncomingEdges(int u)
{
	struct Vertex *ptr;
	struct Edge *q,*tmp;
	
	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->firstEdge == NULL)   
		{
			ptr = ptr->nextVertex;
			continue; 
		}	
		
		if(ptr->firstEdge->destVertex->data == u)
		{
			tmp = ptr->firstEdge;
			ptr->firstEdge = ptr->firstEdge->nextEdge;  
			free(tmp);
			continue; 
		}
		q = ptr->firstEdge;
		while(q->nextEdge!= NULL)
		{
			if(q->nextEdge->destVertex->data == u) 
			{
				tmp = q->nextEdge;
				q->nextEdge = tmp->nextEdge;
				free(tmp);
				continue;
			}
			q = q->nextEdge;
		}
		ptr = ptr->nextVertex;
	}
}
void deleteVertex(int u)
{
	struct Vertex *temp,*q;
	struct Edge *p,*temp1;
	if(start==NULL)
	{
		printf("\n no vertices to be deleted");
		return;
	}
	if(start->data==u)
	{
		temp=start;
		start=start->nextVertex;
	}
else
{
	q=start;
	while(q->nextVertex!=NULL)
	{
		if(q->nextVertex->data==u)
			break;
			q=q->nextVertex;
		}
		if(q->nextVertex==NULL)
		{
			printf("\n vertex not found");
			return;
		}
		else
		{
			temp=q->nextVertex;
			q->nextVertex=temp->nextVertex;
		}
	}
	p=temp->firstEdge;
	while(p!=NULL)
	{
		temp1=p;
		p=p->nextEdge;
		free(temp1);
		}	
		free(temp);
}
void display()
{
	struct Vertex *ptr;
	struct Edge *q;

	ptr = start;
	while(ptr!=NULL)
	{
		printf("%d ->",ptr->data);
		q = ptr->firstEdge;
		while(q!=NULL)
		{
			printf(" %d",q->destVertex->data);
			q = q->nextEdge;
		}
		printf("\n");
		ptr = ptr->nextVertex;
	 }
}
main()
{ // insertVertex();
   //insertEdge();
	int ch,u;
	do
	{
	printf("\n menu");
	printf("\n 1.insert vertex");
	printf("\n 2.insert edge");
	printf("\n 3.delete edge");
	printf("\n 4.delete incoming edge");
	printf("\n 5.display");
	printf("\n enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			insertVertex();
			break;
		case 2:
			insertEdge();
			break;	
		case 3:
		    deleteEdge();
			break;		
		case 4:
			printf("Enter a vertex to be deleted : ");
			scanf("%d",&u);
			//This function deletes all edges coming to this vertex
			deleteIncomingEdges(u);
			//This function deletes the vertex from the vertex list
			deleteVertex(u);
			break;
		case 5:
				display();
				break;
		default:  printf("\n invalid choice");
		exit(0);
		}	
	}while(ch<=5);  
}
