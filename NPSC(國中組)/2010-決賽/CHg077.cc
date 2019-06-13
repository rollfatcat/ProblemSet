//需要熟悉兩種Tree的走法, 找Childern或是找Root

#include<iostream>
#include<vector>
using namespace std;
#define MaxN 50001

int N, M, K;
vector<int> ToRoot[MaxN],  FromRoot[MaxN];
bool vis[MaxN];
int FindNode(){
  int branch_num, branch, now=1;
  cin>>branch_num;
  for(int i=0;i<branch_num;i++)
    cin>>branch,  now=FromRoot[now][branch-1];
  return now;
}
void DFS(int now){
  if(vis[now])  return;
  vis[now]=true, N++;
  if(ToRoot[now].size()>0) //只有一個parent, 題目沒說但保證是Tree
    DFS(ToRoot[now][0]);
}
int main(){
  int caseNum, n, st, ed;
  int st_node[50001];

  cin>>caseNum;
  while(caseNum--){
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
      ToRoot[i].clear(),  FromRoot[i].clear(), vis[i]=false;
    for(int ed=1;ed<=N;ed++)
      for(cin>>n; n--; )
        cin>>st,  ToRoot[st].push_back(ed), FromRoot[ed].push_back(st);
    for(int i=1;i<=M;i++)
      st_node[i]=FindNode();
    for(N=0;K--;)
      cin>>st,  DFS(st_node[st]);
    cout<<N<<endl;
  }
}