// 注意DFS時輸出的字串順序必須符合二進位之後的數值由小到大
// 反著思考：原題是選'1'的位置改為選'0'的位置由小到大
#include<bits/stdc++.h>
using namespace std;

const int MAXN=16;
int N, H;
int bag[MAXN];
char ss[20];

void DFS(int st,int now){
  if(now==H){
    memset(ss,'1',sizeof(ss));
    ss[N]='\0';
    for(int i=0;i<H;i++)
      ss[bag[i]]='0';
    puts(ss);
    return;
  }
  for(int i=st;i<=N-(H-now);i++)
    bag[now]=i,
    DFS(i+1,now+1);
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--)
    scanf("%d %d",&N,&H),
    H=N-H, //改為選'0'的位置和數量
    DFS(0,0);
}