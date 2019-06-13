// 偽線段樹(會發現最大狀態是2^31-1，無法宣告這麼大的陣列)
// 應該用BinarySearch算出小於等於號碼 x 的開關個數(號碼大於的不影響)
// 因為題目會一次給齊開關的過程，再問最後一次的結果
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 500000

int num[MaxN], N;
bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int Call_BS(int x){ return upper_bound(num,num+N,x)-num;}
int BS(int x){ //回傳大於x的最小號碼
  if(x>=num[N-1]) return N;
  int l=0;
  for(int r=N-1,m; l<=r; (x>=num[m])?(l=m+1):(r=m-1))
    m=(l+r)>>1;
  return l;
}
int main(){
  int Q;
  while(scanInt(N) and scanInt(Q)){
    for(int i=0;i<N;i++)
      scanInt(num[i]);
    // RadixSort 76ms=>67ms
    vector<int> bucket[10];
    for(int t=1,base=1; t<=10; t++,base*=10){
      for(int i=0;i<=9;i++)
        bucket[i].clear();
      for(int i=0;i<N;i++)
        bucket[(num[i]/base)%10].push_back(num[i]);
      int idx=0;
      for(int i=0;i<=9;i++)
        for(int j=0;j<bucket[i].size();j++)
          num[idx++]=bucket[i][j];
    }
    for(int Qp;Q--;)
      scanInt(Qp), puts((Call_BS(Qp)&1)?"1":"0");
  }
}
/*
10 3
3 1 3 2 3 3 3 3 3 8
3 6 7
*/