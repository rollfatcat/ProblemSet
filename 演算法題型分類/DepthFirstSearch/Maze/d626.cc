#include<iostream>
using namespace std;
#define MaxN 100

int n;
bool map[MaxN][MaxN];
void DFS(int x,int y){
  if(x<0 or y<0 or x>=n or y>=n or map[y][x])
    return;
  map[y][x]=1;
  DFS(x-1,y);
  DFS(x+1,y);
  DFS(x,y-1);
  DFS(x,y+1);
}
int main(){
  string ss;
  int x, y;

  while(cin>>n){
    for(int i=0;i<n;i++){
      cin>>ss;
      for(int j=0;j<n;j++)
        map[i][j]=(ss[j]=='+');
    }
    cin>>y>>x,  DFS(x,y);
    for(int i=0;i<n;i++, cout<<endl)
      for(int j=0;j<n;j++)
        cout<<((map[i][j])?'+':'-');
  }
}