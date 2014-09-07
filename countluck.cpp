#include <stdio.h>
#include <stdlib.h>
#include <queue>

class cell{
public:
	int x;
	int y;
	bool operator==(const cell &a){
		if(this->x == a.x && this->y == a.y){
			return true;
		}
		return false;
	}
};


void findStartAndExit(char forest[][200],int N,int M,cell *start,cell *end){
	bool startFound = false,endFound = false;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(startFound && endFound){
				break;
			}
			if(forest[i][j] == '*'){
				end->x = i;
				end->y = j;
				endFound = true;
			}
			if(forest[i][j] == 'M'){
				start->x = i;
				start->y = j;
				startFound = true;
			}
		}
	}
	return;
}
bool isEmptyCell(char x){
	if(x == '.'||x=='*'||x == 'M'){
		return true;
	}
	return false;
}
void getEmptyNeighborCells(char forest[][200],int N,int M,cell x,cell *neighbors,int *count){
	*count = 0;
	int i = x.x;
	int j = x.y;
	if(i+1<N){
		if(isEmptyCell(forest[i+1][j])){
			neighbors[*count].x = i+1;
			neighbors[*count].y = j;
			(*count)++;
		}
	}
	if(j-1>=0){
		if(isEmptyCell(forest[i][j-1])){
			neighbors[*count].x = i;
			neighbors[*count].y = j-1;
			(*count)++;
		}
	}
	if(i-1>=0){
		if(isEmptyCell(forest[i-1][j])){
			neighbors[*count].x = i-1;
			neighbors[*count].y = j;
			(*count)++;
		}
	}
	if(j+1<M){
		if(isEmptyCell(forest[i][j+1])){
			neighbors[*count].x = i;
			neighbors[*count].y = j+1;
			(*count)++;
		}
	}
	return;
}
bool isDummy(cell c){
	if(c.x == -1 || c.y == -1){
		return true;
	}
	return false;
}
void computeParentMatrix(char forest[][200],int N,int M,cell start,cell parent[][100]){
	cell dummy;
	dummy.x = -1;
	dummy.y = -1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			parent[i][j] = dummy;
		}
	}
	cell neighbors[4];
	int neighborCount;


	std::queue <cell> Q;
	Q.push(start);
	parent[start.x][start.y] = start;
	while(Q.size() > 0){
		cell t = Q.front();
		Q.pop();
		getEmptyNeighborCells(forest,N,M,t,neighbors,&neighborCount);
		for(int i=0;i<neighborCount;i++){
			if(isDummy(parent[neighbors[i].x][neighbors[i].y])){
				parent[neighbors[i].x][neighbors[i].y] = t;
				Q.push(neighbors[i]);
			}
		}
	}
	return;
}
int backTrackAndFindK(char forest[][200],int N,int M,cell start,cell end,cell parent[][100]){
	cell currentCell = end;
	int k = 0;
	cell neighbors[4];
	int count;
	int temp;
	while(1){
		// printf("currentCell = (%d,%d)\n", currentCell.x,currentCell.y);
		// scanf("%d",&temp);
		currentCell = parent[currentCell.x][currentCell.y];
		getEmptyNeighborCells(forest,N,M,currentCell,neighbors,&count);
		
		if(currentCell == start){
			if((count - 1) >0){
				k++;
			}
			break;
		}else{
			if((count - 2) >0){
				k++;
			}
		}

	}
	return k;
}
int getK(char forest[][200],int N,int M,cell start,cell end){
	cell parent[100][100];
	computeParentMatrix(forest,N,M,start,parent);
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		printf("(%d,%d)\t",parent[i][j].x,parent[i][j].y );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// printf("\nSTART = (%d,%d) END = (%d,%d)",start.x,start.y,end.x,end.y);
	int k = 0;
	k = backTrackAndFindK(forest,N,M,start,end,parent);
	// int k = 0;
	return k;
}

void giveVerdict(char forest[][200],int N,int M,int K){
	// for(int i=0;i<N;i++){
	// 	printf("%s\n",forest[i] );
	// }
	cell start,end;
	findStartAndExit(forest,N,M,&start,&end);
	int actualK = getK(forest,N,M,start,end);
	if(K == actualK){
		printf("Impressed\n");
	}else{
		printf("Oops!\n");
	}
	// printf("\nK = %d",actualK);
	return;
}

int main(){
	char forest[200][200];
	int T,N,M,K;
	scanf("%d",&T);
	while(T>0){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			scanf("%s",forest[i]);
		}
		// for(int i=0;i<N;i++){
		// 	printf("%s\n",forest[i] );
		// }
		scanf("%d",&K);
		giveVerdict(forest,N,M,K);
		T--;
	}
	return 0;
}