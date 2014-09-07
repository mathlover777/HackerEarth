#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int pairs(vector < int > a,int k) {
	int ans;

	sort(a,a.end());

	return ans;
}

int main(){
	int N,K;
	vector<int> a;
	int temp;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		a.push_back(temp);
		// printf("%d\n",a[i] );
	}
	printf("%d\n",pairs(a,K));
	return 0;
}