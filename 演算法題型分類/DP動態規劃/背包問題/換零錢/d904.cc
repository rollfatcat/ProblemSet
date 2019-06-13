#include<iostream>
using namespace std;
#define MaxN 10
#define MaxW 1001
#define MIN(a,b)( (a<b)?a:b )

int main(){
  int W, N;
  int money[10], cnt[MaxW];

  while(cin>>W>>N){
    for(int i=0;i<N;i++)
      cin>>money[i];
    fill(cnt,cnt+MaxW,1000000000);
    cnt[0]=0;
    for(int i=0; i<N; i++)
      for(int j=money[i]; j<=W; j++)
        cnt[j]=MIN( cnt[j], cnt[j-money[i]]+1 );
    cout<<cnt[W]<<endl;
  }
}