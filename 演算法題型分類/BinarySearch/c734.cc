/* 前置題：e995 
 * 數論抓規則，用二分搜尋找範圍
 */
#include<iostream>
#include<vector>
using namespace std;
#define INF 0x7fffffff

vector<int> sum;
int BS(int x){
  if(x>sum.back())  return sum.size();
  int l=0,r=sum.size()-1,m;
  while(l<=r){
    m=(l+r)>>1;
    if(x==sum[m]) return m;
    else if(x>sum[m]) l=m+1;
    else r=m-1;
  }
  return l;
}
int main(){

  int Onelen=0, Onesum=0, len=1, baseL=10;
  sum.push_back(0);
  for(int idx=1; true ;idx++){
    if(idx>=baseL) baseL*=10, len++;
    Onelen+=len,
    Onesum+=Onelen;
    if(Onesum<0) break;
    sum.push_back(Onesum);
  }
  int bound[6]={0,10,180,2700,36000,450000};
  int base[5]={0,10,100,1000,10000};

  int T, n;
  for(cin>>T; T--; ){
    cin>>n;
    for(int pos=n-sum[BS(n)-1], i=1; i<6; pos-=bound[i++])
      if(pos<bound[i]){
        int number=pos/i+base[i-1];
        vector<int> Nbit;
        for(;number;number/=10)
          Nbit.push_back(number%10);
        cout<<Nbit[Nbit.size()-1-(pos%i)]<<' ';
        break;
      }
  }
}