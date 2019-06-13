// 測資範圍：3 ≤ M,N,K ≤ 50，固定挖除的高度是3公分，但整體高度最少是3公分

#include<iostream>
#include<cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, R, C, H, x;
  cin>>caseT;
  while(caseT--){
    cin>>R>>C>>H;
    bool black[R][C];
    memset(black,0,sizeof(black));
    int cnt=0;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++){
        cin>>x;
        if(x){
          if(black[i][j]==0)  black[i][j]=1, cnt++;
          if(i and black[i-1][j]==0) black[i-1][j]=1, cnt++;
          if(j and black[i][j-1]==0) black[i][j-1]=1, cnt++;
          if(i<R-1 and black[i+1][j]==0) black[i+1][j]=1, cnt++;
          if(j<C-1 and black[i][j+1]==0) black[i][j+1]=1, cnt++;
        }
      }
    cout<<(R*C*H-cnt*3)<<'\n';
  }
}
/* 450-38*3=450-114
9 10 5
0 1 1 1 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0
1 1 1 1 1 0 0 0 1 1
0 1 1 1 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
*/