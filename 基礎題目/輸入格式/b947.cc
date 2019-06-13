// 練習自己寫讀取(非必須，如果使用cin/cout要加速讀取)
// 題目是簡單模擬美國的選舉制度得票方式，輸出勝選者
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N; scanInt(N); ){
    char name[2][20];
    scanf("%s %s",name[0],name[1]);
    int score, ticket[2], getTicket[2]={0,0};
    for(getchar(); N--;){
      scanInt(score),
      scanInt(ticket[0]),
      scanInt(ticket[1]);
      if(ticket[0]>ticket[1]) getTicket[0]+=score;
      else getTicket[1]+=score;
    }
    puts( (getTicket[0]==getTicket[1])?"Tie":(getTicket[0]>getTicket[1])?name[0]:name[1] );
  }
}