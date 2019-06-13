// TLE version 卡在匹配Row間的關係建立
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int len, numS;
vector<int> state;
vector<int> link[46370];
long DP[2][46370]={};
void DFS(int deep,int nowS){ // 產生單個Row的合法狀態(費波那契狀態列：F(22)=46368)
  if(deep==len){ state.push_back(nowS); return; }
  DFS(deep+1,nowS<<1);
  if(!(nowS&1))
    DFS(deep+1,(nowS<<1)|1);
}
void PairLink(){ // 時間都耗在這裡：對所有可能的狀態匹配建圖會TLE
  vector<int> bitmask;
  bitmask.push_back(3),
  bitmask.push_back(7);
  for(int i=3;i<len;i++)
    bitmask.push_back(bitmask.back()<<1);
  bitmask.push_back(3<<(len-2));

  for(int i=0;i<state.size();i++)
    for(int j=i+1;j<state.size();j++){
      int nowS=state[i];
      for(int pos; nowS>0; nowS^=pos){
        pos=nowS&-nowS;
        if(state[j]&bitmask[__lg(pos)])
          break;
      }
      if(nowS==0)
        link[i].push_back(j), link[j].push_back(i);
    }
}
int main(){
  cin>>len;
  long map[len][len];
  for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
      cin>>map[i][j];

  DFS(0,0);  // 產生單個Row的合法狀態
  cout<<"end status complete."<<endl;
  PairLink();// 建立Row之間合法的連結關係
  cout<<"end link complete."<<endl;
  for(int i=0;i<state.size();i++)
    for(int nowS=state[i],pos; nowS; nowS^=pos)
      pos=nowS&-nowS, DP[0][i]+=map[0][__lg(pos)];
  for(int Row=1;Row<len;Row++){
    bool now=Row&1, pre=now^1;
    memset(DP[now],0,sizeof(DP[0]));
    for(int i=0;i<state.size();i++){
      for(int j=0;j<link[i].size();j++)
        DP[now][i]=max(DP[now][i],DP[pre][ link[i][j] ]);
      // 把這個Row的狀態和對應的位置上分數相加
      for(int nowS=state[i],pos; nowS; nowS^=pos)
        pos=nowS&-nowS, DP[now][i]+=map[Row][__lg(pos)];
    }
  }
  //
  long maxDP=0;
  for(int i=0;i<state.size();i++)
    maxDP=max(maxDP,DP[(len&1)^1][i]);
  cout<<maxDP<<endl;
}
/*
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
*/