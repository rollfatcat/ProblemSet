// (90%)需要剪枝：(X)最佳解必定包含數列n和數列m當中的最大數
// 計算方式其實是多項式乘法的每項係數，輸出最大的係數值和其所在的次方項

#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 200001

long n[MAXN];
long m[MAXN];
long t[MAXN<<1];
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int N,M; cin>>N>>M;){
    int npos=0, mpos=0;
    long tmpn=0, tmpm=0;
    for(int i=1;i<=N;i++){
      cin>>n[i];
      if(n[i]>tmpn)
        tmpn=n[i], npos=i;
    }
    for(int i=1;i<=M;i++){
      cin>>m[i];
      if(m[i]>tmpm)
        tmpm=m[i], mpos=i;
    }
    memset(t,0,sizeof(t));
    // 問題是卡在這裡 (N,M)<2e5
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
        t[i+j]+=n[i]*m[j];
    long pos=2, maxN=t[2];
    for(int i=min(npos+1,mpos+1);i<=max(npos+M,mpos+N);i++)
      if(t[i]>maxN)
        pos=i, maxN=t[i];
    cout<<pos<<' '<<maxN<<endl;
  }
}