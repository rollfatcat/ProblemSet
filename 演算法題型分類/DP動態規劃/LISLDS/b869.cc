#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int N; cin>>N; ){
    int color[3][2]={};
    char ch;
    bool now=0, nxt=1;

    for(int i=0;i<N;i++){
      cin>>ch; //getchar()會因為優化後的不同步導致讀取錯誤
      color[0][nxt]=color[0][now]+(ch=='r');
      color[1][nxt]=max(color[0][now],color[1][now])+(ch=='g');
      color[2][nxt]=max(color[0][now],max(color[1][now],color[2][now]))+(ch=='b');
      now=nxt, nxt=nxt^1;
    }
    cout<<max(max(color[0][now],color[1][now]),color[2][now])<<endl;
  }
}