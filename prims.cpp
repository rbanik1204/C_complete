#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int wt;
	struct node* next;
}NODE;
typedef struct{
	int src,dest,weight;
}Edge;
NODE* createnode(int u,int w){
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = u;
	newnode->wt = w;
	newnode->next = NULL;
	return newnode;
}
void addEdge(NODE**adj,int u,int v,int w){
	NODE* newnode = createnode(v,w);
	newnode->next = adj[u];
	adj[u] = newnode;
	//Undirected
	NODE*newnode1 = createnode(u,w);
	newnode1->next = adj[v];
	adj[v] = newnode1;
}
void display(NODE**adj,int N){
	NODE* temp = NULL;
	printf("Given graph:\n");
	for(int i = 0;i<N;i++){
		temp = adj[i];
		while(temp != NULL){
			printf("%d-%d\tweight:%d\n",i,temp->data,temp->wt);
			temp = temp->next;
		}
	}
}
int minkey(int *key,int *visited,int N){
	int min = INT_MAX,min_index =-1;
	for(int i=0;i<N;i++){
		if(!visited[i] && key[i]<min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}
void prims(NODE**adj,int V){
	int key[V]; // min weights of mst
	int parent[V]; // parent of each node
	int visited[V]; // unvisited as 0
	for (int i=0;i<V;i++){
		key[i] = INT_MAX;
		parent[i] = -1;
		visited[i] = 0;
	}
	key[0] = 0;
	for(int count=0;count<V-1;count++){
		int u = minkey(key,visited,V);
		visited[u] = 1;
		NODE* temp = adj[u];
		while(temp != NULL){
			int v = temp->data;
			int w = temp->wt;
			if(!visited[v] && w<key[v]){
				key[v] = w;
				parent[v] = u;
			}
			temp = temp->next;
		}
	}
	static int mst_wt;
	printf("Minimum spanning Tree(Prim's):\n");
	for(int i=1;i<V;i++){
		printf("%d - (%d) - (%d)\n",parent[i],key[i],i);
		mst_wt+= key[i];
	}
	printf("Min mst weight:%d",mst_wt);
}
int main(void){
	int V,E;
	printf("Enter number of Vertices and Edges:");
	scanf("%d %d",&V,&E);
	Edge *edges =(Edge*)malloc(E*sizeof(Edge));
	NODE **adj = (NODE**)malloc(V*sizeof(NODE*));
	printf("In format src dest weight\n");
	for(int i=0;i<V;i++)adj[i] = NULL;
	for(int i=0;i<E;i++){
		scanf("%d",&edges[i].src);
		scanf("%d",&edges[i].dest);
		scanf("%d",&edges[i].weight);
		addEdge(adj,edges[i].src,edges[i].dest,edges[i].weight);
	}
	display(adj,V);
	prims(adj,V);
}
