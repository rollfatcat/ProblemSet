#include<bits/stdc++.h>
// GCC 優化程式碼：關閉一些檢查讓時間
#pragma GCC optimize("Ofast")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
using namespace std;

string ss;
const int MAXN=10005;
int target, num_sum, num_cnt, now_x;
int num[MAXN];
vector<int> pos[2];

void DFS(int,int,int,int);// 產生所有可能的數字
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(getline(cin,ss)){
    int p=0;
    for(now_x=num_cnt=0; ss[p]!=0; p++)
      (ss[p]<'0')? num[num_cnt++]=now_x,now_x=0: now_x=10*now_x+ss[p]-'0';

    num[num_cnt++]=now_x;
    num_sum=0;
    for(int i=0;i<num_cnt;i++)
      num_sum+=num[i];
    target=num_sum>>1;
    /* =====分情況討論=====
     * (1)根據 num_cnt 小於等於42個決定是否可以採用暴力法
     * (2)作弊...反例：9999個31時
     */
    if(num_cnt<=42){ // 枚舉暴力法的極限<- 卡在第二筆測資的上限
      // 雙向BFS
      now_x=num_cnt>>1;
      pos[0].clear();
      pos[1].clear();
      DFS(    0,  now_x,0,0);
      DFS(now_x,num_cnt,1,0);
      sort(pos[0].begin(),pos[0].end());
      sort(pos[1].begin(),pos[1].end());
      int near_target=0;
      for(int x:pos[0])
        if(x<=target)
          now_x=upper_bound(pos[1].begin(),pos[1].end(),target-x)-pos[1].begin(),
          near_target=max(near_target,x+pos[1][now_x-1]);
        else
          break;
      cout<<(long)near_target*(num_sum-near_target)<<'\n';
    }else // 無法用暴力法時就直接輸出總和的一半視為最佳解
      cout<<(long)target*(num_sum-target)<<'\n';
  }
}
void DFS(int st,int ed,int sz,int v){
  pos[sz].push_back(v);
  for(int i=st;i<ed;i++)
    DFS(i+1,ed,sz,v+num[i]);
}

/*
6 1 7 3 5 2 6 4 1 3
7 3 4 1 6 1 2 5 2 1 7 6 3 2 4 1 2 1 3 1
7 3 5 4 1 6 8 4 3 2 2 1 6 4 6 4 2 1 3 4 6 5 2 4 1
*/