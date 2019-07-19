#include<bits/stdc++.h>
using namespace std;

// m ≤ 38, n ≤ 500000
const int MAXN=5e5;
const int MAXM=38;
const int MAXL=1001;

int main(){
    int N, M;
    scanf("%d %d\n",&M,&N);
    
    map<long,int> memo;
    long recS[MAXN];
    long all_status=0;
    char ss[MAXL];
    for(int i=0;i<N;i++){
        long nowS=0;
        for(char p=getchar_unlocked();p!='\n' and p>0;p=getchar_unlocked())
            nowS|=(long)1<<( (p<='Z')? (p-'A') : p-'a'+26 );
        all_status|=nowS,
        recS[i]=nowS;
    }
    long ans_cnt=0, cmpS;
    for(int i=0;i<N;i++){
        cmpS=recS[i]^all_status;
        if(memo.find(cmpS)!=memo.end())
            ans_cnt+=memo[cmpS];
        memo[recS[i]]++;
    }
    printf("%ld\n",ans_cnt);
}