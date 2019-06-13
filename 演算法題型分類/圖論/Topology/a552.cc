// 題目要求輸出最小的字典序 => DFS由號碼小的開始拜訪
// vector建立關係圖，只有當目前點指向的點都被選走後才可以選他 => 拓墣排序的概念
#include<iostream>
#include<vector>
using namespace std;

int n, bag[100];
bool use[100], hasAns;
vector<int> e[100];
void DFS(int now){
  if(now==n){
    for(int i=0;i<n;i++)
      cout<<bag[i]<<' ';
    cout<<endl;
    hasAns=true;
    return;
  }
  for(int i=0;i<n;i++)
    if(!use[i]){
      int idx;
      for(idx=0;idx<e[i].size() and use[e[i][idx]];idx++);
      if(idx==e[i].size()){
        use[i]=1,
        bag[now]=i;
        DFS(now+1);
        if(hasAns) return;
        use[i]=0;
      }
    }
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int m; cin>>n>>m; ){
    for(int i=0;i<n;i++)
      e[i].clear(), use[i]=0;
    for(int a,b; m--; )
      cin>>a>>b, e[b].push_back(a);
    hasAns=0;
    DFS(0);
  }
}