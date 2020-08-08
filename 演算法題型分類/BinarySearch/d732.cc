/* 給定Ｎ個嚴格遞增的數字組成的數列和Ｋ次查詢，輸出給定數字在數列中的位置，若不存在輸出０。
 * 解題關鍵：二分搜尋法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxK=1e5;
int N, K;
int num[MaxN];

int BinarySearch(int v){
  for(int L=0, R=N-1, M; L<=R; (num[M]<v)? L=M+1: R=M-1){
    M=L+R>>1;
    if(num[M]==v)
      return M+1;
  }
  return 0;
}
int main(){
  scanf("%d %d\n",&N,&K);
  for(int i=0;i<N;i++)
  	scanf("%d",&num[i]);
  for(int qv;K>0;K--)
    scanf("%d",&qv),
    printf("%d\n",BinarySearch(qv));
}