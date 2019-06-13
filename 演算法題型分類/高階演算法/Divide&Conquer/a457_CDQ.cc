// 逆數對用 MergeSort 解 => CDQ想法

#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000;
int K, M;
struct PAIR{
  int x,y;
  bool operator<(const PAIR &rhs)const{ return(x==rhs.x)?(y>rhs.y):(x>rhs.x); }
}org[MAXN], cpy[MAXN];

long CDQ(int nL,int nR,long res=0){
  if(nL>=nR) return 0;
  // Divide 確保兩個子序列都維持單調棧
  int nM=(nL+nR)>>1;
  res+=CDQ(  nL,nM);
  res+=CDQ(nM+1,nR);
  // 合併兩個子序列，累計逆數對
  for(int i=nL,j=nM+1,k=nL;i<=nM or j<=nR; )
    if(j>nR or i<=nM and org[i].y>=org[j].y )
      cpy[k++]=org[i++];
    else
      cpy[k++]=org[j++],
      res+=nM-i+1;
  for(int i=nL;i<=nR;i++)
    org[i]=cpy[i];
  return res;
}

int main(){
  // 讀取輸入
  scanf("%d %d",&K,&M);
  for(int i=0;i<K;i++)
    scanf("%d",&org[i].x);
  for(int i=0;i<K;i++)
    scanf("%d",&org[i].y);
  // 排序，保證第一維度是由大到小(若第一維度相同時第二維度由大到小)
  sort(org,org+K);
  printf("%ld\n",CDQ(0,K-1));
}
/*
5 10
3 7 5 5 8
4 6 7 5 8
5 10
3 7 5 5 8
4 6 7 7 7
*/