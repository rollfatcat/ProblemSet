// 加速讀取(測資的數字間有若干個空白和換行)
// 練習使用 STL 的 lower_bound/upper_bound
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
const int base=1e9;
int num[MAXN];
inline void scanInt(int &x){
  char c;
  while((c=getchar())=='\n');
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){
  int N, Q;
  scanInt(N),
  scanInt(Q);
  for(int i=0;i<N;i++)
    scanInt(num[i]), num[i]+=base;
  // call Qsort 排序 1e6 個太耗時換成 RaidxSort 試試(時間還是0.8s)
  sort(num,num+N);
  // RadixSort
  /*
  for(int t=1,base=1; t<=10; t++,base*=10){
  vector<int> bucket[10];
  for(int i=0;i<N;i++)
    bucket[(num[i]/base)%10].push_back(num[i]);
  int idx=0;
  for(int i=0;i<=9;i++)
    for(int j=0;j<bucket[i].size();j++)
      num[idx++]=bucket[i][j];
  }
  */
  //
  for(int L,R,cnt;Q--;){
    scanInt(L),
    scanInt(R),
    cnt=upper_bound(num,num+N,R+base)-lower_bound(num,num+N,L+base);
    if(cnt) printf("%d\n",cnt);
    else puts("The candies are too short");
  }
}