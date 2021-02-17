#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b; 
  while(scanf("%d %d\n",&a,&b)!=EOF){
    if(a<b) swap(a,b);
    int maxtrix[2][2]={{1,0},{0,1}}, num[2]={a,b};
    bool now=0, nxt;
    for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
      nxt=now^1;  t=num[now]/num[nxt];
      maxtrix[now][0]-=t*maxtrix[nxt][0],
      maxtrix[now][1]-=t*maxtrix[nxt][1];
    }
    printf("%d %d\n",maxtrix[now][0],maxtrix[now][1]);
  }
}