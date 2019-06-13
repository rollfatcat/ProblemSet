#include<bits/stdc++.h>
using namespace std;

#define MaxN 100000
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

  int i=0, j=0, total=0;
  while(i<alen and j<blen){
    while(i<alen and A[i].dim<B[j].dim) i++;
    if(A[i].dim==B[j].dim)  total+=(A[i++].val*B[j++].val);
    while(j<blen and A[i].dim>B[j].dim) j++;
    if(A[i].dim==B[j].dim)  total+=(A[i++].val*B[j++].val);
  }
  cout<<total<<'\n';
}
/*
1:5 1000:55 1000000:555 0:0
10:6 10000:66 100000:666 1000000:2 0:0
*/