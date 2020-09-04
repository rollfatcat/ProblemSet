/* 給定２個高度稀疏的向量，輸出內積值？
 * 輸入規格：dim:val，當dim=val=0時代表該向量輸入結束，且題目給的dim是嚴格遞增
 * 解題關鍵：Merge
 * 因為維度是嚴格遞增，所以找到兩個維度相同時才需要累加對應的乘積。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
struct Vec{
  int dim, val;
  Vec(int d=0,int v=0):dim(d),val(v){}
} A[MaxN],B[MaxN];
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  char ch;
  int dim, val;
  int alen=0, blen=0;
  while(cin>>dim>>ch>>val and dim and val)
    A[alen++]=Vec(dim,val);
  while(cin>>dim>>ch>>val and dim and val)
    B[blen++]=Vec(dim,val);

  int pA=0, pB=0, total=0;
  while(pA<alen and pB<blen){
    if(A[pA].dim<B[pB].dim)
      pA++;
    else if(A[pA].dim>B[pB].dim)
      pB++;
    else //A[pA].dim==B[pB].dim 
      total+=A[pA++].val*B[pB++].val;

  }
  cout<<total<<'\n';
}