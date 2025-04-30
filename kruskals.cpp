#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int src,dest,weight;
}Edge;
typedef struct{
	int parent,rank;
}DisjointSet;
int compareEdge(const Edge*a,const Edge*b){
	return (a->weight - b->weight);
}
int findpar(DisjointSet *ds,int u){
	if(ds[u].parent != u)
		return ds[u].parent = findpar(ds,ds[u].parent);
	return ds[u].parent;
}
void init_ds(DisjointSet* ds,int V){
	for(int i=0;i<V;i++){
		ds[i].parent = i;
		ds[i].rank = 0;
	}
}
void unionByrank(DisjointSet *ds,int u,int v){
	int ulp_u = findpar(ds,u);
	int ulp_v = findpar(ds,v);
	if(ulp_u == ulp_v) return;
	if(ds[ulp_u].rank>ds[ulp_v].rank)
		ds[ulp_v].parent = ds[ulp_u].parent;
	else if(ds[ulp_u].rank<ds[ulp_v].rank)
		ds[ulp_u].parent = ds[ulp_v].parent;
	else{
		ds[ulp_v].parent = ds[ulp_u].parent;
		ds[ulp_u].rank++;
	}		
}
int main(void){
	int V,E;
	printf("Enter Number of vertices and Edges:");
	scanf("%d %d",&V,&E);
	Edge *edges = (Edge*)malloc(E*sizeof(Edge));
	DisjointSet *ds = (DisjointSet*)malloc(V*sizeof(DisjointSet));
	printf("Enter in format(src dest weight)\n");
	for(int i=0;i<E;i++){
		scanf("%d",&edges[i].src);
		scanf("%d",&edges[i].dest);
		scanf("%d",&edges[i].weight);
	}
	init_ds(ds,V);
	qsort(edges,E,sizeof(Edge),(int (*)(const void*, const void*))compareEdge);
	static int mst_weight;
	for(int i=0;i<E;i++){
		if(findpar(ds,edges[i].src) != findpar(ds,edges[i].dest)){
			mst_weight+=edges[i].weight;
			unionByrank(ds,edges[i].src,edges[i].dest);
		}
	}
	printf("Min weight:%d",mst_weight);
}

