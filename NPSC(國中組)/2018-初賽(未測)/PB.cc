//  2 ≤ N ≤ K ≤ 150000 且 1 ≤ Q ≤ 150000 => 無法做雙層迴圈暴力解
// (猜)解法：對每組做Sort(N㏒N)之後把算過的紀錄在memo
// 若第一次計算則仿造MergeSort的方式計算

#include<bits/stdc++.h>
using namespace std;
#define MAXN 150001

vector<int> group[MAXN];
map<pair<int,int>,int> memo;
long long MergeCount(int a,int b,long long v=0){
  long long Ia=0, Ib=0;
  while(Ia<group[a].size() and Ib<group[b].size())
    if(group[a][Ia]<group[b][Ib])
      v+=group[a][Ia]*(group[b].size()-Ib), Ia++;
    else
      v+=group[b][Ib]*(group[a].size()-Ia), Ib++;
}

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, K, Q, Ta, Tb;
  int cost, ID;
  cin>>N>>K>>Q;
  for(int i=1;i<=K;i++)
    cin>>cost>>ID,
    group[ID].push_back(cost);
  for(int i=1;i<=N;i++)
    sort(group[i].begin(),group[i].end());

  long long sumnv=0;
  while(Q--){
    cin>>Ta>>Tb;
    if(Ta>Tb) swap(Ta,Tb);
    pair query=make_pair(Ta,Tb);
    if(memo.find(query)==memo.end())// 仿造MergeSort(N㏒N)，可能會出問題
      sumnv=MergeCount(Ta,Tb),
      memo[query]=sumnv;
    else // 存取過去的計算結果(㏒K)
      sumnv=memo[query];
    cout<<sumv<<endl;
  }
}
/*
3 5 2
3 1
4 3
2 1
4 2
7 3
1 3
3 2
*/