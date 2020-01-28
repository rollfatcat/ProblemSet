/* (1)後綴和＝前綴和的概念：x1*(x2+x3+...+xN)+x2*(x3+...+xN)+...+xN-1*xN
 * (2)數論：[ (Σx)^2 − Σ(x^2) ]/2
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int org[MaxN];
int main(){
    int N, x;
    while(scanf("%d\n",&N)!=EOF){
        long sum=0, ans=0; 
        for(int i=0;i<N;i++)
            scanf("%d",&org[i]), sum+=org[i];
        for(int i=0;i<N;i++)
            sum-=org[i], ans+=sum*org[i];
        printf("%ld\n",ans);
    }
}