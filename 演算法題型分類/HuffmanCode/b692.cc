// 題目描述的儀式類似 HuffmanCode 的方式只是加法變成減法，但做法完全不同(可以放一起練習)
// 輸入測資的個數高達1e6個代表不可能透過剪枝的暴力法求得最大值 => 觀察規律
/* 分情況討論做法 => 全部都是正數/全部都是負數/有正有負
 * (1)先把所有Ai按數值大小排序；
 * (2)對負值Ai進行被減運算(即充當D角色)，數量最多為N-1個；
 * (3)如果沒有負值Ai，則把正值最小的Ai進行被減運算，以確保運算式中至少包含一個減號；
 * (4)餘下的Ai均進行加法運算。
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){
  char c=getchar();
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){
  int N, num[1000000];

  scanInt(N);
  for(int i=0;i<N;i++)
    scanInt(num[i]);
  sort(num,num+N);
  // 分情況討論
  long sum=0;
  if(num[N-1]<0){
    sum=num[N-1];
    for(int i=0;i<N-1;i++)
      sum-=num[i];
  }else if(num[0]>=0){
    sum=-num[0];
    for(int i=1;i<N;i++)
      sum+=num[i];
  }else{
    for(int i=0;i<N;i++)
      sum+=((num[i]<0)?-num[i]:num[i]);
  }
  printf("%ld\n",sum);
}