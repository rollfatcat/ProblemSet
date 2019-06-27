/* 題目要算 A＋A^2＋A^3＋A^4＋A^5...＋A^K, MAXK=1e6
 * 需要用到快速幂次和 D&C 的概念
 * A＋A^2＋A^3＋A^4＋A^5...＋A^K，分奇數/偶數討論：
 * K is even, ＝( A＋A^2＋A^3＋...＋A^(K/2) )( I＋A^(K/2) )
 * K is odd , ＝( A＋A^2＋A^3＋...＋A^(K/2) )( I＋A^(K/2) )＋A^K
 * 計算成本：O(Ｎ^3*㏒Ｋ)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXK=1e6;
const int MAXN=40;
int N;
struct MATRIX{
  int num[MAXN][MAXN]={};
} Base[__lg(MAXK)+1], unit;
map<int,MATRIX> memo;

MATRIX matrix_mul(MATRIX a,MATRIX b);
MATRIX matrix_add(MATRIX a,MATRIX b);
MATRIX matrix_pow(int p);
MATRIX CDQ(int);
int main(){
  for(int i=0;i<MAXN;i++)
    unit.num[i][i]=1;
  int K;
  while(scanf("%d %d",&N,&K) and N){
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        scanf("%d",&Base[0].num[i][j]),
        Base[0].num[i][j]%=10;
    // 計算會用到的基底矩陣(2的次方項數)
    for(int t=1;t<=__lg(K);t++)
      for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
          Base[t].num[i][j]=0;
          for(int k=0;k<N;k++)
            Base[t].num[i][j]+=Base[t-1].num[i][k]*Base[t-1].num[k][j];
          Base[t].num[i][j]%=10;
        }
    memo.clear();
    MATRIX ans=CDQ(K);
    for(int i=0;i<N;i++,putchar('\n'))
      for(int j=0;j<N;j++)
        printf("%d ",ans.num[i][j]);
  }
}
MATRIX matrix_mul(MATRIX a,MATRIX b){
  MATRIX res;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      res.num[i][j]=0;
      for(int k=0;k<N;k++)
        res.num[i][j]+=a.num[i][k]*b.num[k][j];
      res.num[i][j]%=10;
    }
  return res;
}
MATRIX matrix_add(MATRIX a,MATRIX b){
  MATRIX res;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      res.num[i][j]=(a.num[i][j]+b.num[i][j])%10;
  return res;
}
MATRIX matrix_pow(int p){
  if(memo.find(p)==memo.end()){
    MATRIX rhs=unit;
    for(int i=0;p>0;p>>=1,i++)
      if(p&1)
        rhs=matrix_mul(Base[i],rhs);
    memo[p]=rhs;
  }
  return memo[p];
}
MATRIX CDQ(int K){
  if(K==1) return Base[0];
  MATRIX res=CDQ(K>>1);
  res=matrix_mul(res,matrix_add( unit,matrix_pow(K>>1) ));
  if(K&1)
    res=matrix_add(res,matrix_pow(K));
  return res;
}
/*
4 15
1 2 5 9
8 5 6 7
3 4 8 9
1 3 4 6
===
8 0 9 4
3 8 9 9
9 5 1 6
0 7 4 5
*/