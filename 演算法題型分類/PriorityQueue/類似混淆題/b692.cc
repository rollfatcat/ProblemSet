/* 題目描述的儀式類似 HuffmanCode 的方式只是加法變成減法，但做法完全不同(可以放一起練習)
 * 輸入測資的個數高達1e6個代表不可能透過剪枝的暴力法求得最大值 => 觀察規律
 * 分情況討論做法 => 全部都是正數/全部都是負數/有正有負
 * (1)先把所有Ai按數值大小排序；
 * (2)對負值Ai進行被減運算(即充當D角色)，數量最多為N-1個；
 * (3)如果沒有負值Ai，則把正值最小的Ai進行被減運算，以確保運算式中至少包含一個減號；
 * (4)餘下的Ai均進行加法運算。
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){
  char c=getchar_unlocked(); // getchar_unlocked()
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
const int MAXN=1e6;
const int INF=1<<30;
int main(){
  int N, x;
  int num_max=-INF, num_min=INF;
  long sum=0;

  scanInt(N);
  for(int i=0;i<N;i++)
    scanInt(x),
    num_max=max(num_max,x),
    num_min=min(num_min,x),
    sum+=(x>=0)? x: -x;
  // 分情況討論( 判斷全部是正數或是負數只需要紀錄最大/最小的數字即可 )
  if(num_max<=0) sum+=num_max<<1; // 若全部是負數需"加回"最大的負數兩倍
  if(num_min>=0) sum-=num_min<<1; // 若全部是正數需"扣回"最小的正數兩倍
  printf("%ld\n",sum);
}