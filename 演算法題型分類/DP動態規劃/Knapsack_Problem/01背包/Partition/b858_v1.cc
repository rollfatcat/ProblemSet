// 問題為分堆問題(01背包的變形應用)，目標是使兩堆的差值最小化前提下輸出兩堆中數值較大者
// 直接做分堆，但是考慮範圍達1e7(Ｎ≤ 1000,Ｋ≤ 20000)和 ZJ-b568 比對
// 模仿 ZJ-b568 用陣列＋vector 實作01背包的一維陣列更新方式，但時間還是0.2s

#include<bits/stdc++.h>
using namespace std;

bool IsIn[10000001];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline long SQR(long x){ return x*x; }
int main(){
  int T, N, num[1000];
  scanInt(T);
  while(T--){
    scanInt(N);
    int allS=0;
    for(int i=0;i<N;i++)
      scanInt(num[i]),
      allS+=num[i];
    int halfS=allS>>1;
    vector<int> Rec;
    Rec.push_back(0);
    memset(IsIn,0,sizeof(IsIn));
    for(int i=0;i<N;i++)
      for(int j=Rec.size()-1;j>=0;j--){
        int v=Rec[j]+num[i];
        if(v<=halfS and IsIn[v]==0)
          IsIn[v]=1, Rec.push_back(v);
      }
    int maxv=halfS;
    for(;IsIn[maxv]==0;maxv--);
    printf("%ld\n",SQR(allS-maxv)+SQR(maxv));
  }
}