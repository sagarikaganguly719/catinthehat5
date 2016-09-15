//depth first search
#include<stdio.h>
#include<conio.h>
#define MAX 20
typedef enum boolean{false,true}bool;
int adj[MAX][MAX];
bool visited[MAX];
int n; //no. of nodes in the graph
main()
{   int v,i;
	printf("\n enter starting node for dfs ");
	scanf("%d",&v);
	for(i=1;i<=n;i++)
	visited[i]=false;
	printf("\n DFS traversal: ");
	printf("\n");
	dfs(v);
	printf("\n");
}
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




