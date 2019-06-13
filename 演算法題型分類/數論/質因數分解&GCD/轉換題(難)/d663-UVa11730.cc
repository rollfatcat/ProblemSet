// 有趣的題目, 須觀察展開Tree的規律,才能得到Queue解的特性
// BFS + Branch&Bound
// 解法：http://kos74185foracm.blogspot.com/2013/07/11730-number-transformation.html
// 另一種做法是只展開一次但是紀錄拜訪的點對(起點到終點)的距離 <= 我猜0ms的做法是這樣的,會耗費較多的記憶體
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int prime[11]={2,3,5,7,11,13,17,19,23,29,31};
int main(){
  vector<int> num[1001];
  for(int i=0;i<11;i++)
    for(int j=(prime[i]<<1); j<=1000; j+=prime[i])
      num[j].push_back(prime[i]);
  for(int i=32;i<=1000;i++)
    if(num[i].size()==0)
      for(int j=(i<<1); j<=1000; j+=i)
        num[j].push_back(i);

  for(int S, T, caseNum=1; cin>>S>>T and S; caseNum++){
    // 題目沒有保證S<=T
    if(S>T){ cout<<"Case "<<caseNum<<": -1"<<endl;  continue; }
    if(num[T].size()==0){ cout<<"Case "<<caseNum<<": "<<((S==T)?0:-1)<<endl;  continue; }
    int depth[T+1];
    memset(depth,0xff,sizeof(depth));
    queue<int> Q;
    Q.push(S); depth[S]=0;
    while(!Q.empty()){
      int now=Q.front();  Q.pop();
      if(now==T){ cout<<"Case "<<caseNum<<": "<<depth[now]<<endl; break; }
      for(int i=0;i<num[now].size();i++){
        int nxt=now+num[now][i];
        if(nxt<=T){
          if(depth[nxt]==-1)
            depth[nxt]=depth[now]+1, Q.push(nxt);
        }
        else break;
      }
    }
    if(depth[T]==-1) cout<<"Case "<<caseNum<<": -1"<<endl;
  }
}
/*
Input
1 1000
6 1000
10 1000
15 1000
30 1000
100 1000
1 1
0 0

Output
Case 1: -1
Case 2: 25
Case 3: 23
Case 4: 22
Case 5: 20
Case 6: 16
Case 7: 0
*/