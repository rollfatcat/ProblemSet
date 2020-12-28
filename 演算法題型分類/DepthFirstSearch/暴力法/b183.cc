// 二分圖最大匹配 -> 匈牙利擴增路徑法
// 演算法說明：https://blog.csdn.net/dark_scope/article/details/8880547
// 以下寫法只是DFS暴力窮舉
#include<bits/stdc++.h>
using namespace std;

int N, M, cnt[6];
map<string,int> table;
struct pp{ short opt1, opt2; }one[30];
bool DFS(int now){ // 暴力DFS嘗試所有的組合
  if(now==M)  return true;
  if( cnt[one[now].opt1] ){
    cnt[one[now].opt1]--;
    if( DFS(now+1) )
      return true;
    cnt[one[now].opt1]++;
  }
  if( cnt[one[now].opt2] ){
    cnt[one[now].opt2]--;
    if( DFS(now+1) )
      return true;
    cnt[one[now].opt2]++;
  }
  return false;
}
int main(){
  table["XXL"]=0, table["XL"]=1, table["L"]=2,
  table["M"]=3,   table["S"]=4,  table["XS"]=5;
  while(cin>>N>>M){
    N/=6;
    string ss1, ss2;
    for(int i=0;i<M;i++)
      cin>>ss1>>ss2,
      one[i].opt1=table[ss1],
      one[i].opt2=table[ss2];
    for(int i=0;i<6;i++)
      cnt[i]=N;
    puts(DFS(0)?"YES":"NO");
  }
}
/*
18 6
L XL
XL L
XXL XL
S XS
M S
M L
6 4
S XL
L S
L XL
L XL
*/