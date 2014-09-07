#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct suffix{
	int index;
	int rank[2];
};
typedef struct suffix suffix;
int cmp(suffix a,suffix b){
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}


void buildSuffixArray(const char *a,int *s){
	int n = strlen(a);
	suffix suffixes[n];
	for(int i=0;i<n;i++){
		suffixes[i].index = i;
		suffixes[i].rank[0] = a[i] - 'a';
		suffixes[i].rank[1] = ((i+1)<n) ? (a[i+1]-'a'):-1;
	}
	std::sort(suffixes,suffixes+n,cmp);
	int ind[n];
	for(int k=4;k<2*n;k = k*2){
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for(int i=1;i<n;i++){
			if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}else{
				prev_rank = suffixes[i].rank[0];
				rank++;
				suffixes[i].rank[0] = rank;
			}
			ind[suffixes[i].index] = i;
		}
		int nextIndex;
		for(int i=0;i<n;i++){
			nextIndex = suffixes[i].index + k/2;
			suffixes[i].rank[1] = (nextIndex<n)?(suffixes[ind[nextIndex]].rank[0]):-1;
		}
		std::sort(suffixes,suffixes+n,cmp);
	}
	for(int i=0;i<n;i++){
		s[i] = suffixes[i].index;
	}
	return;
}

void printPrefix(const char *a,int i){
	printf("%s\n", a+i);
	return;
}

int main(){
	const char *a = "bananavhvjvjhvkvjkvkvkjgkjdgfgfdsfafxgcjvk";  // text
	int n = strlen(a);
	int suffixarray[n];
	buildSuffixArray(a,suffixarray);

	for(int i=0;i<n;i++){
		printf("\n");
		printPrefix(a,suffixarray[i]);
	}

	printf("\n");
	return 0;
}