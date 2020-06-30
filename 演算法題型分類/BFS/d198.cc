/* Map的數值可能會overflow 記得用long long
 * 測資很難吃
 */
#include<iostream>
using namespace std;

int W, N;
long long int map[101][101];
bool NP[101][101];

int main(){
  int T, st, ed;
  char c;

  cin>>T;
  while(T--){
    cin>>W>>N;
    for(int i=0;i<=W;i++)
      for(int j=0;j<=N;j++)
        NP[i][j]=1, map[i][j]=0;
    for(int i=1; i<=W; i++){
      cin>>st;
      for(c=getchar(); c==' ';c=getchar())
        cin>>ed,  NP[st][ed]=0;
    }
    map[0][1]=NP[0][1]=1;
    for(int i=1;i<=W;i++)
      for(int j=1;j<=N;j++)
        if(NP[i][j])
          map[i][j]=NP[i][j-1]*map[i][j-1]+NP[i-1][j]*map[i-1][j];
    cout<<map[W][N]<<endl;
    if(T) cout<<endl;
  }
}
