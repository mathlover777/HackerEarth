#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <iostream>
struct icecream{
	int id;
	int cost;
};
typedef struct icecream icecream;

int compare(icecream a,icecream b){
	return a.cost < b.cost ?1:0;
}

void buyIceCream(int m,icecream *c,int n){
	std::sort(c,c+n,compare);

	int i=0,j=n-1;
	int sum;
	while(i<j){
		sum = c[i].cost + c[j].cost;
		if(sum == m){
			break;
		}
		if(sum < m){
			i++;
			continue;
		}
		if(sum > m){
			j--;
			continue;
		}
	}
	// std::cout<<index;
	// printf("value = %d %d\n",c[i].cost,c[j].cost );
	if(c[i].id <c[j].id){
		printf("%d %d\n",c[i].id,c[j].id);
	}else{
		printf("%d %d\n",c[j].id,c[i].id);
	}
	return;
}


int main(){
	int T;
	scanf("%d",&T);
	icecream c[10000];
	int n,m;
	while(T>0){
		scanf("%d%d",&m,&n);
		for(int i=0;i<n;i++){
			scanf("%d",&(c[i].cost));
			c[i].id = i+1;
		}
		buyIceCream(m,c,n);
		T--;
	}
	return 0;
}