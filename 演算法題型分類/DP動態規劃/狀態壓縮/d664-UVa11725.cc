// 狀態壓縮的動態規劃
// 每格子有5種選擇=>不塗色+ 4種顏色(5進位表示)
// 先產生橫向的合法狀態, 再拿這一列的狀態和上一列的狀態核對, 也是合法就累加
// 橫向的合法對產生方式會出現TLE，請不要暴力比對而是用DFS找到(詳情參考TIOJ的1908)
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int PreNow[5][3]={{},{2,3,4},{1,3,4},{1,2,4},{1,2,3}};
int R, C, nowR, endC, base=1000000007;
int DP[2][78125]; // 78125=5^7
vector<int>status[2];
bool BitMask[8][8];
void DFS(int col,int pre,int preS){
  if(col==endC){ // 橫向的"合法狀態"已經完成, 再比對垂直向相鄰狀態的"合法性"
    for(int i=0, preR=1-nowR%2; i<status[preR].size();i++){ // 上下層相鄰必須不同顏色(有塗色才算)
      int idx=0;
      for(int n1=preS, n2=status[preR][i]; idx<C and (n1%5!=n2%5 or n1%5==0 or n2%5==0); idx++,n1/=5,n2/=5);
      if(idx==C)  DP[nowR%2][preS]=(DP[nowR%2][preS]+DP[preR][status[preR][i]])%base;
    }
    status[nowR%2].push_back(preS);  return;
  }
  if(BitMask[nowR][col]) //強迫規定這一格不能塗色
    DFS(col+1, 0, 5*preS);
  else if(pre==0){ //前一格沒有塗色代表這格有4種顏色可以選
    DFS(col+1, 1, 5*preS+1);
    DFS(col+1, 2, 5*preS+2);
    DFS(col+1, 3, 5*preS+3);
    DFS(col+1, 4, 5*preS+4);
  } else { //前一格的顏色影響下一格塗色(相鄰必須不同顏色)
    DFS(col+1, PreNow[pre][0], 5*preS+PreNow[pre][0]);
    DFS(col+1, PreNow[pre][1], 5*preS+PreNow[pre][1]);
    DFS(col+1, PreNow[pre][2], 5*preS+PreNow[pre][2]);
  }
}
int main(){
  int T, cnt;

  cin>>T;
  for(int caseNum=1; caseNum<=T; caseNum++){
    cin>>R>>C>>cnt;
    R++, C++; // R/C代表劃幾刀,會產生(R+1)x(C+1)個區域
    memset(BitMask,0,sizeof(BitMask));
    for(int i=0;i<=C;i++) BitMask[0][i]=true;
    for(int i=0;i<=R;i++) BitMask[i][0]=true;
    for(int x, y; cnt--; )
      cin>>x>>y,  BitMask[x][y]=true;

    endC=C+1;
    memset(DP[0],0,sizeof(DP)),
    status[0].clear(),
    status[0].push_back(0),
    DP[0][0]=1; // 初始化時的條件
    for(nowR=1;nowR<=R;nowR++)
      status[nowR%2].clear(),
      memset(DP[nowR%2],0,sizeof(DP[0])),
      DFS(0,0,0);
    cnt=0;
    for(int i=0;i<status[R%2].size();i++)
      cnt=(cnt+DP[R%2][status[R%2][i]])%base;
    cout<<"Case "<<caseNum<<": "<<cnt<<endl;
  }
}
/*
1
1 5 7
1 4
1 5
1 6
2 1
2 2
2 3
2 6
*/