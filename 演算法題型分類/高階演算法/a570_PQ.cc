// 在時段不能重複的情況下最大化收益 => 掃描線實作
// 搭配 PriorityQueue 的使用( compare是可以覆蓋掉原先宣告在struct的方式 )
// 輸入範圍落在 N=(1,3000), 1 ≦ st < ed ≦ 1e6, val=(1,1e5) => 不可能用 BruteForce-DFS
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1323403143
/* 使用一個掃描線，從左掃到右，當掃描線位置在 ti 時，維護一個前面 prev 的最佳值，
 * 當遇到一個活動的 si 時，給定 prev = max(pred, vi+pred) 當 ti = ei 時。
 * 整體效率 O(n㏒n)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3000;
struct LINE{
  int st, ed, val;
  bool operator<(const LINE &rhs)const{ return st<rhs.st; }
}PQST[MAXN];
struct compare{ bool operator()(LINE a,LINE b){ return a.ed>b.ed; } };

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N;scanInt(N);){
    for(int i=0;i<N;i++)
      scanInt(PQST[i].st),
      scanInt(PQST[i].ed),
      scanInt(PQST[i].val);
    sort(PQST,PQST+N);
    priority_queue<LINE,vector<LINE>,compare> PQED;
    int prev=0;
    for(int idx=0;idx<N;idx++){
      // 選擇線段右端點不和現在這個線段左端點覆蓋的集合中，收益最高者累加到現在這個線段上
      // 掃描線的做法類似 a449 的烏龜王國公車，只是 DP 儲存的最佳狀態直接存在該線段的價值上
      // 烏龜王國公車那題的 DP 是O(n^2)，而這題因為掃描線的特性可以透過 PriorityQueue 實現加速
      // PQED 集合儲存上一個線段＋上個線段更新時沒處理到的部分
      while(PQED.empty()==0 and PQED.top().ed<=PQST[idx].st)
        prev=max(prev,PQED.top().val),
        PQED.pop();
      PQST[idx].val+=prev;
      PQED.push(PQST[idx]);
    }
    for(;PQED.empty()==0;PQED.pop())
      prev=max(prev,PQED.top().val);
    printf("%d\n",prev);
  }
}
/*
4
1 3 5
2 5 6
4 7 3
6 9 4
2
1 2 3
2 3 6
*/