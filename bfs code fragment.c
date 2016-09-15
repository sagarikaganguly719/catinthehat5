//breadth first search
#include<stdio.h>
#include<conio.h>
#define MAX 20
int adj[MAX][MAX];
typedef enum boolean{false,true} bool;
bool visited[MAX];
int n;   //no. of nodes in the graph
main()
{    int v,i;
printf("\n Enter starting node for the bfs ");
scanf("%d",&v);
for(i=1;i<=n;i++)
visited[i]=false;
printf("\n BFS TRAVERSAL");
printf("\n");
bfs(v);
printf("\n");
}
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
