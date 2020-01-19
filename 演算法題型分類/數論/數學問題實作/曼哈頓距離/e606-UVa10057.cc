/* 求下列的最小值 |a1x - x1|+|a2x - x2|+... +|anx - xn|……
 * 從題目可以知道要求『曼哈頓』距離的最小化＋題目給定的『無號數字』和範圍
 * CountSort＋中位數(計算時號碼從1開始)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000000;
const int MaxNumber=65536; // 題目提到：無號整數＝0 ≦ Xi < 65536 
int cnt[MaxNumber];
int main(){
    int N, bound, idx, sum_cnt, x;
    while(scanf("%d",&N)!=EOF){
        fill(cnt,cnt+MaxNumber,0);
        for(int i=0;i<N;i++)
            scanf("%d",&x), cnt[x]++;
        bound=N>>1; 
        sum_cnt=0;
        for(idx=0;idx<MaxNumber;idx++){
            sum_cnt+=cnt[idx];
            if(sum_cnt>bound) 
                break;
        }
        if(N&1){ 
            printf("%d %d %d\n",idx,cnt[idx],1); 
        }else{
            if((sum_cnt-cnt[idx])==bound){
                for(x=idx-1;x>=0 and cnt[x]==0;x--);
                printf("%d %d %d\n",x,cnt[idx]+cnt[x],idx-x+1);
            }else
                printf("%d %d %d\n",idx,cnt[idx],1);
        }
    }
}