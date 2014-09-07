#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

struct node{
	int id;
	int count;
	std::vector<int> neighbor;
	int parent;
};
typedef struct node node;

void createGraph(node *g,int N,int M){
	int u,v;
	for(int i=0;i<N;i++){
		g[i].id = i+1;
		g[i].count = 0;
		g[i].parent = -1;
		g[i].neighbor.clear();
	}
	for(int i=0;i<M;i++){
		scanf("%d%d",&u,&v);
		g[u-1].neighbor.push_back(v-1);
		g[v-1].neighbor.push_back(u-1);
	}
	return;
}
// 1  procedure BFS(G,v) is
// 2      create a queue Q
// 3      create a set V
// 4      add v to V
// 5      enqueue v onto Q
// 6      while Q is not empty loop
// 7         t ← Q.dequeue()
// 8         if t is what we are looking for then
// 9            return t
// 10        end if
// 11        for all edges e in G.adjacentEdges(t) loop
// 12           u ← G.adjacentVertex(t,e)
// 13           if u is not in V then
// 14               add u to V
// 15               enqueue u onto Q
// 16           end if
// 17        end loop
// 18     end loop
// 19     return none
// 20 end BFS
void findParents(node *g,int N,int root){
	bool visited[N];
	for(int i=0;i<N;i++){
		visited[i] = false;
	}
	std::queue <int> Q;
	Q.push(root);
	visited[root] = true;
	g[root].parent = root;
	while(Q.size()>0){
		int t = Q.front();
		Q.pop();
		/***** do something with t****/
		// printf("%d ",g[t].id);
		/*****************************/
		for(int i=0;i<g[t].neighbor.size();i++){
			int u = g[t].neighbor[i];
			if(!visited[u]){
				visited[u] = true;
				Q.push(u);
				g[u].parent = t;
			}
		}
	}
}

void printParents(node *g,int N){
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%d --> %d --> %d\n",g[i].id,g[g[i].parent].id,g[i].count);
	}
}

int getTreeSize(node *g,int i){
	/******* test for leaf ***************/
	if(g[i].neighbor.size() == 1 && g[i].neighbor[0] == g[i].parent){
		g[i].count = 1;
		return 1;
	}
	/*************************************/
	int size = 1;
	for(int k=0;k<g[i].neighbor.size();k++){
		if(g[i].neighbor[k]!=g[i].parent){
			size = size + getTreeSize(g,g[i].neighbor[k]);
		}
	}
	g[i].count = size;
	return size;
}

void computeCounts(node *g,int N,int root){
	getTreeSize(g,root);
	return;
}

int getEvenTreeCount(node *g,int N){
	int count = 0;
	for(int i=0;i<N;i++){
		if(g[i].count%2==0){
			count++;
		}
	}
	return count;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);

	node g[N];
	createGraph(g,N,M);
	findParents(g,N,0);
	computeCounts(g,N,0);
	// printParents(g,N);

	printf("%d",getEvenTreeCount(g,N)-1);

	// printf("\n");
	return 0;
}

