// 01背包和可分割物品的混合題型
// 分開處理後再加總計算
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct nn{ int w, v; double e; };
long DPint[10001]={};
double DPflt[10001]={};
bool compare(nn a,nn b){ return a.e>b.e; }
inline void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
int main(){
  int n, T, w, v, t;
  vector<nn> keep;
  scanInt(n), scanInt(T);
  while(n--){
    scanInt(w), scanInt(v), scanInt(t);
    if(t==1)
      keep.push_back( {w,v,(double)v/w} );
    else // 01背包
      for(int i=T;i>=w;i--)
        DPint[i]=max(DPint[i],DPint[i-w]+v);
  }
  sort(keep.begin(),keep.end(),compare);
  int now=1;
  for(int idx=0,base=0; now<=T and idx<keep.size(); now++){
    if(now>keep[idx].w+base)
      base+=keep[idx].w, idx++;
    DPflt[now]=DPflt[now-1]+keep[idx].e;
  }
  for(;now<=T;now++)
    DPflt[now]=DPflt[now-1];
  double maxV=0.0;
  for(int i=0;i<=T;i++)
    maxV=max(maxV,DPint[i]+DPflt[T-i]);
  printf("%.0lf",maxV);
}
/*
4 10
5 15 2
5 14 2
4 13 2
8 17 1
*/