// 原先第一眼以為要產生所有可能的差值，但會發現數量太大(100000*99999/2)
// 觀察可以發現Q=500並不多 => 線性搜尋數字差(爬行法，做法類似Queue)
#include<iostream>
#include<algorithm>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, Q, num[100000];
  scanInt(N), scanInt(Q);
  for(int i=0;i<N;i++)
    scanInt(num[i]);
  sort(num,num+N);
  for(int diff;Q--;){
    scanInt(diff);
    bool hasAns=false;
    for(int st=0,ed=1; ed<N;){
      if(num[ed]-num[st]>diff) st++; //差值太大，ed往後移一個
      else if(num[ed]-num[st]<diff) ed++; //差值太小，ed往後移一個
      else{ hasAns=true; break; } // 找到差值，跳開
    }
    if(hasAns)  puts("YES");
    else puts("NO");
  }
}