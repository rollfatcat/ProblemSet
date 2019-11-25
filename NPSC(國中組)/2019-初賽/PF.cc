/* 標準動態規劃問題
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000000;
int main(){
    int N, x;
    while(scanf("%d",&N)!=EOF){
        int num[2][3]={}; //  −1e3 ≤ vi ≤ 1e3 且 N=1e6, 最大值不會超過 1e9
        bool now=0, nxt=1;
        for(int i=1;i<=N;i++,nxt=now,now^=1)
            scanf("%d",&x),
            num[nxt][0]=max(num[now][1],num[now][2])+x,
            num[nxt][1]=max(num[now][0],num[now][2])-x,
            num[nxt][2]=max(num[now][0],num[now][1]);
        printf("%d\n",max(max(num[N&1][0],num[N&1][1]),num[N&1][2]));
    }
}
/*
    2
    10 -10
    3
    1 2 3
    7
    4 -6 10 3 -10 -1 5
 */