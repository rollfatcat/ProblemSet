// 圖論:有向邊，找到能到達的最多點數但，用DFS走點必須紀錄全部走過的點(時間很吃緊 1s)
// 點最多是50000，但每一個點都只會有一條邊指向另一個點
// 上述只會發生兩種情況：(1)形成環狀結構且環上的點數量都是一樣 (2)不構成環的部分則是由『接合點』反推
// 利用Stack實作紀錄現在展開的路線, 一但發現接合點或是重複於環上的點就停止
#include<iostream>
#include<stack>
using namespace std;
#define MaxN 50001

int cnt[MaxN], to[MaxN];
bool inS[MaxN], vis[MaxN];

int main(){
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T, N;

  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>N;
    for(int i=1,a,b;i<=N;i++)
      cin>>a>>b, to[a]=b, cnt[i]=vis[i]=inS[i]=0;
    int maxCnt=0, maxI=0, now;
    stack<int> S;

    for(int i=1; i<=N; i++){
      if(!cnt[i]){
        for(now=i; !inS[now] and !cnt[now]; now=to[now])
          S.push(now), inS[now]=1;
        if(!cnt[now]){
          stack<int> Q;
          while(S.top()!=now)
            Q.push(S.top()), S.pop();
          int num=Q.size();
          while(!Q.empty())
            cnt[Q.top()]=num, Q.pop();
          cnt[now]=num, S.pop();
        }
        while(!S.empty())
          cnt[S.top()]=cnt[now]+1,  now=S.top(), S.pop();
      }
      if(cnt[i]>maxCnt)
        maxCnt=cnt[i], maxI=i;
    }
    cout<<"Case "<<caseNum<<": "<<maxI<<endl;
  }
}
/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5
*/