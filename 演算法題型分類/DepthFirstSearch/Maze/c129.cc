// 注意『相鄰』的定義是8個方向不是平常的4個

#include<iostream>
using namespace std;
#define MaxN 100

int m, n;
bool map[MaxN][MaxN];
void DFS(int y, int x){
  if( y<0 or m<=y or x<0 or n<=x or map[y][x]==0 )
    return;
  map[y][x]=0;
  DFS(y-1,x-1);
  DFS(y+1,x-1);
  DFS(y-1,x+1);
  DFS(y+1,x+1);
  DFS(y-1,x);
  DFS(y,x-1);
  DFS(y+1,x);
  DFS(y,x+1);
}

int main(){
  char c;
  while(cin>>m>>n and m>0 and n>0){
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>c, map[i][j]=(c=='@');
    int cnt=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(map[i][j])
          cnt++, DFS(i,j);
    cout<<cnt<<endl;
  }

}