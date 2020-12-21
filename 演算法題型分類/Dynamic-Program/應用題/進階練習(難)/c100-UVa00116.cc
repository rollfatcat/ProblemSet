// Debug很麻煩...
// BackTrack->BottomUp 由終點回推到起點,因為題目要求字典序相等時要保留小的
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int w[11][101]={0};
int map[11][101], to[11][101];
int pos[11][3];

int main(){
  while(cin>>m>>n){
    // 讀取輸入----------
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>w[i][j];
    // 題目要求字典序，所以先排序選擇的優先順序----------
    for(int i=0;i<m;i++)
      pos[i][0]=(i-1+m)%m,
      pos[i][1]=i,
      pos[i][2]=(i+1)%m;
    sort(pos[0],pos[0]+3);
    sort(pos[m-1],pos[m-1]+3);

    // 邊界設定----------
    for(int i=0;i<m;i++)
      map[i][n-1]=w[i][n-1];
    // 從最後一個Column 做 BackTracking
    for(int i=n-2;i>=0;i--)
      for(int j=0;j<m;j++){
        map[j][i]=map[pos[j][0]][i+1],
        to[j][i]=pos[j][0];
        if(map[j][i]>map[pos[j][1]][i+1])
          map[j][i]=map[pos[j][1]][i+1],
          to[j][i]=pos[j][1];
        if(map[j][i]>map[pos[j][2]][i+1])
          map[j][i]=map[pos[j][2]][i+1],
          to[j][i]=pos[j][2];
        map[j][i]+=w[j][i];
      }
    // 挑選加總後最小成本的起點(column=0)
    int st=0;
    for(int i=1;i<m;i++)
      if(map[st][0]>map[i][0])
        st=i;
    cout<<st+1;
    int minNum=map[st][0];
    for(int i=0;i<n-1; st=to[st][i],i++)
      cout<<' '<<to[st][i]+1;
    cout<<endl<<minNum<<endl;
  }
}