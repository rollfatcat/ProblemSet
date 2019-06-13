
#include<iostream>
using namespace std;
#define MaxN 10
#define MaxW 30001

int main(){
  int W;
  int money[5]={1,5,10,25,50};
  long long int cnt[MaxW];

  fill(cnt,cnt+MaxW,0);
  cnt[0]=1;
  for(int i=0; i<5; i++)
    for(int j=money[i]; j<=30000; j++)
      cnt[j]+=cnt[j-money[i]];
  while(cin>>W)
    if(cnt[W]==1)
      cout<<"There is only 1 way to produce "<<W<<" cents change.\n";
    else
      cout<<"There are "<<cnt[W]<<" ways to produce "<<W<<" cents change.\n";

}