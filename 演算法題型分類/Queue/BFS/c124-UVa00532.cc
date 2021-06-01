// Test Data網址：https://www.udebug.com/UVa/532
// 要太多的 memory也會吃 RE (SIGABRT)
// 從2D拓展到3D 注意記憶體使用量
#include<iostream>
#include<queue>
using namespace std;

int L, R, C;
bool map[32][32][32];
struct Node{int x,y,z,d; } st,ed;
int main(){
  int dx[6]={ 1,-1, 0, 0, 0, 0};
  int dy[6]={ 0, 0, 1,-1, 0, 0};
  int dz[6]={ 0, 0, 0, 0, 1,-1};
  char ch;
  while(cin>>L>>R>>C and L){
    for(int i=0;i<L;i++)
      for(int j=0;j<R;j++)
        for(int k=0;k<C;k++){
          cin>>ch;
          map[i][j][k]=(ch!='#');
          if(ch=='S')
            st.x=k, st.y=j, st.z=i, st.d=0;
          if(ch=='E')
            ed.x=k, ed.y=j, ed.z=i;
        }
    queue<Node> Q;
    Q.push(st);
    while(!Q.empty()){
      Node now=Q.front(); Q.pop();
      if(map[now.z][now.y][now.x]==0) //更新過就不展開,這一定要加不然會要太多記憶體
        continue;
      map[now.z][now.y][now.x]=0;
      if(now.x==ed.x and now.y==ed.y and now.z==ed.z){
        ed.d=now.d; break;
      }
      Node nxt;
      nxt.d=now.d+1;
      for(int i=0;i<6;i++){
        nxt.x=now.x+dx[i],  nxt.y=now.y+dy[i],  nxt.z=now.z+dz[i];
        if(nxt.x<0 or nxt.y<0 or nxt.z<0 or C<=nxt.x or R<=nxt.y or L<=nxt.z or map[nxt.z][nxt.y][nxt.x]==0)
          continue;
        Q.push(nxt);
      }
    }
    if(map[ed.z][ed.y][ed.x])
      cout<<"Trapped!"<<endl;
    else
      cout<<"Escaped in "<<ed.d<<" minute(s)."<<endl;
  }
}
