/* 給定下課的時間長度ｎ，第２行的４個數字代表個樓層移動(１-２/２-３/３-４/４-５)的時間
 * 第３行的８個數字則代表需要移動到指定的樓層，輸出是否會趕不上上課時間？
 * 解題關鍵：前綴和
 */
#include<bits/stdc++.h>
using namespace std;

int dis[6]={};
int main(){
  int bound;
  while( scanf("%d\n",&bound)!=EOF ){
    for(int i=2;i<=5;i++){
      scanf("%d",&dis[i]); 
      dis[i]+=dis[i-1];
    }
    bool out=false;
    int nowT, nxtT;  
    scanf("%d",&nowT);
    for(int i=1;i<8;i++){
      scanf("%d",&nxtT);
      out |= abs(dis[nxt]-dis[now])>bound;
      nowT=nxtT;
    }
    puts( (out)? "no": "yes");
  }
}