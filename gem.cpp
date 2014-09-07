#include <stdio.h>
#include <stdlib.h>



int main(){
	int n;
	int a[26];
	int atemp[26];
	char e[100];
	for(int i=0;i<26;i++){
		a[i] = 0;
	}
	int index,j;


	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%s",e);
		j = 0;
		for(int k=0;k<26;k++){
			atemp[k] = 0;
		}
		while(e[j]!='\0'){
			index = ((int)e[j]) - 97;
			atemp[index] = 1;
			j++;
		}
		for(int k=0;k<26;k++){
			if(atemp[k]>0){
				a[k]++;
			}
		}
	}
	int count = 0;
	for(int i=0;i<26;i++){
		if(a[i] == n){
			count++;
		}
	}
	printf("%d",count);

	return 0;
}