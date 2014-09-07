#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>


void printClosest(int *a,int n){
	std::sort(a,a+n);
	// for(int i=0;i<n;i++){
	// 	printf("%d ",a[i] );
	// }
	int mindiff = abs(a[0] - a[1]);

	int diff;
	for(int i=2;i<n;i++){
		diff = abs(a[i] - a[i-1]);
		if(diff < mindiff){
			mindiff = diff;
		}
	}
	for(int i=1;i<n;i++){
		if(mindiff == abs(a[i] - a[i-1])){
			printf("%d %d ",a[i-1],a[i]);
		}
	}

	return;
}


int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	printClosest(a,n);

	// printf("\n");
	return 0;
}