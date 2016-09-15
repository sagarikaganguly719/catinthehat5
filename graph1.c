//graph program
#include<stdio.h>
#include<conio.h>
#define MAX 20
int adj[MAX][MAX];
typedef enum boolean{false,true}bool;
bool visited[MAX];
int n;   //for the number of nodes in the graph
void create_graph()
{
	int i,max_edges,origin,destin;
	printf("enter the number of nodes");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("\n enter edge %d from a to b(00 to quit)",i);
		scanf("%d%d",&origin,&destin);
		if((origin==0)&&(destin==0))
		break;
		if(origin>n||destin>n||origin<=0||destin<=0)
		{
			printf("\n invalid edge\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	} //end of for loop
}

void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf(" %3d ",adj[i][j]);
		}
		printf("\n");
	}
}
//inserting a node
void insert_node()
{
	int i;
	n++;   //increasing no. of nodes in the graph
	printf("the inserted node is %d ",n);
	for(i=1;i<=n;i++)
	{
		adj[i][n]=0; //an entire column=0
		adj[n][i]=0; //an entire row=0
	}
}
//deleting a node
void delete_node()
{
	int u,i,j;
	printf("\n enter node to be deleted");
	scanf("%d",&u);
	if(n==0)
	{
		printf("\n graph is empty");
	}
if(u>n)
{
	printf("\n the node is not present in the graph");
}
 for(i=u;i<=n-1;i++)
 {
 	for(j=1;j<=n;j++)
 	{
 		adj[j][i]=adj[j][i+1];//shifts the columns to the left
 		adj[i][j]=adj[i+1][j];//shifts the rows upward
	 }
 } n--;//decreases the number of nodes in the graph
	}
//inserting an edge
void insert_edge()
{
	int u,v;
	printf("\n enter the start and end vertices of the edge");
	scanf("%d%d",&u,&v);
	if(u>n)
	{
		printf("\n source node doesn't exist");
	}
	if(v>n)
	{
		printf("\n destination node doesn't exist");
	}
	adj[u][v]=1;
}
//deleting an edge
void delete_edge()
{
    int u,v;
	printf("\n enter the start and end vertices of the edge");
	scanf("%d%d",&u,&v);
	if(u>n||v>n||adj[u][v]==0)
	{
		printf("\n this edge doesn't exist");
		}	
	adj[u][v]=0;
}
//breadth first search
void bfs(int v)
{
	int i,front,rear;
	int que[20];
	front=rear=-1;
	printf("%d",v);
	visited[v]=true;   //the 1st ele has been visited cz it's printed first
	rear++;   //the element 
	front++;
	que[rear]=v;  //element inserted from rear
  while(front<=rear)
  {
  	v=que[front]; //delete from the queue
  	front++;
  	for(i=1;i<=n;i++)
  	{
  		//checking for adjacent unvisited nodes
  		if((adj[v][i]==1)&&(visited[i]==false))
  		{printf("%d",i);
  		visited[i]=true;
  		rear++;
  		que[rear]=i;
		  }
	  }
		 }	   
}
//depth first search
void dfs(int v)
 {
 	int i,stack[MAX],top=-1,pop_v,j;
 	
 	top++;
 	stack[top]=v;//first element goes inside the stack
 	while(top>=0)
 	{
 		pop_v=stack[top];
 		top--;   //pop from stack
 		if(visited[pop_v]==false)
 		{
 			printf("%d",pop_v);
 			visited[pop_v]=true;
		 }
 		else
 		continue;
 		for(i=n;i>=1;i--)
 		{
 			if((adj[pop_v][i]==1)&&(visited[i]==false))
 			{
 				top++;  //pushed into stack
 				stack[top]=i;
			 }
		 }
	 }
 }

main()
{
	int ch,v,i;
	do{
	printf("\n menu:");
	printf("\n 1.create");
	printf("\n 2.display");
	printf("\n 3.insert node");
	printf("\n 4.delete node");
	printf("\n 5.insert edge");
	printf("\n 6.delete edge");
	printf("\n 7.breadth first search");
	printf("\n 8.depth first search");
	printf("\n enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create_graph();
			break;
		case 2:
			display();
			break;
		case 3:
			insert_node();
			break;
		case 4:
				delete_node();
			break;
		case 5:
				insert_edge();
				break;
		case 6:
			delete_edge();
			break;
		case 7: 
	
   printf("\n Enter starting node for bfs ");
   scanf("%d",&v);
   for(i=1;i<=n;i++)
   visited[i]=false;
   printf("\n BFS TRAVERSAL");
   printf("\n");
   bfs(v);
   printf("\n");
   
   break;
        case 8:
        	printf("\n enter starting node for dfs ");
	scanf("%d",&v);
	for(i=1;i<=n;i++)
	visited[i]=false;
	printf("\n DFS TRAVERSAL");
	printf("\n");
	dfs(v);
	printf("\n");
	
	break;
		default: printf("invalid choice");
		exit(0);
			
	}
} while(ch<=8);
}

