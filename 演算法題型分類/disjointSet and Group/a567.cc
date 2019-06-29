// 先講線性搜尋的做法再說利用 Disjoint-Set 來加速至 O(n㏒n) ：25ms
/* Greedy : 每個工作都會佔走一天的時間所以就依照收益最高的優先做
 * 透過 Disjoint-set 來加速至 O(n㏒n)，remDay[i] 來記錄 deadline=i 時，可填的時間區間。
 * 每次填入後，代表此可行區間又少一個可填的，所以將它和上一個天數的區間合併
 * (將 remDay[i] 指向找到有空的那天，永遠都是大數指向小數(有空的天數一定比較小))。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
int remDay[MAXN]={};
struct DATA{
  int deadline, profit;
  bool operator<(const DATA &rhs)const{ return profit>rhs.profit; }
}data[MAXN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int FindDay(int now){ return (remDay[now]==now)? now: remDay[now]=FindDay(remDay[now]); }
inline void Union(int a,int b){ remDay[ FindDay(b) ]=FindDay(a); }
int main(){
  for(int N,maxDay;scanInt(N);){
    maxDay=0;
    for(int i=0;i<N;i++)
      scanInt(data[i].deadline),
      scanInt(data[i].profit),
      maxDay=max(maxDay,data[i].deadline);
    sort(data,data+N);
    // 觀察第二筆測資可以發現：deadline的時間可能會比測資的數量多
    for(int i=0;i<=maxDay;i++)
      remDay[i]=i;
    int sumP=0;
    for(int i=0;i<N;i++){
      int empty=FindDay( data[i].deadline );
      if(empty)
        sumP+=data[i].profit,
        Union(remDay[data[i].deadline]-1,data[i].deadline);
    }
    printf("%d\n",sumP);
  }
}
/*
6
2 5
3 6
4 4
4 2
5 3
5 1
8
7 1
7 1
7 1
10 1
11 1
9 1
10 1
11 1
*/