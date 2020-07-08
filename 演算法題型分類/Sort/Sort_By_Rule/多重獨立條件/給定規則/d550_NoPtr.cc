/* N^2 的排序方法( 80%AC+ 20%TLE )
 * 強制使用 N㏒N 的Sort(0.6s/8MB)
 */
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxR 10000
#define MaxC 200

int num[MaxR][MaxC];
int team[MaxR];
int R, C;
bool ChangeTeam(int a,int b){
  for(int i=0;i<C and num[a][i]==num[b][i];i++);
    if(num[a][i]!=num[b][i])
      return num[a][i]<num[b][i];
  // return num[a][i]>num[b][i]; // <- 如果是N^2時請使用這個規則
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>R>>C){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>num[i][j];
    for(int i=0;i<R;i++)
      team[i]=i;
    // N^2 排序法
    //for(int i=0;i<R;i++)
    //  for(int j=i+1;j<R;j++)
    //    if( ChangeTeam(team[i],team[j]) )
    //      swap(team[i],team[j]);
    //
    sort(team,team+R,ChangeTeam);

    for(int i=0;i<R;i++){
      for(int now=team[i], j=0;j<C;j++)
        cout<<num[now][j]<<' ';
      cout<<'\n';
    }
  }
}