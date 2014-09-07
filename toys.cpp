#include <stdio.h>
#include <stdlib.h>




void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}
int getMaxToyCount(int *prices,int n,int k){
	quick_sort(prices,n);
	int count = 0;
	int remaining = k;
	for(int i=0;i<n;i++){
		if(remaining == 0){
			break;
		}
		if(prices[i] <= remaining){
			count++;
			remaining = remaining - prices[i];
		}
	}
	return count;
}

int main() {
    int n, k, i, count;
    scanf("%d%d", &n, &k);
    int *prices = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        scanf("%d", &prices[i]);
    }
     
   
    int answer = 0;
    // Compute the answer
    answer = getMaxToyCount(prices,n,k);
    printf("%d\n", answer);
    free(prices);
    return 0;
}
 
// int main () {
//     int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
//     int n = sizeof a / sizeof a[0];
//     quick_sort(a, n);
//     for(int i=0;i<n;i++){
//     	printf(" %d ",a[i] );
//     }
//     printf("\n");
//     return 0;
// }