// 計算範圍內擁有最多因數個數的數，完成後可以嘗試 d717(非常態解)
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int bound=sqrt(1000000000), bound_p;
bool NotPrime[31623]={0};
vector<int>Prime;

int Fac(int x){
  int cnt=1, bound_x=sqrt(x);
  for(int i=0;i<bound_p and Prime[i]<=bound_x and x>1;i++)
    if(x%Prime[i]==0){
      int p=0;
      while(x%Prime[i]==0)
        p++,  x/=Prime[i];
      cnt*=(p+1);
    }
  if(x>1) cnt=cnt<<1;
  return cnt;
}
int main(){
  NotPrime[0]=NotPrime[1]=1;
  Prime.push_back(2);
  for(int i=2;2*i<=bound;i++)
    NotPrime[2*i]=1;
  int idx, bound_min=sqrt(bound);
  for(idx=3;idx<=bound_min;idx+=2)
    if(!NotPrime[idx]){
      Prime.push_back(idx);
      for(int j=3;idx*j<=bound;j+=2)
        NotPrime[idx*j]=1;
    }
  for(;idx<=bound;idx+=2)
    if(!NotPrime[idx])
      Prime.push_back(idx);
  bound_p=Prime.size();
  int caseNum, l, r;

  cin>>caseNum;
  while(caseNum--){
    cin>>l>>r;
    int maxN=l, maxCnt=Fac(l);
    for(int i=l+1;i<=r;i++){
      int cnt=Fac(i);
      if(cnt>maxCnt)
        maxN=i, maxCnt=cnt;
    }
    cout<<"Between "<<l<<" and "<<r<<", "<<maxN<<" has a maximum of "<<maxCnt<<" divisors."<<endl;
  }
}