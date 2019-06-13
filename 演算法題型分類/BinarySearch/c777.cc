#include<iostream>
#include<vector>
using namespace std;

vector<long> num;
int BS(long x){
  if(x>num.back())  return num.size();
  int l=0, r=num.size()-1, m;
  while(l<=r){
    m=(l+r)/2;
    if(num[m]==x)
      return m;
    else if(num[m]>x)
      r=m-1;
    else
      l=m+1;
  }
  //當找不到目標時,回傳數字落在大於目標中最小的值
  return l;
}
int main(){
  num.push_back(0);
  num.push_back(1);
  num.push_back(2);
  for(int i=3; true; i++){
    long x=num[i-1]+num[i-2]+num[i-3];
    if(x<=1000000000000000000)  num.push_back(x);
    else  break;
  }
  for(long n, m; cin>>n>>m; ){
    if(n>m){ cout<<"0\n"; continue; }
    int l=BS(n), r=BS(m), cnt=r-l;
    if(l==r and m==num[r]) cnt=1;
    if(l!=r and m==num[r] and n==num[l]) cnt++;
    cout<<cnt<<endl;
  }
}