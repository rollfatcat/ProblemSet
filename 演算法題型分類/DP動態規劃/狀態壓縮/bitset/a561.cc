// 給定一個 n 小於1e7，每個非負數字不重複且都小於一千萬，求其排序後的結果。
// 用一個位元代表某個數字是否出現過
// bitset版本會失去位元計算的優勢(掃過 0~1e7 確認數字是否出現過) 0.7s

#include<stdio.h>
#include<bitset>
using namespace std;
#define MAXN 10000001

bitset<MAXN> shown;
int main(){

  int N, x;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&x),
    shown[x]=1;
  // __builtin_ctz(x) : 返回後面的0個數： 7368(1110011001000)返回3
  int idx=0;
  for(int i=0;i<MAXN;i++)
    if(shown[i]){
      if(idx%10==0)
        printf("%d ",i);
      idx++;
    }
  putchar('\n');
}