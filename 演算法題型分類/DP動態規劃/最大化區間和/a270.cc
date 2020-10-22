#include<iostream>
using namespace std;

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int bound; scanInt(bound);){
    int dis[6]={0,0};
    for(int i=2;i<=5;i++)
      scanInt(dis[i]), dis[i]+=dis[i-1];
    bool out=false;
    int now,nxt,t;  scanInt(now);
    for(int i=1;i<8;i++){
      scanInt(nxt);
      t=dis[nxt]-dis[now];
      if(t<0) t=-t;
      if( t>bound )
        out=true;
      now=nxt;
    }
    if(out) puts("no");
    else puts("yes");
  }
}