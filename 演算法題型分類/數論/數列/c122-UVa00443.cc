// 產生只包含特定因數的數列：個別產生質因數的次方項後做DFS累乘
#include<bits/stdc++.h>
using namespace std;

const int bound=2000000000;
vector<int>np[4], num;
int base[4]={2,3,5,7};
void DFS(int now,long x){
  if(now==4){ if(x<=bound) num.push_back(x);  return; }
  for(int i=0;i<np[now].size() and (x*np[now][i])<=bound;i++)
    DFS(now+1,x*np[now][i]);
}
string IdxToStr(int x){
  if(x%10==1 and x%100!=11) return "st";
  if(x%10==2 and x%100!=12) return "nd";
  if(x%10==3 and x%100!=13) return "rd";
  return "th";
}
int main(){
  // np[i]: i的所有次方項數
  for(int i=0;i<4;i++)
    for(long n=1; n<=bound; n*=base[i])
      np[i].push_back(n);
  DFS(0,1);
  sort(num.begin(),num.end());

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int idx; cin>>idx and idx; )
    cout<<"The "<<idx<<IdxToStr(idx)<<" humble number is "<<num[idx-1]<<".\n";
}