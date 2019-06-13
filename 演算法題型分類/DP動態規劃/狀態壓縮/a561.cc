// 給定一個 n 小於1e7，每個非負數字不重複且都小於一千萬，求其排序後的結果。
// 用一個位元代表某個數字是否出現過
// 狀態壓縮的概念＋位元運算( O(1)找到下一個"1"的位置 ) => 0.6s

#include<stdio.h>
using namespace std;

const int MAXN=(10000000>>5)+1; // MAXN=312501
int BitNum[MAXN]={};

inline int lowbit(int x){ return x&-x; }
int main(){

  int N, x;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&x),
    BitNum[x>>5]|=1<<(x&31);
  // __builtin_ctz(x) : 返回後面的0個數： 7368(1110011001000)返回3
  int idx=0;
  for(int i=0;i<MAXN;i++)
    for(int buff=BitNum[i]; buff; idx++,buff^=lowbit(buff))
      if(idx%10==0)
        printf("%d ",(i<<5)+__builtin_ctz(buff));
  putchar('\n');
}