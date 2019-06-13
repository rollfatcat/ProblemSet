// Modular Multiple Inverse
#include<iostream>
using namespace std;

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int a,n; scanInt(a) and scanInt(n); ){
    if(n==1){ puts("No Inverse"); continue; }
    int num[2]={a,n};
    long maxtrix[2][2]={{1,0},{0,1}};
    bool now=0, nxt;
    for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
      nxt=now^1;  t=num[now]/num[nxt];
      maxtrix[now][0]-=t*maxtrix[nxt][0],
      maxtrix[now][1]-=t*maxtrix[nxt][1];
    }
    if(maxtrix[now][0]<0) maxtrix[now][0]+=((now)?n:a);
    if(num[now]==1) printf("%ld\n",maxtrix[now][0]);
    else  puts("No Inverse");
  }
}