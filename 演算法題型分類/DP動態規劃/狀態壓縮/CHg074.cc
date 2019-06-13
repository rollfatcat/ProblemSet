// 狀態壓縮的動態規劃
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int PreNow[3][2]={{1,2},{0,2},{0,1}};
int H, W, len;
long long int DP[2][96]; //只存有效的狀態做DP
vector<int> status, Link[96];

void DFS(int col,int pre, int preS){
  if(col==W){ status.push_back(preS);  return; }
  DFS(col+1, PreNow[pre][0], 3*preS+PreNow[pre][0]);
  DFS(col+1, PreNow[pre][1], 3*preS+PreNow[pre][1]);
}
int main(){
  int caseNum, C;
  for(cin>>caseNum; caseNum--; ){
    cin>>H>>W>>C;
    if(C<3){ cout<<( (C==1)?0:2 )<<endl; continue; }
    status.clear();
    // 產生所有不連續0/1/2的狀態
    for(int i=0;i<3;i++)
      DFS(1,i,i);
    len=status.size();
    memset(DP,0,sizeof(DP));
    for(int i=0;i<len;i++)
      Link[i].clear(), DP[0][i]=1;
    // ith Row 的狀態關係只和 i-1th Row有關而已,做配對
    for(int i=0;i<len;i++)
      for(int j=i+1;j<len;j++){
        int idx=0;
        for(int x=status[i], y=status[j]; idx<W and x%3!=y%3; idx++, x/=3, y/=3);
        if(idx==W)  Link[i].push_back(j), Link[j].push_back(i);
      }
    bool now=0;
    for(int i=1;i<H;i++){
      now=!now;
      memset(DP[now],0,sizeof(DP[0]));
      for(int j=0;j<len;j++)
        for(int k=0;k<Link[j].size();k++)
          DP[now][j]+=DP[!now][ Link[j][k] ];
    }
    long long int sum=0;
    for(int i=0;i<len;i++)
      sum+=DP[now][i];
    cout<<sum<<endl;
  }
}