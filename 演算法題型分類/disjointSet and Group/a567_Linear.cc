// 題目要求最大化收益，且每個工作都是佔一個工作天
/* Greedy : 每個工作都會佔走一天的時間所以就依照收益最高的優先做
 * 每次取出還未排進可行集合內的，接著從它的 deadline 開始向左找，只要可以填進去就填，不行就捨去。
 * 做法類似喬瑟夫模擬問題 : O(n^2)找到下一個有空的天數(89ms)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
struct DATA{
  int deadline, profit;
  bool operator<(const DATA &rhs)const{ return profit>rhs.profit; }
}data[MAXN];
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N,maxDay;scanInt(N);){
    maxDay=0;
    for(int i=0;i<N;i++)
      scanInt(data[i].deadline),
      scanInt(data[i].profit),
      maxDay=max(maxDay,data[i].deadline);
    sort(data,data+N);
    // 觀察第二筆測資可以發現：deadline的時間可能會比測資的數量多
    vector<bool> IsEmpty(maxDay+1,0);
    int sumP=0;
    for(int now,i=0;i<N;i++){
      for(now=data[i].deadline;IsEmpty[now];now--);
      if(now)
        sumP+=data[i].profit, IsEmpty[now]=1;
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