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

bool isPossible(int *a,int *b,int N,int K){
    quick_sort(a,N);
    quick_sort(b,N);

    for(int i=0;i<N;i++){
        if((a[i] + b[N-1-i]) < K){
            return false;
        }
    }
    return true;
}
int main(){
    int T,N,K;
    scanf("%d",&T);
    int a[1000];
    int b[1000];
    while(T>0){
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;i++){
            scanf("%d",a+i);
        }
        for(int i=0;i<N;i++){
            scanf("%d",b+i);
        }

        if(isPossible(a,b,N,K)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        T--;
    }
}