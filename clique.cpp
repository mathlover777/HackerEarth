#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    // \frac{r-1}{r}\cdot\frac{n^2}{2} = \left( 1-\frac{1}{r} \right) \cdot\frac{n^2}{2}. 
int solve(int N,int E){
	double n = N;
	double e = E;

	int trial = ceil( 1.0/(1.0 - (2.0*e/(n*n))));

	// int maxEdge = ceil((1-1/trial)*(n*n/2));
	double maxEdge = (1.0-1.0/(double)trial)*(n*n/2.0);
	printf("MAXEDGE = %lf EDGE = %d trialCliqueSize = %d\n",(double)maxEdge,E,((trial+1)*(trial+2))/2);
	while(maxEdge < E){
		printf("MAXEDGE = %lf EDGE = %d\n",(double)maxEdge,E );
		trial++;
		// maxEdge = ceil((1-(1/trial))*(n*n/2));
		maxEdge = (1.0-(1.0/(double)trial))*(n*n/2.0);
	}

	return trial;
}

int main(){
	int T,N,M;
	scanf("%d",&T);

	while(T>0){
		scanf("%d%d",&N,&M);

		printf("%d\n",solve(N,M) );

		T--;
	}
}