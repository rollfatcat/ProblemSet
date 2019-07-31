/* 觀察規律可以發現：XOR運算的奇偶性
 * parity＝0(以下稱偶同位)與 parity＝1(以下稱奇同位)
 * 奇同位 ＋ 奇同位 → 偶同位
 * 奇同位 ＋ 偶同位 → 奇同位
 * 偶同位 ＋ 偶同位 → 偶同位
 * 因為每次有「1」在 XOR 後消失是一次消失兩個「1」(因為上式的緣故，且 0 XOR 0＝0 也不會影響最後「1」的數量)
 */
#include<bits/stdc++.h>
using namespace std;

int MAXN=1e5;
inline void scanLong(long &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline bool IsOddXOR(long x,int n=0){
    for(;x;n+=x&1,x>>=1);
    return n&1;
}
int main(){
    int N, IsOdd;
    while(scanf("%d\n",&N)!=EOF){
        int cnt[2]={};
        long x, ans_cnt=0;
        for(int i=0;i<N;i++)
            scanLong(x),
            IsOdd=IsOddXOR(x),
            ans_cnt+=cnt[IsOdd],
            cnt[IsOdd]++;
        printf("%ld\n",ans_cnt);
    }
}