// Non-Priorty Queue
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MaxN 101

struct Node{ int n, t;} now, nxt;
int main(){
  int T, N, E, t, M;
  int a, b, c;

  cin>>T;
  while(T--){
    cin>>N>>E>>t>>M;
    vector<Node> map[N+1];
    // a指向b 代表 房間a通向房間b(但反向不一定)
    // 作法是從安全房間反追會從哪邊來,所以反著存
    while(M--)
      cin>>a>>b>>c, map[b].push_back({a,c});

    int shortT[N+1];
    fill(shortT,shortT+N+1,0x7fffffff);
    queue<Node> Q;
    Q.push({E,0});
    int safe=0;
    while(!Q.empty()){
      now=Q.front();  Q.pop();
      shortT[now.n]=now.t;
      safe++;
      // 有和這個點相連的其他點
      for(int i=0;i<map[now.n].size();i++){
        int nxt_t=now.t+map[now.n][i].t;
        //時限內和『可更新』的點才放到Queue內
        if( shortT[map[now.n][i].n]>nxt_t and nxt_t<=t )
          Q.push( {map[now.n][i].n, nxt_t} );
      }
    }
    cout<<safe<<endl;
    if(T) cout<<endl;
  }
}