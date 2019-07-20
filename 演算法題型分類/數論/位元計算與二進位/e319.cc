/* M=3 的 c489，c489是這題的加強版，M可以是任意數字 */
#include<stdio.h>
using namespace std;

// 4 ≤ N< 4e6，每個整數皆在int範圍以內
const int MAXN=4e6;
int bit_cnt[32]={};

inline void scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
    int N, x;
    scanInt(N);
    while(N--){
        scanInt(x);
        for(int i=0;x>0;i++,x>>=1)
            if(x&1)
                bit_cnt[i]++;
    }
    int ans=0;
    for(int i=0;i<32;i++)
        if(bit_cnt[i]%3)
            ans|=1<<i;
    printf("%d\n",ans);
}