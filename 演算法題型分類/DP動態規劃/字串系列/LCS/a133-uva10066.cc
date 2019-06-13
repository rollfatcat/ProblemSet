//給兩個數列 找最常共同子數列
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 101

int main(){
  int cnt[MaxN][MaxN];
  int alen, blen;
  int a[MaxN],  b[MaxN];

  for(int caseNum=1;cin>>alen>>blen and alen;caseNum++){
    for(int i=0;i<alen;i++) cin>>a[i];
    for(int i=0;i<blen;i++) cin>>b[i];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<alen;i++)
      for(int j=0;j<blen;j++)
        cnt[i+1][j+1]=(a[i]==b[j])?(cnt[i][j]+1):max(cnt[i+1][j],cnt[i][j+1]);
    cout<<"Twin Towers #"<<caseNum<<"\nNumber of Tiles : "<<cnt[alen][blen]<<"\n";
  }
}