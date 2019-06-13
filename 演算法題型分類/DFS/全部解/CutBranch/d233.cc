// 作法：http://rs-vb.blogspot.com/2014/09/zj97-d230d233-1-d227.html <- 這個剪枝的估價是有問題的
// DFS+剪枝(90%，#testCase7(10%) TLE)
/* 需要先對連通狀態的點做分組 -> 方便剪枝
 * 針對各組作DFS展開，並且一邊展開一邊作剪枝
 */
#include<bits/stdc++.h>
using namespace std;
#define maxN 1<<8

int N, cnt, maxCnt;
int group_num; // 分組數量
int num_to_group[maxN]; // 映射表：節點號碼對應組別號碼
int rem[maxN]; // 同一組裡，包含這個號碼以及後面的部分，最好的情況可以選擇總數得÷2
bool use[maxN]={}; // 紀錄某個節點有沒有被選取
vector<int> e[maxN], one_group;
vector< vector<int> > member;

// DFS拜訪所有連通狀態的點並且標記映射表和成員表單
void DFS_Group(int now){
  num_to_group[now]=group_num;
  one_group.push_back(now);
  for(int i=0;i<e[now].size();i++)
    if(num_to_group[ e[now][i] ]==-1)
      DFS_Group(e[now][i]);
}
//
void DFS_Map(int id,int now,int cnt){
  maxCnt=max(maxCnt,cnt);
  // 這組的member已經沒了
  if(now>=member[id].size()) return;
  int num=member[id][now], idx=0;
  // 剪枝：已經選取的點＋這個點(假設可以選取)＋剩餘未選取的節點總數÷2，仍然比紀錄差時就不展開
  if((1+cnt+rem[num]/2)<maxCnt) return;
  for(; idx<e[num].size() and !use[e[num][idx]]; idx++);
  // 選擇這個節點，前提是：和這個點連通的其他點沒被選取
  if(idx==e[num].size())
    use[num]=1,
    DFS_Map(id,now+1,cnt+1),
    use[num]=0;
  // 不選這個節點
  DFS_Map(id,now+1,cnt);
}
int main(){
  scanf("%d",&N);
  for(int u,v; scanf("%d",&u) and u;)
    scanf("%d",&v),
    e[u].push_back(v),
    e[v].push_back(u);
  // 分組
  memset(num_to_group,0xff,sizeof(num_to_group));
  group_num=0;
  for(int i=1;i<=N;i++)
    if(num_to_group[i]==-1){
      one_group.clear();
      DFS_Group(i);
      sort(one_group.begin(),one_group.end());
      member.push_back(one_group);
      group_num++;
    }
  // 計算各組號碼後面的剩餘個數
  for(int i=0;i<member.size();i++)
    for(int j=0;j<member[i].size();j++)
      rem[ member[i][j] ]=member[i].size()-j;
  // 針對各組展開DFS
  vector<bool> group_vis(member.size(),0);
  int sumCnt=0;
  for(int i=1;i<=N;i++)
    if(!group_vis[ num_to_group[i] ]){
      group_vis[num_to_group[i]]=1, maxCnt=0;
      DFS_Map(num_to_group[i],0,0);
      sumCnt+=maxCnt;
    }
  printf("%d\n",sumCnt);
}