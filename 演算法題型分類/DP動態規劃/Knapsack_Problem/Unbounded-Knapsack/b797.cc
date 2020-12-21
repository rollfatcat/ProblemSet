// 大數版本的無限背包問題
#include<bits/stdc++.h>
using namespace std;

const long base=1e18;
vector<long> DP[40001];
vector<long> BigNumber_add(vector<long> &a, vector<long> &b){
  vector<long>tmp=a;
  long carry=0;
  for(int k=0; k<b.size(); k++)
    tmp[k]+=b[k]+carry,
    carry=tmp[k]/base,
    tmp[k]%=base;
  for(int k=b.size(); k<a.size() and carry>0; k++)
    tmp[k]+=carry,
    carry=tmp[k]/base,
    tmp[k]%=base;
  if(carry>0) tmp.push_back(carry);
  return tmp;
}
int main(){
  for(int i=0;i<=40000;i++)
    DP[i].push_back(1);
  for(int i=2;i<=200;i++)
    for(int j=0,t=i*i;t<=40000;j++,t++)
      //DP[j+jump]+=DP[j]; <- 改成大數相加
      DP[t]=(DP[j].size()<=DP[t].size())?BigNumber_add(DP[t],DP[j]):BigNumber_add(DP[j],DP[t]);
  int T, N;
  for(scanf("%d",&T); T--;){
    scanf("%d",&N);
    printf("%ld",DP[N].back());
    for(int i=DP[N].size()-2;i>=0;i--)
      printf("%018ld",DP[N][i]);
    puts("");
  }
}