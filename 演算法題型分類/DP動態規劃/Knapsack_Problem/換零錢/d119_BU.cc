#include<iostream>
using namespace std;

int money[10]={1,5,10,20,50,100,200,500,1000,2000};
long long int cnt[50001];
int main(){
  //Bottom-Up
  fill(cnt,cnt+50001,0);
  cnt[0]=1;
  for(int i=0; i<10; i++)
    for(int j=money[i]; j<=50000; j++)
        cnt[j]+=cnt[ j-money[i] ];
  int tmp, total;
  char c;
  while(scanf("%d",&total) and total){
    for(c=getchar();c!='\n';c=getchar())
      scanf("%d",&tmp), total+=tmp;
    cout<<cnt[total]-1<<endl;
  }
}