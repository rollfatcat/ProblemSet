// 惡意精確度問題, 可以練習debug
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 30001

long long int cost[30001]={0};

int main(){
  int money[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
  long long int map[MaxN];
  memset(map,0,sizeof(map));

  map[0]=1;
  for(int i=0;i<11;i++)
    for(int j=money[i];j<=30000;j+=5)
      map[j]+=map[j-money[i]];
  double x;
  while(scanf("%lf",&x) and x>0.0){
    int a=100.0*x;
    a=(a/5+(a%5!=0))*5;
    printf("%6.2lf%17lld\n",x,map[a]);
  }
}