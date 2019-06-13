// 二分搜尋找插入點, 8ms, 但不知道0ms怎麼弄的= =
#include<iostream>
#include<vector>
using namespace std;

vector<int> num;
int BS(int x){
  if(x>num.back())  return num.size();
  int l=0, r=num.size()-1, m;
  while(l<=r){
    m=(l+r)/2;
    if(num[m]==x) return m;
    else if(num[m]>x) r=m-1;
    else l=m+1;
  }
  return l;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int x;

  cin>>x, num.push_back(x), cout<<x<<endl;
  while(cin>>x){
    num.insert(num.begin()+BS(x),x);
    int len=num.size();
    if(len%2) cout<<num[len/2]<<'\n';
    else  cout<<(num[len/2-1]+num[len/2])/2<<'\n';
  }
}